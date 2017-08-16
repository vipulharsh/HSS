#include <algorithm>
#include "assert.h"
#include "sortinglib.h"
#include "nodemanager.h"
#include "math.h"
#include <vector>

extern CkReduction::reducerType sum_uint64_t_type; 
extern CkReduction::reducerType minmax_uint64_t_type; 
int maxSampleSize();


template <class key>
Bucket<key>::Bucket(CkMigrateMessage *msg){}

///initialize Bucket (create data)
template <class key>
Bucket<key>::Bucket(tuning_params par, key min, key max, int nuBuckets_, CkNodeGroupID _nodeMgrID):
	minkey(min), maxkey(max), nBuckets(nuBuckets_), nodeMgrID(_nodeMgrID){
	//CkPrintf("Creating chare %d of bucket chare array\n", this->thisIndex);
	params = new tuning_params;
	*params = par;
	nNodes = CkNumNodes();
        int maxprobe = std::max(params->probe_max, 2*maxSampleSize());
	lastProbe = new key[maxprobe];
	finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
	achieved = new bool[nBuckets+2];
	achievedCounts = new uint64_t[nBuckets+2];

	cumHist = new int[maxprobe+1];

	histCounts = new int[maxprobe +1];
	longhistCounts = new uint64_t[maxprobe +1];

	//std::pair<int, int> pp =  grtstPow2(params->probe_max * indexFactor + 1);
	indices = new int[2 * (maxprobe * indexFactor + 1)];

	numChunks = 1;//nBuckets;
	sepCounts = new int[numChunks+2];
	sepKeys = new key[numChunks+2];
	sorted = new bool[numChunks+2];
	sent = new bool[nBuckets+1];
	Reset();
}


//reset variables after sorting
template <class key>
void Bucket<key>::Reset(){
	memset(achieved+1, false, nBuckets+1);
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
	dummyCount2 = 0;
	callPartialSendOne = false;
	numSent = 0;
	startMergingWork = false;
	tsum = 0;
	recvd = 0;

}


template <class key>
void Bucket<key>::startBarrier(CProxy_Sorter<key> _sorter_proxy, CProxy_Main<key> _main_proxy){
	sorter_proxy = _sorter_proxy;
	main_proxy = _main_proxy;
	//this->contribute(CkCallback(CkIndex_Sorter<key>::finishBarrier(NULL), sorter_proxy));
}


//set bucket data
template <class key>
void Bucket<key>::SetData(){
	DEBUGPRINTF("Set data of chare %d of bucket chare array\n", this->thisIndex);
	//nodemgr = *(Global<key>::nodemgr);
	nodemgr = CProxy_NodeManager<key>(nodeMgrID); 

	numElem = in_elems;
	//CkAssert(num_elements > 0);
	bucket_data = (key*)dataIn;

        //CkPrintf("Registering local chare array [%d], nodemgrID: %d \n", CkMyPe(), nodeMgrID);
	nodemgr[CkMyNode()].registerLocalChare(numElem, CkMyPe(),  
										   this->thisProxy, sorter_proxy);

	//for(int i=0; i<numElem; i++){
	//	ckout<<"bucket_data["<<i<<"]: "<<bucket_data[i]<<" : "<<CkMyPe()<<endl;
	//}
	
	//ckout<<"SetData Begins - "<<CkMyPe()<<endl;
	//ckout<<in_elems<<" KKK  - "<<CkMyPe()<<endl;
	//ckout<<out_elems<<" MMM  - "<<CkMyPe()<<endl;

	mymin = mymax = bucket_data[0];

	double cc1 = CmiWallTimer();
	for(int i=1; i<numElem; i++){
		mymin = std::min(mymin, bucket_data[i]);
		mymax = std::max(mymax, bucket_data[i]);
		//ckout<<bucket_data[i]<<" : ";
	}

	//ckout<<"Time for min max : "<<CmiWallTimer() - cc1<<" for "<<numElem<<" - "<<CkMyPe()<<endl;
	//ckout<<mymin<<" minmax "<<mymax<<" - "<<CkMyPe()<<endl;
	key minmax[2] = {mymin, mymax};
	//needs to be changed to key
//	this->contribute(2*sizeof(uint64_t), minmax, minmax_uint64_t_type, 
//		CkCallback(CkIndex_Sorter<key>::globalMinMax(NULL), sorter_proxy)); 


#if VERBOSE
	double sum = 0; int keysum = 0;
	for(int i = 0; i < numElem; i++) 
	keysum += (int)(bucket_data[i] % 1009);  
	this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
	CkCallback(CkIndex_Main<key>::init_isum(NULL),main_proxy));
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


