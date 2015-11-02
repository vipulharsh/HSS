/*global*/ CkReduction::reducerType sum_uint64_t_type; 

///reduction for summing arrays of unsigned 64-bit integers
CkReductionMsg *sum_uint64_t(int nMsg,CkReductionMsg **msgs)
{
  ///Sum starts off at zero 
  ckout<<"*********Sum starts off at zero "<<endl;
  int size = msgs[0]->getSize()/sizeof(uint64_t);
  uint64_t ret[size];
  memset(ret, 0, sizeof(uint64_t)*size);
  uint64_t *m;
  for (int i=0;i<nMsg;i++) {
    m=(uint64_t *)msgs[i]->getData();
    for (int j = 0; j <size;j ++) 
      ret[j]+=m[j];
  }
  return CkReductionMsg::buildNew(size*sizeof(uint64_t),ret);
} 


/*initcall*/ void register_sum_uint64_t(void){
  sum_uint64_t_type = CkReduction::addReducer(sum_uint64_t);
} 

template <class key, class value>
Sorter<key, value>::Sorter(CkMigrateMessage *msg){}

/* Arguments:
 * 1: log_2 of total data size
 * 2: Degrees of Entropy (number of ANDS) i.e. 0 means uniform, 3 implies every key is defined as rand() & rand () & rand() & rand()
 * 3: Number of "buckets" (number of chares)
 * 4: Size of Probe (must be smaller or equal to the number of buckets, would not make much sense for it to be bigger given large numprocs)
 * 5: Threshold Percentage (number of keys in every bucket must be within this threshold percentage of the average)
 * 6: Number of levels in Tree Merge (log_2(num buckets) would be full tree merge, which is probably most efficient)
 * 7: Number of communication steps (given 4 comm steps, and 12 determined splitters, each non-receiving processor will send three pieces of its data)
 * 8: Threshold of keys below which we apply sorting instead of splitting 
 * 	(sequential optimization ~1000 works well usually, should depend on cache, but also data size, num processors, and distribution)
 * 9: Size of sample for determining median for quicksort style splitting (default is 21, suggested range: (3, 31))
 * 10: Minimum number of guesses within a range
 *
 * arguments 3-10 could potentially be autotuned
 *
 */

template <class key, class value>
Sorter<key, value>::Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max){
  VERBOSEPRINTF("Setting up histogram sort.\n");
  tuning_params *default_pars = new tuning_params();
  default_pars->probe_size = num_chares - 1;
  default_pars->probe_max = 64;
  default_pars->hist_thresh = 5;
  default_pars->splice_thresh = 1024;
  default_pars->eager_send = num_chares;
  /*if (num_chares <= 256)
  else
    default_pars->eager_send = num_chares/8;*/
  default_pars->reuse_probe_results = false;
  init(bucketArr, num_chares, min, max, default_pars);
}


template <class key, class value>
Sorter<key, value>::Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max, tuning_params par){
  init(bucketArr, num_chares, min, max, &par);
}

//this function initializes variables
template <class key, class value>
void Sorter<key, value>::init(const CkArrayID &bucketArr, int num_chares, key min, key max, tuning_params *par){
  VERBOSEPRINTF("Beginning histogram sort.\n");
  num_buckets = num_chares;
  params = par;
  CkAssert(!params->reuse_probe_results || params->probe_size == num_chares - 1); 
  min_key = min;
  max_key = max;
  first_use = true;
  
  splitters = new charm_splitter<key>[num_buckets-1];
  myProxy = this->thisProxy;
  buckets = bucketArr;
}

//set up initial probe (evenly spaced guesses in data range)
//also assign new params
template <class key, class value>
void Sorter<key, value>::Begin(tuning_params par){
  *params = par;
  Begin();
}

