#include <cstring>


extern CkReduction::reducerType sum_uint64_t_type; 
extern CkReduction::reducerType minmax_uint64_t_type; 


template <class key, class value>
Bucket<key, value>::Bucket(CkMigrateMessage *msg){}


///initialize Bucket (create data)
template <class key, class value>
Bucket<key, value>::Bucket(tuning_params par, key min, key max, int nuBuckets_):
	minkey(min), maxkey(max), nBuckets(nuBuckets_){
  CkPrintf("Creating chare %d of bucket chare array\n", this->thisIndex);
  params = new tuning_params;
  *params = par;
  lastProbe = new key[params->probe_max+1];
  finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
  achieved = new bool[nBuckets+2];
  
  cumHist = new int[params->probe_max+1];
  histCounts = new int[params->probe_max +1];
  longhistCounts = new uint64_t[params->probe_max +1];
  
  indices = new int[params->probe_max * indexFactor + 1];
  Reset();
}


//reset variables after sorting
template <class key, class value>
void Bucket<key, value>::Reset(){
	memset(achieved+1, false, nBuckets);
    achieved[0] = achieved[nBuckets] = true;
    //check the validity of this
    numProbes = 0;
    finalSplitters[0] = minkey;    
    finalSplitters[nBuckets] = maxkey;
    achievedSplitters = 2;
}






//set bucket data
template <class key, class value>
void Bucket<key, value>::SetData(CProxy_Sorter<key, value> _sorter_proxy){
  DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
  numElem = in_elems;
  sorter_proxy = _sorter_proxy;
  //CkAssert(num_elements > 0);
  bucket_data = (kv_pair<key, value>*)dataIn;
  //!delete this later
  scratch = new kv_pair<key, value>[numElem+1];

  mymin = mymax = bucket_data[0].k;
  for(int i=1; i<numElem; i++){
  	mymin = std::min(mymin, bucket_data[i].k);
  	mymax = std::max(mymax, bucket_data[i].k);
  }

  //ckout<<mymin<<" minmax "<<mymax<<" - "<<CkMyPe()<<endl;
  key minmax[2] = {mymin, mymax};
  //needs to be changed to key
  this->contribute(2*sizeof(uint64_t), minmax, minmax_uint64_t_type, 
  	CkCallback(CkIndex_Sorter<key,value>::globalMinMax(NULL), sorter_proxy)); 
  
  #if VERBOSE
  double sum = 0; int keysum = 0;
  for(int i = 0; i < numElem; i++) 
    keysum += (int)(bucket_data[i].k % 100);  
  this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
  CkCallback(CkIndex_Main<key, value>::init_isum(NULL),mainProxy));
  #endif
}