template<class key>
void Bucket<key>::sortAll(){
	//Since, we are not "chunking" bucket_data, 
	// work around for localProbe() to work correctly
        numChunks = 1;
        sepKeys[0] = minkey ;
        sepKeys[1] = maxkey ;
        sepCounts[0] = 0;
        sepCounts[1] = numElem;
        std::sort(bucket_data, bucket_data + numElem);
        lastSortedChunk = 1;
        sorted[1] = true; 
}




template <class key>
void Bucket<key>::genSample(sampleInfo sI){
	//ckout<<"I will generate samples now "<<CkMyPe()<<endl;
	//array_msg<key> *sample = new (am->numElem) array_msg<key>;
	key *dest  = (key *)sI.dest;
	//CkPrintf("[%d] genSample of size: %d, dest: %p\n", CkMyPe(), sI.size, sI.dest);
	for(int i=0; i<sI.size; i++){
		dest[i] = bucket_data[sI.indices[i]-sI.offset];
	}
	nodemgr[CkMyNode()].collectSamples(sI);
	//delete(am);
  this->thisProxy[this->thisIndex].sortAll();
	/****  Undo this, after fixing the chunks ***/
	//this->thisProxy[this->thisIndex].stepSort();
}



template <class key>
void Bucket<key>::finalProbes(array_msg<key>* finalprb){
	//CkPrintf("^^^^^^^^^^^[%d]bucket  got the final probes: maxSampleSize: %d \n", CkMyPe(), maxSampleSize());
	memcpy(lastProbe, finalprb->data, finalprb->numElem * sizeof(key));
	lastProbeSize = finalprb->numElem;
	//CkPrintf("^^^^^^^^^^^[%d]lastProbeSize :  %d \n", CkMyPe(), lastProbeSize);
	localProbe();
}






template <class key>
void Bucket<key>::stepSort(){
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
	
	else if(startMergingWork && toSend.empty())
		this->thisProxy[this->thisIndex].MergingWork();

	//if(lastSortedChunk == numChunks)
	//	ckout<<"Sorting finished ********************** Called: "<<(achieved[this->thisIndex] &&  achieved[this->thisIndex+1])<<" - "<<CkMyPe()<<endl;	
}




template <class key>
void Bucket<key>::firstProbe(key firstkey, key lastkey, key step, int probeSize){
	lastProbeSize = probeSize;	
	memset(histCounts, 0, probeSize*sizeof(int));	
	//ckout<<" Hist Count on "<<CkMyPe()<<" --- "<<lastSortedChunk<<endl;

	std::pair<int, key> p2= grtstPow2(step+1);
	//ckout<<step<<" "<<lastkey<<" "<<firstkey<<" "<<probeSize<<" "<<numElem<<" "<<CkMyPe()<<endl;	
	for(int i=0; i<numElem; i++)
		histCounts[(bucket_data[i] - firstkey)>>p2.first]++;			
	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	//ckout<<"Probe Size : "<<probeSize<<endl;
	for (int i = 0; i < probeSize; i++)
		longhistCounts[i] = histCounts[i];

	this->contribute((probeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key>::Histogram(NULL), sorter_proxy));
}




template <class key>
void Bucket<key>::firstLocalProbe(int _lastProbeSize){
	memcpy(lastProbe, finalSplitters, nBuckets * sizeof(key));
	CkAssert(_lastProbeSize == nBuckets);
	lastProbeSize = _lastProbeSize;
	localProbe();
}




