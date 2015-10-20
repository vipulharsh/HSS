#include <cstring>


extern CkReduction::reducerType sum_uint64_t_type; 


template <class key, class value>
Bucket<key, value>::Bucket(CkMigrateMessage *){}


///initialize Bucket (create data)
template <class key, class value>
Bucket<key, value>::Bucket(key min, key max){
  //CkPrintf("Creating chare %d of bucket chare array\n", this->thisIndex);
  minkey = min;
  maxkey = max;
  lastProbe = new key[params->probe_max+1];
  scratch = new kv_pair<key, value>[params->probe_max+1];
  finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
  achieved = new bool[nBuckets+2];
  
  cumHist = new int[params->probe_max+1];
  histCounts = new int[params->probe_max+1];
  indices = new int[params->probe_max * indexFactor + 1];
  Reset();
}


//reset variables after sorting
template <class key, class value>
void Bucket<key, value>::Reset(){
	memset(achieved+1, false, nBuckets);
    achieved[0] = achieved[nBuckets] = true;
    finalSplitters[0] = minkey;    
    finalSplitters[nBuckets] = maxkey;
    achievedSplitters = 2;
}






//set bucket data
template <class key, class value>
void Bucket<key, value>::SetData(){
  DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
  numElem = in_elems;
  //CkAssert(num_elements > 0);
  bucket_data = (kv_pair<key, value>*)dataIn;
  #if VERBOSE
  double sum = 0; int keysum = 0;
  for(int i = 0; i < numElem; i++) 
    keysum += (int)(bucket_data[i].k % 100);  
  this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
  CkCallback(CkIndex_Main<key, value>::init_isum(NULL),mainProxy));
  #endif
}




template <class key, class value>
void Bucket<key, value>::firstProbe(CProxy_Sorter<key, value> _sorter_proxy, key firstkey, key lastkey, int probeSize){
	sorter_proxy = _sorter_proxy;  
	lastProbeSize = probeSize;
	memset(histCounts, 0, probeSize);
	key step = (lastkey - firstkey)/(probeSize-1);
	for(int i=0; i<numElem; i++)
		histCounts[(bucket_data[i].k - firstkey)/step]++;
		
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < probeSize; i++)
		longhistCounts[i] = histCounts[i];
	CkReductionMsg* redmsg = CkReductionMsg::buildNew((probeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type);
	redmsg->setCallback(CkCallback(CkIndex_Sorter<key, value>::Histogram(NULL), sorter_proxy));
	this->contribute(redmsg);
	
	cumHist[0] = 0;
	for(int i=0; i<probeSize-1; i++){
		cumHist[i+1] = histCounts[i] + cumHist[i];
	}
	
	mymin = maxkey;
	mymax = minkey;
	for(int i=0; i<numElem; i++){
		if(bucket_data[i].k < mymin) mymin = bucket_data[i].k;
		if(mymax < bucket_data[i].k) mymax = bucket_data[i].k;
		int ind = (bucket_data[i].k - firstkey)/step;
		scratch[cumHist[ind]] = bucket_data[i];
		cumHist[ind]++;
	}
	//swap scratch & bucket_data
	kv_pair<key, value> * temp = scratch;
	scratch = bucket_data;
	bucket_data = temp;
	//stepsort?
}



template <class key, class value>
void Bucket<key, value>::firstLocalProbe(int _lastProbeSize){
	memcpy(lastProbe, finalSplitters, nBuckets * sizeof(key));
	CkAssert(_lastProbeSize == nBuckets);
	lastProbeSize = _lastProbeSize;
	mymin = maxkey;
	mymax = minkey;
	for(int i=0; i<numElem; i++){
		if(bucket_data[i].k < mymin) mymin = bucket_data[i].k;
		if(mymax < bucket_data[i].k) mymax = bucket_data[i].k;
	}	
	localProbe();
}




template <class key, class value>
void Bucket<key, value>::localProbe(){
	
	//buildIndex
	int numIndices = indexFactor * lastProbeSize + 1;
	key indexStep = (mymax - mymin) / (numIndices-1);	
	int prb = 0;
	indices[0] = 0;
	for(int ind=0; ind<numIndices-1; ind++){	
		int a = (int) (lastProbe[prb] - mymin)/indexStep;
		while(a <= ind){
			prb++;
			a = (int) (lastProbe[prb] - mymin)/indexStep;
		}
		indices[ind+1] = prb;		
	}
		
	memset(histCounts, 0, lastProbeSize);
	for(int i=0; i<numElem; i++){
		int ind = indices[(bucket_data[i].k - mymin)/indexStep];
		while(lastProbe[ind] < bucket_data[i].k)
			ind++;
		histCounts[ind]++;	
	}
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < lastProbeSize; i++)
		longhistCounts[i] = histCounts[i];
	CkReductionMsg* redmsg = CkReductionMsg::buildNew((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type);
	redmsg->setCallback(CkCallback(CkIndex_Sorter<key, value>::Histogram(NULL), sorter_proxy));
	this->contribute(redmsg);
	
	
	cumHist[0] = 0;
	for(int i=0; i<lastProbeSize-1; i++){
		cumHist[i+1] = histCounts[i] + cumHist[i];
	}	
	for(int i=0; i<numElem; i++){
		int ind = indices[(bucket_data[i].k - mymin)/indexStep];
		while(lastProbe[ind] < bucket_data[i].k)
			ind++;
		scratch[cumHist[ind]] = bucket_data[i];
		cumHist[ind]++;
	}
	//swap scratch & bucket_data
	kv_pair<key, value> * temp = scratch;
	scratch = bucket_data;
	bucket_data = temp;
	//stepsort?
}

template <class key, class value>
void Bucket<key, value>::histCountProbes(probeMessage<key> *pm){
	memcpy(lastProbe, pm->probe, nBuckets * sizeof(key));
	lastProbeSize = pm->probeSize;
	if(lastProbeSize > 0)
		localProbe();
	else
		CkPrintf("Splitters have been determined - %d \n", CkMyPe());
}






