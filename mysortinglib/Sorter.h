#ifndef __SORTER_H__
#define __SORTER_H__


template <class key, class value>
class probeMessage : public CMessage_probeMessage<key, value> {
  public:
    key* probe;
    int probeSize;
    key* rangeBoundaries;
    int* resolvedRanges;
    int numRanges;
};



template <class key, class value>
class Sorter : public CBase_Sorter<key, value>  {
  private:
    CProxy_Bucket<key, value> buckets;
    int nBuckets;
    int nElements;

    key* lastProbe;
    key* scratch;
    int lastProbeSize;

    key* finalSplitters;
    bool* achieved;
    int achievedSplitters;

    key minKey, maxKey;
    tuning_params *params;
    bool firstUse;

    /**
    For collecting stats
    **/
    int numProbes;
    double c1, c2;

    int checkGoal(int splitterInd, int histCount);

  public:

    void register_sum_uint64_t(void);
    Sorter(CkMigrateMessage *msg);
    Sorter(){}
    Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max, tuning_params par);
    void Begin();
    void Histogram(CkReductionMsg *msg);
    void Done(CkReductionMsg *msg);
    void SanityCheck(CkReductionMsg *msg);
};
//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Sorter.C"
#endif