template <class key>
void Bucket<key>::localProbe(){
	double c1 = CmiWallTimer();
	assert(lastProbeSize);
	memset(histCounts, 0, lastProbeSize * sizeof(int));
	if(lastSortedChunk > 0){
		int cumCount = 0;
		key comp;
		int prb = -1;
		do{
			prb++;
			comp = lastProbe[prb];
			histCounts[prb] = std::lower_bound(bucket_data + cumCount,
					bucket_data + sepCounts[lastSortedChunk], comp) - bucket_data;
			histCounts[prb] -= cumCount;
			cumCount += histCounts[prb];
		}while(prb<lastProbeSize-1 && (lastProbe[prb] < sepKeys[lastSortedChunk]));
	}

	//ckout<<"Time taken in sorted Histogramming at "<<CkMyPe()<<" : "<<CmiWallTimer()-c1<<endl;

	//ckout<<" LastProbeSize "<<lastProbeSize<<" : "<<CkMyPe()<<endl;
	//ckout<<" Hist Count on "<<CkMyPe()<<" --- "<<lastSortedChunk<<endl;
	//for (int i = 0; i < lastProbeSize; i++)
	//	ckout<<" Hist Count on "<<CkMyPe()<<" - "<<histCounts[i]<<" : "<<lastProbe[i]<<" : "<<lastProbeSize<<endl; 

	if(lastSortedChunk < numChunks){
		//buildIndex : !Change this to for division by 2
		key currmin = mymin;
		if(sepCounts[lastSortedChunk]>0){
			currmin = bucket_data[sepCounts[lastSortedChunk]-1];
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
			//int index = (bucket_data[i] - currmin)/indexStep;
			int index = (bucket_data[i] - currmin)>>indexStepLog;
			int ind = indices[index];
			ind = std::lower_bound(lastProbe + ind, 
				lastProbe + indices[index+1] + 1, bucket_data[i]) - lastProbe;
			while(bucket_data[i] == lastProbe[ind] && ind<lastProbeSize-1)
 				ind++;
 			//ckout<<i<<" **** "<<bucket_data[i]<<" ------- "<<ind<<" & Index: "<<index<<" & "<<indices[index]<<" & "<<indexStep<<" & "<<currmin<<" - "<<CkMyPe()<<endl;
 			//assert(bucket_data[i] < lastProbe[ind]);
			histCounts[ind]++;			
		}
		//ckout<<"Elements Scanned : "<<numElem - sepCounts[lastSortedChunk]<<" "<<CkMyPe()<<endl;
	}

	//use 64-bit in reduction since total histogram might surpass 32-bit limit
	for (int i = 0; i < lastProbeSize; i++)
		longhistCounts[i] = histCounts[i]; 

	for (int i = 0; i < lastProbeSize; i++){
		longhistCounts[i] = histCounts[i]; 
		//CkPrintf("[%d] histogram[lastProbe[%lu]: %lu\n", CkMyPe(), lastProbe[i], longhistCounts[i]);
	}

	//ckout<<" Hist Count on "<<CkMyPe()<<" --- "<<lastSortedChunk<<endl;
	this->contribute((lastProbeSize)*sizeof(uint64_t), longhistCounts, sum_uint64_t_type, 
		CkCallback(CkIndex_Sorter<key>::Histogram(NULL), sorter_proxy));
	double c2 = CmiWallTimer();
	//ckout<<"Time taken in Histogramming at "<<CkMyPe()<<" : "<<c2-c1<<endl;
}

