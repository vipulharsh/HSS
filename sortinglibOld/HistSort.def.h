

/* ---------------- method closures -------------- */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Main < key, value > ::Exit_2_closure : public SDAG::Closure {
      

      Exit_2_closure() {
        init();
      }
      Exit_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~Exit_2_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(Exit_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Main < key, value > ::DataReady_3_closure : public SDAG::Closure {
      

      DataReady_3_closure() {
        init();
      }
      DataReady_3_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~DataReady_3_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(DataReady_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */





/* ---------------- method closures -------------- */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Sorter < key, value > ::Begin_4_closure : public SDAG::Closure {
      

      Begin_4_closure() {
        init();
      }
      Begin_4_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~Begin_4_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(Begin_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Sorter < key, value > ::Begin_5_closure : public SDAG::Closure {
      tuning_params par;


      Begin_5_closure() {
        init();
      }
      Begin_5_closure(CkMigrateMessage*) {
        init();
      }
      tuning_params & getP0() { return par;}
      void pup(PUP::er& __p) {
        __p | par;
        packClosure(__p);
      }
      virtual ~Begin_5_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(Begin_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::StepSort_2_closure : public SDAG::Closure {
      

      StepSort_2_closure() {
        init();
      }
      StepSort_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~StepSort_2_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(StepSort_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::CleanSplitters_3_closure : public SDAG::Closure {
      

      CleanSplitters_3_closure() {
        init();
      }
      CleanSplitters_3_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~CleanSplitters_3_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(CleanSplitters_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::SetCallback_4_closure : public SDAG::Closure {
      CkCallback cb;


      SetCallback_4_closure() {
        init();
      }
      SetCallback_4_closure(CkMigrateMessage*) {
        init();
      }
      CkCallback & getP0() { return cb;}
      void pup(PUP::er& __p) {
        __p | cb;
        packClosure(__p);
      }
      virtual ~SetCallback_4_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(SetCallback_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::SetData_5_closure : public SDAG::Closure {
      

      SetData_5_closure() {
        init();
      }
      SetData_5_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~SetData_5_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(SetData_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::SendPortion_9_closure : public SDAG::Closure {
      int k;
      int npd;


      SendPortion_9_closure() {
        init();
      }
      SendPortion_9_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return k;}
      int & getP1() { return npd;}
      void pup(PUP::er& __p) {
        __p | k;
        __p | npd;
        packClosure(__p);
      }
      virtual ~SendPortion_9_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(SendPortion_9_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::Load_12_closure : public SDAG::Closure {
      

      Load_12_closure() {
        init();
      }
      Load_12_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~Load_12_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(Load_12_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */




/* DEFS: template < class key, class value > chare Main: Chare{
Main(int _num_buckets);
void Exit(void);
void DataReady(void);
void init_isum(CkReductionMsg* impl_msg);
void final_isum(CkReductionMsg* impl_msg);
void init_dsum(CkReductionMsg* impl_msg);
void final_dsum(CkReductionMsg* impl_msg);
};
 */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_Main < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: Main(int _num_buckets);
 */
template < class key, class value > 

CkChareID CProxy_Main < key, value > ::ckNew(int _num_buckets, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int _num_buckets
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|_num_buckets;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|_num_buckets;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main < key, value > ::__idx, CkIndex_Main < key, value > ::idx_Main_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Main < key, value > ::ckNew(int _num_buckets, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int _num_buckets
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|_num_buckets;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|_num_buckets;
  }
  CkCreateChare(CkIndex_Main < key, value > ::__idx, CkIndex_Main < key, value > ::idx_Main_marshall1(), impl_msg, pcid, impl_onPE);
}
template < class key, class value > 

  CProxy_Main < key, value > ::CProxy_Main(int _num_buckets, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int _num_buckets
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|_num_buckets;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|_num_buckets;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main < key, value > ::__idx, CkIndex_Main < key, value > ::idx_Main_marshall1(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_Main_marshall1() {
  int epidx = CkRegisterEp("Main(int _num_buckets)",
      _call_Main_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Main_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Main_marshall1);

  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_Main_marshall1(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int _num_buckets*/
  PUP::fromMem implP(impl_buf);
  int _num_buckets; implP|_num_buckets;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Main < key, value > (_num_buckets);
}
template < class key, class value > 

int CkIndex_Main < key, value > ::_callmarshall_Main_marshall1(char* impl_buf, void* impl_obj_void) {
  Main < key, value > * impl_obj = static_cast< Main < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: int _num_buckets*/
  PUP::fromMem implP(impl_buf);
  int _num_buckets; implP|_num_buckets;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Main < key, value > (_num_buckets);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Main < key, value > ::_marshallmessagepup_Main_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int _num_buckets*/
  PUP::fromMem implP(impl_buf);
  int _num_buckets; implP|_num_buckets;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("_num_buckets");
  implDestP|_num_buckets;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Exit(void);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::Exit(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_Exit_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_Exit_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_Exit_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_Exit_void() {
  int epidx = CkRegisterEp("Exit(void)",
      _call_Exit_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_Exit_void(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->Exit();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Main < key, value > ::Exit_2_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void DataReady(void);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::DataReady(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_DataReady_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_DataReady_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_DataReady_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_DataReady_void() {
  int epidx = CkRegisterEp("DataReady(void)",
      _call_DataReady_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_DataReady_void(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->DataReady();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Main < key, value > ::DataReady_3_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void init_isum(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::init_isum(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_init_isum_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_init_isum_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_init_isum_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_init_isum_CkReductionMsg() {
  int epidx = CkRegisterEp("init_isum(CkReductionMsg* impl_msg)",
      _call_init_isum_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_init_isum_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  impl_obj->init_isum((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void final_isum(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::final_isum(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_final_isum_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_final_isum_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_final_isum_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_final_isum_CkReductionMsg() {
  int epidx = CkRegisterEp("final_isum(CkReductionMsg* impl_msg)",
      _call_final_isum_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_final_isum_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  impl_obj->final_isum((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void init_dsum(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::init_dsum(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_init_dsum_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_init_dsum_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_init_dsum_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_init_dsum_CkReductionMsg() {
  int epidx = CkRegisterEp("init_dsum(CkReductionMsg* impl_msg)",
      _call_init_dsum_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_init_dsum_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  impl_obj->init_dsum((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void final_dsum(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::final_dsum(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_final_dsum_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_final_dsum_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_final_dsum_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_final_dsum_CkReductionMsg() {
  int epidx = CkRegisterEp("final_dsum(CkReductionMsg* impl_msg)",
      _call_final_dsum_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_final_dsum_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  impl_obj->final_dsum((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > void CkIndex_Main < key, value > ::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(int _num_buckets);
  idx_Main_marshall1();

  // REG: void Exit(void);
  idx_Exit_void();

  // REG: void DataReady(void);
  idx_DataReady_void();

  // REG: void init_isum(CkReductionMsg* impl_msg);
  idx_init_isum_CkReductionMsg();

  // REG: void final_isum(CkReductionMsg* impl_msg);
  idx_final_isum_CkReductionMsg();

  // REG: void init_dsum(CkReductionMsg* impl_msg);
  idx_init_dsum_CkReductionMsg();

  // REG: void final_dsum(CkReductionMsg* impl_msg);
  idx_final_dsum_CkReductionMsg();

}
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 
struct CBase_Main : public Chare, virtual CBase
 {
  CProxy_Main < key, value >  thisProxy;
  CBase_Main() : thisProxy(this)
    , Chare()
  { }
  CBase_Main(CkMigrateMessage* m) : thisProxy(this)
    , Chare(m)  { }
  template <typename... Args>
  CBase_Main(Args... args) : thisProxy(this)
    , Chare(args...)  { }
  void pup(PUP::er &p) { }
  void virtual_pup(PUP::er &p) {
    recursive_pup<Main < key, value >  >(dynamic_cast<Main < key, value > * >(this), p);
}
  void parent_pup(PUP::er &p) {
    recursive_pup< Chare >(this, p);
    p|thisProxy;
  }
};
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key, class value > message first_probe{
key splitter_guesses[];
}
;
 */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  void *CMessage_first_probe < key, value > ::operator new(size_t s){
  return first_probe < key, value > ::alloc(__idx, s, 0, 0);
}
template < class key, class value >  void *CMessage_first_probe < key, value > ::operator new(size_t s, int* sz){
  return first_probe < key, value > ::alloc(__idx, s, sz, 0);
}
template < class key, class value >  void *CMessage_first_probe < key, value > ::operator new(size_t s, int* sz,const int pb){
  return first_probe < key, value > ::alloc(__idx, s, sz, pb);
}
template < class key, class value >  void *CMessage_first_probe < key, value > ::operator new(size_t s, int sz0) {
  int sizes[1];
  sizes[0] = sz0;
  return first_probe < key, value > ::alloc(__idx, s, sizes, 0);
}
template < class key, class value >  void *CMessage_first_probe < key, value > ::operator new(size_t s, int sz0, const int p) {
  int sizes[1];
  sizes[0] = sz0;
  return first_probe < key, value > ::alloc(__idx, s, sizes, p);
}
template < class key, class value >  void* CMessage_first_probe < key, value > ::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN_DEFAULT(sizeof(key)*sizes[0]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[1], pb);
}
template < class key, class value >  CMessage_first_probe < key, value > ::CMessage_first_probe() {
first_probe < key, value >  *newmsg = (first_probe < key, value >  *)this;
  newmsg->splitter_guesses = (key *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
}
template < class key, class value >  void CMessage_first_probe < key, value > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key, class value >  void* CMessage_first_probe < key, value > ::pack(first_probe < key, value >  *msg) {
  msg->splitter_guesses = (key *) ((char *)msg->splitter_guesses - (char *)msg);
  return (void *) msg;
}
template < class key, class value >  first_probe < key, value > * CMessage_first_probe < key, value > ::unpack(void* buf) {
  first_probe < key, value >  *msg = (first_probe < key, value >  *) buf;
  msg->splitter_guesses = (key *) ((size_t)msg->splitter_guesses + (char *)msg);
  return msg;
}
template < class key, class value >  int CMessage_first_probe < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key > message next_probe{
key splitter_guesses[];
charm_resolved_range<key > send_info[];
}
;
 */
#ifdef CK_TEMPLATES_ONLY
template < class key >  void *CMessage_next_probe < key > ::operator new(size_t s){
  return next_probe < key > ::alloc(__idx, s, 0, 0);
}
template < class key >  void *CMessage_next_probe < key > ::operator new(size_t s, int* sz){
  return next_probe < key > ::alloc(__idx, s, sz, 0);
}
template < class key >  void *CMessage_next_probe < key > ::operator new(size_t s, int* sz,const int pb){
  return next_probe < key > ::alloc(__idx, s, sz, pb);
}
template < class key >  void *CMessage_next_probe < key > ::operator new(size_t s, int sz0, int sz1) {
  int sizes[2];
  sizes[0] = sz0;
  sizes[1] = sz1;
  return next_probe < key > ::alloc(__idx, s, sizes, 0);
}
template < class key >  void *CMessage_next_probe < key > ::operator new(size_t s, int sz0, int sz1, const int p) {
  int sizes[2];
  sizes[0] = sz0;
  sizes[1] = sz1;
  return next_probe < key > ::alloc(__idx, s, sizes, p);
}
template < class key >  void* CMessage_next_probe < key > ::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN_DEFAULT(sizeof(key)*sizes[0]);
  if(sizes==0)
    CkpvAccess(_offsets)[2] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[2] = CkpvAccess(_offsets)[1] + ALIGN_DEFAULT(sizeof(charm_resolved_range<key >)*sizes[1]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[2], pb);
}
template < class key >  CMessage_next_probe < key > ::CMessage_next_probe() {
next_probe < key >  *newmsg = (next_probe < key >  *)this;
  newmsg->splitter_guesses = (key *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
  newmsg->send_info = (charm_resolved_range<key > *) ((char *)newmsg + CkpvAccess(_offsets)[1]);
}
template < class key >  void CMessage_next_probe < key > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key >  void* CMessage_next_probe < key > ::pack(next_probe < key >  *msg) {
  msg->splitter_guesses = (key *) ((char *)msg->splitter_guesses - (char *)msg);
  msg->send_info = (charm_resolved_range<key > *) ((char *)msg->send_info - (char *)msg);
  return (void *) msg;
}
template < class key >  next_probe < key > * CMessage_next_probe < key > ::unpack(void* buf) {
  next_probe < key >  *msg = (next_probe < key >  *) buf;
  msg->splitter_guesses = (key *) ((size_t)msg->splitter_guesses + (char *)msg);
  msg->send_info = (charm_resolved_range<key > *) ((size_t)msg->send_info + (char *)msg);
  return msg;
}
template < class key >  int CMessage_next_probe < key > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key, class value > message data_msg{
kv_pair<key,value > pairs[];
}
;
 */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  void *CMessage_data_msg < key, value > ::operator new(size_t s){
  return data_msg < key, value > ::alloc(__idx, s, 0, 0);
}
template < class key, class value >  void *CMessage_data_msg < key, value > ::operator new(size_t s, int* sz){
  return data_msg < key, value > ::alloc(__idx, s, sz, 0);
}
template < class key, class value >  void *CMessage_data_msg < key, value > ::operator new(size_t s, int* sz,const int pb){
  return data_msg < key, value > ::alloc(__idx, s, sz, pb);
}
template < class key, class value >  void *CMessage_data_msg < key, value > ::operator new(size_t s, int sz0) {
  int sizes[1];
  sizes[0] = sz0;
  return data_msg < key, value > ::alloc(__idx, s, sizes, 0);
}
template < class key, class value >  void *CMessage_data_msg < key, value > ::operator new(size_t s, int sz0, const int p) {
  int sizes[1];
  sizes[0] = sz0;
  return data_msg < key, value > ::alloc(__idx, s, sizes, p);
}
template < class key, class value >  void* CMessage_data_msg < key, value > ::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN_DEFAULT(sizeof(kv_pair<key,value >)*sizes[0]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[1], pb);
}
template < class key, class value >  CMessage_data_msg < key, value > ::CMessage_data_msg() {
data_msg < key, value >  *newmsg = (data_msg < key, value >  *)this;
  newmsg->pairs = (kv_pair<key,value > *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
}
template < class key, class value >  void CMessage_data_msg < key, value > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key, class value >  void* CMessage_data_msg < key, value > ::pack(data_msg < key, value >  *msg) {
  msg->pairs = (kv_pair<key,value > *) ((char *)msg->pairs - (char *)msg);
  return (void *) msg;
}
template < class key, class value >  data_msg < key, value > * CMessage_data_msg < key, value > ::unpack(void* buf) {
  data_msg < key, value >  *msg = (data_msg < key, value >  *) buf;
  msg->pairs = (kv_pair<key,value > *) ((size_t)msg->pairs + (char *)msg);
  return msg;
}
template < class key, class value >  int CMessage_data_msg < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key, class value > chare Sorter: Chare{
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
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_Sorter < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: Sorter(void);
 */
template < class key, class value > 

CkChareID CProxy_Sorter < key, value > ::ckNew(int impl_onPE)
{
  void *impl_msg = CkAllocSysMsg();
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_void(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Sorter < key, value > ::ckNew(CkChareID* pcid, int impl_onPE)
{
  void *impl_msg = CkAllocSysMsg();
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_void(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Sorter_void() {
  int epidx = CkRegisterEp("Sorter(void)",
      _call_Sorter_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Sorter_void(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj) Sorter < key, value > ();
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max);
 */
template < class key, class value > 

CkChareID CProxy_Sorter < key, value > ::ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall2(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Sorter < key, value > ::ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall2(), impl_msg, pcid, impl_onPE);
}
template < class key, class value > 

  CProxy_Sorter < key, value > ::CProxy_Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall2(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Sorter_marshall2() {
  int epidx = CkRegisterEp("Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max)",
      _call_Sorter_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Sorter_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Sorter_marshall2);

  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Sorter_marshall2(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Sorter < key, value > (bucketArr, num_chares, min, max);
}
template < class key, class value > 

int CkIndex_Sorter < key, value > ::_callmarshall_Sorter_marshall2(char* impl_buf, void* impl_obj_void) {
  Sorter < key, value > * impl_obj = static_cast< Sorter < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Sorter < key, value > (bucketArr, num_chares, min, max);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Sorter < key, value > ::_marshallmessagepup_Sorter_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("bucketArr");
  implDestP|bucketArr;
  if (implDestP.hasComments()) implDestP.comment("num_chares");
  implDestP|num_chares;
  if (implDestP.hasComments()) implDestP.comment("min");
  implDestP|min;
  if (implDestP.hasComments()) implDestP.comment("max");
  implDestP|max;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par);
 */
template < class key, class value > 

CkChareID CProxy_Sorter < key, value > ::ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall3(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Sorter < key, value > ::ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
  }
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall3(), impl_msg, pcid, impl_onPE);
}
template < class key, class value > 

  CProxy_Sorter < key, value > ::CProxy_Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkArrayID &)bucketArr;
    implP|num_chares;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall3(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Sorter_marshall3() {
  int epidx = CkRegisterEp("Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par)",
      _call_Sorter_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Sorter_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Sorter_marshall3);

  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Sorter_marshall3(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  tuning_params par; implP|par;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Sorter < key, value > (bucketArr, num_chares, min, max, par);
}
template < class key, class value > 

int CkIndex_Sorter < key, value > ::_callmarshall_Sorter_marshall3(char* impl_buf, void* impl_obj_void) {
  Sorter < key, value > * impl_obj = static_cast< Sorter < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  tuning_params par; implP|par;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Sorter < key, value > (bucketArr, num_chares, min, max, par);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Sorter < key, value > ::_marshallmessagepup_Sorter_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  tuning_params par; implP|par;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("bucketArr");
  implDestP|bucketArr;
  if (implDestP.hasComments()) implDestP.comment("num_chares");
  implDestP|num_chares;
  if (implDestP.hasComments()) implDestP.comment("min");
  implDestP|min;
  if (implDestP.hasComments()) implDestP.comment("max");
  implDestP|max;
  if (implDestP.hasComments()) implDestP.comment("par");
  implDestP|par;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Begin(void);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::Begin(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_Begin_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_Begin_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_Begin_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Begin_void() {
  int epidx = CkRegisterEp("Begin(void)",
      _call_Begin_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Begin_void(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->Begin();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Sorter < key, value > ::Begin_4_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Begin(const tuning_params &par);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::Begin(const tuning_params &par, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const tuning_params &par
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_Begin_marshall5(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_Begin_marshall5(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_Begin_marshall5(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Begin_marshall5() {
  int epidx = CkRegisterEp("Begin(const tuning_params &par)",
      _call_Begin_marshall5, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Begin_marshall5);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Begin_marshall5);

  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Begin_marshall5(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const tuning_params &par*/
  PUP::fromMem implP(impl_buf);
  tuning_params par; implP|par;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->Begin(par);
}
template < class key, class value > 

int CkIndex_Sorter < key, value > ::_callmarshall_Begin_marshall5(char* impl_buf, void* impl_obj_void) {
  Sorter < key, value > * impl_obj = static_cast< Sorter < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const tuning_params &par*/
  PUP::fromMem implP(impl_buf);
  tuning_params par; implP|par;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->Begin(par);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Sorter < key, value > ::_marshallmessagepup_Begin_marshall5(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const tuning_params &par*/
  PUP::fromMem implP(impl_buf);
  tuning_params par; implP|par;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("par");
  implDestP|par;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Sorter < key, value > ::Begin_5_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Histogram(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::Histogram(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_Histogram_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_Histogram_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_Histogram_CkReductionMsg(), impl_msg, &ckGetChareID(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Histogram_CkReductionMsg() {
  int epidx = CkRegisterEp("Histogram(CkReductionMsg* impl_msg)",
      _call_Histogram_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Histogram_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  impl_obj->Histogram((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Done(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::Done(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_Done_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_Done_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_Done_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Done_CkReductionMsg() {
  int epidx = CkRegisterEp("Done(CkReductionMsg* impl_msg)",
      _call_Done_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_Done_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  impl_obj->Done((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SanityCheck(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::SanityCheck(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_SanityCheck_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_SanityCheck_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_SanityCheck_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_SanityCheck_CkReductionMsg() {
  int epidx = CkRegisterEp("SanityCheck(CkReductionMsg* impl_msg)",
      _call_SanityCheck_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_SanityCheck_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  impl_obj->SanityCheck((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > void CkIndex_Sorter < key, value > ::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Sorter(void);
  idx_Sorter_void();
  CkRegisterDefaultCtor(__idx, idx_Sorter_void());

  // REG: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max);
  idx_Sorter_marshall2();

  // REG: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par);
  idx_Sorter_marshall3();

  // REG: void Begin(void);
  idx_Begin_void();

  // REG: void Begin(const tuning_params &par);
  idx_Begin_marshall5();

  // REG: void Histogram(CkReductionMsg* impl_msg);
  idx_Histogram_CkReductionMsg();

  // REG: void Done(CkReductionMsg* impl_msg);
  idx_Done_CkReductionMsg();

  // REG: void SanityCheck(CkReductionMsg* impl_msg);
  idx_SanityCheck_CkReductionMsg();

}
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 
struct CBase_Sorter : public Chare, virtual CBase
 {
  CProxy_Sorter < key, value >  thisProxy;
  CBase_Sorter() : thisProxy(this)
    , Chare()
  { }
  CBase_Sorter(CkMigrateMessage* m) : thisProxy(this)
    , Chare(m)  { }
  template <typename... Args>
  CBase_Sorter(Args... args) : thisProxy(this)
    , Chare(args...)  { }
  void pup(PUP::er &p) { }
  void virtual_pup(PUP::er &p) {
    recursive_pup<Sorter < key, value >  >(dynamic_cast<Sorter < key, value > * >(this), p);
}
  void parent_pup(PUP::er &p) {
    recursive_pup< Chare >(this, p);
    p|thisProxy;
  }
};
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key, class value > array Bucket: ArrayElement{
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
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_Bucket < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::insert(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, int onPE, const CkEntryOptions *impl_e_opts)
{ 
  //Marshall: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void StepSort(void);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::StepSort(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_StepSort_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CleanSplitters(void);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::CleanSplitters(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_CleanSplitters_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetCallback(const CkCallback &cb);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::SetCallback(const CkCallback &cb, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CkCallback &cb
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkCallback &)cb;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkCallback &)cb;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetCallback_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData(void);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::SetData(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetData_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::SetData(data_msg<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetData_data_msg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CountFirstProbe(first_probe<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::CountFirstProbe(first_probe<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_CountFirstProbe_first_probe(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CountProbe(next_probe<key >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::CountProbe(next_probe<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_CountProbe_next_probe(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SendPortion(int k, int npd);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::SendPortion(int k, int npd, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int k, int npd
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|k;
    implP|npd;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|k;
    implP|npd;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SendPortion_marshall9(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SendAll(next_probe<key >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::SendAll(next_probe<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SendAll_next_probe(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Load(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::Load(data_msg<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_Load_data_msg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Load(void);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::Load(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_Load_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
 */
template < class key, class value > 

CkArrayID CProxy_Bucket < key, value > ::ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  return ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), opts);
}
template < class key, class value > 

void CProxy_Bucket < key, value > ::ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}
template < class key, class value > 

CkArrayID CProxy_Bucket < key, value > ::ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const int s1, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  return ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), opts);
}
template < class key, class value > 

void CProxy_Bucket < key, value > ::ckNew(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)main_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(key &)min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)max;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_Bucket_marshall1() {
  int epidx = CkRegisterEp("Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max)",
      _call_Bucket_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Bucket_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Bucket_marshall1);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_Bucket_marshall1(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main<key,value > main_proxy; implP|main_proxy;
  key min; implP|min;
  key max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Bucket < key, value > (main_proxy, min, max);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_Bucket_marshall1(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main<key,value > main_proxy; implP|main_proxy;
  key min; implP|min;
  key max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Bucket < key, value > (main_proxy, min, max);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_Bucket_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Main<key,value > &main_proxy, const key &min, const key &max*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main<key,value > main_proxy; implP|main_proxy;
  key min; implP|min;
  key max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("main_proxy");
  implDestP|main_proxy;
  if (implDestP.hasComments()) implDestP.comment("min");
  implDestP|min;
  if (implDestP.hasComments()) implDestP.comment("max");
  implDestP|max;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void StepSort(void);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::StepSort(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_StepSort_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_StepSort_void() {
  int epidx = CkRegisterEp("StepSort(void)",
      _call_StepSort_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_StepSort_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->StepSort();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::StepSort_2_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CleanSplitters(void);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::CleanSplitters(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_CleanSplitters_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_CleanSplitters_void() {
  int epidx = CkRegisterEp("CleanSplitters(void)",
      _call_CleanSplitters_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_CleanSplitters_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->CleanSplitters();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::CleanSplitters_3_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetCallback(const CkCallback &cb);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::SetCallback(const CkCallback &cb, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CkCallback &cb
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkCallback &)cb;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkCallback &)cb;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetCallback_marshall4(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_SetCallback_marshall4() {
  int epidx = CkRegisterEp("SetCallback(const CkCallback &cb)",
      _call_SetCallback_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_SetCallback_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_SetCallback_marshall4);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_SetCallback_marshall4(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkCallback &cb*/
  PUP::fromMem implP(impl_buf);
  CkCallback cb; implP|cb;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->SetCallback(cb);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_SetCallback_marshall4(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CkCallback &cb*/
  PUP::fromMem implP(impl_buf);
  CkCallback cb; implP|cb;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->SetCallback(cb);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_SetCallback_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkCallback &cb*/
  PUP::fromMem implP(impl_buf);
  CkCallback cb; implP|cb;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("cb");
  implDestP|cb;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::SetCallback_4_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData(void);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::SetData(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetData_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_SetData_void() {
  int epidx = CkRegisterEp("SetData(void)",
      _call_SetData_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_SetData_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->SetData();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::SetData_5_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::SetData(data_msg<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetData_data_msg(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_SetData_data_msg() {
  int epidx = CkRegisterEp("SetData(data_msg<key,value >* impl_msg)",
      _call_SetData_data_msg, CMessage_data_msg<key,value >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)data_msg<key,value >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_SetData_data_msg(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->SetData((data_msg<key,value >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CountFirstProbe(first_probe<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::CountFirstProbe(first_probe<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_CountFirstProbe_first_probe(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_CountFirstProbe_first_probe() {
  int epidx = CkRegisterEp("CountFirstProbe(first_probe<key,value >* impl_msg)",
      _call_CountFirstProbe_first_probe, CMessage_first_probe<key,value >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)first_probe<key,value >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_CountFirstProbe_first_probe(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->CountFirstProbe((first_probe<key,value >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CountProbe(next_probe<key >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::CountProbe(next_probe<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_CountProbe_next_probe(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_CountProbe_next_probe() {
  int epidx = CkRegisterEp("CountProbe(next_probe<key >* impl_msg)",
      _call_CountProbe_next_probe, CMessage_next_probe<key >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)next_probe<key >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_CountProbe_next_probe(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->CountProbe((next_probe<key >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SendPortion(int k, int npd);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::SendPortion(int k, int npd, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int k, int npd
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|k;
    implP|npd;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|k;
    implP|npd;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_SendPortion_marshall9(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_SendPortion_marshall9() {
  int epidx = CkRegisterEp("SendPortion(int k, int npd)",
      _call_SendPortion_marshall9, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_SendPortion_marshall9);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_SendPortion_marshall9);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_SendPortion_marshall9(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int k, int npd*/
  PUP::fromMem implP(impl_buf);
  int k; implP|k;
  int npd; implP|npd;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->SendPortion(k, npd);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_SendPortion_marshall9(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: int k, int npd*/
  PUP::fromMem implP(impl_buf);
  int k; implP|k;
  int npd; implP|npd;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->SendPortion(k, npd);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_SendPortion_marshall9(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int k, int npd*/
  PUP::fromMem implP(impl_buf);
  int k; implP|k;
  int npd; implP|npd;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("k");
  implDestP|k;
  if (implDestP.hasComments()) implDestP.comment("npd");
  implDestP|npd;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::SendPortion_9_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SendAll(next_probe<key >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::SendAll(next_probe<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_SendAll_next_probe(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_SendAll_next_probe() {
  int epidx = CkRegisterEp("SendAll(next_probe<key >* impl_msg)",
      _call_SendAll_next_probe, CMessage_next_probe<key >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)next_probe<key >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_SendAll_next_probe(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->SendAll((next_probe<key >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Load(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::Load(data_msg<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_Load_data_msg(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_Load_data_msg() {
  int epidx = CkRegisterEp("Load(data_msg<key,value >* impl_msg)",
      _call_Load_data_msg, CMessage_data_msg<key,value >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)data_msg<key,value >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_Load_data_msg(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->Load((data_msg<key,value >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Load(void);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::Load(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_Load_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_Load_void() {
  int epidx = CkRegisterEp("Load(void)",
      _call_Load_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_Load_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->Load();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::Load_12_closure));
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_Bucket_CkMigrateMessage() {
  int epidx = CkRegisterEp("Bucket(CkMigrateMessage* impl_msg)",
      _call_Bucket_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_Bucket_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  new (impl_obj) Bucket < key, value > ((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void StepSort(void);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::StepSort(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_StepSort_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CleanSplitters(void);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::CleanSplitters(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_CleanSplitters_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetCallback(const CkCallback &cb);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::SetCallback(const CkCallback &cb, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CkCallback &cb
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkCallback &)cb;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkCallback &)cb;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetCallback_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData(void);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::SetData(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetData_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::SetData(data_msg<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SetData_data_msg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CountFirstProbe(first_probe<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::CountFirstProbe(first_probe<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_CountFirstProbe_first_probe(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void CountProbe(next_probe<key >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::CountProbe(next_probe<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_CountProbe_next_probe(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SendPortion(int k, int npd);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::SendPortion(int k, int npd, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int k, int npd
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|k;
    implP|npd;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|k;
    implP|npd;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SendPortion_marshall9(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SendAll(next_probe<key >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::SendAll(next_probe<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_SendAll_next_probe(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Load(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::Load(data_msg<key,value >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_Load_data_msg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Load(void);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::Load(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_Load_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > void CkIndex_Bucket < key, value > ::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Bucket(const CProxy_Main<key,value > &main_proxy, const key &min, const key &max);
  idx_Bucket_marshall1();

  // REG: void StepSort(void);
  idx_StepSort_void();

  // REG: void CleanSplitters(void);
  idx_CleanSplitters_void();

  // REG: void SetCallback(const CkCallback &cb);
  idx_SetCallback_marshall4();

  // REG: void SetData(void);
  idx_SetData_void();

  // REG: void SetData(data_msg<key,value >* impl_msg);
  idx_SetData_data_msg();

  // REG: void CountFirstProbe(first_probe<key,value >* impl_msg);
  idx_CountFirstProbe_first_probe();

  // REG: void CountProbe(next_probe<key >* impl_msg);
  idx_CountProbe_next_probe();

  // REG: void SendPortion(int k, int npd);
  idx_SendPortion_marshall9();

  // REG: void SendAll(next_probe<key >* impl_msg);
  idx_SendAll_next_probe();

  // REG: void Load(data_msg<key,value >* impl_msg);
  idx_Load_data_msg();

  // REG: void Load(void);
  idx_Load_void();

  // REG: Bucket(CkMigrateMessage* impl_msg);
  idx_Bucket_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Bucket_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 
struct CBase_Bucket : public ArrayElementT<CkIndex1D>, virtual CBase
 {
  CProxy_Bucket < key, value >  thisProxy;
  CBase_Bucket() : thisProxy(this)
    , ArrayElementT<CkIndex1D>()
  { }
  CBase_Bucket(CkMigrateMessage* m) : thisProxy(this)
    , ArrayElementT<CkIndex1D>(m)  { }
  template <typename... Args>
  CBase_Bucket(Args... args) : thisProxy(this)
    , ArrayElementT<CkIndex1D>(args...)  { }
  void pup(PUP::er &p) { }
  void virtual_pup(PUP::er &p) {
    recursive_pup<Bucket < key, value >  >(dynamic_cast<Bucket < key, value > * >(this), p);
}
  void parent_pup(PUP::er &p) {
    recursive_pup< ArrayElementT<CkIndex1D> >(this, p);
    p|thisProxy;
  }
};
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerHistSort(void)
{
  static int _done = 0; if(_done) return; _done = 1;

  _registerInitCall(register_sum_uint64_t,1);







}
#endif /* CK_TEMPLATES_ONLY */
