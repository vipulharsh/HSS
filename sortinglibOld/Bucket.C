extern CkReduction::reducerType sum_uint64_t_type; 

template <class key, class value>
Bucket<key, value>::Bucket(CkMigrateMessage *){}

///initialize Bucket (create data)
template <class key, class value>
Bucket<key, value>::Bucket(CProxy_Main<key, value> main_proxy, key min, key max){
  //CkPrintf("Creating chare %d of bucket chare array\n", this->thisIndex);
  mainProxy = main_proxy;
  key_min = min;
  key_max = max;
  myProxy = this->thisProxy;
  ///need to define this in order to search data array, can reuse everywhere
  kvp_comp = new kv_pair<key, value>();
  sSample = 17; //should get better strategy for this 
  Reset();
}

//reset variables after sorting
template <class key, class value>
void Bucket<key, value>::Reset(){
  loadIndex = 0;
  buffering = 0;
  sortedIndex = 0;
  num_elements = -1;
  num_Loaded = 0;
  initial_probe = NULL;  //must be this way at start of iteration
  GotSizes = false;
  bLoad = false;
  yieldtosends = false;  
  numsent = 0;
  numsent_buffer = 0;
  doneHists = false;
  isCallbackSet = 0;
}

///input unsorted data (should be called by application)
template <class key, class value>
void Bucket<key, value>::SetCallback(const CkCallback &cb){
  DEBUGPRINTF("Set callback of chare %d of bucket chare array\n", this->thisIndex);
  myCallback = (CkCallback)cb;
  isCallbackSet = 1;
}

///input unsorted data (should be called by application)
template <class key, class value>
void Bucket<key, value>::SetData(data_msg<key, value> *msg){
  DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
  num_elements = msg->num_vals;
  //CkAssert(num_elements > 0);
  bucket_data = msg->pairs;
  init_data = msg;
  CheckInitialDist();
}

template <class key, class value>
void Bucket<key, value>::SetData(){
  DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
  num_elements = in_elems;
  //CkAssert(num_elements > 0);
  bucket_data = (kv_pair<key, value>*)dataIn;
#if VERBOSE
  double sum = 0; int keysum = 0;
  for(int i = 0; i < num_elements; i++) {
    if(bucket_data[i].myKey == key_min) {
      CmiAbort("min_key found in input data; code may not work correctly\n");
    }
    keysum += (int)(bucket_data[i].myKey % 100);
    double *ptr = (double*)(bucket_data[i].myVal.second);
    for(int j = 0; j < 2; j++) {
      sum += *ptr;
      ptr++;
    }
  }
  this->contribute(sizeof(double), &sum, CkReduction::sum_double,
  CkCallback(CkIndex_Main<key, value>::init_dsum(NULL),mainProxy));
  this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
  CkCallback(CkIndex_Main<key, value>::init_isum(NULL),mainProxy));

  //printf("%d ** KeySum %lu Sum %lf\n",1,keysum, sum);
#endif
  init_data = NULL;
  CheckInitialDist();
}

///begin sorting
template <class key, class value>
void Bucket<key, value>::CountFirstProbe(first_probe<key, value> *msg){
  initial_probe = msg;
  splice_thresh = msg->splice_thresh;
  eager_send = msg->eager_send;
  num_buckets = msg->num_buckets;
  SorterProxy = msg->sorter_proxy;
  CheckInitialDist();
}

///remove unused splitters for faster calculation of new splitters, minimize splitter pollution
template <class key, class value>
void Bucket<key, value>::CleanSplitters(){
  //TODO: implement cleaning of structures
}


