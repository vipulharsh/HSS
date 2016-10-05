#ifndef __NODEMANAGER_H__
#define __NODEMANAGER_H__


const int SAMPLE_FACTOR = 20;

int maxSampleSize(){
	int lognnodes = 1, numnodes = CkNumNodes();
	while((1<<lognnodes) <= numnodes) lognnodes++;
	int sampleSize = (SAMPLE_FACTOR *  numnodes * lognnodes);
	return sampleSize + 2;
}


int sampleSizePerNode(){
	int lognnodes = 1, numnodes = CkNumNodes(), numpes = CkNodeSize(CkMyNode());
	while((1<<lognnodes) <= numnodes) lognnodes++;
	int sampleSize = (SAMPLE_FACTOR * lognnodes);
	return sampleSize;
}


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



template <class key, class value>
class NodeManager : public CBase_NodeManager<key, value> {
	private:
		int numnodes;
		int numpes;
		int* pelist;
		int* numElem;
		int sampleSize;
		CProxy_Sorter<key, value> sorter;
		CProxy_Bucket<key, value> bucket_arr;
		array_msg<key> *sample;
		int samplesRcvd;
		int numRecvd;
		//assemble info
		std::vector<std::vector<sendInfo> > ainfo;
		std::vector<data_msg<key, value> *> recvdMsgs;

	public:    
		NodeManager(){
			ckout<<"Node Manager created at "<<CkMyNode()<<endl;
			numnodes = CkNumNodes();
			numpes = CkNodeSize(CkMyNode());
			numElem = new int[numpes];
			pelist = new int[numpes];
			ainfo.resize(numnodes);
			numRecvd = 0;
		}

		void registerLocalChare(int nElem, int pe, CProxy_Bucket<key, value> _bucket_arr,
				CProxy_Sorter<key, value> _sorter){
			ckout<<"registerLocalchare called from PE "<<pe<<" at "<<CkMyNode()<<endl;
			//ckout<<"numnodes :"<<numnodes<<" numpes:"<<numpes<<endl;
			//!This should be a bucket_proxy ID
			bucket_arr = _bucket_arr;
			sorter = _sorter;
			static int currnpes = 0;
			pelist[currnpes] = pe;
			numElem[currnpes++] = nElem;
			int lognnodes = 1;
			while((1<<lognnodes) <= numnodes) lognnodes <<= 1;
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

			typedef std::chrono::high_resolution_clock myclock;
			myclock::time_point beginning = myclock::now();
			myclock::duration d = myclock::now() - beginning;
			unsigned seed = d.count();
			seed = CkMyNode();
			//ckout<<"Seed is "<<seed<<endl;

			std::default_random_engine generator(seed);
			std::uniform_int_distribution<int> distribution(0,cum-1);

			distribution(generator);

			for(int i=0; i<sampleSize; i++){
				randIndices[i] = distribution(generator); 
				//ckout<<"randIndices "<<randIndices[i]<<endl;
				distribution.reset();
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
				array_msg<int> *am = new (ub-cumIndex) array_msg<int>;
				am->numElem = ub-cumIndex;
				for(int i=0; i<am->numElem; i++){
					am->data[i] = randIndices[cumIndex+i] - cumFreq;
				}
				ckout<<"Sending randIndices["<<cumIndex<<","<<ub<<") - ";
				ckout<<cumFreq<<" to PE "<<pelist[i]<<endl;
				bucket_arr[pelist[i]].genSample(am);
				cumIndex = ub;
				cumFreq += numElem[i];
			}
		}

		void collectSamples(array_msg<key> *s){
			static int count = 0;
			memcpy(sample->data + samplesRcvd, s->data, s->numElem * sizeof(key));
			samplesRcvd += s->numElem;
			count++;
			//can enter here twice, check on the basis of number of msgs received
			if(count == numpes){
				ckout<<"Sending ******************* to Sorter ************** size: "<< s->numElem << "from "<<CkMyNode()<<endl;
				for(int i=0; i<sample->numElem; i++)
					ckout<<"From nodemgr "<<CkMyNode()<<" : "<<sample->data[i]<<endl;
				sorter.recvSample(sample);
			}
		}
		void loadkeys(int dest, sendInfo inf){
			ainfo[dest].push_back(inf);	
			if(ainfo[dest].size() == numpes){
				this->thisProxy[CkMyNode()].sendOne(dest);
			}
		}

		void sendOne(int dest){
			CkPrintf("[%d][%d] sendOne to node: %d \n", CkMyNode(), CkMyPe(), dest);
			int numelem = 0;
			for(int i=0; i<ainfo[dest].size(); i++)
				numelem += ainfo[dest][i].ind2 - ainfo[dest][i].ind1;
			data_msg<key, value> *dm = new (numelem) data_msg<key,value>;
			dm->num_vals = numelem;
			dm->sorted = false;
			int curr = 0;
			for(int i=0; i<ainfo[dest].size(); i++){
				int ind1 = ainfo[dest][i].ind1, ind2 = ainfo[dest][i].ind2;
				kv_pair<key, value>* bucket_data = (kv_pair<key, value>*)ainfo[dest][i].base;
				memcpy(dm->data + curr, bucket_data + ind1, (ind2-ind1)*sizeof(kv_pair<key, value>));
				curr += ind2 - ind1;
			}
			this->thisProxy[dest].recvOne(dm);
		}


		void recvOne(data_msg<key, value> *dm){
			//CkPrintf("[%d] message received of size: %d \n", CkMyNode(), dm->num_vals);
			//for(int i=0; i<dm->num_vals; i++)
			//	ckout<<"message  "<<i<<" : "<<dm->data[i].k<<endl;
			recvdMsgs.push_back(dm);
			this->thisProxy[CkMyNode()]->handleOne(dm);
			if(++numRecvd == CkNumNodes())
				CkPrintf("[%d] Received all messages \n", CkMyNode());
		}



};

#endif
