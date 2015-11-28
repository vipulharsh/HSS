#include <algorithm>
#include "assert.h"
#include "sortinglib.h"

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
  
  //std::pair<int, int> pp =  grtstPow2(params->probe_max * indexFactor + 1);
  indices = new int[2 * (params->probe_max * indexFactor + 1)];
  
  numChunks = nBuckets;
  sepCounts = new int[numChunks+2];
  sepKeys = new key[numChunks+2];
  sorted = new bool[numChunks+2];
  sent = new bool[nBuckets+1];
  Reset();
}


//reset variables after sorting
template <class key, class value>
void Bucket<key, value>::Reset(){
	memset(achieved+1, false, nBuckets);
    memset(sorted, false, numChunks+1);
    memset(sent, false, nBuckets+1);
    achieved[0] = true;
    //achieved[0] = achieved[nBuckets] = true;
    //check the validity of this
    numProbes = 0;
    finalSplitters[0] = minkey;    
    //finalSplitters[nBuckets] = maxkey;
    //achievedSplitters = 2;
    achievedSplitters = 1;

    lastSortedChunk = 0;
    doneHists = false;
    loadBuffer.clear();

    received = 0;
}


//set bucket data
template <class key, class value>
void Bucket<key, value>::SetData(CProxy_Sorter<key, value> _sorter_proxy, CProxy_Main<key, value> _main_proxy){
  DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
  numElem = in_elems;
  sorter_proxy = _sorter_proxy;
  main_proxy = _main_proxy;
  //CkAssert(num_elements > 0);
  bucket_data = (kv_pair<key, value>*)dataIn;

  mymin = mymax = bucket_data[0].k;
  
  double cc1 = CmiWallTimer();
  //ckout<<bucket_data[0].k<<" : ";
  for(int i=1; i<numElem; i++){
  	mymin = std::min(mymin, bucket_data[i].k);
  	mymax = std::max(mymax, bucket_data[i].k);
  	//ckout<<bucket_data[i].k<<" : ";
  }
  //ckout<<" - "<<CkMyPe()<<endl;

  ckout<<"Time for min max : "<<CmiWallTimer() - cc1<<" for "<<numElem<<" - "<<CkMyPe()<<endl;
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
  for(int i=0; i<numChunks; i++){
	cumHist[i+1] = histCounts[i] + cumHist[i];
  	sepKeys[i+1] = mymin + step * (i+1);
  }
  sepKeys[0] = mymin;
  sepKeys[numChunks] = maxkey;
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
  CkCallback(CkIndex_Main<key, value>::init_isum(NULL),main_proxy));
  #endif
}