///determine locations of the first set of splitters
template <class key, class value>
void Bucket<key, value>::CheckInitialDist(){
  if (num_elements != -1 && initial_probe != NULL){
    ///get sep_counts(locations) from splitter guesses
    num_separators = initial_probe->num_keys + 2;
    //initialize local histogram array
    sep_counts = new int[num_separators];
    sep_counts[0] = 0;
    sep_counts[num_separators-1] = num_elements;

    //set inital separator keys array to the initial probe
    sep_keys = new key[num_separators];
    sep_keys[0] = key_min;
    sep_keys[num_separators-1] = key_max;
    memcpy(sep_keys+1, initial_probe->splitter_guesses, (num_separators-2)*sizeof(key));

    //initialize array that keeps track of sorted chunks
    sorted = new bool[num_separators];
    std::fill(sorted, sorted+(num_separators-1),0);
    sorted[num_separators-1] = 1;

    if(num_elements != 0) {
      GetSeparators(1, num_separators-2, 0, num_elements, sep_keys, sep_counts);
    } else {
      sortedIndex = num_separators-1;
      for(int i = 0; i < num_separators; i++) {
        sorted[i] = 1;
        sep_counts[i] = 0;
      }
    }

    ///get the number of keys between each pair of splitters and contribute local histogram
    uint64_t *longSenderSizes = new uint64_t[initial_probe->num_keys+1];
    for (int i = 0; i < initial_probe->num_keys + 1; i++){
      longSenderSizes[i] = sep_counts[i+1];
    }
    //contribute local histogram
    this->contribute((initial_probe->num_keys + 1)*sizeof(uint64_t), longSenderSizes, sum_uint64_t_type, CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), SorterProxy));
    delete [] longSenderSizes;

    //begin sorting sections
    myProxy[this->thisIndex].StepSort();
    delete initial_probe;
    initial_probe = NULL;
  }
}

///figures out the value of all splitters indexed between min and max (inclusive), in the range of counts between minVal and maxVal
template <class key, class value>
void Bucket<key, value>::GetSeparators(int min, int max, int minVal, int maxVal, key *new_guesses, int* new_sep_counts){
    int mid;
    ///if the range is below some threshold just sort everything in that threshold then search for the range
    if (maxVal - minVal < splice_thresh){
      mid = (min+max)/2;
      //sort only if necessary
      if (!sorted[mid]){
	if (minVal + 1  < maxVal) std::sort(bucket_data + minVal, bucket_data + maxVal);
	for (int i = min-1; i <= max; i++){
	  sorted[i] = 1;
	}
      }
      //search for middle key
      kvp_comp->myKey = new_guesses[mid];
      new_sep_counts[mid] = std::upper_bound(bucket_data + minVal, bucket_data + maxVal, *kvp_comp) - bucket_data;
    }
    else{
      if (min == max)
	mid = min;
      else {
	//get an approximate median inside given data range then find a pivot closest to that median
	key pivot = getSampleMedian(minVal, maxVal-1, sSample);
	mid = std::lower_bound(new_guesses + min, new_guesses + (max-1), pivot) - new_guesses;
      }
      //splice the array according with the pivot
      new_sep_counts[mid] = SpliceArray(bucket_data, minVal, maxVal, new_guesses[mid]);
    }
    //recurse on the rest of the sep_counts
    if (mid < max)
      GetSeparators(mid+1, max, new_sep_counts[mid], maxVal, new_guesses, new_sep_counts);
    if (mid > min)
      GetSeparators(min, mid-1, minVal, new_sep_counts[mid], new_guesses, new_sep_counts);
    
}

///split array using a quicksort style pivot while simulateneously determining the location of that pivot (actually is some splitter)
template <class key, class value>
int Bucket<key, value>::SpliceArray(kv_pair<key, value>* arr, int begin, int end, key pivot){
  if (begin >= end)
    return end;
  int left = begin-1;
  int right = end;
 
  kv_pair<key, value> t; 
  for(;;){
    //find elements to swap on each side of array
    while(++left < right && arr[left].myKey <= pivot);
    while(--right > left && arr[right].myKey > pivot);
    if (left >= right) break;
    //swap elements
    t = arr[left];
    arr[left] = arr[right];
    arr[right] = t;
    /*arr[left] = arr[right] ^ arr[left];
    arr[right] = arr[right] | arr[left];
    arr[left] = arr[right] | arr[left];*/
  }
  return left;
}

///Sort local data between splitters
///Each entry method call sorts data between two splitters from left to right
///This largely assumes minimal cost of self entry method calls (verified experimentally, dependent on charm)
template <class key, class value>
void Bucket<key, value>::StepSort(){
  ///if we have determined splitters work on those, sort later (those usually involve sorting work anyway, and should be prioritized)
  if(num_elements == 0) yieldtosends = false;

  if (yieldtosends){
    myProxy[this->thisIndex].StepSort();
    return;
  }
  ///move sorted index until we find a range to be sorted or we iterate through all splitters
  while (sortedIndex < num_separators-1 && sorted[sortedIndex]){
    sortedIndex++;
  }
  if (sortedIndex >= num_separators-1){
    DEBUGPRINTF("[%d] done sorting\n", this->thisIndex);
    if (numsent == num_buckets && GotSizes && !bLoad) PrepareForLoad();
    return;
  }
  if (sep_counts[sortedIndex] +1 < sep_counts[sortedIndex+1]){
    std::sort(bucket_data + sep_counts[sortedIndex], bucket_data + sep_counts[sortedIndex+1]);
  }
  sorted[sortedIndex] = 1;
  sortedIndex++;
  ///recursive call, entry only if we are still awaiting histograms
  if (doneHists)
    StepSort();
  else 
    myProxy[this->thisIndex].StepSort();
}

