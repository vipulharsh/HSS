#ifndef __SORTER_H__
#define __SORTER_H__

template <class key>
class charm_resolved_range{
  public: 
    key lowerb;
    key upperb;
    int chare_dest;
    int total;
    
    void pup(PUP::er &p) {
      p | lowerb; 
      p | upperb;
      p | chare_dest;
      p | total;
    }

};

template <class key, class value>
class first_probe : public CMessage_first_probe<key, value> {
  public:
    CProxy_Sorter<key, value> sorter_proxy;
    key* splitter_guesses;
    int num_keys;
    int splice_thresh;
    int eager_send;
    int num_buckets;
    tuning_params params;
};


template <class key>
class next_probe : public CMessage_next_probe<key> {
  public:
    key* splitter_guesses;
    int num_keys;
    charm_resolved_range<key>* send_info;
    int num_ranges;
};

template <class key>
struct charm_splitter{
  uint64_t upperb_count;
  key upperb_key;
  uint64_t lowerb_count;
  key lowerb_key;
  uint64_t goal;
  int virt;
  bool achieved;
  bool broadcasted;
};


template <class key, class value>
class Sorter : public CBase_Sorter<key, value>  {
//class Sorter : public CBase_Sorter<key,value> {
  private:
    CProxy_Bucket<key, value> buckets;
    CProxy_Sorter<key, value> myProxy;
    
    double c1, c2;
    uint64_t num_total_keys;
    int num_buckets;
    int num_steps;
    int num_achv;
    int margin_error;
    bool first_use;
    charm_splitter<key>* splitters;  
    key min_key, max_key;
    key *last_probe;
    tuning_params *params;
    std::vector<int> enrollRange;
    std::vector<int> maxRange;

    void init(const CkArrayID &bucketrr, int num_chares, key min, key max, tuning_params *par);
    key* get_splitter_guesses(int *ptr_num_guesses, std::vector< charm_splitter<key>* > active_splitters);

  public:

    void register_sum_uint64_t(void);
    Sorter(CkMigrateMessage *msg);
    Sorter(){}
    Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max);
    Sorter(const CkArrayID &bucketArr, int num_chares, key min, key max, tuning_params par);
    void Begin();
    void Begin(tuning_params par);
    void Histogram(CkReductionMsg *msg);
    void Done(CkReductionMsg *msg);
    void SanityCheck(CkReductionMsg *msg);
};
//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Sorter.C"
#endif
