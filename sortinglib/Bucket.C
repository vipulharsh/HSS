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
  achievedCounts = new uint64_t[nBuckets+2];

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
    achievedCounts[0] = 0; 
    //finalSplitters[nBuckets] = maxkey;
    //achievedSplitters = 2;
    achievedSplitters = 1;

    lastSortedChunk = 0;
    doneHists = false;
    loadBuffer.clear();

    received = 0;
    noMergingWork = false;
    firstMergingWork = true;
    dummyCount = 0;
    callPartialSendOne = true;
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
  for(int i=1; i<numElem; i++){
  	mymin = std::min(mymin, bucket_data[i].k);
  	mymax = std::max(mymax, bucket_data[i].k);
  	//ckout<<bucket_data[i].k<<" : ";
  }

  //ckout<<"Time for min max : "<<CmiWallTimer() - cc1<<" for "<<numElem<<" - "<<CkMyPe()<<endl;
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
  sepKeys[numChunks] = maxkey ;
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


/******************************************************************************
*
*
*
*
*
* CHECK OVERFLOW ERROR
* WHAT HAPPENS WHEN ONE OF THE KEYS IS EQUAL TO ONE OF THE PROBES
*
*
*
*
*
**********************************************************************************/


template <class key, class value>
void Bucket<key, value>::stepSort(){
	double cc1 = CmiWallTimer();	
	//if(lastSortedChunk == numChunks-1) return;
	if(!sorted[lastSortedChunk+1]){
		std::sort(bucket_data + sepCounts[lastSortedChunk], 
			bucket_data + sepCounts[lastSortedChunk+1]);
	}
	//ckout<<"Size of Chunk : "<<lastSortedChunk<<" : "<<CmiWallTimer()-cc1;
	//ckout<<" : "<<sepCounts[lastSortedChunk+1] - sepCounts[lastSortedChunk]<<" : ";
	//ckout<<" - "<<CkMyPe()<<endl;
	lastSortedChunk++;
	sorted[lastSortedChunk] = true;
	if(lastSortedChunk < numChunks){
		if(doneHists)
			stepSort();
		else
			this->thisProxy[this->thisIndex].stepSort();
	}
	else if(achieved[this->thisIndex] &&  achieved[this->thisIndex+1])
		this->thisProxy[this->thisIndex].MergingWork();

	//if(lastSortedChunk == numChunks)
	//	ckout<<"Sorting finished ********************** Called: "<<(achieved[this->thisIndex] &&  achieved[this->thisIndex+1])<<" - "<<CkMyPe()<<endl;	
}




