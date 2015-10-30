#ifndef _DECL_HistSort_H_
#define _DECL_HistSort_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
#include "defs.h"


/* DECLS: template < class key, class value > chare Main: Chare{
Main(int _num_buckets);
void Exit(void);
void DataReady(void);
void init_isum(CkReductionMsg* impl_msg);
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
    /* DECLS: Main(int _num_buckets);
     */
    // Entry point registration at startup
    
    static int reg_Main_marshall1();
    // Entry point index lookup
    
    inline static int idx_Main_marshall1() {
      static int epidx = reg_Main_marshall1();
      return epidx;
    }

    
    static int ckNew(int _num_buckets) { return idx_Main_marshall1(); }
    
    static void _call_Main_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Main_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Main_marshall1(PUP::er &p,void *msg);
    /* DECLS: void Exit(void);
     */
    // Entry point registration at startup
    
    static int reg_Exit_void();
    // Entry point index lookup
    
    inline static int idx_Exit_void() {
      static int epidx = reg_Exit_void();
      return epidx;
    }

    
    inline static int idx_Exit(void (Main < key, value > ::*)(void) ) {
      return idx_Exit_void();
    }


    
    static int Exit(void) { return idx_Exit_void(); }
    
    static void _call_Exit_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Exit_void(void* impl_msg, void* impl_obj);
    /* DECLS: void DataReady(void);
     */
    // Entry point registration at startup
    
    static int reg_DataReady_void();
    // Entry point index lookup
    
    inline static int idx_DataReady_void() {
      static int epidx = reg_DataReady_void();
      return epidx;
    }

    
    inline static int idx_DataReady(void (Main < key, value > ::*)(void) ) {
      return idx_DataReady_void();
    }


    
    static int DataReady(void) { return idx_DataReady_void(); }
    
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
    {       CProxy_Chare::pup(p); }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main < key, value >  *ckLocal(void) const
    { return (Main < key, value >  *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(int _num_buckets);
 */
    static CkChareID ckNew(int _num_buckets, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int _num_buckets, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Main(int _num_buckets, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void Exit(void);
 */
    
    void Exit(void);

/* DECLS: void DataReady(void);
 */
    
    void DataReady(void);

/* DECLS: void init_isum(CkReductionMsg* impl_msg);
 */
    
    void init_isum(CkReductionMsg* impl_msg);

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

/* DECLS: template < class key, class value > message first_probe{
key splitter_guesses[];
}
;
 */
template < class key, class value > class first_probe;
template < class key, class value > class CMessage_first_probe:public CkMessage{
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
    CMessage_first_probe < key, value > ();
    static void *pack(first_probe < key, value >  *p);
    static first_probe < key, value > * unpack(void* p);
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

/* DECLS: template < class key > message next_probe{
key splitter_guesses[];
charm_resolved_range<key > send_info[];
}
;
 */
template < class key > class next_probe;
template < class key > class CMessage_next_probe:public CkMessage{
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
    CMessage_next_probe < key > ();
    static void *pack(next_probe < key >  *p);
    static next_probe < key > * unpack(void* p);
    void *operator new(size_t, int, int);
    void *operator new(size_t, int, int, const int);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, int, int){dealloc(p);}
    void operator delete(void *p, int, int, const int){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: template < class key, class value > message data_msg{
kv_pair<key,value > pairs[];
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

/* DECLS: template < class key, class value > chare Sorter: Chare{
Sorter(void);
Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max);
Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par);
void Begin(void);
void Begin(const tuning_params &par);
void Histogram(CkReductionMsg* impl_msg);
void Done(CkReductionMsg* impl_msg);
void SanityCheck(CkReductionMsg* impl_msg);
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
    /* DECLS: Sorter(void);
     */
    // Entry point registration at startup
    
    static int reg_Sorter_void();
    // Entry point index lookup
    
    inline static int idx_Sorter_void() {
      static int epidx = reg_Sorter_void();
      return epidx;
    }

    
    static int ckNew(void) { return idx_Sorter_void(); }
    
    static void _call_Sorter_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Sorter_void(void* impl_msg, void* impl_obj);
    /* DECLS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max);
     */
    // Entry point registration at startup
    
    static int reg_Sorter_marshall2();
    // Entry point index lookup
    
    inline static int idx_Sorter_marshall2() {
      static int epidx = reg_Sorter_marshall2();
      return epidx;
    }

    
    static int ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max) { return idx_Sorter_marshall2(); }
    
    static void _call_Sorter_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Sorter_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Sorter_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Sorter_marshall2(PUP::er &p,void *msg);
    /* DECLS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par);
     */
    // Entry point registration at startup
    
    static int reg_Sorter_marshall3();
    // Entry point index lookup
    
    inline static int idx_Sorter_marshall3() {
      static int epidx = reg_Sorter_marshall3();
      return epidx;
    }

    
    static int ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par) { return idx_Sorter_marshall3(); }
    
    static void _call_Sorter_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Sorter_marshall3(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Sorter_marshall3(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Sorter_marshall3(PUP::er &p,void *msg);
    /* DECLS: void Begin(void);
     */
    // Entry point registration at startup
    
    static int reg_Begin_void();
    // Entry point index lookup
    
    inline static int idx_Begin_void() {
      static int epidx = reg_Begin_void();
      return epidx;
    }

    
    inline static int idx_Begin(void (Sorter < key, value > ::*)(void) ) {
      return idx_Begin_void();
    }


    
    static int Begin(void) { return idx_Begin_void(); }
    
    static void _call_Begin_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Begin_void(void* impl_msg, void* impl_obj);
    /* DECLS: void Begin(const tuning_params &par);
     */
    // Entry point registration at startup
    
    static int reg_Begin_marshall5();
    // Entry point index lookup
    
    inline static int idx_Begin_marshall5() {
      static int epidx = reg_Begin_marshall5();
      return epidx;
    }

    
    inline static int idx_Begin(void (Sorter < key, value > ::*)(const tuning_params &par) ) {
      return idx_Begin_marshall5();
    }


    
    static int Begin(const tuning_params &par) { return idx_Begin_marshall5(); }
    
    static void _call_Begin_marshall5(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Begin_marshall5(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Begin_marshall5(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Begin_marshall5(PUP::er &p,void *msg);
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
    {       CProxy_Chare::pup(p); }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Sorter < key, value >  *ckLocal(void) const
    { return (Sorter < key, value >  *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Sorter(void);
 */
    static CkChareID ckNew(int onPE=CK_PE_ANY);
    static void ckNew(CkChareID* pcid, int onPE=CK_PE_ANY);

/* DECLS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max);
 */
    static CkChareID ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par);
 */
    static CkChareID ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void Begin(void);
 */
    
    void Begin(void);

/* DECLS: void Begin(const tuning_params &par);
 */
    
    void Begin(const tuning_params &par, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void Histogram(CkReductionMsg* impl_msg);
 */
    
    void Histogram(CkReductionMsg* impl_msg);

/* DECLS: void Done(CkReductionMsg* impl_msg);
 */
    
    void Done(CkReductionMsg* impl_msg);

/* DECLS: void SanityCheck(CkReductionMsg* impl_msg);
 */
    
    void SanityCheck(CkReductionMsg* impl_msg);

};
#define Sorter_SDAG_CODE 
template < class key, class value > 
struct CBase_Sorter;

/* DECLS: template < class key, class value > array Bucket: ArrayElement{
Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
void StepSort(void);
void CleanSplitters(void);
void SetCallback(const CkCallback &cb);
void SetData(void);
void SetData(data_msg<key,value >* impl_msg);
void CountFirstProbe(first_probe<key,value >* impl_msg);
void CountProbe(next_probe<key >* impl_msg);
void SendPortion(int k, int npd);
void SendAll(next_probe<key >* impl_msg);
void Load(data_msg<key,value >* impl_msg);
void Load(void);
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
    /* DECLS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
     */
    // Entry point registration at startup
    
    static int reg_Bucket_marshall1();
    // Entry point index lookup
    
    inline static int idx_Bucket_marshall1() {
      static int epidx = reg_Bucket_marshall1();
      return epidx;
    }

    
    static int ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max) { return idx_Bucket_marshall1(); }
    
    static void _call_Bucket_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Bucket_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Bucket_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Bucket_marshall1(PUP::er &p,void *msg);
    /* DECLS: void StepSort(void);
     */
    // Entry point registration at startup
    
    static int reg_StepSort_void();
    // Entry point index lookup
    
    inline static int idx_StepSort_void() {
      static int epidx = reg_StepSort_void();
      return epidx;
    }

    
    inline static int idx_StepSort(void (Bucket < key, value > ::*)(void) ) {
      return idx_StepSort_void();
    }


    
    static int StepSort(void) { return idx_StepSort_void(); }
    
    static void _call_StepSort_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_StepSort_void(void* impl_msg, void* impl_obj);
    /* DECLS: void CleanSplitters(void);
     */
    // Entry point registration at startup
    
    static int reg_CleanSplitters_void();
    // Entry point index lookup
    
    inline static int idx_CleanSplitters_void() {
      static int epidx = reg_CleanSplitters_void();
      return epidx;
    }

    
    inline static int idx_CleanSplitters(void (Bucket < key, value > ::*)(void) ) {
      return idx_CleanSplitters_void();
    }


    
    static int CleanSplitters(void) { return idx_CleanSplitters_void(); }
    
    static void _call_CleanSplitters_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_CleanSplitters_void(void* impl_msg, void* impl_obj);
    /* DECLS: void SetCallback(const CkCallback &cb);
     */
    // Entry point registration at startup
    
    static int reg_SetCallback_marshall4();
    // Entry point index lookup
    
    inline static int idx_SetCallback_marshall4() {
      static int epidx = reg_SetCallback_marshall4();
      return epidx;
    }

    
    inline static int idx_SetCallback(void (Bucket < key, value > ::*)(const CkCallback &cb) ) {
      return idx_SetCallback_marshall4();
    }


    
    static int SetCallback(const CkCallback &cb) { return idx_SetCallback_marshall4(); }
    
    static void _call_SetCallback_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SetCallback_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_SetCallback_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_SetCallback_marshall4(PUP::er &p,void *msg);
    /* DECLS: void SetData(void);
     */
    // Entry point registration at startup
    
    static int reg_SetData_void();
    // Entry point index lookup
    
    inline static int idx_SetData_void() {
      static int epidx = reg_SetData_void();
      return epidx;
    }

    
    inline static int idx_SetData(void (Bucket < key, value > ::*)(void) ) {
      return idx_SetData_void();
    }


    
    static int SetData(void) { return idx_SetData_void(); }
    
    static void _call_SetData_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SetData_void(void* impl_msg, void* impl_obj);
    /* DECLS: void SetData(data_msg<key,value >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_SetData_data_msg();
    // Entry point index lookup
    
    inline static int idx_SetData_data_msg() {
      static int epidx = reg_SetData_data_msg();
      return epidx;
    }

    
    inline static int idx_SetData(void (Bucket < key, value > ::*)(data_msg<key,value >* impl_msg) ) {
      return idx_SetData_data_msg();
    }


    
    static int SetData(data_msg<key,value >* impl_msg) { return idx_SetData_data_msg(); }
    
    static void _call_SetData_data_msg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SetData_data_msg(void* impl_msg, void* impl_obj);
    /* DECLS: void CountFirstProbe(first_probe<key,value >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_CountFirstProbe_first_probe();
    // Entry point index lookup
    
    inline static int idx_CountFirstProbe_first_probe() {
      static int epidx = reg_CountFirstProbe_first_probe();
      return epidx;
    }

    
    inline static int idx_CountFirstProbe(void (Bucket < key, value > ::*)(first_probe<key,value >* impl_msg) ) {
      return idx_CountFirstProbe_first_probe();
    }


    
    static int CountFirstProbe(first_probe<key,value >* impl_msg) { return idx_CountFirstProbe_first_probe(); }
    
    static void _call_CountFirstProbe_first_probe(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_CountFirstProbe_first_probe(void* impl_msg, void* impl_obj);
    /* DECLS: void CountProbe(next_probe<key >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_CountProbe_next_probe();
    // Entry point index lookup
    
    inline static int idx_CountProbe_next_probe() {
      static int epidx = reg_CountProbe_next_probe();
      return epidx;
    }

    
    inline static int idx_CountProbe(void (Bucket < key, value > ::*)(next_probe<key >* impl_msg) ) {
      return idx_CountProbe_next_probe();
    }


    
    static int CountProbe(next_probe<key >* impl_msg) { return idx_CountProbe_next_probe(); }
    
    static void _call_CountProbe_next_probe(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_CountProbe_next_probe(void* impl_msg, void* impl_obj);
    /* DECLS: void SendPortion(int k, int npd);
     */
    // Entry point registration at startup
    
    static int reg_SendPortion_marshall9();
    // Entry point index lookup
    
    inline static int idx_SendPortion_marshall9() {
      static int epidx = reg_SendPortion_marshall9();
      return epidx;
    }

    
    inline static int idx_SendPortion(void (Bucket < key, value > ::*)(int k, int npd) ) {
      return idx_SendPortion_marshall9();
    }


    
    static int SendPortion(int k, int npd) { return idx_SendPortion_marshall9(); }
    
    static void _call_SendPortion_marshall9(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SendPortion_marshall9(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_SendPortion_marshall9(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_SendPortion_marshall9(PUP::er &p,void *msg);
    /* DECLS: void SendAll(next_probe<key >* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_SendAll_next_probe();
    // Entry point index lookup
    
    inline static int idx_SendAll_next_probe() {
      static int epidx = reg_SendAll_next_probe();
      return epidx;
    }

    
    inline static int idx_SendAll(void (Bucket < key, value > ::*)(next_probe<key >* impl_msg) ) {
      return idx_SendAll_next_probe();
    }


    
    static int SendAll(next_probe<key >* impl_msg) { return idx_SendAll_next_probe(); }
    
    static void _call_SendAll_next_probe(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_SendAll_next_probe(void* impl_msg, void* impl_obj);
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
    /* DECLS: void Load(void);
     */
    // Entry point registration at startup
    
    static int reg_Load_void();
    // Entry point index lookup
    
    inline static int idx_Load_void() {
      static int epidx = reg_Load_void();
      return epidx;
    }

    
    inline static int idx_Load(void (Bucket < key, value > ::*)(void) ) {
      return idx_Load_void();
    }


    
    static int Load(void) { return idx_Load_void(); }
    
    static void _call_Load_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Load_void(void* impl_msg, void* impl_obj);
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

    CProxyElement_Bucket(void) {}
    CProxyElement_Bucket(const ArrayElement *e) : CProxyElement_ArrayElement(e){  }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p); }

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
    {}
    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}

    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Bucket(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}
/* DECLS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
 */
    
    void insert(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void StepSort(void);
 */
    
    void StepSort(void) ;

/* DECLS: void CleanSplitters(void);
 */
    
    void CleanSplitters(void) ;

/* DECLS: void SetCallback(const CkCallback &cb);
 */
    
    void SetCallback(const CkCallback &cb, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SetData(void);
 */
    
    void SetData(void) ;

/* DECLS: void SetData(data_msg<key,value >* impl_msg);
 */
    
    void SetData(data_msg<key,value >* impl_msg) ;

/* DECLS: void CountFirstProbe(first_probe<key,value >* impl_msg);
 */
    
    void CountFirstProbe(first_probe<key,value >* impl_msg) ;

/* DECLS: void CountProbe(next_probe<key >* impl_msg);
 */
    
    void CountProbe(next_probe<key >* impl_msg) ;

/* DECLS: void SendPortion(int k, int npd);
 */
    
    void SendPortion(int k, int npd, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SendAll(next_probe<key >* impl_msg);
 */
    
    void SendAll(next_probe<key >* impl_msg) ;

/* DECLS: void Load(data_msg<key,value >* impl_msg);
 */
    
    void Load(data_msg<key,value >* impl_msg) ;

/* DECLS: void Load(void);
 */
    
    void Load(void) ;

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

    CProxy_Bucket(void) {}
    CProxy_Bucket(const ArrayElement *e) : CProxy_ArrayElement(e){  }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p); }

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
/* DECLS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
 */
    
    static CkArrayID ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void StepSort(void);
 */
    
    void StepSort(void) ;

/* DECLS: void CleanSplitters(void);
 */
    
    void CleanSplitters(void) ;

/* DECLS: void SetCallback(const CkCallback &cb);
 */
    
    void SetCallback(const CkCallback &cb, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SetData(void);
 */
    
    void SetData(void) ;

/* DECLS: void SetData(data_msg<key,value >* impl_msg);
 */
    
    void SetData(data_msg<key,value >* impl_msg) ;

/* DECLS: void CountFirstProbe(first_probe<key,value >* impl_msg);
 */
    
    void CountFirstProbe(first_probe<key,value >* impl_msg) ;

/* DECLS: void CountProbe(next_probe<key >* impl_msg);
 */
    
    void CountProbe(next_probe<key >* impl_msg) ;

/* DECLS: void SendPortion(int k, int npd);
 */
    
    void SendPortion(int k, int npd, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SendAll(next_probe<key >* impl_msg);
 */
    
    void SendAll(next_probe<key >* impl_msg) ;

/* DECLS: void Load(data_msg<key,value >* impl_msg);
 */
    
    void Load(data_msg<key,value >* impl_msg) ;

/* DECLS: void Load(void);
 */
    
    void Load(void) ;

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

    CProxySection_Bucket(void) {}

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p); }

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
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s) {
      CkVec<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.push_back(CkArrayIndex1D(i));
      return CkSectionID(aid, al.getVec(), al.size());
    } 
    CProxySection_Bucket(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Bucket(const CkArrayID &aid, CkArrayIndex *elems, int nElems) 
        :CProxySection_ArrayElement(aid,elems,nElems) {}
    CProxySection_Bucket(const CkSectionID &sid)       :CProxySection_ArrayElement(sid) {}
    CProxySection_Bucket(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Bucket(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) {}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
/* DECLS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
 */
    

/* DECLS: void StepSort(void);
 */
    
    void StepSort(void) ;

/* DECLS: void CleanSplitters(void);
 */
    
    void CleanSplitters(void) ;

/* DECLS: void SetCallback(const CkCallback &cb);
 */
    
    void SetCallback(const CkCallback &cb, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SetData(void);
 */
    
    void SetData(void) ;

/* DECLS: void SetData(data_msg<key,value >* impl_msg);
 */
    
    void SetData(data_msg<key,value >* impl_msg) ;

/* DECLS: void CountFirstProbe(first_probe<key,value >* impl_msg);
 */
    
    void CountFirstProbe(first_probe<key,value >* impl_msg) ;

/* DECLS: void CountProbe(next_probe<key >* impl_msg);
 */
    
    void CountProbe(next_probe<key >* impl_msg) ;

/* DECLS: void SendPortion(int k, int npd);
 */
    
    void SendPortion(int k, int npd, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void SendAll(next_probe<key >* impl_msg);
 */
    
    void SendAll(next_probe<key >* impl_msg) ;

/* DECLS: void Load(data_msg<key,value >* impl_msg);
 */
    
    void Load(data_msg<key,value >* impl_msg) ;

/* DECLS: void Load(void);
 */
    
    void Load(void) ;

/* DECLS: Bucket(CkMigrateMessage* impl_msg);
 */

};
#define Bucket_SDAG_CODE 
template < class key, class value > 
struct CBase_Bucket;



/* ---------------- method closures -------------- */
template < class key, class value > class Closure_Main {
  public:


    struct Exit_2_closure;


    struct DataReady_3_closure;





};




/* ---------------- method closures -------------- */
template < class key, class value > class Closure_Sorter {
  public:




    struct Begin_4_closure;


    struct Begin_5_closure;




};

/* ---------------- method closures -------------- */
template < class key, class value > class Closure_Bucket {
  public:


    struct StepSort_2_closure;


    struct CleanSplitters_3_closure;


    struct SetCallback_4_closure;


    struct SetData_5_closure;





    struct SendPortion_9_closure;




    struct Load_12_closure;


};

extern void _registerHistSort(void);
#endif