template <class key, class value>
void Bucket<key, value>::stepSort(){
	if(lastSortedChunk == numChunks)
		return;	
	double cc1 = CmiWallTimer();
	
	if(!sorted[lastSortedChunk+1]){
		std::sort(bucket_data + sepCounts[lastSortedChunk], 
			bucket_data + sepCounts[lastSortedChunk+1]);
	}
	//ckout<<"Size of Chunk : "<<lastSortedChunk<<" : "<<CmiWallTimer()-cc1;
	//ckout<<" : "<<sepCounts[lastSortedChunk+1] - sepCounts[lastSortedChunk]<<" : ";
	//ckout<<" - "<<CkMyPe()<<endl;
	lastSortedChunk++;
	sorted[lastSortedChunk] = true;
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
	double c1 = CmiWallTimer();
	memset(histCounts, 0, lastProbeSize * sizeof(int));
	
	if(lastSortedChunk > 0){
		//ckout<<"comes here "<<CkMyPe()<<endl;
		int cumCount = 0;
		for(int prb=0; prb<lastProbeSize; prb++){
			kv_pair<key, value> comp;
			comp.k = lastProbe[prb];
			histCounts[prb] = std::upper_bound(bucket_data + cumCount,
				 bucket_data + sepCounts[lastSortedChunk], comp) - bucket_data;
			histCounts[prb] -= cumCount;
			cumCount += histCounts[prb];
		}
	}

	if(lastSortedChunk < numChunks){
		//buildIndex : !Change this to for division by 2
		int numIndices = std::max(nBuckets, lastProbeSize) * indexFactor;	
		key currmin = mymin;
		if(sepCounts[lastSortedChunk]>0)
			currmin = bucket_data[sepCounts[lastSortedChunk]-1].k;

		key indexStep = std::max((mymax- currmin + numIndices)/numIndices, (key)1);	
		int prb = 0;
		for(int ind=0; ind<numIndices; ind++){	
			//Something needs to be done about long long
			while(((long long) (lastProbe[prb] - currmin)/indexStep) < ind)
				prb++;
			indices[ind] = prb;
		}
		indices[numIndices] = lastProbeSize;

		for(int i=sepCounts[lastSortedChunk]; i<numElem; i++){
			int index = (bucket_data[i].k - currmin)/indexStep;
			int ind = indices[index];
			ind = std::lower_bound(lastProbe + ind, 
				lastProbe + indices[index+1] + 1, bucket_data[i].k) - lastProbe;
			histCounts[ind]++;
		}
		ckout<<"Elements Scanned : "<<numElem - sepCounts[lastSortedChunk]<<" "<<CkMyPe()<<endl;
	}
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < lastProbeSize; i++)
		longhistCounts[i] = histCounts[i];

	this->contribute((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	double c2 = CmiWallTimer();
}


template <class key, class value>
void Bucket<key, value>::histCountProbes(probeMessage<key> *pm){
	numProbes++;
	if(numProbes == 3 && this->thisIndex==3){
	//	ckout<<" Now contributing "<<numProbes<<endl;
	//	this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), sorter_proxy));	
	}	
	 
	for(int i=0; i<pm->num_newachv; i++){
		finalSplitters[pm->newachv_id[i]] = pm->newachv_key[i];
		assert(!achieved[pm->newachv_id[i]]);
		achieved[pm->newachv_id[i]] = true;
	}
	achievedSplitters += pm->num_newachv;
	lastProbeSize = pm->probeSize;
	memcpy(lastProbe, pm->probe, lastProbeSize * sizeof(key));
	if(lastProbeSize > 1){
		localProbe();
		partialSend(pm);
	}
	else{
		ckout<<"Splitters have been determined  - "<<CkMyPe()<<endl;
		doneHists = true;
		partialSend(pm);
		if(received == nBuckets){
			#if VERBOSE
		      	double sum = 0; int keysum = 0;
		      	for(int i = 0; i < loadBuffer[0]->num_vals; i++) 
		      	  keysum += (int)(loadBuffer[0]->data[i].k % 100);   
		      	this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
		      	    CkCallback(CkIndex_Main<key, value>::final_isum(NULL),main_proxy));
		      	//printf("%d ** KeySum %lu Sum %lf\n",CkMyPe(),keysum, sum);
			#endif
		    //for(int i=0; i<*out_elems; i++)
		    //	ckout<<loadBuffer[0]->data[i].k<<" : ";
		    ckout<<" Done at "<<CkMyPe()<<endl;
		    //not working???
			this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), sorter_proxy));		
		}
	}
	delete(pm);
}



template <class key, class value>
void Bucket<key, value>::partialSend(probeMessage<key> *pm){
	//randomize it
	for(int i=0; i<pm->num_newachv; i++){
		for(int bkt = pm->newachv_id[i]; bkt<= pm->newachv_id[i]+1 && bkt<=nBuckets; bkt++){
			if(!sent[bkt] && achieved[bkt] && achieved[bkt-1]){
				//find what all chunks it belongs to
				key sep1 = finalSplitters[bkt-1];
				key sep2 = finalSplitters[bkt];
				int chunk1 = std::upper_bound(sepKeys, sepKeys + numChunks + 1, sep1) - sepKeys - 1;
				int chunk2 = std::lower_bound(sepKeys, sepKeys + numChunks + 1, sep2) - sepKeys;

				//ckout<<numChunks<<" : "<<mymax<<" : "<<sep1<<" ;; "<<sep2<<" : "<<sepKeys[numChunks]<<" ! ";
				//	ckout<<chunk1<<" ;';';';'; "<<chunk2<<" for "<<bkt<<" - "<<CkMyPe()<<endl;
				
				//sort those chunks if not already sorted
				for(int c = chunk1+1; c <= chunk2; c++){
					if(!sorted[c]){
						std::sort(bucket_data + sepCounts[c-1], 
						bucket_data + sepCounts[c]);
						sorted[c] = true;
						//use this sorted chunk to optimize computations in localProbe
						//ckout<<chunk1<<" ;';';';'; "<<chunk2<<" for "<<bkt<<" - "<<CkMyPe()<<endl;
					}
				}

				//find keys and send
				kv_pair<key, value> comp;
				comp.k = sep1;
				int ind1 = std::lower_bound(bucket_data + sepCounts[chunk1],
					 bucket_data + sepCounts[chunk2], comp) - bucket_data;
				comp.k = sep2;
				int ind2 = std::lower_bound(bucket_data + sepCounts[chunk1],
					 bucket_data + sepCounts[chunk2], comp) - bucket_data;
				//ckout<<"Sending "<<ind1<<"-"<<ind2<<" to "<<bkt<<" from "<<this->thisIndex<<endl;
				sent[bkt] = true;
				data_msg<key, value> *dm = new (ind2-ind1) data_msg<key,value>;
				memcpy(dm->data, bucket_data + ind1, (ind2-ind1)*sizeof(kv_pair<key, value>));
				dm->num_vals = ind2-ind1;
				dm->sorted = true;
				this->thisProxy[bkt-1].Load(dm);
			}
		}
	}
}