///entry method called to determine locations of splitters
///this function is quite complicated, but needs to be very efficient
///Separating it into multiple fjunctions is non-trivial and would require transfer of variables which adds an overhead.
template <class key, class value>
void Bucket<key, value>::CountProbe(next_probe<key> *pb){
  DEBUGPRINTF("[%d] processing probe sorted index = %d/%d\n", this->thisIndex, sortedIndex, num_separators-1);
  int *senderSizes = new int[pb->num_keys+1];
  ///if not everything is sorted
  if (sortedIndex < num_separators-1){
    int insideSorted = 0;
    ///look up all splitters in the sorted section at the start
    while(insideSorted < pb->num_keys && pb->splitter_guesses[insideSorted] < sep_keys[sortedIndex]){
      //TODO: cut down search range
      kvp_comp->myKey = pb->splitter_guesses[insideSorted];
      senderSizes[insideSorted] = std::upper_bound(bucket_data, 
	bucket_data + sep_counts[sortedIndex], *kvp_comp) - bucket_data;
      //senderSizes[insideSorted] = Search(Hist[insideSorted], bucket_data, senderSizes[insideSorted-1], sep_counts[sortedIndex]-1);
      insideSorted++;
    }
    if (insideSorted != pb->num_keys){
      //CkPrintf("[%d] I am doing splicing\n", this->thisIndex);
      //need to keep track of the sep_counts and the keys that subdivide the data
      int* new_sep_counts = new int[pb->num_keys + num_separators - insideSorted];
      key* new_sep_keys = new key[pb->num_keys + num_separators - insideSorted];
      memcpy(new_sep_counts, sep_counts, sortedIndex*sizeof(int));
      new_sep_counts[pb->num_keys + num_separators - insideSorted -1] = num_elements;
      memcpy(new_sep_keys, sep_keys, sortedIndex*sizeof(key));
      new_sep_keys[pb->num_keys + num_separators - insideSorted -1] = key_max;

      bool* oldSorted = sorted;
      sorted = new bool[pb->num_keys + num_separators - insideSorted - 1];
      std::fill(sorted+sortedIndex, sorted + (pb->num_keys+num_separators-insideSorted-1), 0);
      std::fill(sorted, sorted+sortedIndex,1);
      int newIdx = sortedIndex; 
      int senderIdx = insideSorted;
      int sepIdx = sortedIndex;
      int siSave;
      ///while we are within the bounds of existing as well as new sep_counts
      while (senderIdx < pb->num_keys && sepIdx < num_separators-1){
	siSave = senderIdx;
	//find all the guesses that fit between the two existing splitters
	while (senderIdx < pb->num_keys && sep_keys[sepIdx] > pb->splitter_guesses[senderIdx]){
	  senderIdx++;
	}
	//determine the locations of all the guesses found above
	if (senderIdx > siSave){
	  memcpy(new_sep_keys + newIdx, pb->splitter_guesses + siSave, (senderIdx-siSave)*sizeof(key));
	  //if that range was sorted, we can jsut search for the guesses
	  if (oldSorted[sepIdx-1] == 1){
	    for (int j = siSave; j < senderIdx; j++){
	      sorted[newIdx + j - siSave - 1] = 1;
	      kvp_comp->myKey = pb->splitter_guesses[j]; 
	      new_sep_counts[newIdx + j - siSave] = std::upper_bound(bucket_data + new_sep_counts[newIdx + j - siSave - 1], 
		bucket_data + sep_counts[sepIdx], *kvp_comp) - bucket_data;
	    }
	  }
	  else //if the range is not sorted we splice
	    GetSeparators(newIdx, newIdx+(senderIdx-siSave)-1, sep_counts[sepIdx-1], sep_counts[sepIdx], new_sep_keys, new_sep_counts);
	  memcpy(senderSizes + siSave, new_sep_counts + newIdx, (senderIdx-siSave)*sizeof(int));
	  newIdx += senderIdx-siSave;
	}
	sorted[newIdx] = oldSorted[sepIdx];
	new_sep_counts[newIdx] = sep_counts[sepIdx];
	new_sep_keys[newIdx] = sep_keys[sepIdx];
	sepIdx++;
	newIdx++;
      }
      ///take care of splitters outside the above bounds
      //copy old splitters to new structure
      if(sepIdx < num_separators-1){
	memcpy(&new_sep_counts[newIdx], &sep_counts[sepIdx], (num_separators-1-sepIdx)*(sizeof(int)));
	memcpy(&new_sep_keys[newIdx], &sep_keys[sepIdx], (num_separators-1-sepIdx)*(sizeof(key)));
      }
      ///find any remaining splitter guesses that are bigger than all old splitters
      if (senderIdx < pb->num_keys){
	memcpy(new_sep_keys + newIdx, pb->splitter_guesses + senderIdx, (pb->num_keys -senderIdx)*sizeof(key));
	//if sorted, search
	if (sorted[num_separators-2]){
	  for (int j = senderIdx; j < pb->num_keys; j++){
	    sorted[newIdx + j - senderIdx] = 1;
	    kvp_comp->myKey = pb->splitter_guesses[j]; 
	    new_sep_counts[newIdx + j - senderIdx] = std::upper_bound(bucket_data + new_sep_counts[newIdx + j - senderIdx - 1],
	      bucket_data + num_elements, *kvp_comp) - bucket_data;
	  }
	}
	else //if unsorted, splice
	  GetSeparators(newIdx, newIdx+(pb->num_keys-senderIdx)-1, sep_counts[num_separators-1], num_elements, new_sep_keys, new_sep_counts);
	memcpy(senderSizes + senderIdx, new_sep_counts + newIdx, (pb->num_keys - senderIdx)*sizeof(int));
      }
      num_separators = pb->num_keys + num_separators - insideSorted;
      delete [] oldSorted;
      delete [] sep_counts;
      delete [] sep_keys;
      sep_counts = new_sep_counts;
      sep_keys = new_sep_keys;
    }
    senderSizes[pb->num_keys] = num_elements;
    //myProxy[this->thisIndex].CleanSplitters();
  }
  else {
    ///if everything is sorted, just search for the splitters	  
    senderSizes[pb->num_keys] = num_elements;
    for (int i = pb->num_keys-1; i >= 0; i--){
      if(num_elements == 0) {
        senderSizes[i] = 0;
      } else {
        kvp_comp->myKey = pb->splitter_guesses[i]; 
        senderSizes[i] = std::upper_bound(bucket_data, bucket_data + num_elements, *kvp_comp) - bucket_data;
      }
    }
  }	
  
  //use 64-bit in reduction since total histogram might surpass 32-bit limit
  uint64_t *longSenderSizes = new uint64_t[pb->num_keys+1];
  for (int i = 0; i < pb->num_keys+1; i++)
    longSenderSizes[i] = senderSizes[i];
  CkReductionMsg* redmsg = CkReductionMsg::buildNew((pb->num_keys+1)*sizeof(uint64_t), longSenderSizes, sum_uint64_t_type);
  redmsg->setCallback(CkCallback(CkIndex_Sorter<key, value>::Histogram(NULL), SorterProxy));
  this->contribute(redmsg);
    
  delete [] longSenderSizes;
  delete [] senderSizes;
  
  //analyze determined ranges
  if (pb->num_ranges > 0){
    probe_buffer.push_back(pb);
    ///begin sending out data if we have determined some splitters
    myProxy[this->thisIndex].SendPortion(0, probe_buffer.size()-1);
    ///prioritize this task over regular sorting
    yieldtosends = true;
  }
}

