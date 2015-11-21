#include <cstring>
#include <algorithm>

extern CkReduction::reducerType sum_uint64_t_type; 
extern CkReduction::reducerType minmax_uint64_t_type; 

template <class key, class value>
Bucket<key, value>::Bucket(CkMigrateMessage *msg){}


//closest power of 2
std::pair<int, int> nextpow2(int n){
	int ret = 1, pow = 0;
	while(ret < n){
		ret *= 2;
		pow++;
	}
	return std::pair<int, int>(ret, pow);
}


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
  cumHist1 = new int[params->probe_max+1];

  histCounts = new int[params->probe_max +1];
  longhistCounts = new uint64_t[params->probe_max +1];
  
  std::pair<int, int> pp =  nextpow2(params->probe_max * indexFactor + 1);
  indices = new int[pp.first];
  
  numChunks = nBuckets;
  sepCounts = new int[numChunks+2];

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

    lastSortedChunk = 0;
    doneHists = false;
}






//set bucket data
template <class key, class value>
void Bucket<key, value>::SetData(CProxy_Sorter<key, value> _sorter_proxy){
  DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
  numElem = in_elems;
  sorter_proxy = _sorter_proxy;
  //CkAssert(num_elements > 0);
  bucket_data = (kv_pair<key, value>*)dataIn;

  mymin = mymax = bucket_data[0].k;
  
  double cc1 = CmiWallTimer();
  for(int i=1; i<numElem; i++){
  	mymin = std::min(mymin, bucket_data[i].k);
  	mymax = std::max(mymax, bucket_data[i].k);
  }
  ckout<<"Time for min max : "<<CmiWallTimer() - cc1<<" - "<<CkMyPe()<<endl;
  //ckout<<mymin<<" minmax "<<mymax<<" - "<<CkMyPe()<<endl;
  key minmax[2] = {mymin, mymax};
  //needs to be changed to key
  this->contribute(2*sizeof(uint64_t), minmax, minmax_uint64_t_type, 
  	CkCallback(CkIndex_Sorter<key,value>::globalMinMax(NULL), sorter_proxy)); 
  
  key step = (mymax - mymin + numChunks)/(numChunks);
  std::pair<int, key> p2 = grtstPow2(step * 2);
  step = p2.second;
  numChunks = (mymax + 1 - mymin)/step + 1;
  memset(histCounts, 0, numChunks*sizeof(int));	

  for(int i=0; i<numElem; i++)
		histCounts[(bucket_data[i].k - mymin)>>p2.first]++;		 
  cumHist[0] = 0;	
  for(int i=0; i<numChunks; i++)
	cumHist[i+1] = histCounts[i] + cumHist[i];

  memcpy(sepCounts, cumHist, (numChunks+1) * sizeof(cumHist[0]));	
  for(int bkt=0; bkt<numChunks; bkt++){
  	for(int i=cumHist[bkt]; i<sepCounts[bkt+1]; i++){
  		int ind = (bucket_data[i].k - mymin)>>p2.first;
  		if(ind != bkt){
  			int swap = cumHist[ind];
  			kv_pair<key, value> temp = bucket_data[i];
  			bucket_data[i] = bucket_data[swap];
  			bucket_data[swap] = temp;
  			cumHist[ind]++;
  			i--;
  		}
  	}
  }
  lastSortedChunk = 0;
  stepSort();

  #if VERBOSE
  double sum = 0; int keysum = 0;
  for(int i = 0; i < numElem; i++) 
    keysum += (int)(bucket_data[i].k % 100);  
  this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
  CkCallback(CkIndex_Main<key, value>::init_isum(NULL),mainProxy));
  #endif
}


template <class key, class value>
void Bucket<key, value>::stepSort(){
	if(lastSortedChunk == numChunks)
		return;	
	double cc1 = CmiWallTimer();
	std::sort(bucket_data + sepCounts[lastSortedChunk], 
		bucket_data + sepCounts[lastSortedChunk+1]);
/*
	ckout<<"Size of Chunk : "<<lastSortedChunk<<" : "<<CmiWallTimer()-cc1;
	ckout<<" : "<<sepCounts[lastSortedChunk+1] - sepCounts[lastSortedChunk]<<" : ";
	ckout<<" - "<<CkMyPe()<<endl;
*/
	lastSortedChunk++;
	if(doneHists)
		stepSort();
	else
		this->thisProxy[this->thisIndex].stepSort();
}