template <class key, class value>
void Bucket<key, value>::firstProbe(key firstkey, key lastkey, key step, int probeSize){
	lastProbeSize = probeSize;	
	memset(histCounts, 0, probeSize*sizeof(int));	
	//ckout<<" Hist Count on "<<CkMyPe()<<" --- "<<lastSortedChunk<<endl;

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
	assert(lastProbeSize);
	memset(histCounts, 0, lastProbeSize * sizeof(int));
	if(lastSortedChunk > 0){
		int cumCount = 0;
		kv_pair<key, value> comp;
		int prb = -1;
		do{
			prb++;
			comp.k = lastProbe[prb];
			histCounts[prb] = std::lower_bound(bucket_data + cumCount,
				 bucket_data + sepCounts[lastSortedChunk], comp) - bucket_data;
			histCounts[prb] -= cumCount;
			cumCount += histCounts[prb];
		}while(prb<lastProbeSize-1 && (lastProbe[prb] < sepKeys[lastSortedChunk]));
	}

	//ckout<<"Time taken in sorted Histogramming at "<<CkMyPe()<<" : "<<CmiWallTimer()-c1<<endl;

//	ckout<<" LastProbeSize "<<lastProbeSize<<" : "<<CkMyPe()<<endl;
//	ckout<<" Hist Count on "<<CkMyPe()<<" --- "<<lastSortedChunk<<endl;
//	for (int i = 0; i < lastProbeSize; i++)
//		ckout<<" Hist Count on "<<CkMyPe()<<" - "<<histCounts[i]<<" : "<<lastProbe[i]<<" : "<<lastProbeSize<<endl; 

	if(lastSortedChunk < numChunks){
		//buildIndex : !Change this to for division by 2
		key currmin = mymin;
		if(sepCounts[lastSortedChunk]>0){
			currmin = bucket_data[sepCounts[lastSortedChunk]-1].k;
		}
	
		int numIndices = std::max(nBuckets, lastProbeSize) * indexFactor;			
		key indexStep = std::max((mymax- currmin + numIndices)/numIndices, (key)1);	
		
		std::pair<int, key> p2= grtstPow2((mymax-currmin)/numIndices + 1);

		//ckout<<currmin<<" : "<<mymax<<" - "<<CkMyPe()<<endl;
		indexStep = p2.second * 2;
		int indexStepLog = p2.first + 1;
		int numIndices2 = numIndices;
		numIndices = (mymax - currmin)/indexStep + 1;
		assert(numIndices <= numIndices2);
		//int indexStepLog = 0;
		//while(currmin + (indexStep * numIndices) <= mymax){
		//	indexStep *= 2;
		//	indexStepLog++;
		//}
		//ckout<<"IndexStep : "<<indexStep<<" - "<<sepCounts[lastSortedChunk]<<" ;;; "<<numIndices<<" - "<<CkMyPe()<<endl;

		int prb = 0;
		for(int ind=0; ind<numIndices; ind++){	
			//Something needs to be done about long long
			while((long long)lastProbe[prb] < (ind * indexStep) + currmin)
				prb++;
			indices[ind] = prb;
			//ckout<<"Index:  "<<ind<<" :: "<<"Probe no: "<<prb<<" - "<<CkMyPe()<<endl;
		}
		indices[numIndices] = lastProbeSize-1;

		for(int i=sepCounts[lastSortedChunk]; i<numElem; i++){
			//int index = (bucket_data[i].k - currmin)/indexStep;
			int index = (bucket_data[i].k - currmin)>>indexStepLog;
			int ind = indices[index];
			ind = std::lower_bound(lastProbe + ind, 
				lastProbe + indices[index+1] + 1, bucket_data[i].k) - lastProbe;
			//ckout<<i<<" **** "<<bucket_data[i].k<<" ------- "<<ind<<" & Index: "<<index<<" & "<<indices[index]<<" & "<<indexStep<<" & "<<currmin<<" - "<<CkMyPe()<<endl;
 			if(bucket_data[i].k == lastProbe[ind])
 				ind++;
 			//assert(bucket_data[i].k < lastProbe[ind]);
			histCounts[ind]++;			
		}
		ckout<<"Elements Scanned : "<<numElem - sepCounts[lastSortedChunk]<<" "<<CkMyPe()<<endl;
	}
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < lastProbeSize; i++)
		longhistCounts[i] = histCounts[i]; 

	//ckout<<" Hist Count on "<<CkMyPe()<<" --- "<<lastSortedChunk<<endl;
	this->contribute((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key,value>::Histogram(NULL), sorter_proxy));
	double c2 = CmiWallTimer();
	//ckout<<"Time taken in Histogramming at "<<CkMyPe()<<" : "<<c2-c1<<endl;
}


