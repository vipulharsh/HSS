#ifndef __BUCKET_H__
#define __BUCKET_H__



template <class key, class value>
class data_msg : public CMessage_data_msg<key, value> {
  public:
    kv_pair<key, value> *data;
    int num_vals;
    bool sorted;
};



template <class key, class value>
class Bucket : public CBase_Bucket<key, value> {
  private:
	
	
	kv_pair<key, value>* bucket_data;
	int numElem;
	static const int indexFactor = 2;


	int nBuckets;
	
	key minkey, maxkey;
	key mymin, mymax;
	
	CProxy_Sorter<key, value> sorter_proxy;
	CProxy_Main<key, value> main_proxy;

	tuning_params *params;
	
	key* finalSplitters;
	bool* achieved;
	uint64_t* achievedCounts;
    int achievedSplitters;
    bool* sent;

    key* lastProbe;
    int lastProbeSize;

    int *sepCounts;
    key *sepKeys;
  	bool *sorted;
    int lastSortedChunk;
   	int numChunks;
   	bool doneHists;


	//kv_pair<key, value>* scratch;
	int* cumHist;
	int* indices;
	int numIndicesShift;
    int* histCounts;
    uint64_t *longhistCounts;

    int numProbes;
    
   	std::vector < data_msg<key, value>* > incomingMsgBuffer;
   	std::vector <std::pair<int, int> > loadBuffer;	
   	int received;
   	int firstUsed;
   	bool set;
    bool firstMergingWork;
    bool mergingDone;
    bool totalmerge;
    bool noMergingWork;


   	void Reset(); 
   	void localProbe();
   	void partialSend(probeMessage<key> *pm);
   	void collapseAndMerge();
   	void totalMerge();
   	void mergeAt(int n);
   	void mymerge(kv_pair<key, value> *first1, kv_pair<key, value> *last1,
								 kv_pair<key, value> *first2, kv_pair<key, value> *last2,
								 kv_pair<key, value> *result);

  public:
      Bucket(CkMigrateMessage *);
	  Bucket(tuning_params par, key _min, key _max, int nBuckets_);
	  void SetData(CProxy_Sorter<key, value> _sorter_proxy, CProxy_Main<key, value> _main_proxy);
	  void stepSort();
	  void firstProbe(key firstkey, key lastkey, key step, int probeSize);
	  void firstLocalProbe(int lastProbeSize);
	  void histCountProbes(probeMessage<key> *pm);
	  void Load(data_msg<key, value>* msg);
    void MergingWork();
};

//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Bucket.C"
#endif