template <class key>
void Bucket<key>::genNextSamples(sampleMessage<key> *sm){
	//ckout<<"Generating samples now:#"<<sm->nIntervals<<" - "<<CkMyPe()<<endl;

	bool flag =  (achieved[this->thisIndex] &&  achieved[this->thisIndex+1]);
	for(int i=0; i<sm->num_newachv; i++){
		finalSplitters[sm->newachv_id[i]] = sm->newachv_key[i];
		//ckout<<"#"<<i<<": "<<pm->newachv_id[i]<<" : "<< pm->newachv_key[i]<<" achieved?"<<(bool)achieved[pm->newachv_id[i]]<<" - "<<CkMyPe()<<endl;
		assert(achieved[sm->newachv_id[i]] == false);
		achieved[sm->newachv_id[i]] = true;
		achievedCounts[sm->newachv_id[i]] = sm->newachv_count[i];
	}
	achievedSplitters += sm->num_newachv;
	/*** Undo ***/
	//partialSend(sm);

	//ckout<<"achievedSplitters: "<<achievedSplitters<<" - "<<CkMyPe()<<endl;
	if(achievedSplitters == nBuckets+1){
		//ckout<<"Splitters have been determined  - toSend.size(): "<<toSend.size()<<" - "<<CkMyPe()<<endl;
		//ckout<<"callPartialSendOne: "<<callPartialSendOne<<" - "<<CkMyPe()<<endl;	
		doneHists = true;
		//callPartialSendOne = true;
		//partialSendOne();
		sendAll();
		//this->contribute(CkCallback(CkIndex_Sorter<key>::Done(NULL), sorter_proxy));
		return;
		//Not required, I think
		if(lastSortedChunk == numChunks && numSent == nBuckets)
			MergingWork();
		if(mergingDone){
			postMerging();
		}
		return;
	}


	
	//array_msg<key> *sample = new (am->numElem) array_msg<key>;
	std::vector<key> samples;
	typedef std::chrono::high_resolution_clock myclock;
	static myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();

  //int sampleSize = ceil((sampleSizePerPe() * achievedSplitters) / (sm->f * nBuckets));
  int sampleSize = ceil(sampleSizePerPe() / sm->f);

	seed = (sampleSize * CkMyPe());
	//ckout<<"Seed is "<<seed<<endl;
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0,numElem-1);
	distribution(generator);
	
	for(int i=0; i<sampleSize; i++){
		int randIndex = distribution(generator);
		key k = bucket_data[randIndex]; 
		int l = std::lower_bound(sm->lb, sm->lb + sm->nIntervals, k) - (sm->lb+1);
		int u = std::upper_bound(sm->ub, sm->ub + sm->nIntervals, k) - (sm->ub+1);
		//ckout<<"randIndex: "<<randIndex<<", l: "<<l<<", u: "<<u<<", k: "<<k<<endl;
		//ckout<<l<<" "<<u<<endl;
		if(l != u){
			//ckout<<"Found a key!: "<<k<<endl;
			samples.push_back(k);
		}
		//distribution.reset();
	}
	//ckout<<"Sample size for next round: "<<samples.size()<<"/"<<sampleSize<<" - "<<CkMyPe()<<endl;
	nodemgr[CkMyNode()].assembleSamples(samples);
}



template <class key>
void Bucket<key>::histCountProbes(probeMessage<key> *pm){
	numProbes++;
	bool flag =  (achieved[this->thisIndex] &&  achieved[this->thisIndex+1]);
	for(int i=0; i<pm->num_newachv; i++){
		finalSplitters[pm->newachv_id[i]] = pm->newachv_key[i];
		//ckout<<"#"<<i<<": "<<pm->newachv_id[i]<<" : "<< pm->newachv_key[i]<<" achieved?"<<(bool)achieved[pm->newachv_id[i]]<<" - "<<CkMyPe()<<endl;
		assert(achieved[pm->newachv_id[i]] == false);
		achieved[pm->newachv_id[i]] = true;
		achievedCounts[pm->newachv_id[i]] = pm->newachv_count[i];
	}
	achievedSplitters += pm->num_newachv;
	lastProbeSize = pm->probeSize;
	memcpy(lastProbe, pm->probe, lastProbeSize * sizeof(key));

	if(flag != (achieved[this->thisIndex] &&  achieved[this->thisIndex+1])){
			startMergingWork = true;
			mergingDone = false;
			//if(lastSortedChunk == numChunks)
			//	this->thisProxy[this->thisIndex].MergingWork();
	}
	
	if(lastProbeSize > 1)
		localProbe();
	else
		doneHists = true;

	/*** Undo ***/
	//partialSend(pm);


	if(lastProbeSize <= 1){
		ckout<<"Splitters have been determined  - "<<CkMyPe()<<endl;	
		//sendAll();
		this->contribute(CkCallback(CkIndex_Sorter<key>::Done(NULL), sorter_proxy));
		return;
		//Not required, I think
		//if(lastSortedChunk == numChunks && numSent == nBuckets)
		//	MergingWork();
		if(mergingDone){
			postMerging();
		}

	}
	delete(pm);
}