template <class key, class value>
void Bucket<key, value>::Load(data_msg<key, value>* msg){

	if(!msg->sorted){
		std::sort(msg->data, msg->data + msg->num_vals);
		msg->sorted = true;
	}
/*
	key kk=0;
	for(int i=0; i<msg->num_vals; i++)
		kk += msg->data[i].k;
	ckout<<kk<<" Successful "<<endl;
*/
	loadBuffer.push_back(msg);
	received++;

	if(received < nBuckets){
		collapseAndMerge();
	}
	else{
		//ckout<<"loadBuffer Size yet to be merged : "<<loadBuffer.size()<<endl;
		totalMerge();
		*dataOut = loadBuffer[0]->data;
		*out_elems = loadBuffer[0]->num_vals;
		if(doneHists){
			#if VERBOSE
		      	double sum = 0; int keysum = 0;
		      	for(int i = 0; i < loadBuffer[0]->num_vals; i++) 
		      	  keysum += (int)(loadBuffer[0]->data[i].k % 100);   
		      	this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
		      	    CkCallback(CkIndex_Main<key, value>::final_isum(NULL),main_proxy));
		      	//printf("%d ** KeySum %lu Sum %lf\n",CkMyPe(),keysum, sum);
			#endif
		    //for(int i=0; i<*out_elems; i++)
		    //	ckout<<loadBuffer[0]->data[i].k<<" : ";
		    ckout<<" Done at "<<CkMyPe()<<endl;
		    //not working???
			this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), sorter_proxy));		
		}
	}
}


template <class key, class value>
void Bucket<key, value>::collapseAndMerge(){
	while (loadBuffer.size() > 1) {
        int n = loadBuffer.size() - 2;
        if ((n >= 1 && 
       		loadBuffer[n-1]->num_vals <= loadBuffer[n]->num_vals + loadBuffer[n+1]->num_vals)
        ||(n >= 2 && 
        	loadBuffer[n-2]->num_vals <= loadBuffer[n-1]->num_vals + loadBuffer[n]->num_vals)) {   
            if (loadBuffer[n-1]->num_vals < loadBuffer[n+1]->num_vals)
                n--;
        } 
        else if (loadBuffer[n]->num_vals > loadBuffer[n+1]->num_vals)
            break; // Invariant is established
        
        mergeAt(n);
    }
}

template <class key, class value>
void Bucket<key, value>::totalMerge(){
	while(loadBuffer.size() > 1)
		mergeAt(loadBuffer.size()-2);
}



//merge loadBuffers[n] & loadBuffers[n+1]
template <class key, class value>
void Bucket<key, value>::mergeAt(int n){
	data_msg<key, value>* msg1;
	data_msg<key, value>* msg2;
	if(loadBuffer[n]->num_vals > loadBuffer[n+1]->num_vals){
		msg1 = loadBuffer[n+1];
		msg2 = loadBuffer[n];
	}
	else{
		msg1 = loadBuffer[n];
		msg2 = loadBuffer[n+1];
	}
	int s1 = msg1->num_vals;
	int s2 = msg2->num_vals; 

	data_msg<key, value> *result = new (s1 + s2) data_msg<key,value>;
	result->num_vals = s1 + s2;
	result->sorted = true;
	
	//ckout<<"MergeAt :- "<<CkMyPe()<<" : "<<n<<" : "<<s1<<" : "<<s2<<" : "<<endl;
	
	std::merge(msg1->data, msg1->data + s1, msg2->data, msg2->data + s2, result->data);
	loadBuffer.erase(loadBuffer.begin()+n);
	loadBuffer[n] = result;
	delete(msg1); delete(msg2);
}


