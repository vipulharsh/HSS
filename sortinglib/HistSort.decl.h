#ifndef _DECL_HistSort_H_
#define _DECL_HistSort_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
#include "defs.h"



/* DECLS: template < class key, class value > chare Main: Chare{
Main(int num_buckets_, int probe_max, int num_partitions_);
void Exit();
void DataReady();
void init_isum(CkReductionMsg* impl_msg);
void intermediate_isum(CkReductionMsg* impl_msg);
void final_isum(CkReductionMsg* impl_msg);
void init_dsum(CkReductionMsg* impl_msg);
void final_dsum(CkReductionMsg* impl_msg);
};
 */
template < class key, class value >  class Main;
template < class key, class value >  class CkIndex_Main;
template < class key, class value >  class CProxy_Main;
/* --------------- index object ------------------ */
template < class key, class value > class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main < key, value >  local_t;
    typedef CkIndex_Main < key, value >  index_t;
    typedef CProxy_Main < key, value >  proxy_t;
    typedef CProxy_Main < key, value >  element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(int num_buckets_, int probe_max, int num_partitions_);
     */
    // Entry point registration at startup
    
    static int reg_Main_marshall1();
    // Entry point index lookup
    
    inline static int idx_Main_marshall1() {
      static int epidx = reg_Main_marshall1();
      return epidx;
    }

    
    static int ckNew(int num_buckets_, int probe_max, int num_partitions_) { return idx_Main_marshall1(); }
    
    static void _call_Main_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Main_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Main_marshall1(PUP::er &p,void *msg);
    /* DECLS: void Exit();
     */
    // Entry point registration at startup
    
    static int reg_Exit_void();
    // Entry point index lookup
    
    inline static int idx_Exit_void() {
      static int epidx = reg_Exit_void();
      return epidx;
    }

    
    inline static int idx_Exit(void (Main < key, value > ::*)() ) {
      return idx_Exit_void();
    }


    
    static int Exit() { return idx_Exit_void(); }
    
    static void _call_Exit_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Exit_void(void* impl_msg, void* impl_obj);
    /* DECLS: void DataReady();
     */
    // Entry point registration at startup
    
    static int reg_DataReady_void();
    // Entry point index lookup
    
    inline static int idx_DataReady_void() {
      static int epidx = reg_DataReady_void();
      return epidx;
    }

    
    inline static int idx_DataReady(void (Main < key, value > ::*)() ) {
      return idx_DataReady_void();
    }


    
    static int DataReady() { return idx_DataReady_void(); }
    
    static void _call_DataReady_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_DataReady_void(void* impl_msg, void* impl_obj);
    /* DECLS: void init_isum(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_init_isum_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_init_isum_CkReductionMsg() {
      static int epidx = reg_init_isum_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_init_isum(void (Main < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_init_isum_CkReductionMsg();
    }


    
    static int init_isum(CkReductionMsg* impl_msg) { return idx_init_isum_CkReductionMsg(); }
    
    static void _call_init_isum_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_init_isum_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void intermediate_isum(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_intermediate_isum_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_intermediate_isum_CkReductionMsg() {
      static int epidx = reg_intermediate_isum_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_intermediate_isum(void (Main < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_intermediate_isum_CkReductionMsg();
    }


    
    static int intermediate_isum(CkReductionMsg* impl_msg) { return idx_intermediate_isum_CkReductionMsg(); }
    
    static void _call_intermediate_isum_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_intermediate_isum_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void final_isum(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_final_isum_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_final_isum_CkReductionMsg() {
      static int epidx = reg_final_isum_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_final_isum(void (Main < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_final_isum_CkReductionMsg();
    }


    
    static int final_isum(CkReductionMsg* impl_msg) { return idx_final_isum_CkReductionMsg(); }
    
    static void _call_final_isum_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_final_isum_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void init_dsum(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_init_dsum_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_init_dsum_CkReductionMsg() {
      static int epidx = reg_init_dsum_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_init_dsum(void (Main < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_init_dsum_CkReductionMsg();
    }


    
    static int init_dsum(CkReductionMsg* impl_msg) { return idx_init_dsum_CkReductionMsg(); }
    
    static void _call_init_dsum_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_init_dsum_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void final_dsum(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_final_dsum_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_final_dsum_CkReductionMsg() {
      static int epidx = reg_final_dsum_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_final_dsum(void (Main < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_final_dsum_CkReductionMsg();
    }


    
    static int final_dsum(CkReductionMsg* impl_msg) { return idx_final_dsum_CkReductionMsg(); }
    
    static void _call_final_dsum_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_final_dsum_CkReductionMsg(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
template < class key, class value > class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main < key, value >  local_t;
    typedef CkIndex_Main < key, value >  index_t;
    typedef CProxy_Main < key, value >  proxy_t;
    typedef CProxy_Main < key, value >  element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main < key, value >  *ckLocal(void) const
    { return (Main < key, value >  *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(int num_buckets_, int probe_max, int num_partitions_);
 */
    static CkChareID ckNew(int num_buckets_, int probe_max, int num_partitions_, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int num_buckets_, int probe_max, int num_partitions_, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Main(int num_buckets_, int probe_max, int num_partitions_, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void Exit();
 */
    
    void Exit(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void DataReady();
 */
    
    void DataReady(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void init_isum(CkReductionMsg* impl_msg);
 */
    
    void init_isum(CkReductionMsg* impl_msg);

/* DECLS: void intermediate_isum(CkReductionMsg* impl_msg);
 */
    
    void intermediate_isum(CkReductionMsg* impl_msg);

/* DECLS: void final_isum(CkReductionMsg* impl_msg);
 */
    
    void final_isum(CkReductionMsg* impl_msg);

/* DECLS: void init_dsum(CkReductionMsg* impl_msg);
 */
    
    void init_dsum(CkReductionMsg* impl_msg);

/* DECLS: void final_dsum(CkReductionMsg* impl_msg);
 */
    
    void final_dsum(CkReductionMsg* impl_msg);

};
#define Main_SDAG_CODE 
template < class key, class value > 
struct CBase_Main;

/* DECLS: template < class key > message probeMessage{
key probe[];
key newachv_key[];
int newachv_id[];
uint64_t newachv_count[];
}
;
 */
template < class key > class probeMessage;
template < class key > class CMessage_probeMessage:public CkMessage{
  public:
    static int __idx;
    void* operator new(size_t, void*p) { return p; }
    void* operator new(size_t);
    void* operator new(size_t, int*, const int);
    void* operator new(size_t, int*);
#if CMK_MULTIPLE_DELETE
    void operator delete(void*p, void*){dealloc(p);}
    void operator delete(void*p){dealloc(p);}
    void operator delete(void*p, int*, const int){dealloc(p);}
    void operator delete(void*p, int*){dealloc(p);}
#endif
    void operator delete(void*p, size_t){dealloc(p);}
    static void* alloc(int,size_t, int*, int);
    static void dealloc(void *p);
    CMessage_probeMessage < key > ();
    static void *pack(probeMessage < key >  *p);
    static probeMessage < key > * unpack(void* p);
    void *operator new(size_t, int, int, int, int);
    void *operator new(size_t, int, int, int, int, const int);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, int, int, int, int){dealloc(p);}
    void operator delete(void *p, int, int, int, int, const int){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: template < class key > message sampleMessage{
key lb[];
key ub[];
key newachv_key[];
int newachv_id[];
uint64_t newachv_count[];
}
;
 */
template < class key > class sampleMessage;
template < class key > class CMessage_sampleMessage:public CkMessage{
  public:
    static int __idx;
    void* operator new(size_t, void*p) { return p; }
    void* operator new(size_t);
    void* operator new(size_t, int*, const int);
    void* operator new(size_t, int*);
#if CMK_MULTIPLE_DELETE
    void operator delete(void*p, void*){dealloc(p);}
    void operator delete(void*p){dealloc(p);}
    void operator delete(void*p, int*, const int){dealloc(p);}
    void operator delete(void*p, int*){dealloc(p);}
#endif
    void operator delete(void*p, size_t){dealloc(p);}
    static void* alloc(int,size_t, int*, int);
    static void dealloc(void *p);
    CMessage_sampleMessage < key > ();
    static void *pack(sampleMessage < key >  *p);
    static sampleMessage < key > * unpack(void* p);
    void *operator new(size_t, int, int, int, int, int);
    void *operator new(size_t, int, int, int, int, int, const int);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, int, int, int, int, int){dealloc(p);}
    void operator delete(void *p, int, int, int, int, int, const int){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: template < class key, class value > message data_msg{
kv_pair<key,value > data[];
}
;
 */
template < class key, class value > class data_msg;
template < class key, class value > class CMessage_data_msg:public CkMessage{
  public:
    static int __idx;
    void* operator new(size_t, void*p) { return p; }
    void* operator new(size_t);
    void* operator new(size_t, int*, const int);
    void* operator new(size_t, int*);
#if CMK_MULTIPLE_DELETE
    void operator delete(void*p, void*){dealloc(p);}
    void operator delete(void*p){dealloc(p);}
    void operator delete(void*p, int*, const int){dealloc(p);}
    void operator delete(void*p, int*){dealloc(p);}
#endif
    void operator delete(void*p, size_t){dealloc(p);}
    static void* alloc(int,size_t, int*, int);
    static void dealloc(void *p);
    CMessage_data_msg < key, value > ();
    static void *pack(data_msg < key, value >  *p);
    static data_msg < key, value > * unpack(void* p);
    void *operator new(size_t, int);
    void *operator new(size_t, int, const int);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, int){dealloc(p);}
    void operator delete(void *p, int, const int){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: template < class key > message array_msg{
key data[];
}
;
 */
template < class key > class array_msg;
template < class key > class CMessage_array_msg:public CkMessage{
  public:
    static int __idx;
    void* operator new(size_t, void*p) { return p; }
    void* operator new(size_t);
    void* operator new(size_t, int*, const int);
    void* operator new(size_t, int*);
#if CMK_MULTIPLE_DELETE
    void operator delete(void*p, void*){dealloc(p);}
    void operator delete(void*p){dealloc(p);}
    void operator delete(void*p, int*, const int){dealloc(p);}
    void operator delete(void*p, int*){dealloc(p);}
#endif
    void operator delete(void*p, size_t){dealloc(p);}
    static void* alloc(int,size_t, int*, int);
    static void dealloc(void *p);
    CMessage_array_msg < key > ();
    static void *pack(array_msg < key >  *p);
    static array_msg < key > * unpack(void* p);
    void *operator new(size_t, int);
    void *operator new(size_t, int, const int);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, int){dealloc(p);}
    void operator delete(void *p, int, const int){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: template < class key, class value > chare Sorter: Chare{
Sorter();
Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID);
void finishBarrier(CkReductionMsg* impl_msg);
void Histogram(CkReductionMsg* impl_msg);
void Done(CkReductionMsg* impl_msg);
void SanityCheck(CkReductionMsg* impl_msg);
void recvSample(array_msg<key >* impl_msg);
};
 */
template < class key, class value >  class Sorter;
template < class key, class value >  class CkIndex_Sorter;
template < class key, class value >  class CProxy_Sorter;
/* --------------- index object ------------------ */
template < class key, class value > class CkIndex_Sorter:public CkIndex_Chare{
  public:
    typedef Sorter < key, value >  local_t;
    typedef CkIndex_Sorter < key, value >  index_t;
    typedef CProxy_Sorter < key, value >  proxy_t;
    typedef CProxy_Sorter < key, value >  element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Sorter();
     */
    // Entry point registration at startup
    
    static int reg_Sorter_void();
    // Entry point index lookup
    
    inline static int idx_Sorter_void() {
      static int epidx = reg_Sorter_void();
      return epidx;
    }

    
    static int ckNew() { return idx_Sorter_void(); }
    
    static void _call_Sorter_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Sorter_void(void* impl_msg, void* impl_obj);
    /* DECLS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID);
     */
    // Entry point registration at startup
    
    static int reg_Sorter_marshall2();
    // Entry point index lookup
    
    inline static int idx_Sorter_marshall2() {
      static int epidx = reg_Sorter_marshall2();
      return epidx;
    }

    
    static int ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID) { return idx_Sorter_marshall2(); }
    
    static void _call_Sorter_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Sorter_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Sorter_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Sorter_marshall2(PUP::er &p,void *msg);
    /* DECLS: void finishBarrier(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_finishBarrier_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_finishBarrier_CkReductionMsg() {
      static int epidx = reg_finishBarrier_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_finishBarrier(void (Sorter < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_finishBarrier_CkReductionMsg();
    }


    
    static int finishBarrier(CkReductionMsg* impl_msg) { return idx_finishBarrier_CkReductionMsg(); }
    
    static void _call_finishBarrier_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_finishBarrier_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void Histogram(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Histogram_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_Histogram_CkReductionMsg() {
      static int epidx = reg_Histogram_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_Histogram(void (Sorter < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_Histogram_CkReductionMsg();
    }


    
    static int Histogram(CkReductionMsg* impl_msg) { return idx_Histogram_CkReductionMsg(); }
    
    static void _call_Histogram_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Histogram_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void Done(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Done_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_Done_CkReductionMsg() {
      static int epidx = reg_Done_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_Done(void (Sorter < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_Done_CkReductionMsg();
    }


    
    static int Done(CkReductionMsg* impl_msg) { return idx_Done_CkReductionMsg(); }
    
    static void _call_Done_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Done_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void SanityCheck(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_SanityCheck_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_SanityCheck_CkReductionMsg() {
      static int epidx = reg_SanityCheck_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_SanityCheck(void (Sorter < key, value > ::*)(CkReductionMsg* impl_msg) ) {
      return idx_SanityCheck_CkReductionMsg();
    }


    
    static int SanityCheck(CkReductionMsg* impl_msg) { return idx_SanityCheck_CkReductionMsg(); }
    
    static void _call_SanityCheck_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SanityCheck_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void recvSample(array_msg<key >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_recvSample_array_msg();
    // Entry point index lookup
    
    inline static int idx_recvSample_array_msg() {
      static int epidx = reg_recvSample_array_msg();
      return epidx;
    }

    
    inline static int idx_recvSample(void (Sorter < key, value > ::*)(array_msg<key >* impl_msg) ) {
      return idx_recvSample_array_msg();
    }


    
    static int recvSample(array_msg<key >* impl_msg) { return idx_recvSample_array_msg(); }
    
    static void _call_recvSample_array_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_recvSample_array_msg(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
template < class key, class value > class CProxy_Sorter:public CProxy_Chare{
  public:
    typedef Sorter < key, value >  local_t;
    typedef CkIndex_Sorter < key, value >  index_t;
    typedef CProxy_Sorter < key, value >  proxy_t;
    typedef CProxy_Sorter < key, value >  element_t;

    CProxy_Sorter(void) {};
    CProxy_Sorter(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Sorter(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Sorter < key, value >  *ckLocal(void) const
    { return (Sorter < key, value >  *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Sorter();
 */
    static CkChareID ckNew(int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID);
 */
    static CkChareID ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void finishBarrier(CkReductionMsg* impl_msg);
 */
    
    void finishBarrier(CkReductionMsg* impl_msg);

/* DECLS: void Histogram(CkReductionMsg* impl_msg);
 */
    
    void Histogram(CkReductionMsg* impl_msg);

/* DECLS: void Done(CkReductionMsg* impl_msg);
 */
    
    void Done(CkReductionMsg* impl_msg);

/* DECLS: void SanityCheck(CkReductionMsg* impl_msg);
 */
    
    void SanityCheck(CkReductionMsg* impl_msg);

/* DECLS: void recvSample(array_msg<key >* impl_msg);
 */
    
    void recvSample(array_msg<key >* impl_msg);

};
#define Sorter_SDAG_CODE 
template < class key, class value > 
struct CBase_Sorter;

class sampleInfo;

class sendInfo;

/* DECLS: template < class key, class value > array Bucket: ArrayElement{
Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
void SetData();
void genSample(const sampleInfo &sI);
void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
void firstLocalProbe(int lastProbeSize);
void histCountProbes(probeMessage<key >* impl_msg);
void genNextSamples(sampleMessage<key >* impl_msg);
void sortAll();
void stepSort();
void Load(data_msg<key,value >* impl_msg);
void recvFinalKeys(int srcnode, const sendInfo &s);
void MergingWork();
void partialSendOne();
void finalProbes(array_msg<key >* impl_msg);
void finish();
Bucket(CkMigrateMessage* impl_msg);
};
 */
template < class key, class value >  class Bucket;
template < class key, class value >  class CkIndex_Bucket;
template < class key, class value >  class CProxy_Bucket;
template < class key, class value >  class CProxyElement_Bucket;
template < class key, class value >  class CProxySection_Bucket;
/* --------------- index object ------------------ */
template < class key, class value > class CkIndex_Bucket:public CkIndex_ArrayElement{
  public:
    typedef Bucket < key, value >  local_t;
    typedef CkIndex_Bucket < key, value >  index_t;
    typedef CProxy_Bucket < key, value >  proxy_t;
    typedef CProxyElement_Bucket < key, value >  element_t;
    typedef CProxySection_Bucket < key, value >  section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
     */
    // Entry point registration at startup
    
    static int reg_Bucket_marshall1();
    // Entry point index lookup
    
    inline static int idx_Bucket_marshall1() {
      static int epidx = reg_Bucket_marshall1();
      return epidx;
    }

    
    static int ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID) { return idx_Bucket_marshall1(); }
    
    static void _call_Bucket_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Bucket_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Bucket_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Bucket_marshall1(PUP::er &p,void *msg);
    /* DECLS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
     */
    // Entry point registration at startup
    
    static int reg_startBarrier_marshall2();
    // Entry point index lookup
    
    inline static int idx_startBarrier_marshall2() {
      static int epidx = reg_startBarrier_marshall2();
      return epidx;
    }

    
    inline static int idx_startBarrier(void (Bucket < key, value > ::*)(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy) ) {
      return idx_startBarrier_marshall2();
    }


    
    static int startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy) { return idx_startBarrier_marshall2(); }
    
    static void _call_startBarrier_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_startBarrier_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_startBarrier_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_startBarrier_marshall2(PUP::er &p,void *msg);
    /* DECLS: void SetData();
     */
    // Entry point registration at startup
    
    static int reg_SetData_void();
    // Entry point index lookup
    
    inline static int idx_SetData_void() {
      static int epidx = reg_SetData_void();
      return epidx;
    }

    
    inline static int idx_SetData(void (Bucket < key, value > ::*)() ) {
      return idx_SetData_void();
    }


    
    static int SetData() { return idx_SetData_void(); }
    
    static void _call_SetData_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SetData_void(void* impl_msg, void* impl_obj);
    /* DECLS: void genSample(const sampleInfo &sI);
     */
    // Entry point registration at startup
    
    static int reg_genSample_marshall4();
    // Entry point index lookup
    
    inline static int idx_genSample_marshall4() {
      static int epidx = reg_genSample_marshall4();
      return epidx;
    }

    
    inline static int idx_genSample(void (Bucket < key, value > ::*)(const sampleInfo &sI) ) {
      return idx_genSample_marshall4();
    }


    
    static int genSample(const sampleInfo &sI) { return idx_genSample_marshall4(); }
    
    static void _call_genSample_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_genSample_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_genSample_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_genSample_marshall4(PUP::er &p,void *msg);
    /* DECLS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
     */
    // Entry point registration at startup
    
    static int reg_firstProbe_marshall5();
    // Entry point index lookup
    
    inline static int idx_firstProbe_marshall5() {
      static int epidx = reg_firstProbe_marshall5();
      return epidx;
    }

    
    inline static int idx_firstProbe(void (Bucket < key, value > ::*)(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize) ) {
      return idx_firstProbe_marshall5();
    }


    
    static int firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize) { return idx_firstProbe_marshall5(); }
    
    static void _call_firstProbe_marshall5(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_firstProbe_marshall5(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_firstProbe_marshall5(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_firstProbe_marshall5(PUP::er &p,void *msg);
    /* DECLS: void firstLocalProbe(int lastProbeSize);
     */
    // Entry point registration at startup
    
    static int reg_firstLocalProbe_marshall6();
    // Entry point index lookup
    
    inline static int idx_firstLocalProbe_marshall6() {
      static int epidx = reg_firstLocalProbe_marshall6();
      return epidx;
    }

    
    inline static int idx_firstLocalProbe(void (Bucket < key, value > ::*)(int lastProbeSize) ) {
      return idx_firstLocalProbe_marshall6();
    }


    
    static int firstLocalProbe(int lastProbeSize) { return idx_firstLocalProbe_marshall6(); }
    
    static void _call_firstLocalProbe_marshall6(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_firstLocalProbe_marshall6(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_firstLocalProbe_marshall6(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_firstLocalProbe_marshall6(PUP::er &p,void *msg);
    /* DECLS: void histCountProbes(probeMessage<key >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_histCountProbes_probeMessage();
    // Entry point index lookup
    
    inline static int idx_histCountProbes_probeMessage() {
      static int epidx = reg_histCountProbes_probeMessage();
      return epidx;
    }

    
    inline static int idx_histCountProbes(void (Bucket < key, value > ::*)(probeMessage<key >* impl_msg) ) {
      return idx_histCountProbes_probeMessage();
    }


    
    static int histCountProbes(probeMessage<key >* impl_msg) { return idx_histCountProbes_probeMessage(); }
    
    static void _call_histCountProbes_probeMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_histCountProbes_probeMessage(void* impl_msg, void* impl_obj);
    /* DECLS: void genNextSamples(sampleMessage<key >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_genNextSamples_sampleMessage();
    // Entry point index lookup
    
    inline static int idx_genNextSamples_sampleMessage() {
      static int epidx = reg_genNextSamples_sampleMessage();
      return epidx;
    }

    
    inline static int idx_genNextSamples(void (Bucket < key, value > ::*)(sampleMessage<key >* impl_msg) ) {
      return idx_genNextSamples_sampleMessage();
    }


    
    static int genNextSamples(sampleMessage<key >* impl_msg) { return idx_genNextSamples_sampleMessage(); }
    
    static void _call_genNextSamples_sampleMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_genNextSamples_sampleMessage(void* impl_msg, void* impl_obj);
    /* DECLS: void sortAll();
     */
    // Entry point registration at startup
    
    static int reg_sortAll_void();
    // Entry point index lookup
    
    inline static int idx_sortAll_void() {
      static int epidx = reg_sortAll_void();
      return epidx;
    }

    
    inline static int idx_sortAll(void (Bucket < key, value > ::*)() ) {
      return idx_sortAll_void();
    }


    
    static int sortAll() { return idx_sortAll_void(); }
    
    static void _call_sortAll_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_sortAll_void(void* impl_msg, void* impl_obj);
    /* DECLS: void stepSort();
     */
    // Entry point registration at startup
    
    static int reg_stepSort_void();
    // Entry point index lookup
    
    inline static int idx_stepSort_void() {
      static int epidx = reg_stepSort_void();
      return epidx;
    }

    
    inline static int idx_stepSort(void (Bucket < key, value > ::*)() ) {
      return idx_stepSort_void();
    }


    
    static int stepSort() { return idx_stepSort_void(); }
    
    static void _call_stepSort_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_stepSort_void(void* impl_msg, void* impl_obj);
    /* DECLS: void Load(data_msg<key,value >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Load_data_msg();
    // Entry point index lookup
    
    inline static int idx_Load_data_msg() {
      static int epidx = reg_Load_data_msg();
      return epidx;
    }

    
    inline static int idx_Load(void (Bucket < key, value > ::*)(data_msg<key,value >* impl_msg) ) {
      return idx_Load_data_msg();
    }


    
    static int Load(data_msg<key,value >* impl_msg) { return idx_Load_data_msg(); }
    
    static void _call_Load_data_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Load_data_msg(void* impl_msg, void* impl_obj);
    /* DECLS: void recvFinalKeys(int srcnode, const sendInfo &s);
     */
    // Entry point registration at startup
    
    static int reg_recvFinalKeys_marshall12();
    // Entry point index lookup
    
    inline static int idx_recvFinalKeys_marshall12() {
      static int epidx = reg_recvFinalKeys_marshall12();
      return epidx;
    }

    
    inline static int idx_recvFinalKeys(void (Bucket < key, value > ::*)(int srcnode, const sendInfo &s) ) {
      return idx_recvFinalKeys_marshall12();
    }


    
    static int recvFinalKeys(int srcnode, const sendInfo &s) { return idx_recvFinalKeys_marshall12(); }
    
    static void _call_recvFinalKeys_marshall12(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_recvFinalKeys_marshall12(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_recvFinalKeys_marshall12(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_recvFinalKeys_marshall12(PUP::er &p,void *msg);
    /* DECLS: void MergingWork();
     */
    // Entry point registration at startup
    
    static int reg_MergingWork_void();
    // Entry point index lookup
    
    inline static int idx_MergingWork_void() {
      static int epidx = reg_MergingWork_void();
      return epidx;
    }

    
    inline static int idx_MergingWork(void (Bucket < key, value > ::*)() ) {
      return idx_MergingWork_void();
    }


    
    static int MergingWork() { return idx_MergingWork_void(); }
    
    static void _call_MergingWork_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_MergingWork_void(void* impl_msg, void* impl_obj);
    /* DECLS: void partialSendOne();
     */
    // Entry point registration at startup
    
    static int reg_partialSendOne_void();
    // Entry point index lookup
    
    inline static int idx_partialSendOne_void() {
      static int epidx = reg_partialSendOne_void();
      return epidx;
    }

    
    inline static int idx_partialSendOne(void (Bucket < key, value > ::*)() ) {
      return idx_partialSendOne_void();
    }


    
    static int partialSendOne() { return idx_partialSendOne_void(); }
    
    static void _call_partialSendOne_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_partialSendOne_void(void* impl_msg, void* impl_obj);
    /* DECLS: void finalProbes(array_msg<key >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_finalProbes_array_msg();
    // Entry point index lookup
    
    inline static int idx_finalProbes_array_msg() {
      static int epidx = reg_finalProbes_array_msg();
      return epidx;
    }

    
    inline static int idx_finalProbes(void (Bucket < key, value > ::*)(array_msg<key >* impl_msg) ) {
      return idx_finalProbes_array_msg();
    }


    
    static int finalProbes(array_msg<key >* impl_msg) { return idx_finalProbes_array_msg(); }
    
    static void _call_finalProbes_array_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_finalProbes_array_msg(void* impl_msg, void* impl_obj);
    /* DECLS: void finish();
     */
    // Entry point registration at startup
    
    static int reg_finish_void();
    // Entry point index lookup
    
    inline static int idx_finish_void() {
      static int epidx = reg_finish_void();
      return epidx;
    }

    
    inline static int idx_finish(void (Bucket < key, value > ::*)() ) {
      return idx_finish_void();
    }


    
    static int finish() { return idx_finish_void(); }
    
    static void _call_finish_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_finish_void(void* impl_msg, void* impl_obj);
    /* DECLS: Bucket(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Bucket_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Bucket_CkMigrateMessage() {
      static int epidx = reg_Bucket_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Bucket_CkMigrateMessage(); }
    
    static void _call_Bucket_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Bucket_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
template < class key, class value >  class CProxyElement_Bucket : public CProxyElement_ArrayElement{
  public:
    typedef Bucket < key, value >  local_t;
    typedef CkIndex_Bucket < key, value >  index_t;
    typedef CProxy_Bucket < key, value >  proxy_t;
    typedef CProxyElement_Bucket < key, value >  element_t;
    typedef CProxySection_Bucket < key, value >  section_t;


    /* TRAM aggregators */

    CProxyElement_Bucket(void) {
    }
    CProxyElement_Bucket(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Bucket < key, value >  *ckLocal(void) const
    { return (Bucket < key, value >  *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
 */
    
    void insert(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
 */
    
    void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SetData();
 */
    
    void SetData(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void genSample(const sampleInfo &sI);
 */
    
    void genSample(const sampleInfo &sI, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
 */
    
    void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void firstLocalProbe(int lastProbeSize);
 */
    
    void firstLocalProbe(int lastProbeSize, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void histCountProbes(probeMessage<key >* impl_msg);
 */
    
    void histCountProbes(probeMessage<key >* impl_msg) ;

/* DECLS: void genNextSamples(sampleMessage<key >* impl_msg);
 */
    
    void genNextSamples(sampleMessage<key >* impl_msg) ;

/* DECLS: void sortAll();
 */
    
    void sortAll(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void stepSort();
 */
    
    void stepSort(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void Load(data_msg<key,value >* impl_msg);
 */
    
    void Load(data_msg<key,value >* impl_msg) ;

/* DECLS: void recvFinalKeys(int srcnode, const sendInfo &s);
 */
    
    void recvFinalKeys(int srcnode, const sendInfo &s, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void MergingWork();
 */
    
    void MergingWork(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void partialSendOne();
 */
    
    void partialSendOne(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void finalProbes(array_msg<key >* impl_msg);
 */
    
    void finalProbes(array_msg<key >* impl_msg) ;

/* DECLS: void finish();
 */
    
    void finish(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Bucket(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- collective proxy -------------- */
template < class key, class value >  class CProxy_Bucket : public CProxy_ArrayElement{
  public:
    typedef Bucket < key, value >  local_t;
    typedef CkIndex_Bucket < key, value >  index_t;
    typedef CProxy_Bucket < key, value >  proxy_t;
    typedef CProxyElement_Bucket < key, value >  element_t;
    typedef CProxySection_Bucket < key, value >  section_t;

    CProxy_Bucket(void) {
    }
    CProxy_Bucket(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Empty array construction
    static CkArrayID ckNew(CkArrayOptions opts = CkArrayOptions()) { return ckCreateEmptyArray(opts); }
    static void      ckNew(CkCallback cb, CkArrayOptions opts = CkArrayOptions()) { ckCreateEmptyArrayAsync(cb, opts); }

    // Generalized array indexing:
    CProxyElement_Bucket < key, value >  operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Bucket < key, value > (ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Bucket < key, value >  operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Bucket < key, value > (ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Bucket < key, value >  operator [] (int idx) const 
        {return CProxyElement_Bucket < key, value > (ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Bucket < key, value >  operator () (int idx) const 
        {return CProxyElement_Bucket < key, value > (ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Bucket(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Bucket(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
 */
    
    static CkArrayID ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
 */
    
    void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SetData();
 */
    
    void SetData(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void genSample(const sampleInfo &sI);
 */
    
    void genSample(const sampleInfo &sI, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
 */
    
    void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void firstLocalProbe(int lastProbeSize);
 */
    
    void firstLocalProbe(int lastProbeSize, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void histCountProbes(probeMessage<key >* impl_msg);
 */
    
    void histCountProbes(probeMessage<key >* impl_msg) ;

/* DECLS: void genNextSamples(sampleMessage<key >* impl_msg);
 */
    
    void genNextSamples(sampleMessage<key >* impl_msg) ;

/* DECLS: void sortAll();
 */
    
    void sortAll(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void stepSort();
 */
    
    void stepSort(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void Load(data_msg<key,value >* impl_msg);
 */
    
    void Load(data_msg<key,value >* impl_msg) ;

/* DECLS: void recvFinalKeys(int srcnode, const sendInfo &s);
 */
    
    void recvFinalKeys(int srcnode, const sendInfo &s, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void MergingWork();
 */
    
    void MergingWork(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void partialSendOne();
 */
    
    void partialSendOne(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void finalProbes(array_msg<key >* impl_msg);
 */
    
    void finalProbes(array_msg<key >* impl_msg) ;

/* DECLS: void finish();
 */
    
    void finish(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Bucket(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- section proxy -------------- */
template < class key, class value >  class CProxySection_Bucket : public CProxySection_ArrayElement{
  public:
    typedef Bucket < key, value >  local_t;
    typedef CkIndex_Bucket < key, value >  index_t;
    typedef CProxy_Bucket < key, value >  proxy_t;
    typedef CProxyElement_Bucket < key, value >  element_t;
    typedef CProxySection_Bucket < key, value >  section_t;

    CProxySection_Bucket(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Bucket < key, value >  operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Bucket < key, value > (ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Bucket < key, value >  operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Bucket < key, value > (ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Bucket < key, value >  operator [] (int idx) const 
        {return CProxyElement_Bucket < key, value > (ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Bucket < key, value >  operator () (int idx) const 
        {return CProxyElement_Bucket < key, value > (ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      CkVec<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.push_back(CkArrayIndex1D(i));
      return CkSectionID(aid, al.getVec(), al.size(), factor);
    } 
    CProxySection_Bucket(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Bucket(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems,nElems, factor) { ckAutoDelegate(); }
    CProxySection_Bucket(const CkSectionID &sid)  
        :CProxySection_ArrayElement(sid) { ckAutoDelegate(); }
    CProxySection_Bucket(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Bucket(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) { ckAutoDelegate(); }
    CProxySection_Bucket(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, int factor) 
        :CProxySection_ArrayElement(n,aid,elems,nElems, factor) { ckAutoDelegate(); }
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    void ckAutoDelegate(int opts=1) {
      if(ckIsDelegated()) return;
      CProxySection_ArrayElement::ckAutoDelegate(opts);
    } 
    void setReductionClient(CkCallback *cb) {
      CProxySection_ArrayElement::setReductionClient(cb);
    } 
    void resetSection() {
      CProxySection_ArrayElement::resetSection();
    } 
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, CkCallback &cb, int userData=-1, int fragSize=-1);
/* DECLS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
 */
    

/* DECLS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
 */
    
    void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SetData();
 */
    
    void SetData(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void genSample(const sampleInfo &sI);
 */
    
    void genSample(const sampleInfo &sI, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
 */
    
    void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void firstLocalProbe(int lastProbeSize);
 */
    
    void firstLocalProbe(int lastProbeSize, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void histCountProbes(probeMessage<key >* impl_msg);
 */
    
    void histCountProbes(probeMessage<key >* impl_msg) ;

/* DECLS: void genNextSamples(sampleMessage<key >* impl_msg);
 */
    
    void genNextSamples(sampleMessage<key >* impl_msg) ;

/* DECLS: void sortAll();
 */
    
    void sortAll(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void stepSort();
 */
    
    void stepSort(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void Load(data_msg<key,value >* impl_msg);
 */
    
    void Load(data_msg<key,value >* impl_msg) ;

/* DECLS: void recvFinalKeys(int srcnode, const sendInfo &s);
 */
    
    void recvFinalKeys(int srcnode, const sendInfo &s, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void MergingWork();
 */
    
    void MergingWork(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void partialSendOne();
 */
    
    void partialSendOne(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void finalProbes(array_msg<key >* impl_msg);
 */
    
    void finalProbes(array_msg<key >* impl_msg) ;

/* DECLS: void finish();
 */
    
    void finish(const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Bucket(CkMigrateMessage* impl_msg);
 */

};
#define Bucket_SDAG_CODE 
template < class key, class value > 
struct CBase_Bucket;

class wrap_ptr;

/* DECLS: template < class key, class value > nodegroup NodeManager: NodeGroup{
NodeManager(const key &_minkey, const key &_maxkey);
void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
void collectSamples(const sampleInfo &sI);
void assembleSamples(const std::vector<key > &proc_sample);
void loadkeys(int dest, const sendInfo &inf);
void sendOne(int dest);
void releaseBufMsgs();
void recvOne(data_msg<key,value >* impl_msg);
void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
void finishOne();
void localhist(data_msg<key,value >* impl_msg);
void depositHist();
void sendToBuckets(data_msg<key,value >* impl_msg);
};
 */
template < class key, class value >  class NodeManager;
template < class key, class value >  class CkIndex_NodeManager;
template < class key, class value >  class CProxy_NodeManager;
template < class key, class value >  class CProxyElement_NodeManager;
template < class key, class value >  class CProxySection_NodeManager;
/* --------------- index object ------------------ */
template < class key, class value > class CkIndex_NodeManager:public CkIndex_NodeGroup{
  public:
    typedef NodeManager < key, value >  local_t;
    typedef CkIndex_NodeManager < key, value >  index_t;
    typedef CProxy_NodeManager < key, value >  proxy_t;
    typedef CProxyElement_NodeManager < key, value >  element_t;
    typedef CProxySection_NodeManager < key, value >  section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: NodeManager(const key &_minkey, const key &_maxkey);
     */
    // Entry point registration at startup
    
    static int reg_NodeManager_marshall1();
    // Entry point index lookup
    
    inline static int idx_NodeManager_marshall1() {
      static int epidx = reg_NodeManager_marshall1();
      return epidx;
    }

    
    static int ckNew(const key &_minkey, const key &_maxkey) { return idx_NodeManager_marshall1(); }
    
    static void _call_NodeManager_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_NodeManager_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_NodeManager_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_NodeManager_marshall1(PUP::er &p,void *msg);
    /* DECLS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
     */
    // Entry point registration at startup
    
    static int reg_registerLocalChare_marshall2();
    // Entry point index lookup
    
    inline static int idx_registerLocalChare_marshall2() {
      static int epidx = reg_registerLocalChare_marshall2();
      return epidx;
    }

    
    inline static int idx_registerLocalChare(void (NodeManager < key, value > ::*)(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter) ) {
      return idx_registerLocalChare_marshall2();
    }


    
    static int registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter) { return idx_registerLocalChare_marshall2(); }
    
    static void _call_registerLocalChare_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_registerLocalChare_marshall2(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_registerLocalChare_marshall2(PUP::er &p,void *msg);
    /* DECLS: void collectSamples(const sampleInfo &sI);
     */
    // Entry point registration at startup
    
    static int reg_collectSamples_marshall3();
    // Entry point index lookup
    
    inline static int idx_collectSamples_marshall3() {
      static int epidx = reg_collectSamples_marshall3();
      return epidx;
    }

    
    inline static int idx_collectSamples(void (NodeManager < key, value > ::*)(const sampleInfo &sI) ) {
      return idx_collectSamples_marshall3();
    }


    
    static int collectSamples(const sampleInfo &sI) { return idx_collectSamples_marshall3(); }
    
    static void _call_collectSamples_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_collectSamples_marshall3(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_collectSamples_marshall3(PUP::er &p,void *msg);
    /* DECLS: void assembleSamples(const std::vector<key > &proc_sample);
     */
    // Entry point registration at startup
    
    static int reg_assembleSamples_marshall4();
    // Entry point index lookup
    
    inline static int idx_assembleSamples_marshall4() {
      static int epidx = reg_assembleSamples_marshall4();
      return epidx;
    }

    
    inline static int idx_assembleSamples(void (NodeManager < key, value > ::*)(const std::vector<key > &proc_sample) ) {
      return idx_assembleSamples_marshall4();
    }


    
    static int assembleSamples(const std::vector<key > &proc_sample) { return idx_assembleSamples_marshall4(); }
    
    static void _call_assembleSamples_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_assembleSamples_marshall4(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_assembleSamples_marshall4(PUP::er &p,void *msg);
    /* DECLS: void loadkeys(int dest, const sendInfo &inf);
     */
    // Entry point registration at startup
    
    static int reg_loadkeys_marshall5();
    // Entry point index lookup
    
    inline static int idx_loadkeys_marshall5() {
      static int epidx = reg_loadkeys_marshall5();
      return epidx;
    }

    
    inline static int idx_loadkeys(void (NodeManager < key, value > ::*)(int dest, const sendInfo &inf) ) {
      return idx_loadkeys_marshall5();
    }


    
    static int loadkeys(int dest, const sendInfo &inf) { return idx_loadkeys_marshall5(); }
    
    static void _call_loadkeys_marshall5(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_loadkeys_marshall5(void* impl_msg, void* impl_obj);
    
    static void _marshallmessagepup_loadkeys_marshall5(PUP::er &p,void *msg);
    /* DECLS: void sendOne(int dest);
     */
    // Entry point registration at startup
    
    static int reg_sendOne_marshall6();
    // Entry point index lookup
    
    inline static int idx_sendOne_marshall6() {
      static int epidx = reg_sendOne_marshall6();
      return epidx;
    }

    
    inline static int idx_sendOne(void (NodeManager < key, value > ::*)(int dest) ) {
      return idx_sendOne_marshall6();
    }


    
    static int sendOne(int dest) { return idx_sendOne_marshall6(); }
    
    static void _call_sendOne_marshall6(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_sendOne_marshall6(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_sendOne_marshall6(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_sendOne_marshall6(PUP::er &p,void *msg);
    /* DECLS: void releaseBufMsgs();
     */
    // Entry point registration at startup
    
    static int reg_releaseBufMsgs_void();
    // Entry point index lookup
    
    inline static int idx_releaseBufMsgs_void() {
      static int epidx = reg_releaseBufMsgs_void();
      return epidx;
    }

    
    inline static int idx_releaseBufMsgs(void (NodeManager < key, value > ::*)() ) {
      return idx_releaseBufMsgs_void();
    }


    
    static int releaseBufMsgs() { return idx_releaseBufMsgs_void(); }
    
    static void _call_releaseBufMsgs_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_releaseBufMsgs_void(void* impl_msg, void* impl_obj);
    /* DECLS: void recvOne(data_msg<key,value >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_recvOne_data_msg();
    // Entry point index lookup
    
    inline static int idx_recvOne_data_msg() {
      static int epidx = reg_recvOne_data_msg();
      return epidx;
    }

    
    inline static int idx_recvOne(void (NodeManager < key, value > ::*)(data_msg<key,value >* impl_msg) ) {
      return idx_recvOne_data_msg();
    }


    
    static int recvOne(data_msg<key,value >* impl_msg) { return idx_recvOne_data_msg(); }
    
    static void _call_recvOne_data_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_recvOne_data_msg(void* impl_msg, void* impl_obj);
    /* DECLS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
     */
    // Entry point registration at startup
    
    static int reg_handleOne_marshall9();
    // Entry point index lookup
    
    inline static int idx_handleOne_marshall9() {
      static int epidx = reg_handleOne_marshall9();
      return epidx;
    }

    
    inline static int idx_handleOne(void (NodeManager < key, value > ::*)(const wrap_ptr &msg, int sampleInd, int numsamples) ) {
      return idx_handleOne_marshall9();
    }


    
    static int handleOne(const wrap_ptr &msg, int sampleInd, int numsamples) { return idx_handleOne_marshall9(); }
    
    static void _call_handleOne_marshall9(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_handleOne_marshall9(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_handleOne_marshall9(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_handleOne_marshall9(PUP::er &p,void *msg);
    /* DECLS: void finishOne();
     */
    // Entry point registration at startup
    
    static int reg_finishOne_void();
    // Entry point index lookup
    
    inline static int idx_finishOne_void() {
      static int epidx = reg_finishOne_void();
      return epidx;
    }

    
    inline static int idx_finishOne(void (NodeManager < key, value > ::*)() ) {
      return idx_finishOne_void();
    }


    
    static int finishOne() { return idx_finishOne_void(); }
    
    static void _call_finishOne_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_finishOne_void(void* impl_msg, void* impl_obj);
    /* DECLS: void localhist(data_msg<key,value >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_localhist_data_msg();
    // Entry point index lookup
    
    inline static int idx_localhist_data_msg() {
      static int epidx = reg_localhist_data_msg();
      return epidx;
    }

    
    inline static int idx_localhist(void (NodeManager < key, value > ::*)(data_msg<key,value >* impl_msg) ) {
      return idx_localhist_data_msg();
    }


    
    static int localhist(data_msg<key,value >* impl_msg) { return idx_localhist_data_msg(); }
    
    static void _call_localhist_data_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_localhist_data_msg(void* impl_msg, void* impl_obj);
    /* DECLS: void depositHist();
     */
    // Entry point registration at startup
    
    static int reg_depositHist_void();
    // Entry point index lookup
    
    inline static int idx_depositHist_void() {
      static int epidx = reg_depositHist_void();
      return epidx;
    }

    
    inline static int idx_depositHist(void (NodeManager < key, value > ::*)() ) {
      return idx_depositHist_void();
    }


    
    static int depositHist() { return idx_depositHist_void(); }
    
    static void _call_depositHist_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_depositHist_void(void* impl_msg, void* impl_obj);
    /* DECLS: void sendToBuckets(data_msg<key,value >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_sendToBuckets_data_msg();
    // Entry point index lookup
    
    inline static int idx_sendToBuckets_data_msg() {
      static int epidx = reg_sendToBuckets_data_msg();
      return epidx;
    }

    
    inline static int idx_sendToBuckets(void (NodeManager < key, value > ::*)(data_msg<key,value >* impl_msg) ) {
      return idx_sendToBuckets_data_msg();
    }


    
    static int sendToBuckets(data_msg<key,value >* impl_msg) { return idx_sendToBuckets_data_msg(); }
    
    static void _call_sendToBuckets_data_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_sendToBuckets_data_msg(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
template < class key, class value > class CProxyElement_NodeManager: public CProxyElement_NodeGroup{
  public:
    typedef NodeManager < key, value >  local_t;
    typedef CkIndex_NodeManager < key, value >  index_t;
    typedef CProxy_NodeManager < key, value >  proxy_t;
    typedef CProxyElement_NodeManager < key, value >  element_t;
    typedef CProxySection_NodeManager < key, value >  section_t;


    /* TRAM aggregators */

    CProxyElement_NodeManager(void) {
    }
    CProxyElement_NodeManager(const IrrGroup *g) : CProxyElement_NodeGroup(g){
    }
    CProxyElement_NodeManager(CkGroupID _gid,int _onPE,CK_DELCTOR_PARAM) : CProxyElement_NodeGroup(_gid,_onPE,CK_DELCTOR_ARGS){
    }
    CProxyElement_NodeManager(CkGroupID _gid,int _onPE) : CProxyElement_NodeGroup(_gid,_onPE){
    }

    int ckIsDelegated(void) const
    { return CProxyElement_NodeGroup::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_NodeGroup::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_NodeGroup::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_NodeGroup::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxyElement_NodeGroup::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxyElement_NodeGroup::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxyElement_NodeGroup::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_NodeGroup::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_NodeGroup::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_NodeGroup::ckSetReductionClient(cb); }
int ckGetGroupPe(void) const
{return CProxyElement_NodeGroup::ckGetGroupPe();}

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_NodeGroup::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_NodeGroup::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_NodeGroup::pup(p);
    }
    void ckSetGroupID(CkGroupID g) {
      CProxyElement_NodeGroup::ckSetGroupID(g);
    }
    NodeManager < key, value > * ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static NodeManager < key, value > * ckLocalBranch(CkGroupID gID) {
      return (NodeManager < key, value > *)CkLocalNodeBranch(gID);
    }
/* DECLS: NodeManager(const key &_minkey, const key &_maxkey);
 */
    

/* DECLS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
 */
    
    void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void collectSamples(const sampleInfo &sI);
 */
    
    void collectSamples(const sampleInfo &sI, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void assembleSamples(const std::vector<key > &proc_sample);
 */
    
    void assembleSamples(const std::vector<key > &proc_sample, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void loadkeys(int dest, const sendInfo &inf);
 */
    
    void loadkeys(int dest, const sendInfo &inf, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sendOne(int dest);
 */
    
    void sendOne(int dest, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void releaseBufMsgs();
 */
    
    void releaseBufMsgs(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void recvOne(data_msg<key,value >* impl_msg);
 */
    
    void recvOne(data_msg<key,value >* impl_msg);

/* DECLS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
 */
    
    void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void finishOne();
 */
    
    void finishOne(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void localhist(data_msg<key,value >* impl_msg);
 */
    
    void localhist(data_msg<key,value >* impl_msg);

/* DECLS: void depositHist();
 */
    
    void depositHist(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sendToBuckets(data_msg<key,value >* impl_msg);
 */
    
    void sendToBuckets(data_msg<key,value >* impl_msg);

};
/* ---------------- collective proxy -------------- */
template < class key, class value > class CProxy_NodeManager: public CProxy_NodeGroup{
  public:
    typedef NodeManager < key, value >  local_t;
    typedef CkIndex_NodeManager < key, value >  index_t;
    typedef CProxy_NodeManager < key, value >  proxy_t;
    typedef CProxyElement_NodeManager < key, value >  element_t;
    typedef CProxySection_NodeManager < key, value >  section_t;

    CProxy_NodeManager(void) {
    }
    CProxy_NodeManager(const IrrGroup *g) : CProxy_NodeGroup(g){
    }
    CProxy_NodeManager(CkGroupID _gid,CK_DELCTOR_PARAM) : CProxy_NodeGroup(_gid,CK_DELCTOR_ARGS){  }
    CProxy_NodeManager(CkGroupID _gid) : CProxy_NodeGroup(_gid){  }
    CProxyElement_NodeManager < key, value >  operator[](int onPE) const
      {return CProxyElement_NodeManager < key, value > (ckGetGroupID(),onPE,CK_DELCTOR_CALL);}

    int ckIsDelegated(void) const
    { return CProxy_NodeGroup::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_NodeGroup::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_NodeGroup::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_NodeGroup::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxy_NodeGroup::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxy_NodeGroup::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxy_NodeGroup::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_NodeGroup::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_NodeGroup::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_NodeGroup::ckSetReductionClient(cb); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_NodeGroup::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_NodeGroup::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_NodeGroup::pup(p);
    }
    void ckSetGroupID(CkGroupID g) {
      CProxy_NodeGroup::ckSetGroupID(g);
    }
    NodeManager < key, value > * ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static NodeManager < key, value > * ckLocalBranch(CkGroupID gID) {
      return (NodeManager < key, value > *)CkLocalNodeBranch(gID);
    }
/* DECLS: NodeManager(const key &_minkey, const key &_maxkey);
 */
    
    static CkGroupID ckNew(const key &_minkey, const key &_maxkey, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_NodeManager(const key &_minkey, const key &_maxkey, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
 */
    
    void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void collectSamples(const sampleInfo &sI);
 */
    
    void collectSamples(const sampleInfo &sI, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void assembleSamples(const std::vector<key > &proc_sample);
 */
    
    void assembleSamples(const std::vector<key > &proc_sample, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void loadkeys(int dest, const sendInfo &inf);
 */
    
    void loadkeys(int dest, const sendInfo &inf, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sendOne(int dest);
 */
    
    void sendOne(int dest, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void releaseBufMsgs();
 */
    
    void releaseBufMsgs(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void recvOne(data_msg<key,value >* impl_msg);
 */
    
    void recvOne(data_msg<key,value >* impl_msg);

/* DECLS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
 */
    
    void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void finishOne();
 */
    
    void finishOne(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void localhist(data_msg<key,value >* impl_msg);
 */
    
    void localhist(data_msg<key,value >* impl_msg);

/* DECLS: void depositHist();
 */
    
    void depositHist(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sendToBuckets(data_msg<key,value >* impl_msg);
 */
    
    void sendToBuckets(data_msg<key,value >* impl_msg);

};
/* ---------------- section proxy -------------- */
template < class key, class value > class CProxySection_NodeManager: public CProxySection_NodeGroup{
  public:
    typedef NodeManager < key, value >  local_t;
    typedef CkIndex_NodeManager < key, value >  index_t;
    typedef CProxy_NodeManager < key, value >  proxy_t;
    typedef CProxyElement_NodeManager < key, value >  element_t;
    typedef CProxySection_NodeManager < key, value >  section_t;

    CProxySection_NodeManager(void) {
    }
    CProxySection_NodeManager(const IrrGroup *g) : CProxySection_NodeGroup(g){
    }
    CProxySection_NodeManager(const CkGroupID &_gid,const int *_pelist,int _npes,CK_DELCTOR_PARAM) : CProxySection_NodeGroup(_gid,_pelist,_npes,CK_DELCTOR_ARGS){  }
    CProxySection_NodeManager(const CkGroupID &_gid,const int *_pelist,int _npes) : CProxySection_NodeGroup(_gid,_pelist,_npes){  }
    CProxySection_NodeManager(int n,const CkGroupID *_gid, int const * const *_pelist,const int *_npes) : CProxySection_NodeGroup(n,_gid,_pelist,_npes){  }
    CProxySection_NodeManager(int n,const CkGroupID *_gid, int const * const *_pelist,const int *_npes,CK_DELCTOR_PARAM) : CProxySection_NodeGroup(n,_gid,_pelist,_npes,CK_DELCTOR_ARGS){  }

    int ckIsDelegated(void) const
    { return CProxySection_NodeGroup::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_NodeGroup::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_NodeGroup::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_NodeGroup::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxySection_NodeGroup::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxySection_NodeGroup::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxySection_NodeGroup::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_NodeGroup::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_NodeGroup::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_NodeGroup::ckSetReductionClient(cb); }
inline int ckGetNumSections() const
{ return CProxySection_NodeGroup::ckGetNumSections(); }
inline CkSectionInfo &ckGetSectionInfo()
{ return CProxySection_NodeGroup::ckGetSectionInfo(); }
inline CkSectionID *ckGetSectionIDs()
{ return CProxySection_NodeGroup::ckGetSectionIDs(); }
inline CkSectionID &ckGetSectionID()
{ return CProxySection_NodeGroup::ckGetSectionID(); }
inline CkSectionID &ckGetSectionID(int i)
{ return CProxySection_NodeGroup::ckGetSectionID(i); }
inline CkGroupID ckGetGroupIDn(int i) const
{ return CProxySection_NodeGroup::ckGetGroupIDn(i); }
inline int *ckGetElements() const
{ return CProxySection_NodeGroup::ckGetElements(); }
inline int *ckGetElements(int i) const
{ return CProxySection_NodeGroup::ckGetElements(i); }
inline int ckGetNumElements() const
{ return CProxySection_NodeGroup::ckGetNumElements(); } 
inline int ckGetNumElements(int i) const
{ return CProxySection_NodeGroup::ckGetNumElements(i); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_NodeGroup::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_NodeGroup::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_NodeGroup::pup(p);
    }
    void ckSetGroupID(CkGroupID g) {
      CProxySection_NodeGroup::ckSetGroupID(g);
    }
    NodeManager < key, value > * ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static NodeManager < key, value > * ckLocalBranch(CkGroupID gID) {
      return (NodeManager < key, value > *)CkLocalNodeBranch(gID);
    }
/* DECLS: NodeManager(const key &_minkey, const key &_maxkey);
 */
    

/* DECLS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
 */
    
    void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void collectSamples(const sampleInfo &sI);
 */
    
    void collectSamples(const sampleInfo &sI, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void assembleSamples(const std::vector<key > &proc_sample);
 */
    
    void assembleSamples(const std::vector<key > &proc_sample, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void loadkeys(int dest, const sendInfo &inf);
 */
    
    void loadkeys(int dest, const sendInfo &inf, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sendOne(int dest);
 */
    
    void sendOne(int dest, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void releaseBufMsgs();
 */
    
    void releaseBufMsgs(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void recvOne(data_msg<key,value >* impl_msg);
 */
    
    void recvOne(data_msg<key,value >* impl_msg);

/* DECLS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
 */
    
    void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void finishOne();
 */
    
    void finishOne(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void localhist(data_msg<key,value >* impl_msg);
 */
    
    void localhist(data_msg<key,value >* impl_msg);

/* DECLS: void depositHist();
 */
    
    void depositHist(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sendToBuckets(data_msg<key,value >* impl_msg);
 */
    
    void sendToBuckets(data_msg<key,value >* impl_msg);

};
#define NodeManager_SDAG_CODE 
template < class key, class value > 
struct CBase_NodeManager;




/* ---------------- method closures -------------- */
template < class key, class value > class Closure_Main {
  public:


    struct Exit_2_closure;


    struct DataReady_3_closure;






};





/* ---------------- method closures -------------- */
template < class key, class value > class Closure_Sorter {
  public:







};



/* ---------------- method closures -------------- */
template < class key, class value > class Closure_Bucket {
  public:


    struct startBarrier_2_closure;


    struct SetData_3_closure;


    struct genSample_4_closure;


    struct firstProbe_5_closure;


    struct firstLocalProbe_6_closure;




    struct sortAll_9_closure;


    struct stepSort_10_closure;



    struct recvFinalKeys_12_closure;


    struct MergingWork_13_closure;


    struct partialSendOne_14_closure;



    struct finish_16_closure;


};


/* ---------------- method closures -------------- */
template < class key, class value > class Closure_NodeManager {
  public:


    struct registerLocalChare_2_closure;


    struct collectSamples_3_closure;


    struct assembleSamples_4_closure;


    struct loadkeys_5_closure;


    struct sendOne_6_closure;


    struct releaseBufMsgs_7_closure;



    struct handleOne_9_closure;


    struct finishOne_10_closure;



    struct depositHist_12_closure;


};

extern void _registerHistSort(void);
#endif