//set up initial probe (evenly spaced guesses in data range)
template <class key, class value>
void Sorter<key, value>::Begin(){
  //set up splitters and some variables
  num_steps = 0;
  num_total_keys = 0;
  num_achv = 0;

  first_probe<key, value> *initial_probe = new (params->probe_size) first_probe<key, value>;
  last_probe = new key[params->probe_size];  
  initial_probe->num_keys = params->probe_size;

  key hop = (max_key - min_key)/(params->probe_size+1);
  if (params->reuse_probe_results && !first_use){ //set the probe to what the splitters converged to last time
    for (int i = 0; i < params->probe_size; i++){
      initial_probe->splitter_guesses[i] = splitters[i].lowerb_key;
      DEBUGPRINTF("initial probe[%d] = %llu\n", i, initial_probe->splitter_guesses[i]);
    }
  } else{ //initial probe divides the range into even chunks
    key offset = min_key;
    for (int i = 0; i < params->probe_size; i++){
      offset += hop;
      initial_probe->splitter_guesses[i] = offset;
      DEBUGPRINTF("initial probe[%d] = %llu\n", i, initial_probe->splitter_guesses[i]);
    }
  }
  
  for (int i = 0; i < num_buckets-1; i++){
    splitters[i].lowerb_count = 0;
    splitters[i].upperb_count = -1;
    splitters[i].lowerb_key = min_key;
    splitters[i].upperb_key = max_key;
    splitters[i].goal = -1; //need to know total number of keys to determine this
    splitters[i].achieved = false;
    splitters[i].broadcasted = false;
  }


  memcpy(last_probe, initial_probe->splitter_guesses, params->probe_size*sizeof(key));

  //send some execution parameters to buckets
  initial_probe->splice_thresh = params->splice_thresh;
  initial_probe->eager_send = params->eager_send;
  initial_probe->num_buckets = num_buckets;
  memcpy(&(initial_probe->params), params, sizeof(tuning_params));
  initial_probe->sorter_proxy =	myProxy;
  
  c1 = CmiWallTimer();
  VERBOSEPRINTF("Beginning probing.\n");
  buckets.CountFirstProbe(initial_probe);
}


