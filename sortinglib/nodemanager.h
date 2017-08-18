#ifndef __NODEMANAGER_H__
#define __NODEMANAGER_H__

#include <chrono>
#include <random>
#include <queue>
#include <unistd.h>
#include <climits>
#include <map>


extern uint64_t getRandom(); 


unsigned getRandomSeed(){
  typedef std::chrono::high_resolution_clock myclock;
  myclock::time_point beginning = myclock::now();
  myclock::duration d = myclock::now() - beginning;
  return d.count();
}


const int SAMPLE_FACTOR = 1;


const int SAMPLE_FACTOR_MULTIPLIER = 1;

#define LS_EPS 5

int maxSampleSize(){
	int numprocs = CkNumPes(), numpes = CkNodeSize(CkMyNode()), lognprocs=1;
	while((1<<lognprocs) <= numprocs) lognprocs++;
	return SAMPLE_FACTOR * SAMPLE_FACTOR_MULTIPLIER * numprocs;
}

int sampleSizePerNode(){
	int numproc = CkNumPes();
	int lognprocs = 1, numpes = CkNodeSize(CkMyNode());
	while((1<<lognprocs) <= numproc) lognprocs++;
	return SAMPLE_FACTOR * SAMPLE_FACTOR_MULTIPLIER * numpes;
}

int sampleSizePerPe(){
	return SAMPLE_FACTOR * SAMPLE_FACTOR_MULTIPLIER;
}

int ls_getStride(){
	uint64_t elemsPerPe = numTotalElems/CkNumPes();
	elemsPerPe += ((elemsPerPe * EPS * 2)/100);
	return std::max(1, (int)(((double)elemsPerPe * LS_EPS)/(CkNumNodes() * 100)));
}



/* For random sampling */
int ls_getMaxSampleSize(){
  int lognpes = 1, numpes = CkNodeSize(CkMyNode());
  while((1<<lognpes) <= numpes) lognpes++;
  return std::max(CkNumNodes()+2, (3 * lognpes * numpes * 100)/LS_EPS);
}


int ls_getSampleSize(int locElems){
	uint64_t elemsPerNode = numTotalElems/CkNumNodes();
	elemsPerNode += ((elemsPerNode * EPS * 2)/100);
	return std::max(1, (int)(((uint64_t)ls_getMaxSampleSize() * (uint64_t)locElems)/elemsPerNode));
}




/*  For Regular sampling
int ls_getMaxSampleSize(){
  uint64_t stride = ls_getStride();
	uint64_t elemsPerNode = numTotalElems/CkNumNodes();
	elemsPerNode += ((elemsPerNode * EPS * 2)/100);
	int sampleSize = elemsPerNode/stride;
   return sampleSize + 2; //for the last one
}

int ls_getSampleSize(int locElems){
	return locElems/ls_getStride();
}
*/



class wrap_ptr{
public:
	void *ptr;
	wrap_ptr() {} 
	wrap_ptr(void *_ptr): ptr(_ptr) {}
	void pup(PUP::er &p){
		pup_bytes(&p, this, sizeof(*this));
	}
};

class sampleInfo{
public:
	int size;
	int *indices;
	void *dest;
	int offset;
	sampleInfo() {}
	sampleInfo(int _size, int *_indices, void *_dest, int _offset): 
		size(_size), indices(_indices), dest(_dest), offset(_offset){}
	void pup(PUP::er &p){
		pup_bytes(&p, this, sizeof(*this));
	}
};



class sendInfo{
	public:
		int ind1, ind2;
		void* base;
		sendInfo() {}
		sendInfo(void *_base, int _ind1, int _ind2) : base(_base), ind1(_ind1), ind2(_ind2) {}
		void pup(PUP::er &p){
			pup_bytes(&p, this, sizeof(*this));
		}
};


template<class key>
class sortItem{
public:
	key k;
	short int peId;
   sortItem(key _k, short int _peId): k(_k), peId(_peId) {}
   friend bool operator<(const sortItem<key>& a, const sortItem<key>& b){
	   return (a.k > b.k); //emulate min heap
   }
};





