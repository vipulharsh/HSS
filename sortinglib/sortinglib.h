#ifndef __SORTING_LIB_H__
#define __SORTING_LIB_H__
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <list>
#include <algorithm>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <chrono>
#include <climits>
#include "defs.h"

#define UINT64_MAX (18446744073709551615ULL)

/*readonly*/ CkNodeGroupID nodeMgrID;


//Global variables
__thread int in_elems, *out_elems;
__thread void* dataIn, **dataOut;
__thread CkCallback *CB;  __thread bool callBackSet;
uint64_t numTotalElems;


#include "HistSort.decl.h"

/*
template <class key, class value> 
class Global {
public:    
    static CProxy_NodeManager<key> *nodemgr;

private:    
    Global() {}
    Global(const Global& rhs) {}
    void operator=(const Global& rhs) {}
};
*/

/*
template <class key, class value> 
CProxy_NodeManager<key> * Global<key>::nodemgr = new CProxy_NodeManager<key>;
*/


template <class key>
class tagged_key {
  public:
    key k;
    int pe;
    int ind;
    tagged_key(){}
    tagged_key(key _k, int _pe, int _ind): k(_k), pe(_pe), ind(_ind){}
    /*inline*/ bool operator< (const tagged_key<key>& other) const{
      return (k==other.k? (ind==other.ind? (pe<other.pe): (ind < other.ind)):(k < other.k));
    }
    friend std::ostream& operator<< (std::ostream &out, const tagged_key<key> &tk){
      out<< "(" << tk.k << "," << tk.pe << "," << tk.ind << ")";
      return out;
    }
    void pup(PUP::er &p){
      p|k;
      p|pe;
      p|ind;
    }
};


template <class key>
tagged_key<key> getTaggedMaxKey(key maxkey){
  return tagged_key<key>(maxkey, INT_MAX, INT_MAX);
}


template <class key>
tagged_key<key> getTaggedMinKey(key minkey){
  return tagged_key<key>(minkey, INT_MIN, INT_MIN);
}


template <class key>
std::pair<int, key> grtstPow2(key n){
  key ret = 1;
  int cnt = 0;
  while(ret < n){
    ret *= 2;
    cnt++;
  }
  return std::pair<int, key>(cnt-1, ret>>1);
}

template<int> std::pair<int, int> grtstPow2(int);


#include "Sorter.h"
#include "Bucket.h"


#ifndef CK_TEMPLATES_ONLY
template <class key>
void registerSortingLib();
#endif

template <class key>
void HistSorting(int input_elems_, key* dataIn_, 
                 int *output_elems_, key** dataOut_,
                 int probe_max, CkCallback *CB_) {
  dataIn = (void*)dataIn_;
  dataOut = (void**)dataOut_;
  in_elems = input_elems_;
  out_elems = output_elems_;
  
  callBackSet = false;
  CB = CB_;
  if(CB_){
    callBackSet = true;
  }



  //CkPrintf("[%d] HistSorting on, First Elt. %ld \n",CkMyPe(), ((key*) dataIn)[0]);

  if(CkMyPe() == 0) {
//#if DEBUG
    CkPrintf("[%d] Histogram Sorting on %d at %.3lf MB\n",CkMyPe(),CkNumPes(),CmiMemoryUsage()/(1024.0*1024));
//#endif
   static CProxy_Main<key> mainProxy = CProxy_Main<key>::ckNew(CkNumPes(), probe_max, CkNumNodes(), CkMyPe());
    //mainProxy.DataReady();
  }
}






