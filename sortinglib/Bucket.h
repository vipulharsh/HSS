#ifndef __BUCKET_H__
#define __BUCKET_H__


template <class key>
class data_msg : public CMessage_data_msg<key> {
  public:
    key *data;
    int num_vals;
    bool sorted;
};


//struct for lb
//! pup method, also pup method not implemented for kv_pair in sortinglib.h
template <class key>
struct lb_struct{
    int numVals;
    int start;
    data_msg<key>* msg;
};


template <class key>
class array_msg : public CMessage_array_msg<key> {
  public:
    tagged_key<key>* data;
    int numElem;
};


template <class key>
key* lower_bound_tagged(key *first, key *last, tagged_key<key> val, int pe=CkMyPe(), key* base=NULL){
    if(base == NULL)
        base = first;
    key *it;
    int  count, step;
    count = last - first;
    while (count>0){
        it = first; step=count/2; std::advance(it,step);
        if (tagged_key<key>(*it,pe,it-base) < val) {
            first=++it;
            count-=step+1;
        }
        else count=step;
    }
    return first;
}


template <class key>
key* upper_bound_tagged(key *first, key *last, tagged_key<key> val){
    key *base = first;
    key *it;
    int count, step;
    count = last - first;
    while (count>0)
    {
        it = first; step=count/2; std::advance(it,step);
        if (! (val < tagged_key<key>(*it,CkMyPe(),it-base))) {
            first=++it;
            count-=step+1;
        }
        else count=step;
    }
    return first;
}


template <class key>
class Bucket : public CBase_Bucket<key> {
  private:

      key* bucket_data;

      int numElem;
      static const int indexFactor = 3;

      int nBuckets;
      int nNodes;

      key minkey, maxkey;
      key mymin, mymax;

      CProxy_Sorter<key> sorter_proxy;
      CProxy_Main<key> main_proxy;

      tuning_params *params;

      tagged_key<key>* finalSplitters;
      bool* achieved;
      uint64_t* achievedCounts;
      int achievedSplitters;
      bool* sent;

      tagged_key<key>* lastProbe;
      int lastProbeSize;

      int *sepCounts;
      key *sepKeys;
      bool *sorted;
      int lastSortedChunk;
      int numChunks;
      bool doneHists;


      int* cumHist;
      int* indices;
      int numIndicesShift;
      int* histCounts;
      uint64_t *longhistCounts;

      int numProbes;

      std::vector < data_msg<key>* > incomingMsgBuffer;
      std::vector <lb_struct<key> > loadBuffer;	

      std::vector <int> toSend;
      int received;
      int lastUsed;
      bool firstMergingWork;
      bool mergingDone;
      bool totalmerge;
      bool noMergingWork;
      bool callPartialSendOne;
      bool startMergingWork;
      int numSent;

      key* scratch;

      CProxy_NodeManager<key>  nodemgr;
      CkNodeGroupID nodeMgrID;

      int tsum, recvd;
      void Reset(); 
      void localProbe();
      void partialSend(sampleMessage<key> *sm);
      void heapSort(key *out_data, int out_num);
      void collapseAndMerge();
      void totalMerge();
      void mergeAt(int n);
      void forward_merge(key *first1, key *last1,
              key *first2, key *last2,
              key *result);
      void backward_merge(key *first1, key *last1,
              key *first2, key *last2,
              key *result);
      void postMerging();

      std::vector<sendInfo> recvData;
    
  public:
      Bucket(CkMigrateMessage *);
      Bucket(tuning_params par, key _min, key _max, int nBuckets_, CkNodeGroupID _nodeMgrID);
      void startBarrier(CProxy_Sorter<key> _sorter_proxy, CProxy_Main<key> _main_proxy);
      void SetData();
      void genSample(sampleInfo sI);
      void finalProbes(array_msg<key>* finalprb);
      void sortAll();
      void sendAll();
      void recvFinalKeys(int srcnode, sendInfo s);
      inline void setTotalKeys(){
          CkAssert(achieved[nNodes]);
          numTotalElems = achievedCounts[nNodes];
      }

      void stepSort();
      void firstProbe(key firstkey, key lastkey, key step, int probeSize);
      void firstLocalProbe(int lastProbeSize);
      void genNextSamples(sampleMessage<key> *sm);
      void Load(data_msg<key>* msg);
      void MergingWork();
      void partialSendOne();
      void finish();
};

//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Bucket.C"
#endif
