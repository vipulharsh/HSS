#ifndef __SORTER_H__
#define __SORTER_H__

#include <map>
#include <vector>

template <class key>
class probeMessage : public CMessage_probeMessage<key> {
  public:
    key* probe;
    int probeSize;
    key* newachv_key;
    int* newachv_id;
    uint64_t* newachv_count;
    int num_newachv;
};


template <class key, class value>
class Sorter : public CBase_Sorter<key, value>  {
  private:
    CProxy_Bucket<key, value> buckets;
    CProxy_Main<key, value> mainproxy;
    CkNodeGroupID nodeMgrID;

    int nBuckets, nNodes;
    uint64_t nElements;

    key* lastProbe;
    std::map<key, uint64_t> allPreviousProbes;
    key* scratch;
    int lastProbeSize;

    key* finalSplitters;
    bool* achieved;
    int achievedSplitters;
    uint64_t* achievedCounts;

    key minkey, maxkey;
    key globalmin, globalmax;
    tuning_params *params;
    bool firstUse;

    std::vector<key> collectedSample;

    /**
    For collecting stats
    **/
    int numProbes;
    double c1, c2;

    int checkGoal(int splitterInd, uint64_t histCount);
    void nextProbes(std::vector<std::pair<key, int> > &newachv, uint64_t* histCounts, CkReductionMsg *msg);
    
  public:

    void register_sum_uint64_t(void);
    void register_minmax_uint64_t(void); 
    Sorter(CkMigrateMessage *msg);
    Sorter(){}
    Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max,
         tuning_params par, CProxy_Main<key, value> _mainproxy, CkNodeGroupID _nodeMgrID);
    void finishBarrier(CkReductionMsg *msg);
    void recvSample(array_msg<key>* am);
    void Init();
    //void Begin();
    void Histogram(CkReductionMsg *msg);
    //void globalMinMax(CkReductionMsg *msg);
    void Done(CkReductionMsg *msg);
    void SanityCheck(CkReductionMsg *msg);
};
//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Sorter.C"
#endif