template <class key, class value>
void Bucket<key, value>::firstProbe(key firstkey, key lastkey, int probeSize){
	lastProbeSize = probeSize;	
	memset(histCounts, 0, probeSize*sizeof(int));	
	key step = (lastkey - firstkey + probeSize-1)/(probeSize);
	
	//ckout<<step<<" "<<lastkey<<" "<<firstkey<<" "<<probeSize<<" "<<numElem<<" "<<CkMyPe()<<endl;	
	for(int i=0; i<numElem; i++)
		histCounts[(bucket_data[i].k - firstkey)/step]++;		
	
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	//ckout<<"Probe Size : "<<probeSize<<endl;
	for (int i = 0; i < probeSize; i++)
		longhistCounts[i] = histCounts[i];

	this->contribute((probeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	
	cumHist[0] = 0;	
	for(int i=0; i<probeSize; i++){
		cumHist[i+1] = histCounts[i] + cumHist[i];
		//ckout<<" >> "<<cumHist[i+1]<<endl;
	}
	
	for(int i=0; i<numElem; i++){
		//ckout<<bucket_data[i].k<<endl;
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
	localProbe();
}




template <class key, class value>
void Bucket<key, value>::localProbe(){
	//buildIndex
	//if(CkMyPe()==2)
	//	ckout<<"Inside Local Probe "<<numProbes<<" "<<CkMyPe()<<endl;
	//double c1 = CmiWallTimer();
	int numIndices = indexFactor * lastProbeSize;
	key indexStep = std::max((mymax - mymin + numIndices) / numIndices, (key)1);	
	int prb = 0;
	//ckout<<" lastProbeSize "<<endl;
	//if(CkMyPe()==2 && numProbes==15){
	//	ckout<<"Bucket Info "<< indexStep<<" : "<<mymax<<" : "<<mymin<<" : "<<numIndices<<" "<<CkMyPe()<<endl;
	//}
	for(int ind=0; ind<numIndices; ind++){	
		//Something needs to be done about long long
		while(((long long) (lastProbe[prb] - mymin)/indexStep) < ind)
			prb++;
		indices[ind] = prb;
	}


	//if(CkMyPe()==2 && numProbes==15){
	//	ckout<<"lastProbeSize:  "<<lastProbeSize;
	//	ckout<<" Step:  "<<indexStep<<" : "<<"Indices built :"<<numIndices<<" : "<<CkMyPe()<<endl;
	//		for(int i=0; i<numIndices; i++)
	//			ckout<<" : "<<indices[i]<<endl;
	//	for(int i=0; i<lastProbeSize; i++)
	//		ckout<<lastProbe[i]<<" {}{}{}{}{}{} "<<CkMyPe()<<endl;
	//}
	
	
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

	this->contribute((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	
	cumHist[0] = 0;
	for(int i=0; i<lastProbeSize-1; i++){
		cumHist[i+1] = histCounts[i] + cumHist[i];
	}	

	//if(numProbes == 15)
	//	return;
//	if(CkMyPe() == 2 && numProbes==15)
//		ckout<<" LPS "<<lastProbeSize<<endl;
	int maxcount = 0, avgCount = 0;
	for(int i=0; i<numElem; i++){
		//if(CkMyPe() == 2 && numProbes==15)
		//	ckout<<" LPS "<<bucket_data[i].k<<" ";
		int ind = indices[(bucket_data[i].k - mymin)/indexStep];		
		//if(CkMyPe() == 2 && numProbes==15)
		//	ckout<<ind<<" "<<indexStep<<" "<<(bucket_data[i].k - mymin)<<" "<<(bucket_data[i].k - mymin)/indexStep<<endl;
		int count = 1;
		while(lastProbe[ind] < bucket_data[i].k){
			ind++;		
			count++;
		}
		maxcount = std::max(count, maxcount);
		avgCount += count;
		scratch[cumHist[ind]] = bucket_data[i];
		cumHist[ind]++;
	}
	//ckout<<"Max Latency: "<<maxcount<<" "<<"Avg Latency :"<<(double)avgCount/numElem<<endl;
	//if(numProbes == 15)
	//	return;
	
	//swap scratch & bucket_data
	kv_pair<key, value> * temp = scratch;
	scratch = bucket_data;
	bucket_data = temp;

	//double c2 = CmiWallTimer();
	//ckout<<"It: "<<numProbes<<" "<<c2-c1<<" - "<<CkMyPe()<<endl;
	//if(CkMyPe()==2)
	//	ckout<<"Exiting Local Probe   "<<lastProbeSize<<" "<<CkMyPe()<<endl;	
	//stepsort?
}

template <class key, class value>
void Bucket<key, value>::histCountProbes(probeMessage<key> *pm){
	numProbes++;
	//if(CkMyPe() == 2)
	//	ckout<<"Inside histCountProbes "<<numProbes<<endl;

	lastProbeSize = pm->probeSize;
	//if(CkMyPe() == 2)
	//	ckout<<"00****** "<<lastProbeSize<<" "<<CkMyPe()<<endl;

	memcpy(lastProbe, pm->probe, lastProbeSize * sizeof(key));
	//!should be lastProbeSize > 1
	if(lastProbeSize > 1){
		localProbe();
	}
	else{
		ckout<<"Splitters have been determined  - "<<CkMyPe()<<endl;
		this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), sorter_proxy));
	}
	delete(pm);
}



template <class key, class value>
void Bucket<key, value>::checkMemoryCorruption(){}