//assumes all splitters have been achieved and local sorting is complete
template <class key>
void Bucket<key>::sendAll(){
	//randomize it
	int prev = 0;
	for(int i = 1; i <= nBuckets; i++){
		//better randomization
		int bkt = (i + this->thisIndex)%nNodes + 1; 
		key sep1 = finalSplitters[bkt-1];
		key sep2 = finalSplitters[bkt];
		//find keys and send
		key comp;
		comp = sep1;
		int ind1 = std::lower_bound(bucket_data + prev,
					bucket_data + numElem, comp) - bucket_data;
		comp = sep2;
		int ind2 = std::lower_bound(bucket_data + prev,
					bucket_data + numElem, comp) - bucket_data;
		//ckout<<"Sending ["<< this->thisIndex<<"] "<<ind1<<"-"<<ind2<<" to "<<bkt-1<<endl;
		nodemgr[CkMyNode()].loadkeys(bkt-1, sendInfo(bucket_data, ind1, ind2));
/*
		data_msg<key> *dm = new (ind2-ind1) data_msg<key>;
		memcpy(dm->data, bucket_data + ind1, (ind2-ind1)*sizeof(key));
		dm->num_vals = ind2-ind1;
		dm->sorted = true;
		this->thisProxy[bkt-1].Load(dm);
		numSent++;
*/
	}
}



template <class key>
void Bucket<key>::recvFinalKeys(int srcnode, sendInfo s){
	recvData.push_back(s);
	if(recvData.size() == CkNumNodes()){
		int out_num = 0;
		for(int i=0; i<recvData.size(); i++)
			out_num += recvData[i].ind2 - recvData[i].ind1;
		key *out_data = new key[out_num];
		int prev = 0;
		for(int i=0; i<recvData.size(); i++){
			int n = recvData[i].ind2 - recvData[i].ind1;
			//CkPrintf("[%d] recvFinalKeys, size: %d \n", CkMyPe(), n);
			void *base = (void *)(((char *)recvData[i].base) + sizeof(key) * recvData[i].ind1);
			memcpy(out_data + prev, base, n * sizeof(key));
			prev += n;
		}
		std::sort(out_data, out_data + out_num);
		//ckout<<" Finished sorting, out_elems: "<<out_num<<" - "<<CkMyPe()<<endl;
		//for(int i=0; i<out_num; i++){
		//	ckout<<"out_data["<<i<<"]: "<<out_data[i]<<" : "<<CkMyPe()<<endl;
		//}
		*dataOut = out_data;
		*out_elems = out_num;	
		postMerging();
	}
}









template <class key>
void Bucket<key>::partialSend(sampleMessage<key> *sm){
	//randomize it
	for(int ti=0,i; ti<sm->num_newachv; ti++){
		i = (ti + this->thisIndex)%sm->num_newachv;
		for(int bkt = sm->newachv_id[i]; bkt<= sm->newachv_id[i]+1 && bkt<=nBuckets; bkt++){
			assert(bkt>0);
			if(!sent[bkt] && achieved[bkt] && achieved[bkt-1]){
				toSend.push_back(bkt);
				sent[bkt] = true;
				if(callPartialSendOne){
					CmiAbort("callPartialSendOne is not initialized");
					this->thisProxy[this->thisIndex].partialSendOne();
					callPartialSendOne = false;
				}
			}
		}
	}
}