template <class key>
class NodeManager : public CBase_NodeManager<key> {
	private:
		int numnodes;
		int numpes;
		int* pelist;
		int* numElem;
		int sampleSize;
		CProxy_Sorter<key> sorter;
		CProxy_Bucket<key> bucket_arr;
		array_msg<key> *sample;
		tagged_key<key> *nodeSample;
		key minkey, maxkey;
		int samplesRcvd, sampleMsgsRcvd;
		int numSent, numRecvd, numFinished;
		tagged_key<key>* ls_sample; //ls_ :: localsort
		tagged_key<key>* splitters;
		int ls_numTotSamples;
		int numDeposited;
		uint64_t numElemFinal;
		int stride;
		//assemble info
		std::vector<std::vector<sendInfo> > ainfo;
		std::vector<data_msg<key> *> recvdMsgs;
		std::vector<data_msg<key> *> bufMsgs;
		std::map<int, uint64_t*> histLocCounts; //one for each pe
		uint64_t* finalHistCounts;

		Bucket<key>* getLocalBucket(){
			for(int i=0; i<numpes; i++){
				Bucket<key> *obj = bucket_arr[pelist[i]].ckLocal();
				if(obj != NULL) return obj;
			}
			CkAbort("GetLocalBucket, getLocalBucket not found \n");
		}


	public:
		NodeManager(key _minkey, key _maxkey): minkey(_minkey), maxkey(_maxkey){
			//ckout<<"Node Manager created at "<<CkMyNode()<<endl;
			numnodes = CkNumNodes();
			numpes = CkNodeSize(CkMyNode());
			numElem = new int[numpes];
			pelist = new int[numpes];
			splitters = new tagged_key<key>[numpes];
			nodeSample = new tagged_key<key>[sampleSizePerNode() * 10]; //allocate extra, just in case
			ainfo.resize(CkNumPes());
			numRecvd = numFinished = numDeposited = numSent = 0;
			ls_numTotSamples=0;
			numElemFinal=0;
			sampleMsgsRcvd=0;
		}

		void registerLocalChare(int nElem, int pe, CProxy_Bucket<key> _bucket_arr,
				CProxy_Sorter<key> _sorter){
			//ckout<<"registerLocalchare called from PE "<<pe<<" at "<<CkMyNode()<<endl;
			//ckout<<"numnodes :"<<numnodes<<" numpes:"<<numpes<<endl;
			//!This should be a bucket_proxy ID
			bucket_arr = _bucket_arr;
			sorter = _sorter;
			static int currnpes = 0;
			pelist[currnpes] = pe;
			numElem[currnpes++] = nElem;
			if(currnpes == numpes){ //all PE's registered
				sampleSize = sampleSizePerNode();
				//ckout<<"sample size: "<<sampleSize<<endl;
				genSampleIndices();
			}
		}

		//call this function
		void genSampleIndices(){
			int *randIndices = new int[sampleSize];
			int cum = numElem[0];
			for(int i=1; i<numpes; i++)
				cum += numElem[i]; 

			unsigned seed = getRandomSeed();
			seed = CkMyNode();
			//ckout<<"Seed is "<<seed<<endl;

			//std::default_random_engine generator(seed);
			//std::uniform_int_distribution<int> distribution(0,cum-1);

			//distribution(generator);

			for(int i=0; i<sampleSize; i++){
				//randIndices[i] = distribution(generator); 
				randIndices[i] = getRandom()%cum; 
				//ckout<<"randIndices "<<randIndices[i]<<endl;
				//distribution.reset();
			}

			sample= new (sampleSize) array_msg<key>;
			sample->numElem = sampleSize;

			std::sort(randIndices, randIndices + sampleSize);
			int cumIndex = 0, cumFreq = 0;
			samplesRcvd = 0;
			for(int i=0; i<numpes; i++){
				int ub = std::upper_bound(randIndices + cumIndex, 
						randIndices + sampleSize, cumFreq + numElem[i]) - randIndices;   
				//send  randIndices[cumIndex, ub) - cumFreq to PE pelist[i]
				sampleInfo sI(ub-cumIndex, randIndices+cumIndex, sample->data + cumIndex, cumFreq);
				/*
				array_msg<int> *am = new (ub-cumIndex) array_msg<int>;
				am->numElem = ub-cumIndex;
				for(int j=0; j<am->numElem; j++){
					am->data[j] = randIndices[cumIndex+j] - cumFreq;
				}
				*/
				//ckout<<"Sending randIndices["<<cumIndex<<","<<ub<<") - ";
				//ckout<<cumFreq<<" to PE "<<pelist[i]<<" dest: "<<sI.dest<<endl;
				bucket_arr[pelist[i]].genSample(sI);
				cumIndex = ub;
				cumFreq += numElem[i];
			}
		}

