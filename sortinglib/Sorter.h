#ifndef __SORTER_H__
#define __SORTER_H__

#include <map>
#include <vector>


template <class key>
class sampleMessage : public CMessage_sampleMessage<key> {
  public:
    double f;
    int nIntervals;
    tagged_key<key>* lb;
    tagged_key<key>* ub;
    tagged_key<key>* newachv_key;
    int* newachv_id;
    uint64_t* newachv_count;
    int num_newachv;
};


template <class key>
class Sorter : public CBase_Sorter<key>  {
  private:
    CProxy_Bucket<key> buckets;
    CProxy_Main<key> mainproxy;
    CkNodeGroupID nodeMgrID;

    int nBuckets, nNodes;
    uint64_t nElements;

    tagged_key<key>* lastProbe;
    int lastProbeSize;

    tagged_key<key>* finalSplitters;
    bool* achieved;
    int achievedSplitters;
    uint64_t* achievedCounts;

    key minkey, maxkey;
    tagged_key<key> minkey_tagged, maxkey_tagged;
    key globalmin, globalmax;
    tuning_params *params;
    bool firstUse;

    std::vector<tagged_key<key> > collectedSample;

    tagged_key<key> *lb_keys, *ub_keys;
    uint64_t *lb_ranks, *ub_ranks;

    /**
    For collecting stats
    **/
    int numProbes;
    double c1, c2;

    int checkGoal(int splitterInd, uint64_t histCount);
    void nextSamples(std::vector<std::pair<tagged_key<key>, int> > &newachv, uint64_t* histCounts, CkReductionMsg *msg);
    
  public:

    void register_sum_uint64_t(void);
    void register_minmax_uint64_t(void); 
    Sorter(CkMigrateMessage *msg);
    Sorter(){}
    Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max,
         tuning_params par, CProxy_Main<key> _mainproxy, CkNodeGroupID _nodeMgrID);
    void finishBarrier(CkReductionMsg *msg);
    void recvSample(array_msg<key>* am);
    void Init();
    //void Begin();
    void Histogram(CkReductionMsg *msg);
    void updateBounds(CkReductionMsg *msg);
    //void globalMinMax(CkReductionMsg *msg);
    void Done(CkReductionMsg *msg);
    void SanityCheck(CkReductionMsg *msg);
    inline uint64_t idealSplitterRank(int i){ return (nElements*i)/nBuckets;}
};
//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Sorter.C"
#endif