///entry method used to schedule recursive calls for cheap
///Sends data to determined ranges as dictated by destinations and resolvedRanges
///if k is -1 this sends all data that it needs to, if not it only sends data for 1 processor than calls on itself with k = k+1 
template <class key, class value>
void Bucket<key, value>::SendPortion(int k, int npd){
  next_probe<key>* pb = probe_buffer[npd];

  charm_resolved_range<key> *rranges = pb->send_info;
  int numranges = pb->num_ranges;
  
  int iter, upperSplitter, lowerSplitter, start, end;
  //send out either to a single processor or to all the newly defined ranges
  for (int i = std::max(k,0); i < numranges; i++){
    iter = (i + this->thisIndex)%(numranges); //enforces circularity of sends to prevent overload
    if (rranges[iter].chare_dest == this->thisIndex) {
      new_num_elements = rranges[iter].total;
    }
    if(num_elements == 0) {
      numsent = num_buckets;
      continue;
    }
    DEBUGPRINTF("[%d] trying to send data to chare %d\n", this->thisIndex, rranges[iter].chare_dest);
    ///if everything is already sorted
    if (sortedIndex >= num_separators -1){
      //TODO: I THINK THE SEARCH SPACE CAN BE NARROWED HERE
      //just search for the range
      if (rranges[iter].chare_dest != num_buckets -1){
	kvp_comp->myKey = rranges[iter].upperb;
	end = std::upper_bound(bucket_data, bucket_data + num_elements, *kvp_comp) - bucket_data;
      }
      else
	end = num_elements;
      if (rranges[iter].chare_dest == 0)
	start = 0;
      else {
	kvp_comp->myKey = rranges[iter].lowerb;
	start = std::upper_bound(bucket_data, bucket_data + end, *kvp_comp) - bucket_data;
      }
      //printf("[%d] Send to %d %d-%d %llu:%llu\n",CkMyPe(), rranges[iter].chare_dest, start, end, rranges[iter].lowerb, rranges[iter].upperb);
      SendOne(iter, start, end, rranges[iter].chare_dest);
      //if(end - start)
      //  printf("[%d] CASE 1 sending data to chare %d, %d - %d, %lu - %lu, %lu - %lu\n", this->thisIndex, rranges[iter].chare_dest, start, end, rranges[iter].lowerb, rranges[iter].upperb, bucket_data[0].myKey, bucket_data[num_elements-1].myKey);
    }
    else {
    ///not everything is sorted so we have to make sure the data we send out gets sorted first
    //if (rranges[iter].chare_dest != num_buckets - 1){
      ///find upper splitter
      upperSplitter = std::lower_bound(sep_keys, sep_keys + num_separators, rranges[iter].upperb) - sep_keys;
      ///find lower splitter, sorting everything in between
      lowerSplitter = upperSplitter;
      do {
	lowerSplitter--;
	DEBUGPRINTF("[%d] sortedIndex = %d lowerSplitter = %d\n", this->thisIndex, sortedIndex, lowerSplitter);
	///if not in a sorted section of data
	if (lowerSplitter >= sortedIndex && !sorted[lowerSplitter]){
	  std::sort(bucket_data + sep_counts[lowerSplitter], bucket_data + sep_counts[lowerSplitter+1]);
	  sorted[lowerSplitter] = 1;
	}
      } while (sep_keys[lowerSplitter] > rranges[iter].lowerb);
//	TODO: This can be done faster
      kvp_comp->myKey = rranges[iter].lowerb;
      start = std::upper_bound(bucket_data + sep_counts[lowerSplitter], bucket_data + sep_counts[upperSplitter], *kvp_comp) - bucket_data;
      kvp_comp->myKey = rranges[iter].upperb;
      end = std::upper_bound(bucket_data + sep_counts[lowerSplitter], bucket_data + sep_counts[upperSplitter], *kvp_comp) - bucket_data;
      SendOne(iter, start, end, rranges[iter].chare_dest);
      //if(end - start)
      //  printf("[%d] CASE 2 sending data to chare %d, %d - %d, %lu - %lu, %lu - %lu\n", this->thisIndex, rranges[iter].chare_dest, start, end, rranges[iter].lowerb, rranges[iter].upperb, bucket_data[0].myKey, bucket_data[num_elements-1].myKey);
    }
    ///WARNING: this is weird what if k == -1 and this is the last data getting sent out? will that case be handled ok?

    ///if k = -1 continue, otherwise call yourself and do a few checks
    if (k != -1){
      yieldtosends = true;  
      //if we are not done continue sending
      if(k+1 < numranges) {
        myProxy[this->thisIndex].SendPortion(k+1 ,npd);
        return;
      } 
    }
  }
  if (numsent == num_buckets && GotSizes && sortedIndex >= num_separators -1 && !bLoad) PrepareForLoad();
  yieldtosends = false;
}