template <class key>
void Bucket<key>::partialSendOne(){

	assert(!toSend.empty());

	int bkt = toSend.back();


	if(bkt == 0){
		ckout<<"wtf: "<<toSend.size()<<endl;
		ckout<<numChunks<<" : "<<mymax<<" : "<<" : "<<sepKeys[numChunks]<<" ! ";
		ckout<<" for "<<bkt<<" - "<<CkMyPe()<<endl;
	}

	toSend.pop_back();

	//find what all chunks it belongs to
	key sep1 = finalSplitters[bkt-1];
	key sep2 = finalSplitters[bkt];
	int chunk1 = std::upper_bound(sepKeys, sepKeys + numChunks + 1, sep1) - sepKeys - 1;
	int chunk2 = std::lower_bound(sepKeys, sepKeys + numChunks + 1, sep2) - sepKeys;


	if(bkt == 0 || bkt == 144){
		ckout<<numChunks<<" : "<<mymax<<" : "<<sep1<<" ;; "<<sep2<<" : "<<sepKeys[numChunks]<<" ! ";
		ckout<<chunk1<<" ;';';';'; "<<chunk2<<" for "<<bkt<<" - "<<CkMyPe()<<endl;
	}


	//sort those chunks if not already sorted
	for(int c = chunk1+1; c <= chunk2; c++){
		if(!sorted[c]){
			std::sort(bucket_data + sepCounts[c-1], 
			bucket_data + sepCounts[c]);
			sorted[c] = true;
			//use this sorted chunk to optimize computations in localProbe
			assert(false); //HSS should not come here since everything is sorted before 1st round
			ckout<<chunk1<<" ;';';';'; "<<chunk2<<" for "<<bkt<<" - "<<CkMyPe()<<endl;
		}
	}

	//find keys and send
	key comp;
	comp = sep1;
	int ind1 = std::lower_bound(bucket_data + sepCounts[chunk1],
		bucket_data + sepCounts[chunk2], comp) - bucket_data;
	comp = sep2;
	int ind2 = std::lower_bound(bucket_data + sepCounts[chunk1],
		bucket_data + sepCounts[chunk2], comp) - bucket_data;
	//ckout<<"Sending "<<ind1<<"-"<<ind2<<" to "<<bkt<<" from "<<this->thisIndex<<endl;
	data_msg<key> *dm = new (ind2-ind1) data_msg<key>;
	memcpy(dm->data, bucket_data + ind1, (ind2-ind1)*sizeof(key));
	dm->num_vals = ind2-ind1;
	dm->sorted = true;
	this->thisProxy[bkt-1].Load(dm);
	numSent++;
	if(!toSend.empty()){
		if(!doneHists)
			this->thisProxy[this->thisIndex].partialSendOne();
		else
			partialSendOne();
	}
	else{
		callPartialSendOne = true;
		if(lastSortedChunk == numChunks && !mergingDone && startMergingWork && numSent == nBuckets)
			this->thisProxy[this->thisIndex].MergingWork();
	}
}





template <class key>
void Bucket<key>::Load(data_msg<key>* msg){
	//ckout<<"Data Message received - "<<CkMyPe()<<endl;
	//ckout<<"lastSortedChunk: "<<lastSortedChunk<<" , "<<numChunks<<" noMergingWork: "<<noMergingWork<<endl;

	recvd++;

	for(int i = 0; i < msg->num_vals; i++)
		tsum += (int)(msg->data[i] % 1009);

	if(recvd == nBuckets){
		//ckout<<"contributing: "<<tsum<<" : recvd:"<<recvd<<" - "<<CkMyPe()<<endl;
		this->contribute(sizeof(int), &tsum, CkReduction::sum_int,
			CkCallback(CkIndex_Main<key>::intermediate_isum(NULL),main_proxy));
	}

	incomingMsgBuffer.push_back(msg);
	if(noMergingWork && lastSortedChunk==numChunks){
		noMergingWork = false;
		this->thisProxy[this->thisIndex].MergingWork();
	}
}



