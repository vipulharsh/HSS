#include <cstring>


extern CkReduction::reducerType sum_uint64_t_type; 


template <class key, class value>
Bucket<key, value>::Bucket(CkMigrateMessage *msg){}


///initialize Bucket (create data)
template <class key, class value>
Bucket<key, value>::Bucket(tuning_params par, key min, key max, int nuBuckets_):
	minkey(min), maxkey(max), nBuckets(nuBuckets_){
  CkPrintf("Creating chare %d of bucket chare array\n", this->thisIndex);
  params = new tuning_params;
  *params = par;
  lastProbe = new key[params->temp_probe_max+1];
  finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
  achieved = new bool[nBuckets+2];
  
  cumHist = new int[params->temp_probe_max+1];
  histCounts = new int[params->temp_probe_max +1];
  longhistCounts = new uint64_t[params->temp_probe_max +1];
  
  indices = new int[params->temp_probe_max * indexFactor + 1];
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
  //!delete this later
  scratch = new kv_pair<key, value>[numElem+1];
  
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
	memset(histCounts, 0, probeSize*sizeof(int));	
	key step = (lastkey - firstkey + probeSize-1)/(probeSize);
	
	//ckout<<step<<" "<<lastkey<<" "<<firstkey<<" "<<probeSize<<" "<<numElem<<" "<<CkMyPe()<<endl;
	
	for(int i=0; i<numElem; i++)
		histCounts[(bucket_data[i].k - firstkey)/step]++;		
	
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	//ckout<<"Probe Size : "<<probeSize<<endl;
	for (int i = 0; i < probeSize; i++){
		longhistCounts[i] = histCounts[i];
	}

	
	//!ckout<<"Sending "<<probeSize<<" histcounts, bytes : "<<(probeSize)*sizeof(uint64_t)<<endl;
	//!this->contribute((probeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
	//!	CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	this->contribute((probeSize)*sizeof(int), histCounts, CkReduction::sum_int, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	
	cumHist[0] = 0;
	
	ckout<<probeSize<<endl;
	for(int i=0; i<probeSize; i++){
		cumHist[i+1] = histCounts[i] + cumHist[i];
		//ckout<<" >> "<<cumHist[i+1]<<endl;
	}
	
	mymin = maxkey;
	mymax = minkey;
	

	for(int i=0; i<numElem; i++){
		//ckout<<bucket_data[i].k<<endl;
		if(bucket_data[i].k < mymin) mymin = bucket_data[i].k;
		if(mymax < bucket_data[i].k) mymax = bucket_data[i].k;
		int ind = (bucket_data[i].k - firstkey)/step;
		//ckout<<bucket_data[i].k<<" : "<<ind<<" : "<<cumHist[ind]<<endl;
		scratch[cumHist[ind]] = bucket_data[i];
		cumHist[ind]++;
	}
	//swap scratch & bucket_data
	kv_pair<key, value> * temp = scratch;
	scratch = bucket_data;
	bucket_data = temp;

	//for(int i=0; i<numElem; i++)
	//	ckout<<bucket_data[i].k<<endl;

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
	int numIndices = indexFactor * lastProbeSize;
	key indexStep = (mymax - mymin + numIndices - 1) / numIndices;	
	int prb = 0;
	//ckout<<"Bucket Info "<< indexStep<<" : "<<mymax<<" : "<<mymin<<" : "<<numIndices<<" "<<CkMyPe()<<endl;
	for(int ind=0; ind<numIndices; ind++){	
		//Something needs to be done about long long
		while(((long long) (lastProbe[prb] - mymin)/indexStep) < ind){
			prb++;
		}
		indices[ind] = prb;
	}
	//ckout<<" Step:  "<<indexStep<<" : "<<"Indices built :"<<numIndices<<" : "<<CkMyPe()<<endl;
	//	for(int i=0; i<numIndices; i++)
	//		ckout<<" : "<<indices[i]<<endl;

	//for(int i=0; i<lastProbeSize; i++)
	//	ckout<<lastProbe[i]<<" {}{}{}{}{}{} "<<CkMyPe()<<endl;
	
	
	memset(histCounts, 0, lastProbeSize * sizeof(int));
	
	for(int i=0; i<numElem; i++){
		int ind = indices[(bucket_data[i].k - mymin)/indexStep];
		while(lastProbe[ind] < bucket_data[i].k)
			ind++;
		histCounts[ind]++;
		//ckout<<histCounts[ind]<<endl;	
	}

	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < lastProbeSize; i++)
		longhistCounts[i] = histCounts[i];
	//CkReductionMsg* redmsg = CkReductionMsg::buildNew((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type);
	//redmsg->setCallback(CkCallback(CkIndex_Sorter<key, value>::Histogram(NULL), sorter_proxy));
	//this->contribute(redmsg);
	
	this->contribute((lastProbeSize)*sizeof(int), histCounts, CkReduction::sum_int, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));

	cumHist[0] = 0;
	for(int i=0; i<lastProbeSize-1; i++){
		cumHist[i+1] = histCounts[i] + cumHist[i];
	}	
	
	//ckout<<"Done 2 "<<CkMyPe()<<endl;
	for(int i=0; i<numElem; i++){
		int ind = indices[(bucket_data[i].k - mymin)/indexStep];
		//if(CkMyPe() == 1 && i>660 && i<665)
		//	ckout<<"Done 3 "<<i<<" : "<<ind<<" : "<<CkMyPe()<<endl;
		
		while(lastProbe[ind] < bucket_data[i].k)
			ind++;
		
		//if(CkMyPe() == 1 && i>660 && i<665)
		//	ckout<<"Done 3.5 "<<i<<" : "<<ind<<" : "<<CkMyPe()<<" : "<<cumHist[ind]<<endl;

		scratch[cumHist[ind]] = bucket_data[i];
		cumHist[ind]++;
		//if(CkMyPe() == 1 && i>660 && i<665)
		//	ckout<<"Done 4 "<<i<<" : "<<ind<<" : "<<CkMyPe()<<endl;
	}
	
	//swap scratch & bucket_data
	kv_pair<key, value> * temp = scratch;
	scratch = bucket_data;
	bucket_data = temp;
	//stepsort?
}

template <class key, class value>
void Bucket<key, value>::histCountProbes(probeMessage<key> *pm){
	lastProbeSize = pm->probeSize;
	memcpy(lastProbe, pm->probe, lastProbeSize * sizeof(key));
	//ckout<<pm->probe[0]<<" Ayein? "<<lastProbe[0]<<endl;
	//!should be lastProbeSize > 1
	if(lastProbeSize > 1){
		localProbe();
	}
	else{
		ckout<<"Splitters have been determined  - "<<CkMyPe()<<endl;
	}
	delete(pm);
}