template <class key, class value>
void Bucket<key, value>::histCountProbes(probeMessage<key> *pm){
	numProbes++;
	bool flag =  (achieved[this->thisIndex] &&  achieved[this->thisIndex+1]);
	for(int i=0; i<pm->num_newachv; i++){
		finalSplitters[pm->newachv_id[i]] = pm->newachv_key[i];
		assert(!achieved[pm->newachv_id[i]]);
		achieved[pm->newachv_id[i]] = true;
		achievedCounts[pm->newachv_id[i]] = pm->newachv_count[i];
	}
	achievedSplitters += pm->num_newachv;
	lastProbeSize = pm->probeSize;
	memcpy(lastProbe, pm->probe, lastProbeSize * sizeof(key));
	
	if(flag != (achieved[this->thisIndex] &&  achieved[this->thisIndex+1])){
			mergingDone = false;
			//if(lastSortedChunk == numChunks)																																			if(lastSortedChunk == numChunks)
			//	this->thisProxy[this->thisIndex].MergingWork();
	}
    
	if(lastProbeSize > 1)
		localProbe();
	else
		doneHists = true;

	partialSend(pm);
	
	if(lastProbeSize <= 1){
		//ckout<<"Splitters have been determined  - "<<CkMyPe()<<endl;	
		if(lastSortedChunk == numChunks)																
			this->thisProxy[this->thisIndex].MergingWork();
		if(mergingDone){
			#if VERBOSE
		      	kv_pair<key, value> *finalData = (kv_pair<key, value>*)*dataOut;
		      	double sum = 0; int keysum = 0;
		      	for(int i = 0; i < *out_elems; i++) 
		      	  keysum += (int)(finalData[i].k % 100);   
		      	this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
		      	    CkCallback(CkIndex_Main<key, value>::final_isum(NULL),main_proxy));
		      	//printf("%d ** KeySum %lu Sum %lf\n",CkMyPe(),keysum, sum);
			#endif
		    //for(int i=0; i<*out_elems; i++)
		    //	ckout<<loadBuffer[0]->data[i].k<<" : ";
		    uint64_t cnt = achievedCounts[this->thisIndex+1] - achievedCounts[this->thisIndex];
		    ckout<<*out_elems<<" : "<<cnt<<" : "<<dummyCount<<" : "<<dummyCount2<<" Done at "<<CkMyPe()<<endl;
		    //not working???
			this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), sorter_proxy));		
		}

	}
	delete(pm);
}



template <class key, class value>
void Bucket<key, value>::partialSend(probeMessage<key> *pm){
	//randomize it
	for(int ti=0,i; ti<pm->num_newachv; ti++){
		i = (ti + this->thisIndex)%pm->num_newachv;
		for(int bkt = pm->newachv_id[i]; bkt<= pm->newachv_id[i]+1 && bkt<=nBuckets; bkt++){
			if(!sent[bkt] && achieved[bkt] && achieved[bkt-1]){
				toSend.push_back(bkt);
				sent[bkt] = true;
				if(callPartialSendOne){
					this->thisProxy[this->thisIndex].partialSendOne();
					callPartialSendOne = false;
				}
			}
		}
	}
}



template <class key, class value>
void Bucket<key, value>::partialSendOne(){
	int bkt = toSend.back();
	toSend.pop_back();

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
	data_msg<key, value> *dm = new (ind2-ind1) data_msg<key,value>;
	memcpy(dm->data, bucket_data + ind1, (ind2-ind1)*sizeof(kv_pair<key, value>));
	dm->num_vals = ind2-ind1;
	dm->sorted = true;
	this->thisProxy[bkt-1].Load(dm);
	if(!toSend.empty())
		this->thisProxy[this->thisIndex].partialSendOne();
	else
		callPartialSendOne = true;
}





template <class key, class value>
void Bucket<key, value>::Load(data_msg<key, value>* msg){
	incomingMsgBuffer.push_back(msg);
	if(noMergingWork && lastSortedChunk==numChunks){
		noMergingWork = false;
		this->thisProxy[this->thisIndex].MergingWork();
	}
}