template <class key>
void Bucket<key>::MergingWork(){

	//CkPrintf("[%d] MergingWork, mergingDone: %d \n", CkMyPe(), mergingDone);

	if(mergingDone) return;

	noMergingWork = false;
	if(firstMergingWork){
		//ckout<<"Merging Begins - "<<CkMyPe()<<endl;
		//ckout<<*out_elems<<" LLL  - "<<CkMyPe()<<endl;
		
		*out_elems = achievedCounts[this->thisIndex+1] - achievedCounts[this->thisIndex];	
		*dataOut = new key[*out_elems];
		scratch = new key[(*out_elems)/2];
		//firstUsed = *out_elems;
		lastUsed = 0;
		firstMergingWork = false;
		totalmerge = false;
	}
	
	else if(lastSortedChunk == numChunks && toSend.empty()){
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
			data_msg<key>* msg = incomingMsgBuffer.back();
			incomingMsgBuffer.pop_back();
			//ckout<<" ;;;* "<<CkMyPe()<<" : "<<msg->num_vals<<" ;;; "<< firstUsed <<endl;
			if(!msg->sorted){
				std::sort(msg->data, msg->data + msg->num_vals);
				msg->sorted = true;
			}
			lb_struct<key> lb;
			lb.numVals = msg->num_vals;
			lb.start = lastUsed;
			lb.msg = msg;
			loadBuffer.push_back(lb);
			lastUsed += msg->num_vals;
			received++;
			if(received == nBuckets){
				totalmerge = true;
				//ckout<<"totalmerge: "<<endl;
			}
			//ckout<<"incomingMsgBuffer - "<<incomingMsgBuffer.size()<<" - "<<CkMyPe()<<endl;
	    }
	    else if(totalmerge){

	    	if(loadBuffer.size() == 1  && loadBuffer[0].msg != NULL){
	    		*dataOut = loadBuffer[0].msg->data;
	    	}

			mergingDone = true;
			//ckout<<"Total Merge over -"<<CkMyPe()<<endl;
			//ckout<<*out_elems<<" : "<<doneHists<<" Done at "<<CkMyPe()<<endl;
			if(doneHists){
				postMerging();
			}
			return;	
		}
		else{ //Nothing happened
			//ckout<<"Nothing happened "<<CkMyPe()<<endl;
			noMergingWork = true;
		}
	}
    if(!noMergingWork && lastSortedChunk==numChunks && toSend.empty()){
		//if(doneHists) MergingWork();
		if(doneHists && numSent==nBuckets)
			MergingWork();
		else //if no partial sends
			this->thisProxy[this->thisIndex].MergingWork();
		//else
		//	callMergingWork = true;
	}
}



template <class key>
void Bucket<key>::postMerging(){
	#if VERBOSE
		key *finalData = (key*)*dataOut;
		double sum = 0; int keysum = 0;
		for(int i = 0; i < *out_elems; i++)
			keysum += (int)(finalData[i] % 1009);
		this->contribute(sizeof(int), &keysum, CkReduction::sum_int,
			CkCallback(CkIndex_Main<key>::final_isum(NULL),main_proxy));
		//printf("%d ** KeySum %lu Sum %lf\n",CkMyPe(),keysum, sum);
	#endif
	//for(int i=0; i<*out_elems; i++)
	//	ckout<<loadBuffer[0]->data[i]<<" : ";
	//uint64_t cnt = achievedCounts[this->thisIndex+1] - achievedCounts[this->thisIndex];
	//ckout<<*out_elems<<"  "<<dummyCount<<"  "<<dummyCount2<<" Done at "<<"  "<<CkMyPe()<<endl;
	/** !TODO **/
	//if(callBackSet)
	//	CB->send();
	#ifndef VERBOSE
	this->contribute(CkCallback(CkIndex_Sorter<key>::Done(NULL), sorter_proxy));
	#endif
}




template <class key>
void Bucket<key>::finish(){
	this->contribute(CkCallback(CkIndex_Sorter<key>::Done(NULL), sorter_proxy));
}



//merge loadBuffers[n] & loadBuffers[n+1]
template <class key>
void Bucket<key>::mergeAt(int n){

	key *finalData = (key*)*dataOut;	      	

	//if the first one is a msg
	if(loadBuffer[n].msg != NULL){
		key* first2;
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
				sizeof(key)*loadBuffer[n].numVals);
		forward_merge(  scratch,
						scratch + loadBuffer[n].numVals, 
						finalData + loadBuffer[n+1].start,
						finalData + loadBuffer[n+1].start + loadBuffer[n+1].numVals,
						finalData + loadBuffer[n].start  
					 );
	}
	//none of them are msgs, second one smaller
	else{
		memcpy(scratch, finalData + loadBuffer[n+1].start,
				sizeof(key)*loadBuffer[n+1].numVals);
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

	lb_struct<key> lb;
	lb.start = loadBuffer[n].start;
	lb.numVals = loadBuffer[n].numVals + loadBuffer[n+1].numVals;
	lb.msg = NULL;
	loadBuffer[n] = lb;
	dummyCount2 += loadBuffer[n].numVals;
	loadBuffer.erase(loadBuffer.begin()+n+1);
}


template <class key>
void Bucket<key>::forward_merge(key *first1, key *last1,
								 		key *first2, key *last2,
								    	key *result){
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


template <class key>
void Bucket<key>::backward_merge(key *first1, key *last1,
										key *first2, key *last2, key *result){
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


