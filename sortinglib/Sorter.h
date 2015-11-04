#ifndef __SORTER_H__
#define __SORTER_H__

#include <map>

template <class key>
class probeMessage : public CMessage_probeMessage<key> {
  public:
    key* probe;
    int probeSize;
    key* newachv_key;
    int* newachv_id;
    int num_newachv;
};



template <class key, class value>
class Sorter : public CBase_Sorter<key, value>  {
  private:
    CProxy_Bucket<key, value> buckets;
    int nBuckets;
    uint64_t nElements;

    key* lastProbe;
    std::map<key, uint64_t> allPreviousProbes;
    key* scratch;
    int lastProbeSize;

    key* finalSplitters;
    bool* achieved;
    int achievedSplitters;

    key minkey, maxkey;
    key globalmin, globalmax;
    tuning_params *params;
    bool firstUse;

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
    Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max, tuning_params par);
    void Begin();
    void Histogram(CkReductionMsg *msg);
    void globalMinMax(CkReductionMsg *msg);
    void Done(CkReductionMsg *msg);
    void SanityCheck(CkReductionMsg *msg);
};
//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Sorter.C"
#endif