		void collectSamples(sampleInfo sI){
			static int count = 0;

			//memcpy(sample->data + samplesRcvd, s->data, s->numElem * sizeof(key));
			samplesRcvd += sI.size;
			count++;
			//can enter here twice, check on the basis of number of msgs received
			if(count == numpes){
				//ckout<<"Sending ******************* to Sorter ************** size: "<< sample->numElem << "from "<<CkMyNode()<<endl;
				//for(int i=0; i<sample->numElem; i++)
				//	ckout<<"From nodemgr "<<CkMyNode()<<" : "<<sample->data[i]<<endl;
				sorter.recvSample(sample);
				samplesRcvd = 0;
			}
		}


		void assembleSamples(std::vector<tagged_key<key> > proc_sample){
			sampleMsgsRcvd++;
			for(int i=0; i<proc_sample.size(); i++){
				nodeSample[i+samplesRcvd] = proc_sample[i];
			}
			samplesRcvd += proc_sample.size();
			if(sampleMsgsRcvd == numpes){
				//ckout<<"All samples received #"<<samplesRcvd<<", maxSampleSize: "<<sampleSizePerNode()<<" - "<<CkMyNode()<<endl;
				sample= new (samplesRcvd) array_msg<key>;
				sample->numElem = samplesRcvd;
				memcpy(sample->data, nodeSample, samplesRcvd*sizeof(tagged_key<key>));
				sorter.recvSample(sample);
				samplesRcvd = 0;
				sampleMsgsRcvd = 0;
			}
		}
		


		void loadkeys(int dest, sendInfo inf){
			ainfo[dest].push_back(inf);   //This will cause synchronization problems.	
			if(ainfo[dest].size() == numpes){
				numSent++;
				this->thisProxy[CkMyNode()].sendOne(dest);
				if(numSent == CkNumNodes())
					this->thisProxy[CkMyNode()].releaseBufMsgs();
			}
		}

		void sortCopyMsg(data_msg<key> *dm,  int dest){
			std::priority_queue<sortItem<key> > heap;
 			CkAssert(ainfo[dest].size() == numpes);
			int first[numpes]; //first element which is not in heap
			for(int i=0; i<ainfo[dest].size(); i++){
				first[i] = ainfo[dest][i].ind1;
				if(first[i] <  ainfo[dest][i].ind2){//not empty
					key* bucket_data = (key*)ainfo[dest][i].base;
					heap.push(sortItem<key>(bucket_data[first[i]], i));
					first[i]++;
				}
			}
			for(int i=0; i<dm->num_vals; i++){
				sortItem<key> sI = heap.top();
				heap.pop();
				key* bucket_data = (key*)ainfo[dest][sI.peId].base;
				dm->data[i] = bucket_data[first[sI.peId] - 1];
				if(first[sI.peId] <  ainfo[dest][sI.peId].ind2){//not empty
               heap.push(sortItem<key>(bucket_data[first[sI.peId]], sI.peId));
					first[sI.peId]++;
				}
			}
		}

		