//this function cannot be split up efficienctly, because it uses a lot of local variables and needs to do some complex work.
//It takes in the combined Histogram and adjusts the splitters according to it.
template <class key, class value>
void Sorter<key, value>::Histogram(CkReductionMsg *msg){
  VERBOSEPRINTF("Doing Histogramming %lf seconds after start.\n", (CmiWallTimer()-c1));
  num_steps++;
  ckout<<"Histogramming "<<endl;
  uint64_t* hist_counts = (uint64_t*)msg->getData();
  int lenhist = (int)msg->getSize()/sizeof(uint64_t);

  ///do prefix sum on counts (is this necessarily the fastest way?)
  #ifdef DEBUG
  DEBUGPRINTF("count [%d] = %llu\n", 0, hist_counts[0]);
  for (int i = 1; i < lenhist; i++){
    DEBUGPRINTF("count [%d] = %llu\n", i, hist_counts[i]);
  }
  #endif

  ///if first step, initialize total length and splitter goals
  if (num_steps == 1){
    num_total_keys = hist_counts[lenhist-1];
    uint64_t hop = num_total_keys/num_buckets;
    margin_error = (hop*params->hist_thresh)/100;
    if(margin_error < 5) margin_error = 5;
    uint64_t offset = 0;
    for (int i = 0; i < num_buckets - 1; i++){
      offset += hop;
      splitters[i].goal = offset;
      splitters[i].upperb_count = num_total_keys;
    }
  }

  int idxExp = 0;
  int idxReal = 0;
  int splitterCount = 0;
  key histval;
  bool borderChanged;
  int justachv = 0;

  std::vector< charm_splitter<key>* > active_splitters;
  std::vector<int> toBroadcast; 
  uint64_t sumhist = hist_counts[0];
  uint64_t diffval;
  //CkPrintf("lenhist is %d\n",lenhist);
  ///logic for determining which splitters have been achieved and bounding the rest by the closest counts and splitter-guesses
  ///this code needs at least some comments or something
  enrollRange.clear();
  maxRange.clear();
  while (idxReal < num_buckets-1){
    if (splitters[idxReal].achieved){ //if this splitter has been determined
      if (!splitters[idxReal].broadcasted && (idxReal == 0 || splitters[idxReal-1].achieved)){ //if previous splitter has now been determined, broadcast this range
	     toBroadcast.push_back(idxReal);
	     splitters[idxReal].broadcasted = true;
      } 
      //don't need to analyze determined splitter, so move on
      idxReal++;
      continue;
    }
    if(num_steps != 1) {
      while(idxExp < lenhist-1 && idxReal > maxRange[idxExp]) {
        idxExp++;
      }
    }
    //figure out the current count and current guess from last probe
    if (idxExp >= lenhist-1){
      if (idxExp >= lenhist) sumhist = num_total_keys;
      else sumhist =  hist_counts[idxExp];
      histval = max_key;
      //printf("BEYOND %llu->%llu %llu %d\n",sumhist, splitters[idxReal].goal,histval,idxExp);
    }
    else {
      sumhist = hist_counts[idxExp];
      histval = last_probe[idxExp];
      //printf("%llu->%llu %llu %d\n",sumhist, splitters[idxReal].goal,histval,idxExp);
    }

    //find how far the current splitter is from the guess
    if (sumhist > splitters[idxReal].goal)
      diffval = sumhist - splitters[idxReal].goal;
    else
      diffval = splitters[idxReal].goal - sumhist;

    if (diffval < margin_error){ //if we achieved the splitter within the threshold 
      //cement the key and the count
      //printf("[%d] Found spliter for bucket %d, %llu, %d\n",CkMyPe(), sumhist, histval, diffval);
      splitters[idxReal].upperb_key = histval;
      splitters[idxReal].lowerb_key = histval;
      splitters[idxReal].achieved = true;
      justachv++;
      splitters[idxReal].upperb_count = sumhist;
      splitters[idxReal].lowerb_count = sumhist;
      //CkPrintf("Set LOWER/UPPER %d %lld\n",idxReal, splitters[idxReal].lowerb_key);

      //broadcast the range if the previous one has been achieved also
      if (idxReal == 0 || splitters[idxReal-1].achieved){
	     toBroadcast.push_back(idxReal);
	     splitters[idxReal].broadcasted = true;
      } 
      if (idxReal == num_buckets-2){ //if this is the last splitter broadcast the last range as well
	     toBroadcast.push_back(num_buckets-1);
      }
      idxExp++;
      idxReal++;
    } 

    else if (splitters[idxReal].goal < sumhist){ //if we did not hit the splitter within the threshold
      borderChanged = false;        
      //check if this guess produced better bounds and update the bounds
      
      if (idxExp > 0){
	     if (hist_counts[idxExp-1] > splitters[idxReal].lowerb_count || (hist_counts[idxExp-1] == splitters[idxReal].lowerb_count && last_probe[idxExp-1] > splitters[idxReal].lowerb_key)){
	       borderChanged = true;
	       splitters[idxReal].lowerb_count = hist_counts[idxExp-1];
	       splitters[idxReal].lowerb_key = last_probe[idxExp-1];
          //CkPrintf("Set LOWER %d %llu\n",idxReal, splitters[idxReal].lowerb_key);
	     }
      }
      if ((sumhist < splitters[idxReal].upperb_count) || (sumhist == splitters[idxReal].upperb_count && histval < splitters[idxReal].upperb_key)){
	     borderChanged = true;
	     splitters[idxReal].upperb_count = sumhist;
	     splitters[idxReal].upperb_key = histval;
        //CkPrintf("Set UPPER %d %llu %llu\n",idxReal, splitters[idxReal].upperb_key,histval);
      }
      //if the bounds did not tighten, ideally, this should never happen
      if (!borderChanged){ 
	#ifdef VERBOSE
	if (lenhist >= num_buckets) CkPrintf("borderChanged should never be false %d %d %llu %llu %llu %llu %llu!!!\n", 
	   idxExp, idxReal, splitters[idxReal].goal, sumhist-hist_counts[idxExp-1], sumhist,
	   splitters[idxReal].lowerb_count,  splitters[idxReal].upperb_count);
	CkPrintf("The distributions is probably too dense to handle the given margin of error\n");
	#endif
	//if there was some guess and it did not tighten bounds
	if ((params->probe_size - num_achv) < num_buckets){ 
	  //just declare the splitter converged, currently we cannot do any better
	  splitters[idxReal].achieved = true;
	  if (splitters[idxReal].goal - splitters[idxReal].lowerb_count <= splitters[idxReal].upperb_count - splitters[idxReal].goal){ 
	    splitters[idxReal].upperb_key = splitters[idxReal].lowerb_key;
	    splitters[idxReal].upperb_count = splitters[idxReal].lowerb_count;
	  }
	  else {
	    splitters[idxReal].lowerb_key = splitters[idxReal].upperb_key;
	    splitters[idxReal].lowerb_count = splitters[idxReal].upperb_count;
	  }
	  if (idxReal == 0 || splitters[idxReal-1].achieved){
	    toBroadcast.push_back(idxReal);
	    splitters[idxReal].broadcasted = true;
	  } 
	  if (idxReal == num_buckets-2){
	    toBroadcast.push_back(num_buckets-1);
	  }
	  idxReal++;
    idxExp++;
	  continue;
	}
      }
      //continue to next splitter
      active_splitters.push_back(&splitters[idxReal]);
      enrollRange.push_back(idxReal);
      idxReal++;
    } else{
      idxExp++;
    }
  }
  num_achv += justachv;
  splitterCount = active_splitters.size();
  
  
  //if we have successfully not determined close enough values for all the splitters, define new probe
  next_probe<key> *new_probe;
  int num_guesses = 0;
  key *guesses;
  if (splitterCount > 0){
    guesses = get_splitter_guesses(&num_guesses, active_splitters);
    new_probe = new (num_guesses, toBroadcast.size()) next_probe<key>;
    VERBOSEPRINTF("num_guesses = %d\n", num_guesses);
    memcpy(new_probe->splitter_guesses, guesses, num_guesses*sizeof(key));
    /*for(int i = 0; i < num_guesses - 1; i++) {
      if(new_probe->splitter_guesses[i] > new_probe->splitter_guesses[i+1]) {
        CmiPrintf("Splitters out of order at %d/%d\n",i, num_guesses);
        CmiAbort("Splitters out of order\n");
      }
    }*/
  }
  else
    new_probe = new (num_guesses, toBroadcast.size()) next_probe<key>;

  new_probe->num_keys = num_guesses;
  new_probe->num_ranges = toBroadcast.size();

  ///send the resolved ranges
  for (int i = 0; i < toBroadcast.size(); i++){
    if (toBroadcast[i] == 0){
      new_probe->send_info[i].lowerb = min_key;
      new_probe->send_info[i].upperb = splitters[toBroadcast[i]].upperb_key;
      new_probe->send_info[i].total = splitters[0].upperb_count;
    } else if (toBroadcast[i] == num_buckets-1){
      new_probe->send_info[i].lowerb = splitters[toBroadcast[i]-1].upperb_key;
      new_probe->send_info[i].upperb = max_key;
      new_probe->send_info[i].total = num_total_keys - splitters[toBroadcast[i]-1].upperb_count;
    } else {
      new_probe->send_info[i].lowerb = splitters[toBroadcast[i]-1].upperb_key;
      new_probe->send_info[i].upperb = splitters[toBroadcast[i]].upperb_key;
      new_probe->send_info[i].total = splitters[toBroadcast[i]].upperb_count - splitters[toBroadcast[i]-1].upperb_count;
    }
    new_probe->send_info[i].chare_dest = toBroadcast[i];
    /*if(new_probe->send_info[i].total < 0) {
      CkPrintf("range %d (%llu, %llu) receiving %d elements\n", new_probe->send_info[i].chare_dest,
      new_probe->send_info[i].lowerb, new_probe->send_info[i].upperb, new_probe->send_info[i].total);
      CmiAbort("Aborting due to negative total\n");
    }*/
    DEBUGPRINTF("range %d (%llu, %llu) receiving %d elements\n", new_probe->send_info[i].chare_dest,
      new_probe->send_info[i].lowerb, new_probe->send_info[i].upperb, new_probe->send_info[i].total);
  }
  #ifdef DEBUG
  for (int i = 0; i < new_probe->num_keys; i++)
    CkPrintf("probe[%d] = %llu\n", i, new_probe->splitter_guesses[i]);
  #endif
  CkSetQueueing(new_probe, CK_QUEUEING_LIFO);
  if (splitterCount == 0){ //if all splitters have been converged to
    c2 = CmiWallTimer();    
    VERBOSEPRINTF("Done Histogramming in %lf seconds did %d iterations.\n", (c2-c1), num_steps);
    buckets.SendAll(new_probe);
    first_use = false;
  }
  else { //if we still need to convergeto some splitters
    VERBOSEPRINTF("Need to determine %d more splitters, broadcasting %d ranges.\n", splitterCount, toBroadcast.size());
    buckets.CountProbe(new_probe);
  }
  active_splitters.clear();
  toBroadcast.clear(); 

  delete [] last_probe;
  delete msg;
  if (splitterCount > 0){
    last_probe = guesses;
  }
}