//send a message or store it in buffer
template <class key, class value>
void Bucket<key, value>::SendOne(int iter, int start, int end, int chare_dest){
  if (end-start > 0){
    data_msg<key, value> *msg_to_send = new (end-start) data_msg<key, value>;
    msg_to_send->num_vals = end-start;
    memcpy(msg_to_send->pairs, bucket_data + start, (end-start)*sizeof(kv_pair<key, value>));
    #ifdef DEBUG
    CkPrintf("[%d] doing sanity check on message going to %d\n", this->thisIndex, chare_dest);
    for (int i = 1; i < end-start; i++){
      if (msg_to_send->pairs[i] < msg_to_send->pairs[i-1]){
	printf("[%d] Sanity check failled on element %d\n", this->thisIndex, i);
	CkAssert(false);
      }
    }
    #endif
      
    //*((int*)CkPriorityPtr(msg)) = INT_MAX;
    //CkSetQueueing(msg, CK_QUEUEING_IFIFO); 
    ///only send very few of the messages since we finished sorting and probably have nothing to overlap with
    ///once merging begins we will send the rest gradually
    if (eager_send != 0) { // && (chare_dest + this->thisIndex) % (num_buckets/eager_send) == 0)
      myProxy[chare_dest].Load(msg_to_send);
    } else {
      sendBuffer.push_back(new buffered_msg<key, value>(msg_to_send, chare_dest));
    }
  }
  else {
    DEBUGPRINTF("[%d] not sending any data to chare %d\n", this->thisIndex, chare_dest);
  }
  numsent++;
}