//main entrypoint of tester, coordinates testing of sorting library
template <class key>
class Main : public CBase_Main<key> {
  private:
    int num_buckets, num_partitions;
    //chare array proxies
    CProxy_Sorter<key> sorter;
    CProxy_Bucket<key> bucket_arr;
    tuning_params pars; 
    int isumk, tsumk, fsumk;
  public:
    //main constructor
    Main (int num_buckets_, int probe_max, int num_partitions_) {
      //input parameter is number of buckets (data chares)
      num_buckets = num_buckets_;
      //equal to #chares or #nodes, depending on whether node level or pe level
      num_partitions = num_partitions_;
      // Create the sorting entities
      CkArrayOptions opts(num_buckets);
      pars.probe_size = num_buckets - 1;
      if(probe_max == -1)
        pars.probe_max = 64;
      else
        pars.probe_max = probe_max;
      
      pars.hist_thresh = 5;
      pars.splice_thresh = 1024;
      //try a variety of communication stages
      if (num_buckets <= 256)
        pars.eager_send = num_buckets;
      else
        pars.eager_send = num_buckets/16; //need to play with this

      pars.reuse_probe_results = true;
  
      CkNodeGroupID nodeMgrID = CProxy_NodeManager<key>::ckNew(0, UINT64_MAX);

      bucket_arr = CProxy_Bucket<key>::ckNew(pars, 0,
                       UINT64_MAX,  num_partitions, nodeMgrID, opts);
      
      // maxkey should be MAXINT - c * p
      sorter = CProxy_Sorter<key>::ckNew(bucket_arr, num_partitions, 0, 
                     UINT64_MAX, pars, this->thisProxy, nodeMgrID);

      CkStartQD(CkCallback(CkIndex_Main<key>::DataReady(NULL), this->thisProxy));
      //DataReady(); 
    }
    //migration constructor
    Main (CkMigrateMessage *m) { }
    //starts sorting
    void DataReady(CkReductionMsg *msg);
    //a reduction that exists application
    void Exit() {
      CkExit();
    }
    void init_isum(CkReductionMsg *msg) {
      isumk = *((int *) msg->getData());
      printf("Initial key sum %d\n",*((int *) msg->getData()));
      delete msg;
    }
    void intermediate_isum(CkReductionMsg *msg) {
      tsumk = *((int *) msg->getData());
      printf("Intermediate key sum %d\n",*((int *) msg->getData()));
      delete msg;
    }

    void final_isum(CkReductionMsg *msg) {
      fsumk = *((int *) msg->getData());
      printf("Final key sum %d\n",*((int *) msg->getData()));
      ckout<<isumk<<" "<<tsumk<<" "<<fsumk<<endl;
      if(isumk != fsumk){
        CmiAbort("Checksums don't match \n");
      }
      //delete msg;
      sorter.Done(msg);
    }
};

//a reduction that signifies that data chare array has generated its data and sorting can begin
template <class key>
void Main<key>::DataReady(CkReductionMsg *msg) {
  //There is a possibility of a data race here
  CkPrintf("((((((((( [%d/%d]DataReady \n", CkMyPe(), CkMyNode()); 
  bucket_arr.startBarrier(sorter, this->thisProxy);     
	//this->contribute(CkCallback(CkIndex_Sorter<key>::finishBarrier(NULL), sorter_proxy));
  CkStartQD(CkCallback(CkIndex_Sorter<key>::finishBarrier(NULL), sorter));
  //bucket_arr.SetData(sorter, this->thisProxy);     
  //sorter.Begin();       
}



#include "nodemanager.h"


#define CK_TEMPLATES_ONLY
#include "HistSort.def.h"
#undef CK_TEMPLATES_ONLY 

#ifndef CK_TEMPLATES_ONLY


//template <class key>
template<>
void recursive_pup_impl<Sorter<unsigned long>, 1>::operator()(Sorter<unsigned long> *obj, PUP::er &p) {
    obj->parent_pup(p);
    obj->Sorter<unsigned long>::pup(p);
}


template <>
void recursive_pup_impl<Bucket<unsigned long>, 1>::operator()(Bucket<unsigned long> *obj, PUP::er &p) {
    obj->parent_pup(p);
    obj->Bucket<unsigned long>::pup(p);
}

template <>
void recursive_pup_impl<Main<unsigned long>, 1>::operator()(Main<unsigned long> *obj, PUP::er &p) {
    obj->parent_pup(p);
    obj->Main::pup(p);
}


template <>
void recursive_pup_impl<NodeManager<unsigned long>, 1>::operator()(NodeManager<unsigned long> *obj, PUP::er &p) {
    obj->parent_pup(p);
    obj->NodeManager<unsigned long>::pup(p);
}


#endif //#ifndef CK_TEMPLATES_ONLY
#endif