template <class key, class value>
void Bucket<key, value>::MergingWork(){
	noMergingWork = false;
	if(firstMergingWork){
		//ckout<<"Merging Begins - "<<CkMyPe()<<endl;
		*out_elems = achievedCounts[this->thisIndex+1] - achievedCounts[this->thisIndex];
		//ckout<<*out_elems<<" LLL  - "<<CkMyPe()<<endl;
		*dataOut = new kv_pair<key, value>[*out_elems];
		scratch = new kv_pair<key, value>[(*out_elems)/2];
		//firstUsed = *out_elems;
		lastUsed = 0;
		firstMergingWork = false;
		totalmerge = false;
	}
	
	else if(lastSortedChunk == numChunks){
		bool mergeat = false;
		int n;
		if (loadBuffer.size() > 1) {
	        mergeat = true; 
	        n = loadBuffer.size() - 2;
		    //ckout<<"Merging Deciding "<<totalmerge<<" - "<<CkMyPe()<<endl;
		    if(!totalmerge){
	            int s1, s2, s3, s4;
		        s1 = loadBuffer[n+1].numVals;
		        s2 = loadBuffer[n].numVals;
		        if(n>=1)
		        	s3 = loadBuffer[n-1].numVals;
		        if(n>=2)
		        	s4 = loadBuffer[n-2].numVals; 

		        if ((n >= 1 && s3 <= s2 + s1) || (n >= 2 &&  s4 <= s3 + s2)){   
		            if (s3 < s1)
		                n--;
		        }
		        else if (s2 > s1){
		           mergeat = false ; // Invariant is established
		        }
		    }    
	    }
    
        if(mergeat){        
	        mergeAt(n);
	        //ckout<<"Merging At "<<loadBuffer.size()<<" - "<<CkMyPe()<<endl;
	    }
	    else if(incomingMsgBuffer.size()>0){
	    	data_msg<key, value>* msg = incomingMsgBuffer.back();
			incomingMsgBuffer.pop_back();
			//ckout<<" ;;;* "<<CkMyPe()<<" : "<<msg->num_vals<<" ;;; "<< firstUsed <<endl;
			if(!msg->sorted){
				std::sort(msg->data, msg->data + msg->num_vals);
				msg->sorted = true;
			}
			lb_struct<key, value> lb;
			lb.numVals = msg->num_vals;
			lb.start = lastUsed;
			lb.msg = msg;
			loadBuffer.push_back(lb);
			lastUsed += msg->num_vals;
			received++;
			if(received == nBuckets){
				totalmerge = true;
			}
			//ckout<<"incomingMsgBuffer - "<<incomingMsgBuffer.size()<<" - "<<CkMyPe()<<endl;
	    }
	    else if(totalmerge){
	    	mergingDone = true;
	    	//ckout<<"Total Merge over -"<<CkMyPe()<<endl;
	    	//ckout<<*out_elems<<" : "<<doneHists<<" Done at "<<CkMyPe()<<endl;
	    	if(doneHists){
				#if VERBOSE
					kv_pair<key, value> *finalData = (kv_pair<key, value>*)*dataOut;
			      	double sum = 0; int keysum = 0;
			      	for(int i = 0; i < *out_elems; i++) 
			      	  keysum += (int)(finalData[i].k % 100);   
			      	this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
			      	    CkCallback(CkIndex_Main<key, value>::final_isum(NULL),main_proxy));
			      	//printf("%d ** KeySum %lu Sum %lf\n",CkMyPe(),keysum, sum);
				#endif
			    //for(int i=0; i<*out_elems; i++)
			    //	ckout<<loadBuffer[0]->data[i].k<<" : ";
			    uint64_t cnt = achievedCounts[this->thisIndex+1] - achievedCounts[this->thisIndex];
			    ckout<<*out_elems<<" : "<<cnt<<" : "<<dummyCount<<" : "<<dummyCount2<<" Done at "<<" - "<<CkMyPe()<<endl;
			    this->contribute(CkCallback(CkIndex_Sorter<key, value>::Done(NULL), sorter_proxy));		
			}
			return;	
	    }
	    else{ //Nothing happened
	    	//ckout<<"Nothing happened "<<CkMyPe()<<endl;
	    	noMergingWork = true;
	    }
	}
    if(!noMergingWork && lastSortedChunk==numChunks){
	    if(doneHists)
			MergingWork();
		//else
		//	this->thisProxy[this->thisIndex].MergingWork();
	}
}