//this is an entry method that gets called when all splitters were converged
//the probe contains only nrewly resolved ranges
template <class key, class value>
void Bucket<key, value>::SendAll(next_probe<key> *pb){
  probe_buffer.push_back(pb);
  SendPortion(-1, probe_buffer.size()-1);
  GotSizes = true;
  //allow merging to begin if we sent(or created buffered messages) all data 
  if (numsent == num_buckets && sortedIndex >= num_separators -1 && !bLoad) PrepareForLoad();
  //if we are sendign everything at once (useful for machine specific all-to-all)
  //if (eager_send == 0){
  while (sendBuffer.size() > 0){
    myProxy[sendBuffer.back()->chare_dest].Load(sendBuffer.back()->msg);
    delete sendBuffer.back();
    sendBuffer.pop_back();
  }
//  }
}

//delete old data and get read y to load data
template <class key, class value>
void Bucket<key, value>::PrepareForLoad(){
  DEBUGPRINTF("[%d] preparing to load data\n",this->thisIndex);
  //delete old data, counts, and splitters. we dont need it anymore!
  if(init_data != NULL) delete init_data;    
  delete [] sep_keys;
  delete [] sep_counts;
  delete [] sorted;  

  for (int i = 0; i < probe_buffer.size(); i++){
    delete probe_buffer[i];
  }
  probe_buffer.clear();

  if (new_num_elements == 0){
#if VERBOSE
    printf("[%d] Zero elements\n",CkMyPe());
    double sum = 0; int keysum = 0;
    this->contribute(sizeof(double), &sum, CkReduction::sum_double,
        CkCallback(CkIndex_Main<key, value>::final_dsum(NULL),mainProxy));
    this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
        CkCallback(CkIndex_Main<key, value>::final_isum(NULL),mainProxy));

    //printf("%d ** KeySum %lu Sum %lf\n",2,keysum, sum);
#endif

    if(isCallbackSet) {
      data_msg<key, value> *msg_to_return = new (new_num_elements) data_msg<key, value>;
      msg_to_return->num_vals = new_num_elements;
      myCallback.send(msg_to_return);
    } else {
      *out_elems = new_num_elements;
      *dataOut = (void*)(new kv_pair<key, value>[new_num_elements]);
      this->contribute(CkCallback(CkIndex_Main<key, value>::Exit(), mainProxy));
    }

    while (sendBuffer.size() > numsent_buffer){
      buffered_msg<key, value>* msg_to_send = sendBuffer[(numsent_buffer + this->thisIndex)%sendBuffer.size()];
      myProxy[msg_to_send->chare_dest].Load(msg_to_send->msg);
      delete msg_to_send;
      numsent_buffer++;
    }

    sendBuffer.clear();
    Reset();
    #ifdef VERBOSE
    this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), SorterProxy));
    #endif
  }
  else {
    bLoad = true;
    myProxy[this->thisIndex].Load(); //start accepting data for merging
  }
}

