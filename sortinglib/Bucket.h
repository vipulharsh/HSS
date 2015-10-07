#ifndef __BUCKET_H__
#define __BUCKET_H__

template <class key, class value>
class data_msg : public CMessage_data_msg<key, value> {
  public:
    kv_pair<key, value> *pairs;
    int num_vals;
};

template <class key, class value>
class buffered_msg {
  public: 
    data_msg<key, value>* msg; 
    int chare_dest;
    
    buffered_msg(data_msg<key, value>* m, int d){
      msg = m;
      chare_dest = d;
  }
};

template <class key, class value>
class Bucket : public CBase_Bucket<key, value> {
  private:
    CProxy_Main<key, value> mainProxy;
    CProxy_Sorter<key, value> SorterProxy;
    CProxy_Bucket<key, value> myProxy;
    int num_buckets;
    int num_elements;
    int new_num_elements;
    kv_pair<key, value>* bucket_data;
    key key_min, key_max;
    int splice_thresh;
    int eager_send;
    kv_pair<key, value> *kvp_comp;
    double c1, c2;
    std::vector < next_probe<key>* > probe_buffer;
    key* sep_keys;
    int* sep_counts;
    int num_separators;
    bool* sorted;
    //int* oldSorted;
    //bool bSorted;
    bool doneHists;
    int loadIndex;
    int sSample;
    std::vector < data_msg<key, value>* > LoadBuffer;
    int buffering;
    int sortedIndex;
    std::vector < kv_pair<key, value>* > lastMerged;
    kv_pair<key, value> *swap1;
    kv_pair<key, value> *swap2;
    std::vector <int> lastArraySizes;
    //int *sizes;
    data_msg<key, value> *oddMessage; //need to keep track of this in order to delete it later
    int num_Loaded;
    kv_pair<key, value> *mergedData;
    bool GotSizes;
    bool bLoad;
    int numsent;
    int numsent_buffer;
    //some messages need to be buffered and sent to the destination later
    std::vector <buffered_msg<key, value>* > sendBuffer;
    //int sendBufferIdx;
    bool yieldtosends;   


 
    ///incoming messages to be freed, need to keep track of these
    data_msg<key, value> *init_data;
    first_probe<key, value> *initial_probe;

    CkCallback myCallback;
    int isCallbackSet;

    key getSampleMedian(int min, int max, int len);

    void Reset();

    void CheckInitialDist();

    void GetSeparators(int min, int max, int minVal, int maxVal, key *new_guesses, int *new_sep_counts);


    int SpliceArray(kv_pair<key, value>* arr, int begin, int end, key pivot);

    inline void SendOne(int iter, int start, int end, int chare_dest);

    void PrepareForLoad();

    void LoadNow(data_msg<key, value>* msg);

    void merge_next(kv_pair<key, value>* swapData);

  public:

    Bucket(CkMigrateMessage *);

    Bucket(CProxy_Main<key, value> main_proxy, key min, key max);
    
    void SetCallback(const CkCallback &cb);
    
    void SetData();
    void SetData(data_msg<key, value> *msg);

    void StepSort();

    void CleanSplitters();

    void CountFirstProbe(first_probe<key, value> *msg);

    void CountProbe(next_probe<key> *pb);

    void SendAll(next_probe<key> *pb);

    void SendPortion(int k, int npd);    

    void Load(data_msg<key, value>* msg);
    
    void Load();
};

//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Bucket.C"
#endif