		void sendOne(int dest){
			//CkPrintf("[%d][%d] sendOne to node: %d \n", CkMyNode(), CkMyPe(), dest);
			int numelem = 0;
			for(int i=0; i<ainfo[dest].size(); i++)
				numelem += ainfo[dest][i].ind2 - ainfo[dest][i].ind1;
			data_msg<key> *dm = new (numelem) data_msg<key>;
			dm->num_vals = numelem;

			//sortCopyMsg(dm, dest);
			//dm->sorted = true;


			dm->sorted = false;
			int curr = 0;
			for(int i=0; i<ainfo[dest].size(); i++){
				int ind1 = ainfo[dest][i].ind1, ind2 = ainfo[dest][i].ind2;
				key* bucket_data = (key*)ainfo[dest][i].base;
				memcpy(dm->data + curr, bucket_data + ind1, (ind2-ind1)*sizeof(key));
				curr += ind2 - ind1;
			}
      //std::sort(dm->data, dm->data + dm->num_vals);
      //dm->sorted = true;

			this->thisProxy[dest].recvOne(dm);
		}


		void releaseBufMsgs(){
			for(int i=0; i<bufMsgs.size(); i++)
				recvOne(bufMsgs[i]);
				//this->thisProxy[CkMyNode()].recvOne(bufMsgs[i]); //not required
			bufMsgs.clear();
		}


		void recvOne(data_msg<key> *dm){
			//CkPrintf("[%d] message received of size: %d \n", CkMyNode(), dm->num_vals);
			//for(int i=0; i<dm->num_vals; i++)
			//	ckout<<"message  "<<i<<" : "<<dm->data[i]<<endl;
			if(numSent != CkNumNodes()){
				bufMsgs.push_back(dm);
				return;
				CkAbort("Haven't sent all messages yet");
			}
				
			if(recvdMsgs.size() == 0){
				Bucket<key> *obj = getLocalBucket();
				obj->setTotalKeys();
				stride = ls_getStride();
				numElemFinal = 0;
				//ckout<<" ["<<CkMyNode()<<"] bucket obj : "<<obj<<"   pelist[0]: "<< pelist[0]<<" "<<numTotalElems<<" ls_getMaxSampleSize: "<<ls_getMaxSampleSize()<<" stride: "<<stride<<endl;
				ls_sample = new tagged_key<key>[ls_getMaxSampleSize()];	
			}
			int numsamples = ls_getSampleSize(dm->num_vals);
			numElemFinal += dm->num_vals;
			recvdMsgs.push_back(dm);
			ls_numTotSamples += numsamples;
			if(ls_numTotSamples >= ls_getMaxSampleSize()) {
				CkPrintf("[%d] ls_numTotSamples: %d, ls_MaxSampleSize: %d, stride: %d, numElemFinal: %lu, numsamples: %d, msg_size: %d\n",
							CkMyNode(), ls_numTotSamples, ls_getMaxSampleSize(), ls_getStride(), numElemFinal, numsamples, dm->num_vals);
				CmiAbort("Sample size exceeds expectations");
			}
			//CkPrintf("[%d, %d] Calling handleOne, dm->num_vals: %d, ind: %d, sampleInd: %d, numsamples: %d\n", CkMyNode(), CkMyPe(), dm->num_vals, recvdMsgs.size()-1, ls_numTotSamples - numsamples, numsamples);	
			this->thisProxy[CkMyNode()].handleOne(wrap_ptr(dm), ls_numTotSamples - numsamples, numsamples, recvdMsgs.size()-1);
			++numRecvd;
			//if(numRecvd == CkNumNodes())
			//	CkPrintf("[%d] Received all messages \n", CkMyNode());
		}