///it is possible to merge before sorting is done, but why do it?
///if we are ready to merge keep loading until we loaded everything in buffer 
template <class key, class value>
void Bucket<key, value>::Load(){
  if (buffering > 0) {
    LoadNow(LoadBuffer[--buffering]);
    myProxy[this->thisIndex].Load();
  } else 
    LoadBuffer.clear();
}

///load entry method, just throw the msg into a buffer and tell the loader to start work if it is stopped
template <class key, class value>
void Bucket<key, value>::Load(data_msg<key, value>* msg){
  DEBUGPRINTF("[%d] received data chunk\n", this->thisIndex);
  if (bLoad){ //why was this here?... && ((GotSizes && buffering == 1) || (!GotSizes && buffering == 2)))
    LoadNow(msg);
  }else {
    LoadBuffer.push_back(msg);
    buffering++;
  }
}

///actually start merging 
template <class key, class value>
void Bucket<key, value>::LoadNow(data_msg<key, value>* msg){
  DEBUGPRINTF("[%d] loading data chunk\n", this->thisIndex);
  for (int i = 0; i < 1; i++){
    if (sendBuffer.size() > numsent_buffer){
      buffered_msg<key, value>* msg_to_send = sendBuffer[(numsent_buffer + this->thisIndex)%sendBuffer.size()];
      myProxy[msg_to_send->chare_dest].Load(msg_to_send->msg);
      delete msg_to_send;
      numsent_buffer++;
    }
  }
  ///if this is the first message, initialize stuff
  loadIndex += msg->num_vals;
  DEBUGPRINTF("[%d] loadIndex = %d/%d\n", this->thisIndex, loadIndex, new_num_elements);
  lastMerged.push_back(msg->pairs);
  lastArraySizes.push_back(loadIndex);
  if (loadIndex == msg->num_vals){
      if (this->thisIndex < 4)
	c1 = CmiWallTimer();
    num_Loaded = 1;
    //use to arrays of size n/p for merging
    //chunks will jump from 1 buffer to the other at every merge level
    swap1 = new kv_pair<key, value>[new_num_elements];
    swap2 = new kv_pair<key, value>[new_num_elements];
    DEBUGPRINTF("[%d] loadIndex = %d/%d\n", this->thisIndex, loadIndex, new_num_elements);
    oddMessage = msg;
  }
  else {
    num_Loaded++;
    int div;
    ///do a tree merge
    for (div = 1; num_Loaded%((int)pow(2,div)) == 0; div++){  
      if (div % 2 == 0)
	merge_next(swap2);
      else 
	merge_next(swap1);

      if (div == 1){
	delete msg;
	delete oddMessage;
      }
    }
    //if we did not do any merging save this message (need to delete it later)
    if (div == 1){
      oddMessage = msg;
    }
    if (loadIndex == new_num_elements ){
#if 1
      //dumb completion using NULL for rest of tree
      if(lastMerged.size() > 1){
        int curLoaded = num_Loaded + 1;
        int nextPow2 = 1;
        while(curLoaded > nextPow2) {
          nextPow2 *= 2;
        }
        int lastSize = lastArraySizes.back();
        for(; curLoaded <= nextPow2; curLoaded++) {
          lastMerged.push_back(NULL);
          lastArraySizes.push_back(lastSize);
          int div;
          ///do a tree merge
          for (div = 1; curLoaded%((int)pow(2,div)) == 0; div++){  
            if (div % 2 == 0)
              merge_next(swap2);
            else 
              merge_next(swap1);
          }
        }
        if (div == 1){
	  delete oddMessage;
        }
      }
#else
      while(lastMerged.size() > 1){
	if (div % 2 == 0)
	  merge_next(swap2);
	else 
	  merge_next(swap1);
	if (div == 1)
	  delete oddMessage;
	div++;
      }
#endif
    }
  }
  //merge the left over arrays since we got all of our data
  if (loadIndex == new_num_elements ){
    mergedData = lastMerged[0];
    ///we are done merging
    #ifdef VERBOSE
    this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), SorterProxy));
    #endif

    //return data to user through the given callback
    if(isCallbackSet) {
      data_msg<key, value> *msg_to_return = new (new_num_elements) data_msg<key, value>;
      msg_to_return->num_vals = new_num_elements;
      memcpy(msg_to_return->pairs, mergedData, new_num_elements*sizeof(kv_pair<key,value>));
      myCallback.send(msg_to_return);
    } else {
      *out_elems = new_num_elements;
      if(num_Loaded == 1) {
        *dataOut = (void*)(new kv_pair<key, value>[new_num_elements]);
        memcpy(*dataOut, mergedData, new_num_elements*sizeof(kv_pair<key,value>));
      } else {
        *dataOut = mergedData;
      }
#if VERBOSE
      double sum = 0; int keysum = 0;
      for(int i = 0; i < new_num_elements; i++) {
        keysum += (int)(mergedData[i].myKey % 100);
        double *ptr = (double*)(mergedData[i].myVal.second);
        for(int j = 0; j < 2; j++) {
          sum += *ptr;
          ptr++;
        }
      }   
      this->contribute(sizeof(double), &sum, CkReduction::sum_double,
          CkCallback(CkIndex_Main<key, value>::final_dsum(NULL),mainProxy));
      this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
          CkCallback(CkIndex_Main<key, value>::final_isum(NULL),mainProxy));

      //printf("%d ** KeySum %lu Sum %lf\n",2,keysum, sum);