//refines the probe
template <class key, class value>
key* Sorter<key, value>::get_splitter_guesses(int *ptr_num_guesses, std::vector< charm_splitter<key>* > active_splitters){
  int num_guesses;// = *ptr_num_guesses;
  int splitterCount = active_splitters.size();
  
  ///figure out how much oversplitting we can do
  int virtSent = params->probe_size;
  if (params->probe_size > splitterCount){
    int numVirt = params->probe_size / splitterCount;
    int extraVirt = params->probe_size % splitterCount;
    for (int i = 0; i < splitterCount; i++){
      if (i < extraVirt)
        active_splitters[i]->virt = numVirt+1;
      else
	active_splitters[i]->virt = numVirt;
    }
  }
  else {
    virtSent = splitterCount+1;
    for (int i = 0; i < splitterCount; i++){
      active_splitters[i]->virt = 1;
    }
  }

  ///define a new probe
  key *newsps = new key[params->probe_size];
  num_guesses = 0;
  int idx = 0;
  int divisors;
  key divjump = 0;
  int accvirt = 0;
  int firstidx = 0;
  int maxRank;
  ///Create guesses out of unresolved splitters
  //printf("START NEW SPLITTING\n");
  while (idx < splitterCount){
    //CkPrintf("NEW IDX ");
    maxRank = enrollRange[idx];
    if (accvirt == 0) {
      //CkPrintf("NEW ITER ");
      firstidx = idx;
    }
    accvirt += active_splitters[idx]->virt;
    //place multiple splitters guesses into ranges that bound multiple unresolved splitters
    if (idx == splitterCount-1 || active_splitters[idx]->upperb_key != active_splitters[idx+1]->upperb_key){
      divisors = std::min(params->probe_max, accvirt);
      if (divisors > 0)
	         divjump = (key)(active_splitters[idx]->upperb_key - active_splitters[idx]->lowerb_key)/(divisors+1);
      if (divjump == 0){
	divjump = 1;
      }
      ///we first figure out how many guesses to place in the range, now we place them
      for (int i = 0; i < divisors; i++) {
	if (divjump == 1 && (i+1)*divjump + active_splitters[idx]->lowerb_key > active_splitters[idx]->upperb_key)
	  newsps[num_guesses] = active_splitters[idx]->upperb_key;
	else
	  newsps[num_guesses] = (i+1)*divjump + active_splitters[idx]->lowerb_key;
	num_guesses++;
        maxRange.push_back(maxRank);
        //CkPrintf("%d %llu ",maxRank,newsps[num_guesses-1]);
      }
      accvirt = 0;
    }     
    idx++;
  }
  //CkPrintf("\n");
  *ptr_num_guesses = num_guesses;
  return newsps;
}

//Optionary reduction that informs the Sorter chare that sorting has completed
template <class key, class value>
void Sorter<key, value>::Done(CkReductionMsg *msg){
  c2 = CmiWallTimer();
  VERBOSEPRINTF("\nCompleted in %lf seconds.\n", (c2-c1));
}

//A sanity check that insures global sorted order
template <class key, class value>
void Sorter<key, value>::SanityCheck(CkReductionMsg *msg){
  DEBUGPRINTF("Doing global order sanity check.\n");
  key* borderkeys = (key*)msg->getData();
  int lenhist = (int)msg->getSize()/sizeof(key);
  for (int i = 1; i < lenhist; i++){
    CkAssert(borderkeys[i] >= borderkeys[i-1]);
  }
}

#include "HistSort.def.h"