template <class key, class value>
void Bucket<key, value>::firstProbe(key firstkey, key lastkey, key step, int probeSize){
	lastProbeSize = probeSize;	
	memset(histCounts, 0, probeSize*sizeof(int));	
	std::pair<int, key> p2= grtstPow2(step+1);
	//ckout<<step<<" "<<lastkey<<" "<<firstkey<<" "<<probeSize<<" "<<numElem<<" "<<CkMyPe()<<endl;	
	for(int i=0; i<numElem; i++)
		histCounts[(bucket_data[i].k - firstkey)>>p2.first]++;			
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	//ckout<<"Probe Size : "<<probeSize<<endl;
	for (int i = 0; i < probeSize; i++)
		longhistCounts[i] = histCounts[i];

	this->contribute((probeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
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
	double c1 = CmiWallTimer();
	memset(histCounts, 0, lastProbeSize * sizeof(int));
	
	if(lastSortedChunk > 0){
		//ckout<<"comes here "<<CkMyPe()<<endl;
		int cumCount = 0;
		for(int prb=0; prb<lastProbeSize; prb++){
			kv_pair<key, value> comp;
			comp.k = lastProbe[prb];
			histCounts[prb] = std::upper_bound(bucket_data,
				 bucket_data + sepCounts[lastSortedChunk], comp) - bucket_data;
			histCounts[prb] -= cumCount;
			cumCount += histCounts[prb];
		}
	}


	if(lastSortedChunk < numChunks){
		int numIndices = std::max(nBuckets, lastProbeSize) * indexFactor;	
		key currmin;
		if(sepCounts[lastSortedChunk]>0)
			currmin = bucket_data[sepCounts[lastSortedChunk]-1].k;
		else
			currmin = mymin;
		key indexStep = std::max((mymax- currmin + numIndices)/numIndices, (key)1);	
		int prb = 0;
		//ckout<<" lastProbeSize "<<endl;
		//if(CkMyPe()==2 && numProbes==15){
		//	ckout<<"Bucket Info "<< indexStep<<" : "<<mymax<<" : "<<mymin<<" : "<<numIndices<<" "<<CkMyPe()<<endl;
		//}
		for(int ind=0; ind<numIndices; ind++){	
			//Something needs to be done about long long
			while(((long long) (lastProbe[prb] - currmin)/indexStep) < ind)
				prb++;
			indices[ind] = prb;
		}
		indices[numIndices] = lastProbeSize;

	//if(CkMyPe()==2 && numProbes==15){
	//	ckout<<"lastProbeSize:  "<<lastProbeSize;
	//	ckout<<" Step:  "<<indexStep<<" : "<<"Indices built :"<<numIndices<<" : "<<CkMyPe()<<endl;
	//		for(int i=0; i<numIndices; i++)
	//			ckout<<" : "<<indices[i]<<endl;
	//	for(int i=0; i<lastProbeSize; i++)
	//		ckout<<lastProbe[i]<<" {}{}{}{}{}{} "<<CkMyPe()<<endl;
	//}
		int maxcount = 0, avgcount = 0;
		for(int i=sepCounts[lastSortedChunk]; i<numElem; i++){
			int index = (bucket_data[i].k - currmin)/indexStep;
			int ind = indices[index];
			int count=1;
			if(indices[ind+1] - indices[ind] >= 15){
				ind = std::lower_bound(lastProbe + ind, 
					lastProbe + indices[index+1] + 1, bucket_data[i].k) - lastProbe;
			}
			else{
				while(lastProbe[ind] < bucket_data[i].k){
					ind++; //count++;
				}
			}

			histCounts[ind]++;
			//maxcount = std::max(maxcount, count);
			//avgcount += count;
		//ckout<<histCounts[ind]<<" ? "<<CkMyPe()<<endl;	
		}
		//ckout<<"Avg Count is : "<<((double)avgcount)/numElem<<" : ";
		//ckout<<"Real Avg : "<<((double)avgcount)/(numElem - sepCounts[lastSortedChunk])<<" : ";
		//ckout<<"Max Count is : "<<maxcount<<" : ";
		ckout<<"Elements Scanned : "<<numElem - sepCounts[lastSortedChunk]<<" "<<CkMyPe()<<endl;
	}

	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < lastProbeSize; i++)
		longhistCounts[i] = histCounts[i];

	this->contribute((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	//ckout<<"Max Latency: "<<maxcount<<" "<<"Avg Latency :"<<(double)avgCount/numElem<<endl;
	double c2 = CmiWallTimer();
	//ckout<<"It: "<<numProbes<<" "<<c2-c1<<" - "<<CkMyPe()<<endl;
	//if(CkMyPe()==2)
	//	ckout<<"Exiting Local Probe   "<<lastProbeSize<<" "<<CkMyPe()<<endl;	
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