#endif
      this->contribute(CkCallback(CkIndex_Main<key, value>::Exit(), mainProxy));
    }

    while (sendBuffer.size() > numsent_buffer){
      buffered_msg<key, value>* msg_to_send = sendBuffer[(numsent_buffer + this->thisIndex)%sendBuffer.size()];
      myProxy[msg_to_send->chare_dest].Load(msg_to_send->msg);
      delete msg_to_send;
      numsent_buffer++;
    }

    #ifdef DEBUG
    CkPrintf("[%d] trying to return data through callback\n", this->thisIndex);
    //Sanity Check 
    CkPrintf("Performing sanity check...\n");
    for (int i = 1; i < new_num_elements; i++){
      if (mergedData[i] < mergedData[i-1]){
	printf("[%d] Sanity check failled on element %d\n", this->thisIndex, i);
	CkAssert(false);
      }
    }
    key *sanity_array = new key[num_buckets*2];
    std::fill(sanity_array, sanity_array+(num_buckets*2), key_min);
    contribute(num_buckets*2*sizeof(key), sanity_array, CkReduction::sum_int, CkCallback(CkIndex_Sorter<key, value>::SanityCheck(NULL), SorterProxy));
    #endif
    //delete the buffers, the data has been returned to its rightful owner
    if(num_Loaded == 1 && oddMessage != NULL)
      delete oddMessage;
    if(isCallbackSet || mergedData != swap1)
      delete [] swap1;
    if(isCallbackSet || mergedData != swap2)
    delete [] swap2;
    sendBuffer.clear();
    lastMerged.clear();
    lastArraySizes.clear();
    Reset();
  }
}

//merge the next two arrays in the buffer
template <class key, class value>
void Bucket<key, value>::merge_next(kv_pair<key, value> *swapData){
  //get the offsets two arrays to merge
  kv_pair<key, value> *firstData = lastMerged.back();
  lastMerged.pop_back();
  int first_size = lastArraySizes.back();
  lastArraySizes.pop_back();
  
  kv_pair<key, value> *secondData = lastMerged.back();
  lastMerged.pop_back();
  int second_size = lastArraySizes.back();
  lastArraySizes.pop_back();
  
  //get the offset in the buffer of the two arrays
  int offset;
  if (lastArraySizes.size() > 0)
    offset = lastArraySizes[lastArraySizes.size()-1];
  else
    offset = 0;

  //merge 'em
  std::merge(secondData, secondData + (second_size-offset), firstData, firstData + (first_size-second_size), swapData+offset);
  //if that data was in a message we need to delete the message
  lastMerged.push_back(swapData+offset);
  lastArraySizes.push_back(first_size);

}


///gets a sample median simply by picking out a sample from an array and sorting it
///should really use an algorithm for finding the median, though stl sort should be blazing fast for a reasonably small sample size
template <class key, class value>
key Bucket<key, value>::getSampleMedian(int min, int max, int len){
  int step, i;
  //len = (max-min)/step;
  step = (max-min)/len;
  key arr[len];
  for (i = 0; i < len; i++){
    arr[i] = bucket_data[min+step*i].myKey;
  }
  std::sort(arr, arr+len);
  return arr[len/2];
}