		void handleOne(wrap_ptr msg, int sampleInd, int numsamples, int msgnum){
			//this->thisProxy[CkMyNode()].finishOne();
			//return;
			data_msg<key> *dm = (data_msg<key> *)msg.ptr;
			//CkPrintf("[%d, %d]handleOne,  numSamples: %d, msgsize: %d, sampleInd: %d, maxSamplesize: %d \n", CkMyNode(), CkMyPe(), numsamples, dm->num_vals, sampleInd, ls_getMaxSampleSize());

			if(!dm->sorted)
				std::sort(dm->data, dm->data + dm->num_vals);


/****** Random Sample *******  ===> use for histogram */
      if(dm->num_vals > 0){
        unsigned seed = sampleInd;
        //ckout<<"Seed is "<<seed<<endl;
        /*
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> distribution(0,dm->num_vals-1);
        distribution(generator);
        */
        for(int i=0; i<numsamples; i++){
          //int randIdx = distribution(generator); 
          int randIdx = getRandom()%dm->num_vals; 
          ls_sample[sampleInd + i] = tagged_key<key>(dm->data[randIdx], msgnum, randIdx);
          //distribution.reset();
        }
        if(sampleInd+numsamples >= ls_getMaxSampleSize())
          CkAbort("Numsamples exceeds expectations\n"); 
      }


/****** Regular Sampling *******
			if(dm->num_vals > 0){
				for(int i=stride-1; i<dm->num_vals; i+=stride)
					ls_sample[sampleInd + (i/stride)] = tagged_key<key>(dm->data[i], msgnum, i);
				if(sampleInd+numsamples >= ls_getMaxSampleSize())
					CkAbort("Numsamples exceeds expectations\n"); 
			}
*/
			this->thisProxy[CkMyNode()].finishOne();
		}


		void finishOne(){
			++numFinished;	
			if(numFinished == CkNumNodes()){ //all messages have been received, processed
				
				//for(int i=0; i<numpes; i++){
				//	 bucket_arr[pelist[i]].finish();				
				//}
				//return;
				//CkPrintf("[%d] My elems: %d\n", CkMyNode(), numElemFinal);

				ls_sample[ls_numTotSamples++] = getTaggedMaxKey<key>(maxkey);
				std::sort(ls_sample, ls_sample + ls_numTotSamples); //sort all sampled keys
        /*
				int numpes = CkNodeSize(CkMyNode());
				uint64_t elemPerPe = numElemFinal/numpes;
				uint64_t threshold = (elemPerPe * LS_EPS)/100;
				
				for(int i=0; i<numpes-1; i++){
					uint64_t target = (elemPerPe * (i+1)) - threshold;
					int idx = target/stride;
					splitters[i] = ls_sample[idx];
				}
				splitters[numpes-1] = getTaggedMaxKey<key>(maxkey);
				std::sort(pelist, pelist + numpes);
				//for(int i=0; i<numpes; i++){
				//	CkPrintf("[%d] Splitterss #%d: %llu\n", CkMyNode(), i, splitters[i]);
				//}
				//CkPrintf("[%d] RecvdMsgs.size: %d\n", CkMyNode(), recvdMsgs.size());
				for(int i=0; i<recvdMsgs.size(); i++){
					//for(int j=0; j<recvdMsgs[i]->num_vals; j++)
					//	CkPrintf("[%d] recvdmsg[%d] #(%d): %llu\n", CkMyNode(), i, j, recvdMsgs[i]->data[j]);
					usleep(1000000);
					//this->thisProxy[CkMyNode()].sendToBuckets(recvdMsgs[i]);
					this->thisProxy[CkMyNode()].sendToBuckets(i);
				}
				//CkPrintf("[%d] Finished sorting, sampling from all messages \n", CkMyNode());
        */
        for(int i=0; i<numpes; i++){
            uint64_t* histCounts = new uint64_t[ls_numTotSamples+1];	
            std::fill(histCounts, histCounts + ls_numTotSamples + 1, 0);
            histLocCounts[pelist[i]] =  histCounts;
        }
        for(int i=0; i<recvdMsgs.size(); i++){
        	this->thisProxy[CkMyNode()].localhist(recvdMsgs[i]);
        }
			}
		}

		void localhist(data_msg<key>* dm){
		    uint64_t* histCounts = (histLocCounts.find(CkMyPe()))->second;
			//CkPrintf("localhist [%d, %d] histCounts: %p \n", CkMyNode(), CkMyPe(), histCounts);
			//for(int i=0; i<dm->num_vals; i++)
			//	CkPrintf("dm->val[%d]: %llu \n", i, dm->data[i]);	
			int cumCount = 0;
			tagged_key<key> comp;
			int prb = -1;
			do{
				prb++;
				comp = ls_sample[prb];
				int cnt = lower_bound_tagged(dm->data,
						dm->data + dm->num_vals, comp) - dm->data;
				histCounts[prb] += cnt - cumCount;
				cumCount = cnt;
			}while(prb<ls_numTotSamples-1);  //the second condition from Bucket.C is not necessary
			this->thisProxy[CkMyNode()].depositHist();
	  }