//merge loadBuffers[n] & loadBuffers[n+1]
template <class key, class value>
void Bucket<key, value>::mergeAt(int n){

 	kv_pair<key, value> *finalData = (kv_pair<key, value>*)*dataOut;	      	

	//if the first one is a msg
	if(loadBuffer[n].msg != NULL){
		kv_pair<key, value>* first2;
		if(loadBuffer[n+1].msg == NULL)
			first2 = finalData + loadBuffer[n+1].start;
		else
			first2 = loadBuffer[n+1].msg->data;
		forward_merge(  loadBuffer[n].msg->data,
					    loadBuffer[n].msg->data + loadBuffer[n].numVals,
					    first2,	
					    first2 + loadBuffer[n+1].numVals,
						finalData + loadBuffer[n].start 
					 );
	}
	//if the first one is not a msg and the second one is a msg
	else if(loadBuffer[n+1].msg != NULL){
		backward_merge( finalData + loadBuffer[n].start - 1,
						finalData + loadBuffer[n].start - 1 + loadBuffer[n].numVals,
						loadBuffer[n+1].msg->data - 1,
						loadBuffer[n+1].msg->data -1 + loadBuffer[n+1].numVals,
						finalData + loadBuffer[n+1].start -1 + loadBuffer[n+1].numVals
					  );
	}
	//none of them are msgs, first one smaller
	else if(loadBuffer[n].numVals < loadBuffer[n+1].numVals){
		memcpy(scratch, finalData + loadBuffer[n].start, 
				sizeof(kv_pair<key, value>)*loadBuffer[n].numVals);
		forward_merge( scratch,
					   scratch + loadBuffer[n].numVals, 
					   finalData + loadBuffer[n+1].start,
					   finalData + loadBuffer[n+1].start + loadBuffer[n+1].numVals,
					   finalData + loadBuffer[n].start  
					  );
	}
	//none of them are msgs, second one smaller
	else{
		memcpy(scratch, finalData + loadBuffer[n+1].start,
				sizeof(kv_pair<key, value>)*loadBuffer[n+1].numVals);
		backward_merge(	finalData + loadBuffer[n].start - 1,
						finalData + loadBuffer[n].start - 1 + loadBuffer[n].numVals,
						scratch - 1,
						scratch - 1 + loadBuffer[n+1].numVals,
						finalData + loadBuffer[n+1].start - 1 + loadBuffer[n+1].numVals
					  ); 
	}
	//ckout<<"MergeAt :- "<<CkMyPe()<<" : "<<n<<" : "<<loadBuffer[n+1].first<<" : "<<loadBuffer[n+1].second<<" : "<<loadBuffer[n].first<<" : "<<loadBuffer[n].second<<endl;
	
	if(loadBuffer[n].msg != NULL)
		delete(loadBuffer[n].msg);
	if(loadBuffer[n+1].msg != NULL)
		delete(loadBuffer[n+1].msg);

	lb_struct<key, value> lb;
	lb.start = loadBuffer[n].start;
	lb.numVals = loadBuffer[n].numVals + loadBuffer[n+1].numVals;
	lb.msg = NULL;
	loadBuffer[n] = lb;
	dummyCount2 += loadBuffer[n].numVals;
	loadBuffer.erase(loadBuffer.begin()+n+1);
}


template <class key, class value>
void Bucket<key, value>::forward_merge(kv_pair<key, value> *first1, kv_pair<key, value> *last1,
								 	   kv_pair<key, value> *first2, kv_pair<key, value> *last2,
								       kv_pair<key, value> *result){
  while (true) {
    if (first1==last1) {
    	std::copy(first2, last2, result);
    	return;
    }
    if (first2==last2) {
    	std::copy(first1, last1, result);
    	return;
    }
    *result++ = (*first2<*first1)? *first2++ : *first1++;
  }
}


template <class key, class value>
void Bucket<key, value>::backward_merge(kv_pair<key, value> *first1, kv_pair<key, value> *last1,
								 	   kv_pair<key, value> *first2, kv_pair<key, value> *last2,
								       kv_pair<key, value> *result){
  while (true) {
    if (first1==last1){
    	std::copy(first2+1, last2+1, result-(last2-first2)+1);
    	return;
    }
    if (first2==last2){
    	std::copy(first1+1, last1+1, result-(last1-first1)+1);
    	return;
    }
    *result-- = (*last1<*last2)? *last2-- : *last1--;
  }
}