    //how will this be an entry method
    void depositHist(){
      numDeposited++;
      if(numDeposited == CkNumNodes()){
        int numHists = histLocCounts.size();
        uint64_t *histograms[numHists];
        std::map<int, uint64_t*>::iterator it;
        int i;
        for(i=0,it = histLocCounts.begin(); it != histLocCounts.end(); it++, i++)
          histograms[i] = it->second;
        uint64_t cum = 0;
        for(int i=0; i<ls_numTotSamples; i++){
          for(int j=1; j<numHists; j++)
            histograms[0][i] += histograms[j][i];
          cum += histograms[0][i];
          //if(!CkMyNode())
          //  CkPrintf("[%d] FinalHist[%llu]: %llu \n",  CkMyNode(), ls_sample[i], cum);
        }
        //CkPrintf("[%d] FinalHist: %llu, sample-size: %d \n",  CkMyNode(),  cum, ls_numTotSamples);
        finalHistCounts	= histograms[0];
        //CkPrintf("Deposited [%d] All localsort hists deposited \n", CkMyNode());

        //convert to cumulative counts
        for(int i=1; i<ls_numTotSamples; i++)
            finalHistCounts[i] += finalHistCounts[i-1];

        /* Finalize splitters : brute force*/
        int numpes = CkNodeSize(CkMyNode());
        uint64_t elemPerPe = numElemFinal/numpes;
        for(int i=0; i<numpes-1; i++){
          long long target = (elemPerPe * (i+1));
          //if(!CkMyNode())
          //    CkPrintf("#%d, target: %ld, elemPerPe: %llu \n", i, target, elemPerPe);
          int bestSpltr = -1;
          long long closest = LONG_MAX;
          for(int j=1; j<ls_numTotSamples; j++){
            long long dist = labs(target - ((long long)finalHistCounts[j]));
            if(dist < closest){
               closest = dist;
               bestSpltr = j;
            }
          }
          splitters[i] = ls_sample[bestSpltr];
        }
        splitters[numpes-1] = getTaggedMaxKey<key>(maxkey);
        std::sort(pelist, pelist + numpes);
        //if(!CkMyNode()){
        for(int i=0; i<numpes; i++){
        	//CkPrintf("[%d] Splitterss #%d: %llu\n", CkMyNode(), i, splitters[i]);
        }
        //}
        //Now distribute data among all local threads
        for(int i=0; i<recvdMsgs.size(); i++){
          //for(int j=0; j<recvdMsgs[i]->num_vals; j++)
          //	CkPrintf("[%d] recvdmsg[%d] #(%d): %llu\n", CkMyNode(), i, j, recvdMsgs[i]->data[j]);
          this->thisProxy[CkMyNode()].sendToBuckets(i);
        }
      }
	  }


	//void sendToBuckets(data_msg<key>* dm){
	void sendToBuckets(int msg_num){
    data_msg<key>* dm = recvdMsgs[msg_num];
		tagged_key<key> prev = getTaggedMinKey<key>(minkey);
		for(int i=0; i<numpes; i++){
      tagged_key<key> sep1 = prev;
      tagged_key<key> sep2 = splitters[i];
      //find keys and send
      tagged_key<key> comp;
      comp = sep1;
      int ind1 = lower_bound_tagged(dm->data,
          dm->data + dm->num_vals, comp, msg_num) - dm->data;
      comp = sep2;
      int ind2 = lower_bound_tagged(dm->data,
          dm->data + dm->num_vals, comp, msg_num) - dm->data;
      //if(!CkMyNode()){
      //  std::cout<<"Finalsending ["<< CkMyNode() <<"] "<<ind1<<"-"<<ind2<<" to "<<pelist[i]<< " - splitters:["<<sep1<<" , "<<sep2<<"]"<<std::endl;
      //}
      bucket_arr[pelist[i]].recvFinalKeys(i, sendInfo(dm->data, ind1, ind2));
      prev = splitters[i];
    }
	}

};

#endif
