


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

    struct Closure_Bucket < key, value > ::startBarrier_2_closure : public SDAG::Closure {
      CProxy_Sorter<key,value > _sorter_proxy;
      CProxy_Main<key,value > _main_proxy;


      startBarrier_2_closure() {
        init();
      }
      startBarrier_2_closure(CkMigrateMessage*) {
        init();
      }
      CProxy_Sorter<key,value > & getP0() { return _sorter_proxy;}
      CProxy_Main<key,value > & getP1() { return _main_proxy;}
      void pup(PUP::er& __p) {
        __p | _sorter_proxy;
        __p | _main_proxy;
        packClosure(__p);
      }
      virtual ~startBarrier_2_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(startBarrier_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::SetData_3_closure : public SDAG::Closure {
      

      SetData_3_closure() {
        init();
      }
      SetData_3_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~SetData_3_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(SetData_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::genSample_4_closure : public SDAG::Closure {
      sampleInfo sI;


      genSample_4_closure() {
        init();
      }
      genSample_4_closure(CkMigrateMessage*) {
        init();
      }
      sampleInfo & getP0() { return sI;}
      void pup(PUP::er& __p) {
        __p | sI;
        packClosure(__p);
      }
      virtual ~genSample_4_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(genSample_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::firstProbe_5_closure : public SDAG::Closure {
      key firstkey;
      key lastkey;
      key stepSize;
      int probeSize;


      firstProbe_5_closure() {
        init();
      }
      firstProbe_5_closure(CkMigrateMessage*) {
        init();
      }
      key & getP0() { return firstkey;}
      key & getP1() { return lastkey;}
      key & getP2() { return stepSize;}
      int & getP3() { return probeSize;}
      void pup(PUP::er& __p) {
        __p | firstkey;
        __p | lastkey;
        __p | stepSize;
        __p | probeSize;
        packClosure(__p);
      }
      virtual ~firstProbe_5_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(firstProbe_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::firstLocalProbe_6_closure : public SDAG::Closure {
      int lastProbeSize;


      firstLocalProbe_6_closure() {
        init();
      }
      firstLocalProbe_6_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return lastProbeSize;}
      void pup(PUP::er& __p) {
        __p | lastProbeSize;
        packClosure(__p);
      }
      virtual ~firstLocalProbe_6_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(firstLocalProbe_6_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::sortAll_9_closure : public SDAG::Closure {
      

      sortAll_9_closure() {
        init();
      }
      sortAll_9_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~sortAll_9_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(sortAll_9_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::stepSort_10_closure : public SDAG::Closure {
      

      stepSort_10_closure() {
        init();
      }
      stepSort_10_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~stepSort_10_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(stepSort_10_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::recvFinalKeys_12_closure : public SDAG::Closure {
      int srcnode;
      sendInfo s;


      recvFinalKeys_12_closure() {
        init();
      }
      recvFinalKeys_12_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return srcnode;}
      sendInfo & getP1() { return s;}
      void pup(PUP::er& __p) {
        __p | srcnode;
        __p | s;
        packClosure(__p);
      }
      virtual ~recvFinalKeys_12_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(recvFinalKeys_12_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::MergingWork_13_closure : public SDAG::Closure {
      

      MergingWork_13_closure() {
        init();
      }
      MergingWork_13_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~MergingWork_13_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(MergingWork_13_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::partialSendOne_14_closure : public SDAG::Closure {
      

      partialSendOne_14_closure() {
        init();
      }
      partialSendOne_14_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~partialSendOne_14_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(partialSendOne_14_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_Bucket < key, value > ::finish_16_closure : public SDAG::Closure {
      

      finish_16_closure() {
        init();
      }
      finish_16_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~finish_16_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(finish_16_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */



/* ---------------- method closures -------------- */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::registerLocalChare_2_closure : public SDAG::Closure {
      int nElem;
      int pe;
      CProxy_Bucket<key,value > _bucket_arr;
      CProxy_Sorter<key,value > _sorter;


      registerLocalChare_2_closure() {
        init();
      }
      registerLocalChare_2_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return nElem;}
      int & getP1() { return pe;}
      CProxy_Bucket<key,value > & getP2() { return _bucket_arr;}
      CProxy_Sorter<key,value > & getP3() { return _sorter;}
      void pup(PUP::er& __p) {
        __p | nElem;
        __p | pe;
        __p | _bucket_arr;
        __p | _sorter;
        packClosure(__p);
      }
      virtual ~registerLocalChare_2_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(registerLocalChare_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::collectSamples_3_closure : public SDAG::Closure {
      sampleInfo sI;


      collectSamples_3_closure() {
        init();
      }
      collectSamples_3_closure(CkMigrateMessage*) {
        init();
      }
      sampleInfo & getP0() { return sI;}
      void pup(PUP::er& __p) {
        __p | sI;
        packClosure(__p);
      }
      virtual ~collectSamples_3_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(collectSamples_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::assembleSamples_4_closure : public SDAG::Closure {
      std::vector<key > proc_sample;


      assembleSamples_4_closure() {
        init();
      }
      assembleSamples_4_closure(CkMigrateMessage*) {
        init();
      }
      std::vector<key > & getP0() { return proc_sample;}
      void pup(PUP::er& __p) {
        __p | proc_sample;
        packClosure(__p);
      }
      virtual ~assembleSamples_4_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(assembleSamples_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::loadkeys_5_closure : public SDAG::Closure {
      int dest;
      sendInfo inf;


      loadkeys_5_closure() {
        init();
      }
      loadkeys_5_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return dest;}
      sendInfo & getP1() { return inf;}
      void pup(PUP::er& __p) {
        __p | dest;
        __p | inf;
        packClosure(__p);
      }
      virtual ~loadkeys_5_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(loadkeys_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::sendOne_6_closure : public SDAG::Closure {
      int dest;


      sendOne_6_closure() {
        init();
      }
      sendOne_6_closure(CkMigrateMessage*) {
        init();
      }
      int & getP0() { return dest;}
      void pup(PUP::er& __p) {
        __p | dest;
        packClosure(__p);
      }
      virtual ~sendOne_6_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(sendOne_6_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::releaseBufMsgs_7_closure : public SDAG::Closure {
      

      releaseBufMsgs_7_closure() {
        init();
      }
      releaseBufMsgs_7_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~releaseBufMsgs_7_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(releaseBufMsgs_7_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::handleOne_9_closure : public SDAG::Closure {
      wrap_ptr msg;
      int sampleInd;
      int numsamples;


      handleOne_9_closure() {
        init();
      }
      handleOne_9_closure(CkMigrateMessage*) {
        init();
      }
      wrap_ptr & getP0() { return msg;}
      int & getP1() { return sampleInd;}
      int & getP2() { return numsamples;}
      void pup(PUP::er& __p) {
        __p | msg;
        __p | sampleInd;
        __p | numsamples;
        packClosure(__p);
      }
      virtual ~handleOne_9_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(handleOne_9_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::finishOne_10_closure : public SDAG::Closure {
      

      finishOne_10_closure() {
        init();
      }
      finishOne_10_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~finishOne_10_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(finishOne_10_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 

    struct Closure_NodeManager < key, value > ::depositHist_12_closure : public SDAG::Closure {
      

      depositHist_12_closure() {
        init();
      }
      depositHist_12_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~depositHist_12_closure() {
      }
      PUPable_decl_template(SINGLE_ARG(depositHist_12_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */





/* DEFS: template < class key, class value > chare Main: Chare{
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
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_Main < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: Main(int num_buckets_, int probe_max, int num_partitions_);
 */
template < class key, class value > 

CkChareID CProxy_Main < key, value > ::ckNew(int num_buckets_, int probe_max, int num_partitions_, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int num_buckets_, int probe_max, int num_partitions_
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num_buckets_;
    implP|probe_max;
    implP|num_partitions_;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num_buckets_;
    implP|probe_max;
    implP|num_partitions_;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main < key, value > ::__idx, CkIndex_Main < key, value > ::idx_Main_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Main < key, value > ::ckNew(int num_buckets_, int probe_max, int num_partitions_, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int num_buckets_, int probe_max, int num_partitions_
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num_buckets_;
    implP|probe_max;
    implP|num_partitions_;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num_buckets_;
    implP|probe_max;
    implP|num_partitions_;
  }
  CkCreateChare(CkIndex_Main < key, value > ::__idx, CkIndex_Main < key, value > ::idx_Main_marshall1(), impl_msg, pcid, impl_onPE);
}
template < class key, class value > 

  CProxy_Main < key, value > ::CProxy_Main(int num_buckets_, int probe_max, int num_partitions_, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int num_buckets_, int probe_max, int num_partitions_
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num_buckets_;
    implP|probe_max;
    implP|num_partitions_;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num_buckets_;
    implP|probe_max;
    implP|num_partitions_;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main < key, value > ::__idx, CkIndex_Main < key, value > ::idx_Main_marshall1(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_Main_marshall1() {
  int epidx = CkRegisterEp("Main(int num_buckets_, int probe_max, int num_partitions_)",
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
  /*Unmarshall pup'd fields: int num_buckets_, int probe_max, int num_partitions_*/
  PUP::fromMem implP(impl_buf);
  int num_buckets_; implP|num_buckets_;
  int probe_max; implP|probe_max;
  int num_partitions_; implP|num_partitions_;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Main < key, value > (num_buckets_, probe_max, num_partitions_);
}
template < class key, class value > 

int CkIndex_Main < key, value > ::_callmarshall_Main_marshall1(char* impl_buf, void* impl_obj_void) {
  Main < key, value > * impl_obj = static_cast< Main < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: int num_buckets_, int probe_max, int num_partitions_*/
  PUP::fromMem implP(impl_buf);
  int num_buckets_; implP|num_buckets_;
  int probe_max; implP|probe_max;
  int num_partitions_; implP|num_partitions_;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Main < key, value > (num_buckets_, probe_max, num_partitions_);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Main < key, value > ::_marshallmessagepup_Main_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int num_buckets_, int probe_max, int num_partitions_*/
  PUP::fromMem implP(impl_buf);
  int num_buckets_; implP|num_buckets_;
  int probe_max; implP|probe_max;
  int num_partitions_; implP|num_partitions_;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("num_buckets_");
  implDestP|num_buckets_;
  if (implDestP.hasComments()) implDestP.comment("probe_max");
  implDestP|probe_max;
  if (implDestP.hasComments()) implDestP.comment("num_partitions_");
  implDestP|num_partitions_;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void Exit();
 */
template < class key, class value > 

void CProxy_Main < key, value > ::Exit(const CkEntryOptions *impl_e_opts)
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
  int epidx = CkRegisterEp("Exit()",
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
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Main < key, value > ::Exit_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void DataReady();
 */
template < class key, class value > 

void CProxy_Main < key, value > ::DataReady(const CkEntryOptions *impl_e_opts)
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
  int epidx = CkRegisterEp("DataReady()",
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
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Main < key, value > ::DataReady_3_closure))
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
/* DEFS: void intermediate_isum(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Main < key, value > ::intermediate_isum(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main < key, value > ::idx_intermediate_isum_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main < key, value > ::idx_intermediate_isum_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main < key, value > ::idx_intermediate_isum_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Main < key, value > ::reg_intermediate_isum_CkReductionMsg() {
  int epidx = CkRegisterEp("intermediate_isum(CkReductionMsg* impl_msg)",
      _call_intermediate_isum_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Main < key, value > ::_call_intermediate_isum_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main < key, value > * impl_obj = static_cast<Main < key, value >  *>(impl_obj_void);
  impl_obj->intermediate_isum((CkReductionMsg*)impl_msg);
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
  // REG: Main(int num_buckets_, int probe_max, int num_partitions_);
  idx_Main_marshall1();

  // REG: void Exit();
  idx_Exit_void();

  // REG: void DataReady();
  idx_DataReady_void();

  // REG: void init_isum(CkReductionMsg* impl_msg);
  idx_init_isum_CkReductionMsg();

  // REG: void intermediate_isum(CkReductionMsg* impl_msg);
  idx_intermediate_isum_CkReductionMsg();

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
  void _sdag_pup(PUP::er &p) { }
  void virtual_pup(PUP::er &p) {
    recursive_pup<Main < key, value >  >(dynamic_cast<Main < key, value > * >(this), p);
}
  void parent_pup(PUP::er &p) {
    recursive_pup< Chare >(this, p);
    p|thisProxy;
  }
};
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key > message probeMessage{
key probe[];
key newachv_key[];
int newachv_id[];
uint64_t newachv_count[];
}
;
 */
#ifdef CK_TEMPLATES_ONLY
template < class key >  void *CMessage_probeMessage < key > ::operator new(size_t s){
  return probeMessage < key > ::alloc(__idx, s, 0, 0);
}
template < class key >  void *CMessage_probeMessage < key > ::operator new(size_t s, int* sz){
  return probeMessage < key > ::alloc(__idx, s, sz, 0);
}
template < class key >  void *CMessage_probeMessage < key > ::operator new(size_t s, int* sz,const int pb){
  return probeMessage < key > ::alloc(__idx, s, sz, pb);
}
template < class key >  void *CMessage_probeMessage < key > ::operator new(size_t s, int sz0, int sz1, int sz2, int sz3) {
  int sizes[4];
  sizes[0] = sz0;
  sizes[1] = sz1;
  sizes[2] = sz2;
  sizes[3] = sz3;
  return probeMessage < key > ::alloc(__idx, s, sizes, 0);
}
template < class key >  void *CMessage_probeMessage < key > ::operator new(size_t s, int sz0, int sz1, int sz2, int sz3, const int p) {
  int sizes[4];
  sizes[0] = sz0;
  sizes[1] = sz1;
  sizes[2] = sz2;
  sizes[3] = sz3;
  return probeMessage < key > ::alloc(__idx, s, sizes, p);
}
template < class key >  void* CMessage_probeMessage < key > ::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN_DEFAULT(sizeof(key)*sizes[0]);
  if(sizes==0)
    CkpvAccess(_offsets)[2] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[2] = CkpvAccess(_offsets)[1] + ALIGN_DEFAULT(sizeof(key)*sizes[1]);
  if(sizes==0)
    CkpvAccess(_offsets)[3] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[3] = CkpvAccess(_offsets)[2] + ALIGN_DEFAULT(sizeof(int)*sizes[2]);
  if(sizes==0)
    CkpvAccess(_offsets)[4] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[4] = CkpvAccess(_offsets)[3] + ALIGN_DEFAULT(sizeof(uint64_t)*sizes[3]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[4], pb);
}
template < class key >  CMessage_probeMessage < key > ::CMessage_probeMessage() {
probeMessage < key >  *newmsg = (probeMessage < key >  *)this;
  newmsg->probe = (key *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
  newmsg->newachv_key = (key *) ((char *)newmsg + CkpvAccess(_offsets)[1]);
  newmsg->newachv_id = (int *) ((char *)newmsg + CkpvAccess(_offsets)[2]);
  newmsg->newachv_count = (uint64_t *) ((char *)newmsg + CkpvAccess(_offsets)[3]);
}
template < class key >  void CMessage_probeMessage < key > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key >  void* CMessage_probeMessage < key > ::pack(probeMessage < key >  *msg) {
  msg->probe = (key *) ((char *)msg->probe - (char *)msg);
  msg->newachv_key = (key *) ((char *)msg->newachv_key - (char *)msg);
  msg->newachv_id = (int *) ((char *)msg->newachv_id - (char *)msg);
  msg->newachv_count = (uint64_t *) ((char *)msg->newachv_count - (char *)msg);
  return (void *) msg;
}
template < class key >  probeMessage < key > * CMessage_probeMessage < key > ::unpack(void* buf) {
  probeMessage < key >  *msg = (probeMessage < key >  *) buf;
  msg->probe = (key *) ((size_t)msg->probe + (char *)msg);
  msg->newachv_key = (key *) ((size_t)msg->newachv_key + (char *)msg);
  msg->newachv_id = (int *) ((size_t)msg->newachv_id + (char *)msg);
  msg->newachv_count = (uint64_t *) ((size_t)msg->newachv_count + (char *)msg);
  return msg;
}
template < class key >  int CMessage_probeMessage < key > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key > message sampleMessage{
key lb[];
key ub[];
key newachv_key[];
int newachv_id[];
uint64_t newachv_count[];
}
;
 */
#ifdef CK_TEMPLATES_ONLY
template < class key >  void *CMessage_sampleMessage < key > ::operator new(size_t s){
  return sampleMessage < key > ::alloc(__idx, s, 0, 0);
}
template < class key >  void *CMessage_sampleMessage < key > ::operator new(size_t s, int* sz){
  return sampleMessage < key > ::alloc(__idx, s, sz, 0);
}
template < class key >  void *CMessage_sampleMessage < key > ::operator new(size_t s, int* sz,const int pb){
  return sampleMessage < key > ::alloc(__idx, s, sz, pb);
}
template < class key >  void *CMessage_sampleMessage < key > ::operator new(size_t s, int sz0, int sz1, int sz2, int sz3, int sz4) {
  int sizes[5];
  sizes[0] = sz0;
  sizes[1] = sz1;
  sizes[2] = sz2;
  sizes[3] = sz3;
  sizes[4] = sz4;
  return sampleMessage < key > ::alloc(__idx, s, sizes, 0);
}
template < class key >  void *CMessage_sampleMessage < key > ::operator new(size_t s, int sz0, int sz1, int sz2, int sz3, int sz4, const int p) {
  int sizes[5];
  sizes[0] = sz0;
  sizes[1] = sz1;
  sizes[2] = sz2;
  sizes[3] = sz3;
  sizes[4] = sz4;
  return sampleMessage < key > ::alloc(__idx, s, sizes, p);
}
template < class key >  void* CMessage_sampleMessage < key > ::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN_DEFAULT(sizeof(key)*sizes[0]);
  if(sizes==0)
    CkpvAccess(_offsets)[2] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[2] = CkpvAccess(_offsets)[1] + ALIGN_DEFAULT(sizeof(key)*sizes[1]);
  if(sizes==0)
    CkpvAccess(_offsets)[3] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[3] = CkpvAccess(_offsets)[2] + ALIGN_DEFAULT(sizeof(key)*sizes[2]);
  if(sizes==0)
    CkpvAccess(_offsets)[4] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[4] = CkpvAccess(_offsets)[3] + ALIGN_DEFAULT(sizeof(int)*sizes[3]);
  if(sizes==0)
    CkpvAccess(_offsets)[5] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[5] = CkpvAccess(_offsets)[4] + ALIGN_DEFAULT(sizeof(uint64_t)*sizes[4]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[5], pb);
}
template < class key >  CMessage_sampleMessage < key > ::CMessage_sampleMessage() {
sampleMessage < key >  *newmsg = (sampleMessage < key >  *)this;
  newmsg->lb = (key *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
  newmsg->ub = (key *) ((char *)newmsg + CkpvAccess(_offsets)[1]);
  newmsg->newachv_key = (key *) ((char *)newmsg + CkpvAccess(_offsets)[2]);
  newmsg->newachv_id = (int *) ((char *)newmsg + CkpvAccess(_offsets)[3]);
  newmsg->newachv_count = (uint64_t *) ((char *)newmsg + CkpvAccess(_offsets)[4]);
}
template < class key >  void CMessage_sampleMessage < key > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key >  void* CMessage_sampleMessage < key > ::pack(sampleMessage < key >  *msg) {
  msg->lb = (key *) ((char *)msg->lb - (char *)msg);
  msg->ub = (key *) ((char *)msg->ub - (char *)msg);
  msg->newachv_key = (key *) ((char *)msg->newachv_key - (char *)msg);
  msg->newachv_id = (int *) ((char *)msg->newachv_id - (char *)msg);
  msg->newachv_count = (uint64_t *) ((char *)msg->newachv_count - (char *)msg);
  return (void *) msg;
}
template < class key >  sampleMessage < key > * CMessage_sampleMessage < key > ::unpack(void* buf) {
  sampleMessage < key >  *msg = (sampleMessage < key >  *) buf;
  msg->lb = (key *) ((size_t)msg->lb + (char *)msg);
  msg->ub = (key *) ((size_t)msg->ub + (char *)msg);
  msg->newachv_key = (key *) ((size_t)msg->newachv_key + (char *)msg);
  msg->newachv_id = (int *) ((size_t)msg->newachv_id + (char *)msg);
  msg->newachv_count = (uint64_t *) ((size_t)msg->newachv_count + (char *)msg);
  return msg;
}
template < class key >  int CMessage_sampleMessage < key > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key, class value > message data_msg{
kv_pair<key,value > data[];
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
  newmsg->data = (kv_pair<key,value > *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
}
template < class key, class value >  void CMessage_data_msg < key, value > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key, class value >  void* CMessage_data_msg < key, value > ::pack(data_msg < key, value >  *msg) {
  msg->data = (kv_pair<key,value > *) ((char *)msg->data - (char *)msg);
  return (void *) msg;
}
template < class key, class value >  data_msg < key, value > * CMessage_data_msg < key, value > ::unpack(void* buf) {
  data_msg < key, value >  *msg = (data_msg < key, value >  *) buf;
  msg->data = (kv_pair<key,value > *) ((size_t)msg->data + (char *)msg);
  return msg;
}
template < class key, class value >  int CMessage_data_msg < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key > message array_msg{
key data[];
}
;
 */
#ifdef CK_TEMPLATES_ONLY
template < class key >  void *CMessage_array_msg < key > ::operator new(size_t s){
  return array_msg < key > ::alloc(__idx, s, 0, 0);
}
template < class key >  void *CMessage_array_msg < key > ::operator new(size_t s, int* sz){
  return array_msg < key > ::alloc(__idx, s, sz, 0);
}
template < class key >  void *CMessage_array_msg < key > ::operator new(size_t s, int* sz,const int pb){
  return array_msg < key > ::alloc(__idx, s, sz, pb);
}
template < class key >  void *CMessage_array_msg < key > ::operator new(size_t s, int sz0) {
  int sizes[1];
  sizes[0] = sz0;
  return array_msg < key > ::alloc(__idx, s, sizes, 0);
}
template < class key >  void *CMessage_array_msg < key > ::operator new(size_t s, int sz0, const int p) {
  int sizes[1];
  sizes[0] = sz0;
  return array_msg < key > ::alloc(__idx, s, sizes, p);
}
template < class key >  void* CMessage_array_msg < key > ::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN_DEFAULT(sizeof(key)*sizes[0]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[1], pb);
}
template < class key >  CMessage_array_msg < key > ::CMessage_array_msg() {
array_msg < key >  *newmsg = (array_msg < key >  *)this;
  newmsg->data = (key *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
}
template < class key >  void CMessage_array_msg < key > ::dealloc(void *p) {
  CkFreeMsg(p);
}
template < class key >  void* CMessage_array_msg < key > ::pack(array_msg < key >  *msg) {
  msg->data = (key *) ((char *)msg->data - (char *)msg);
  return (void *) msg;
}
template < class key >  array_msg < key > * CMessage_array_msg < key > ::unpack(void* buf) {
  array_msg < key >  *msg = (array_msg < key >  *) buf;
  msg->data = (key *) ((size_t)msg->data + (char *)msg);
  return msg;
}
template < class key >  int CMessage_array_msg < key > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: template < class key, class value > chare Sorter: Chare{
Sorter();
Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID);
void finishBarrier(CkReductionMsg* impl_msg);
void Histogram(CkReductionMsg* impl_msg);
void Done(CkReductionMsg* impl_msg);
void SanityCheck(CkReductionMsg* impl_msg);
void recvSample(array_msg<key >* impl_msg);
};
 */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_Sorter < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: Sorter();
 */
template < class key, class value > 

CkChareID CProxy_Sorter < key, value > ::ckNew(int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg();
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_void(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Sorter < key, value > ::ckNew(CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg();
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_void(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Sorter_void() {
  int epidx = CkRegisterEp("Sorter()",
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
/* DEFS: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID);
 */
template < class key, class value > 

CkChareID CProxy_Sorter < key, value > ::ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID
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
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)mainproxy;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
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
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)mainproxy;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall2(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
template < class key, class value > 

void CProxy_Sorter < key, value > ::ckNew(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID
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
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)mainproxy;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
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
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)mainproxy;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall2(), impl_msg, pcid, impl_onPE);
}
template < class key, class value > 

  CProxy_Sorter < key, value > ::CProxy_Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID
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
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)mainproxy;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
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
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)mainproxy;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Sorter < key, value > ::__idx, CkIndex_Sorter < key, value > ::idx_Sorter_marshall2(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_Sorter_marshall2() {
  int epidx = CkRegisterEp("Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID)",
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
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  tuning_params par; implP|par;
  CProxy_Main<key,value > mainproxy; implP|mainproxy;
  CkNodeGroupID _nodeMgrID; implP|_nodeMgrID;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Sorter < key, value > (bucketArr, num_chares, min, max, par, mainproxy, _nodeMgrID);
}
template < class key, class value > 

int CkIndex_Sorter < key, value > ::_callmarshall_Sorter_marshall2(char* impl_buf, void* impl_obj_void) {
  Sorter < key, value > * impl_obj = static_cast< Sorter < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  tuning_params par; implP|par;
  CProxy_Main<key,value > mainproxy; implP|mainproxy;
  CkNodeGroupID _nodeMgrID; implP|_nodeMgrID;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Sorter < key, value > (bucketArr, num_chares, min, max, par, mainproxy, _nodeMgrID);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Sorter < key, value > ::_marshallmessagepup_Sorter_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID*/
  PUP::fromMem implP(impl_buf);
  CkArrayID bucketArr; implP|bucketArr;
  int num_chares; implP|num_chares;
  key min; implP|min;
  key max; implP|max;
  tuning_params par; implP|par;
  CProxy_Main<key,value > mainproxy; implP|mainproxy;
  CkNodeGroupID _nodeMgrID; implP|_nodeMgrID;
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
  if (implDestP.hasComments()) implDestP.comment("mainproxy");
  implDestP|mainproxy;
  if (implDestP.hasComments()) implDestP.comment("_nodeMgrID");
  implDestP|_nodeMgrID;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finishBarrier(CkReductionMsg* impl_msg);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::finishBarrier(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_finishBarrier_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_finishBarrier_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_finishBarrier_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_finishBarrier_CkReductionMsg() {
  int epidx = CkRegisterEp("finishBarrier(CkReductionMsg* impl_msg)",
      _call_finishBarrier_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_finishBarrier_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  impl_obj->finishBarrier((CkReductionMsg*)impl_msg);
}
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
/* DEFS: void recvSample(array_msg<key >* impl_msg);
 */
template < class key, class value > 

void CProxy_Sorter < key, value > ::recvSample(array_msg<key >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Sorter < key, value > ::idx_recvSample_array_msg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Sorter < key, value > ::idx_recvSample_array_msg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Sorter < key, value > ::idx_recvSample_array_msg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Sorter < key, value > ::reg_recvSample_array_msg() {
  int epidx = CkRegisterEp("recvSample(array_msg<key >* impl_msg)",
      _call_recvSample_array_msg, CMessage_array_msg<key >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)array_msg<key >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Sorter < key, value > ::_call_recvSample_array_msg(void* impl_msg, void* impl_obj_void)
{
  Sorter < key, value > * impl_obj = static_cast<Sorter < key, value >  *>(impl_obj_void);
  impl_obj->recvSample((array_msg<key >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > void CkIndex_Sorter < key, value > ::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Sorter();
  idx_Sorter_void();
  CkRegisterDefaultCtor(__idx, idx_Sorter_void());

  // REG: Sorter(const CkArrayID &bucketArr, int num_chares, const key &min, const key &max, const tuning_params &par, const CProxy_Main<key,value > &mainproxy, const CkNodeGroupID &_nodeMgrID);
  idx_Sorter_marshall2();

  // REG: void finishBarrier(CkReductionMsg* impl_msg);
  idx_finishBarrier_CkReductionMsg();

  // REG: void Histogram(CkReductionMsg* impl_msg);
  idx_Histogram_CkReductionMsg();

  // REG: void Done(CkReductionMsg* impl_msg);
  idx_Done_CkReductionMsg();

  // REG: void SanityCheck(CkReductionMsg* impl_msg);
  idx_SanityCheck_CkReductionMsg();

  // REG: void recvSample(array_msg<key >* impl_msg);
  idx_recvSample_array_msg();

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
  void _sdag_pup(PUP::er &p) { }
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
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_Bucket < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 
void CProxySection_Bucket < key, value > ::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template < class key, class value > 
void CProxySection_Bucket < key, value > ::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::insert(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, int onPE, const CkEntryOptions *impl_e_opts)
{ 
  //Marshall: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)_main_proxy;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)_main_proxy;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_startBarrier_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData();
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::SetData(const CkEntryOptions *impl_e_opts) 
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
/* DEFS: void genSample(const sampleInfo &sI);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::genSample(const sampleInfo &sI, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const sampleInfo &sI
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_genSample_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const key &firstkey, const key &lastkey, const key &stepSize, int probeSize
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(key &)firstkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)lastkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)stepSize;
    implP|probeSize;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(key &)firstkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)lastkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)stepSize;
    implP|probeSize;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_firstProbe_marshall5(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void firstLocalProbe(int lastProbeSize);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::firstLocalProbe(int lastProbeSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int lastProbeSize
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|lastProbeSize;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|lastProbeSize;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_firstLocalProbe_marshall6(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void histCountProbes(probeMessage<key >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::histCountProbes(probeMessage<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_histCountProbes_probeMessage(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void genNextSamples(sampleMessage<key >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::genNextSamples(sampleMessage<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_genNextSamples_sampleMessage(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sortAll();
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::sortAll(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_sortAll_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void stepSort();
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::stepSort(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_stepSort_void(),0);
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
/* DEFS: void recvFinalKeys(int srcnode, const sendInfo &s);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::recvFinalKeys(int srcnode, const sendInfo &s, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int srcnode, const sendInfo &s
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|srcnode;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)s;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|srcnode;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)s;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_recvFinalKeys_marshall12(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void MergingWork();
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::MergingWork(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_MergingWork_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void partialSendOne();
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::partialSendOne(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_partialSendOne_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finalProbes(array_msg<key >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::finalProbes(array_msg<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_finalProbes_array_msg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finish();
 */
template < class key, class value > 

void CProxyElement_Bucket < key, value > ::finish(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_finish_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
 */
template < class key, class value > 

CkArrayID CProxy_Bucket < key, value > ::ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), opts);
  return gId;
}
template < class key, class value > 

void CProxy_Bucket < key, value > ::ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}
template < class key, class value > 

CkArrayID CProxy_Bucket < key, value > ::ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const int s1, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), opts);
  return gId;
}
template < class key, class value > 

void CProxy_Bucket < key, value > ::ckNew(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(tuning_params &)par;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_min;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_max;
    implP|nBuckets_;
    //Have to cast away const-ness to get pup routine
    implP|(CkNodeGroupID &)_nodeMgrID;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Bucket < key, value > ::idx_Bucket_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_Bucket_marshall1() {
  int epidx = CkRegisterEp("Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID)",
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
  /*Unmarshall pup'd fields: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID*/
  PUP::fromMem implP(impl_buf);
  tuning_params par; implP|par;
  key _min; implP|_min;
  key _max; implP|_max;
  int nBuckets_; implP|nBuckets_;
  CkNodeGroupID _nodeMgrID; implP|_nodeMgrID;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Bucket < key, value > (par, _min, _max, nBuckets_, _nodeMgrID);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_Bucket_marshall1(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID*/
  PUP::fromMem implP(impl_buf);
  tuning_params par; implP|par;
  key _min; implP|_min;
  key _max; implP|_max;
  int nBuckets_; implP|nBuckets_;
  CkNodeGroupID _nodeMgrID; implP|_nodeMgrID;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) Bucket < key, value > (par, _min, _max, nBuckets_, _nodeMgrID);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_Bucket_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID*/
  PUP::fromMem implP(impl_buf);
  tuning_params par; implP|par;
  key _min; implP|_min;
  key _max; implP|_max;
  int nBuckets_; implP|nBuckets_;
  CkNodeGroupID _nodeMgrID; implP|_nodeMgrID;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("par");
  implDestP|par;
  if (implDestP.hasComments()) implDestP.comment("_min");
  implDestP|_min;
  if (implDestP.hasComments()) implDestP.comment("_max");
  implDestP|_max;
  if (implDestP.hasComments()) implDestP.comment("nBuckets_");
  implDestP|nBuckets_;
  if (implDestP.hasComments()) implDestP.comment("_nodeMgrID");
  implDestP|_nodeMgrID;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)_main_proxy;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)_main_proxy;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_startBarrier_marshall2(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_startBarrier_marshall2() {
  int epidx = CkRegisterEp("startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy)",
      _call_startBarrier_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_startBarrier_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_startBarrier_marshall2);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_startBarrier_marshall2(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy*/
  PUP::fromMem implP(impl_buf);
  CProxy_Sorter<key,value > _sorter_proxy; implP|_sorter_proxy;
  CProxy_Main<key,value > _main_proxy; implP|_main_proxy;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->startBarrier(_sorter_proxy, _main_proxy);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_startBarrier_marshall2(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy*/
  PUP::fromMem implP(impl_buf);
  CProxy_Sorter<key,value > _sorter_proxy; implP|_sorter_proxy;
  CProxy_Main<key,value > _main_proxy; implP|_main_proxy;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->startBarrier(_sorter_proxy, _main_proxy);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_startBarrier_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy*/
  PUP::fromMem implP(impl_buf);
  CProxy_Sorter<key,value > _sorter_proxy; implP|_sorter_proxy;
  CProxy_Main<key,value > _main_proxy; implP|_main_proxy;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("_sorter_proxy");
  implDestP|_sorter_proxy;
  if (implDestP.hasComments()) implDestP.comment("_main_proxy");
  implDestP|_main_proxy;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::startBarrier_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData();
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::SetData(const CkEntryOptions *impl_e_opts) 
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
  int epidx = CkRegisterEp("SetData()",
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
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::SetData_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void genSample(const sampleInfo &sI);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::genSample(const sampleInfo &sI, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const sampleInfo &sI
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_genSample_marshall4(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_genSample_marshall4() {
  int epidx = CkRegisterEp("genSample(const sampleInfo &sI)",
      _call_genSample_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_genSample_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_genSample_marshall4);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_genSample_marshall4(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const sampleInfo &sI*/
  PUP::fromMem implP(impl_buf);
  sampleInfo sI; implP|sI;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->genSample(sI);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_genSample_marshall4(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const sampleInfo &sI*/
  PUP::fromMem implP(impl_buf);
  sampleInfo sI; implP|sI;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->genSample(sI);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_genSample_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const sampleInfo &sI*/
  PUP::fromMem implP(impl_buf);
  sampleInfo sI; implP|sI;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("sI");
  implDestP|sI;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::genSample_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const key &firstkey, const key &lastkey, const key &stepSize, int probeSize
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(key &)firstkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)lastkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)stepSize;
    implP|probeSize;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(key &)firstkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)lastkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)stepSize;
    implP|probeSize;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_firstProbe_marshall5(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_firstProbe_marshall5() {
  int epidx = CkRegisterEp("firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize)",
      _call_firstProbe_marshall5, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_firstProbe_marshall5);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_firstProbe_marshall5);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_firstProbe_marshall5(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const key &firstkey, const key &lastkey, const key &stepSize, int probeSize*/
  PUP::fromMem implP(impl_buf);
  key firstkey; implP|firstkey;
  key lastkey; implP|lastkey;
  key stepSize; implP|stepSize;
  int probeSize; implP|probeSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->firstProbe(firstkey, lastkey, stepSize, probeSize);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_firstProbe_marshall5(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const key &firstkey, const key &lastkey, const key &stepSize, int probeSize*/
  PUP::fromMem implP(impl_buf);
  key firstkey; implP|firstkey;
  key lastkey; implP|lastkey;
  key stepSize; implP|stepSize;
  int probeSize; implP|probeSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->firstProbe(firstkey, lastkey, stepSize, probeSize);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_firstProbe_marshall5(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const key &firstkey, const key &lastkey, const key &stepSize, int probeSize*/
  PUP::fromMem implP(impl_buf);
  key firstkey; implP|firstkey;
  key lastkey; implP|lastkey;
  key stepSize; implP|stepSize;
  int probeSize; implP|probeSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("firstkey");
  implDestP|firstkey;
  if (implDestP.hasComments()) implDestP.comment("lastkey");
  implDestP|lastkey;
  if (implDestP.hasComments()) implDestP.comment("stepSize");
  implDestP|stepSize;
  if (implDestP.hasComments()) implDestP.comment("probeSize");
  implDestP|probeSize;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::firstProbe_5_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void firstLocalProbe(int lastProbeSize);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::firstLocalProbe(int lastProbeSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int lastProbeSize
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|lastProbeSize;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|lastProbeSize;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_firstLocalProbe_marshall6(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_firstLocalProbe_marshall6() {
  int epidx = CkRegisterEp("firstLocalProbe(int lastProbeSize)",
      _call_firstLocalProbe_marshall6, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_firstLocalProbe_marshall6);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_firstLocalProbe_marshall6);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_firstLocalProbe_marshall6(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int lastProbeSize*/
  PUP::fromMem implP(impl_buf);
  int lastProbeSize; implP|lastProbeSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->firstLocalProbe(lastProbeSize);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_firstLocalProbe_marshall6(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: int lastProbeSize*/
  PUP::fromMem implP(impl_buf);
  int lastProbeSize; implP|lastProbeSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->firstLocalProbe(lastProbeSize);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_firstLocalProbe_marshall6(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int lastProbeSize*/
  PUP::fromMem implP(impl_buf);
  int lastProbeSize; implP|lastProbeSize;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("lastProbeSize");
  implDestP|lastProbeSize;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::firstLocalProbe_6_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void histCountProbes(probeMessage<key >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::histCountProbes(probeMessage<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_histCountProbes_probeMessage(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_histCountProbes_probeMessage() {
  int epidx = CkRegisterEp("histCountProbes(probeMessage<key >* impl_msg)",
      _call_histCountProbes_probeMessage, CMessage_probeMessage<key >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)probeMessage<key >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_histCountProbes_probeMessage(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->histCountProbes((probeMessage<key >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void genNextSamples(sampleMessage<key >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::genNextSamples(sampleMessage<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_genNextSamples_sampleMessage(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_genNextSamples_sampleMessage() {
  int epidx = CkRegisterEp("genNextSamples(sampleMessage<key >* impl_msg)",
      _call_genNextSamples_sampleMessage, CMessage_sampleMessage<key >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)sampleMessage<key >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_genNextSamples_sampleMessage(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->genNextSamples((sampleMessage<key >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sortAll();
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::sortAll(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_sortAll_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_sortAll_void() {
  int epidx = CkRegisterEp("sortAll()",
      _call_sortAll_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_sortAll_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->sortAll();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::sortAll_9_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void stepSort();
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::stepSort(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_stepSort_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_stepSort_void() {
  int epidx = CkRegisterEp("stepSort()",
      _call_stepSort_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_stepSort_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->stepSort();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::stepSort_10_closure))
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
/* DEFS: void recvFinalKeys(int srcnode, const sendInfo &s);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::recvFinalKeys(int srcnode, const sendInfo &s, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int srcnode, const sendInfo &s
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|srcnode;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)s;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|srcnode;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)s;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_recvFinalKeys_marshall12(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_recvFinalKeys_marshall12() {
  int epidx = CkRegisterEp("recvFinalKeys(int srcnode, const sendInfo &s)",
      _call_recvFinalKeys_marshall12, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_recvFinalKeys_marshall12);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_recvFinalKeys_marshall12);

  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_recvFinalKeys_marshall12(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int srcnode, const sendInfo &s*/
  PUP::fromMem implP(impl_buf);
  int srcnode; implP|srcnode;
  sendInfo s; implP|s;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->recvFinalKeys(srcnode, s);
}
template < class key, class value > 

int CkIndex_Bucket < key, value > ::_callmarshall_recvFinalKeys_marshall12(char* impl_buf, void* impl_obj_void) {
  Bucket < key, value > * impl_obj = static_cast< Bucket < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: int srcnode, const sendInfo &s*/
  PUP::fromMem implP(impl_buf);
  int srcnode; implP|srcnode;
  sendInfo s; implP|s;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->recvFinalKeys(srcnode, s);
  return implP.size();
}
template < class key, class value > 

void CkIndex_Bucket < key, value > ::_marshallmessagepup_recvFinalKeys_marshall12(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int srcnode, const sendInfo &s*/
  PUP::fromMem implP(impl_buf);
  int srcnode; implP|srcnode;
  sendInfo s; implP|s;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("srcnode");
  implDestP|srcnode;
  if (implDestP.hasComments()) implDestP.comment("s");
  implDestP|s;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::recvFinalKeys_12_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void MergingWork();
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::MergingWork(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_MergingWork_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_MergingWork_void() {
  int epidx = CkRegisterEp("MergingWork()",
      _call_MergingWork_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_MergingWork_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->MergingWork();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::MergingWork_13_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void partialSendOne();
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::partialSendOne(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_partialSendOne_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_partialSendOne_void() {
  int epidx = CkRegisterEp("partialSendOne()",
      _call_partialSendOne_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_partialSendOne_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->partialSendOne();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::partialSendOne_14_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finalProbes(array_msg<key >* impl_msg);
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::finalProbes(array_msg<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_finalProbes_array_msg(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_finalProbes_array_msg() {
  int epidx = CkRegisterEp("finalProbes(array_msg<key >* impl_msg)",
      _call_finalProbes_array_msg, CMessage_array_msg<key >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)array_msg<key >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_finalProbes_array_msg(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  impl_obj->finalProbes((array_msg<key >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finish();
 */
template < class key, class value > 

void CProxy_Bucket < key, value > ::finish(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Bucket < key, value > ::idx_finish_void(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_Bucket < key, value > ::reg_finish_void() {
  int epidx = CkRegisterEp("finish()",
      _call_finish_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_Bucket < key, value > ::_call_finish_void(void* impl_msg, void* impl_obj_void)
{
  Bucket < key, value > * impl_obj = static_cast<Bucket < key, value >  *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->finish();
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_Bucket < key, value > ::finish_16_closure))
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
/* DEFS: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)_main_proxy;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter_proxy;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main<key,value > &)_main_proxy;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_startBarrier_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void SetData();
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::SetData(const CkEntryOptions *impl_e_opts) 
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
/* DEFS: void genSample(const sampleInfo &sI);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::genSample(const sampleInfo &sI, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const sampleInfo &sI
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_genSample_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const key &firstkey, const key &lastkey, const key &stepSize, int probeSize
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(key &)firstkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)lastkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)stepSize;
    implP|probeSize;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(key &)firstkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)lastkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)stepSize;
    implP|probeSize;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_firstProbe_marshall5(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void firstLocalProbe(int lastProbeSize);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::firstLocalProbe(int lastProbeSize, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int lastProbeSize
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|lastProbeSize;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|lastProbeSize;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_firstLocalProbe_marshall6(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void histCountProbes(probeMessage<key >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::histCountProbes(probeMessage<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_histCountProbes_probeMessage(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void genNextSamples(sampleMessage<key >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::genNextSamples(sampleMessage<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_genNextSamples_sampleMessage(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sortAll();
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::sortAll(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_sortAll_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void stepSort();
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::stepSort(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_stepSort_void(),0);
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
/* DEFS: void recvFinalKeys(int srcnode, const sendInfo &s);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::recvFinalKeys(int srcnode, const sendInfo &s, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int srcnode, const sendInfo &s
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|srcnode;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)s;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|srcnode;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)s;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_recvFinalKeys_marshall12(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void MergingWork();
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::MergingWork(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_MergingWork_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void partialSendOne();
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::partialSendOne(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_partialSendOne_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finalProbes(array_msg<key >* impl_msg);
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::finalProbes(array_msg<key >* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_finalProbes_array_msg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finish();
 */
template < class key, class value > 

void CProxySection_Bucket < key, value > ::finish(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Bucket < key, value > ::idx_finish_void(),0);
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
  // REG: Bucket(const tuning_params &par, const key &_min, const key &_max, int nBuckets_, const CkNodeGroupID &_nodeMgrID);
  idx_Bucket_marshall1();

  // REG: void startBarrier(const CProxy_Sorter<key,value > &_sorter_proxy, const CProxy_Main<key,value > &_main_proxy);
  idx_startBarrier_marshall2();

  // REG: void SetData();
  idx_SetData_void();

  // REG: void genSample(const sampleInfo &sI);
  idx_genSample_marshall4();

  // REG: void firstProbe(const key &firstkey, const key &lastkey, const key &stepSize, int probeSize);
  idx_firstProbe_marshall5();

  // REG: void firstLocalProbe(int lastProbeSize);
  idx_firstLocalProbe_marshall6();

  // REG: void histCountProbes(probeMessage<key >* impl_msg);
  idx_histCountProbes_probeMessage();

  // REG: void genNextSamples(sampleMessage<key >* impl_msg);
  idx_genNextSamples_sampleMessage();

  // REG: void sortAll();
  idx_sortAll_void();

  // REG: void stepSort();
  idx_stepSort_void();

  // REG: void Load(data_msg<key,value >* impl_msg);
  idx_Load_data_msg();

  // REG: void recvFinalKeys(int srcnode, const sendInfo &s);
  idx_recvFinalKeys_marshall12();

  // REG: void MergingWork();
  idx_MergingWork_void();

  // REG: void partialSendOne();
  idx_partialSendOne_void();

  // REG: void finalProbes(array_msg<key >* impl_msg);
  idx_finalProbes_array_msg();

  // REG: void finish();
  idx_finish_void();

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
  void _sdag_pup(PUP::er &p) { }
  void virtual_pup(PUP::er &p) {
    recursive_pup<Bucket < key, value >  >(dynamic_cast<Bucket < key, value > * >(this), p);
}
  void parent_pup(PUP::er &p) {
    recursive_pup< ArrayElementT<CkIndex1D> >(this, p);
    p|thisProxy;
  }
};
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: template < class key, class value > nodegroup NodeManager: NodeGroup{
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
#ifdef CK_TEMPLATES_ONLY
template < class key, class value >  int CkIndex_NodeManager < key, value > ::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
/* DEFS: NodeManager(const key &_minkey, const key &_maxkey);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|nElem;
    implP|pe;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Bucket<key,value > &)_bucket_arr;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|nElem;
    implP|pe;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Bucket<key,value > &)_bucket_arr;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void collectSamples(const sampleInfo &sI);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::collectSamples(const sampleInfo &sI, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const sampleInfo &sI
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void assembleSamples(const std::vector<key > &proc_sample);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::assembleSamples(const std::vector<key > &proc_sample, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const std::vector<key > &proc_sample
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<key > &)proc_sample;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<key > &)proc_sample;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void loadkeys(int dest, const sendInfo &inf);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::loadkeys(int dest, const sendInfo &inf, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int dest, const sendInfo &inf
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|dest;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)inf;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|dest;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)inf;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sendOne(int dest);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::sendOne(int dest, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int dest
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|dest;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|dest;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void releaseBufMsgs();
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::releaseBufMsgs(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void recvOne(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::recvOne(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::handleOne(const wrap_ptr &msg, int sampleInd, int numsamples, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const wrap_ptr &msg, int sampleInd, int numsamples
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(wrap_ptr &)msg;
    implP|sampleInd;
    implP|numsamples;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(wrap_ptr &)msg;
    implP|sampleInd;
    implP|numsamples;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finishOne();
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::finishOne(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void localhist(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::localhist(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void depositHist();
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::depositHist(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sendToBuckets(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxyElement_NodeManager < key, value > ::sendToBuckets(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetGroupPe(), ckGetGroupID());
  } else CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetGroupPe(), ckGetGroupID(),0+CK_MSG_EXPEDITED);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: NodeManager(const key &_minkey, const key &_maxkey);
 */
template < class key, class value > 

CkGroupID CProxy_NodeManager < key, value > ::ckNew(const key &_minkey, const key &_maxkey, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const key &_minkey, const key &_maxkey
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_minkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_maxkey;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(key &)_minkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_maxkey;
  }
  UsrToEnv(impl_msg)->setMsgtype(NodeBocInitMsg);
  if (impl_e_opts)
    UsrToEnv(impl_msg)->setGroupDep(impl_e_opts->getGroupDepID());
  CkGroupID gId = CkCreateNodeGroup(CkIndex_NodeManager < key, value > ::__idx, CkIndex_NodeManager < key, value > ::idx_NodeManager_marshall1(), impl_msg);
  return gId;
}
template < class key, class value > 

  CProxy_NodeManager < key, value > ::CProxy_NodeManager(const key &_minkey, const key &_maxkey, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const key &_minkey, const key &_maxkey
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_minkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_maxkey;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(key &)_minkey;
    //Have to cast away const-ness to get pup routine
    implP|(key &)_maxkey;
  }
  UsrToEnv(impl_msg)->setMsgtype(NodeBocInitMsg);
  if (impl_e_opts)
    UsrToEnv(impl_msg)->setGroupDep(impl_e_opts->getGroupDepID());
  ckSetGroupID(CkCreateNodeGroup(CkIndex_NodeManager < key, value > ::__idx, CkIndex_NodeManager < key, value > ::idx_NodeManager_marshall1(), impl_msg));
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_NodeManager_marshall1() {
  int epidx = CkRegisterEp("NodeManager(const key &_minkey, const key &_maxkey)",
      _call_NodeManager_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_NodeManager_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_NodeManager_marshall1);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_NodeManager_marshall1(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const key &_minkey, const key &_maxkey*/
  PUP::fromMem implP(impl_buf);
  key _minkey; implP|_minkey;
  key _maxkey; implP|_maxkey;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) NodeManager < key, value > (_minkey, _maxkey);
}
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::_callmarshall_NodeManager_marshall1(char* impl_buf, void* impl_obj_void) {
  NodeManager < key, value > * impl_obj = static_cast< NodeManager < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const key &_minkey, const key &_maxkey*/
  PUP::fromMem implP(impl_buf);
  key _minkey; implP|_minkey;
  key _maxkey; implP|_maxkey;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) NodeManager < key, value > (_minkey, _maxkey);
  return implP.size();
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_NodeManager_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const key &_minkey, const key &_maxkey*/
  PUP::fromMem implP(impl_buf);
  key _minkey; implP|_minkey;
  key _maxkey; implP|_maxkey;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("_minkey");
  implDestP|_minkey;
  if (implDestP.hasComments()) implDestP.comment("_maxkey");
  implDestP|_maxkey;
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|nElem;
    implP|pe;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Bucket<key,value > &)_bucket_arr;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|nElem;
    implP|pe;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Bucket<key,value > &)_bucket_arr;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_registerLocalChare_marshall2() {
  int epidx = CkRegisterEp("registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter)",
      _call_registerLocalChare_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_registerLocalChare_marshall2);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_registerLocalChare_marshall2(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    impl_msg = CkCopyMsg(&impl_msg);
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter*/
  PUP::fromMem implP(impl_buf);
  int nElem; implP|nElem;
  int pe; implP|pe;
  CProxy_Bucket<key,value > _bucket_arr; implP|_bucket_arr;
  CProxy_Sorter<key,value > _sorter; implP|_sorter;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->registerLocalChare(nElem, pe, _bucket_arr, _sorter);
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_registerLocalChare_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter*/
  PUP::fromMem implP(impl_buf);
  int nElem; implP|nElem;
  int pe; implP|pe;
  CProxy_Bucket<key,value > _bucket_arr; implP|_bucket_arr;
  CProxy_Sorter<key,value > _sorter; implP|_sorter;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("nElem");
  implDestP|nElem;
  if (implDestP.hasComments()) implDestP.comment("pe");
  implDestP|pe;
  if (implDestP.hasComments()) implDestP.comment("_bucket_arr");
  implDestP|_bucket_arr;
  if (implDestP.hasComments()) implDestP.comment("_sorter");
  implDestP|_sorter;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::registerLocalChare_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void collectSamples(const sampleInfo &sI);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::collectSamples(const sampleInfo &sI, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const sampleInfo &sI
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetGroupID(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_collectSamples_marshall3() {
  int epidx = CkRegisterEp("collectSamples(const sampleInfo &sI)",
      _call_collectSamples_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_collectSamples_marshall3);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_collectSamples_marshall3(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    impl_msg = CkCopyMsg(&impl_msg);
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const sampleInfo &sI*/
  PUP::fromMem implP(impl_buf);
  sampleInfo sI; implP|sI;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->collectSamples(sI);
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_collectSamples_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const sampleInfo &sI*/
  PUP::fromMem implP(impl_buf);
  sampleInfo sI; implP|sI;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("sI");
  implDestP|sI;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::collectSamples_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void assembleSamples(const std::vector<key > &proc_sample);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::assembleSamples(const std::vector<key > &proc_sample, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const std::vector<key > &proc_sample
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<key > &)proc_sample;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<key > &)proc_sample;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_assembleSamples_marshall4() {
  int epidx = CkRegisterEp("assembleSamples(const std::vector<key > &proc_sample)",
      _call_assembleSamples_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_assembleSamples_marshall4);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_assembleSamples_marshall4(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    impl_msg = CkCopyMsg(&impl_msg);
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const std::vector<key > &proc_sample*/
  PUP::fromMem implP(impl_buf);
  std::vector<key > proc_sample; implP|proc_sample;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->assembleSamples(proc_sample);
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_assembleSamples_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const std::vector<key > &proc_sample*/
  PUP::fromMem implP(impl_buf);
  std::vector<key > proc_sample; implP|proc_sample;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("proc_sample");
  implDestP|proc_sample;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::assembleSamples_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void loadkeys(int dest, const sendInfo &inf);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::loadkeys(int dest, const sendInfo &inf, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int dest, const sendInfo &inf
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|dest;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)inf;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|dest;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)inf;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_loadkeys_marshall5() {
  int epidx = CkRegisterEp("loadkeys(int dest, const sendInfo &inf)",
      _call_loadkeys_marshall5, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_loadkeys_marshall5);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_loadkeys_marshall5(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    impl_msg = CkCopyMsg(&impl_msg);
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int dest, const sendInfo &inf*/
  PUP::fromMem implP(impl_buf);
  int dest; implP|dest;
  sendInfo inf; implP|inf;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->loadkeys(dest, inf);
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_loadkeys_marshall5(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int dest, const sendInfo &inf*/
  PUP::fromMem implP(impl_buf);
  int dest; implP|dest;
  sendInfo inf; implP|inf;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("dest");
  implDestP|dest;
  if (implDestP.hasComments()) implDestP.comment("inf");
  implDestP|inf;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::loadkeys_5_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sendOne(int dest);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::sendOne(int dest, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int dest
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|dest;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|dest;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_sendOne_marshall6() {
  int epidx = CkRegisterEp("sendOne(int dest)",
      _call_sendOne_marshall6, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_sendOne_marshall6);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_sendOne_marshall6);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_sendOne_marshall6(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int dest*/
  PUP::fromMem implP(impl_buf);
  int dest; implP|dest;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sendOne(dest);
}
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::_callmarshall_sendOne_marshall6(char* impl_buf, void* impl_obj_void) {
  NodeManager < key, value > * impl_obj = static_cast< NodeManager < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: int dest*/
  PUP::fromMem implP(impl_buf);
  int dest; implP|dest;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sendOne(dest);
  return implP.size();
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_sendOne_marshall6(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int dest*/
  PUP::fromMem implP(impl_buf);
  int dest; implP|dest;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("dest");
  implDestP|dest;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::sendOne_6_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void releaseBufMsgs();
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::releaseBufMsgs(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_releaseBufMsgs_void() {
  int epidx = CkRegisterEp("releaseBufMsgs()",
      _call_releaseBufMsgs_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_releaseBufMsgs_void(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkFreeSysMsg(impl_msg);
  impl_obj->releaseBufMsgs();
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::releaseBufMsgs_7_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void recvOne(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::recvOne(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_recvOne_data_msg() {
  int epidx = CkRegisterEp("recvOne(data_msg<key,value >* impl_msg)",
      _call_recvOne_data_msg, CMessage_data_msg<key,value >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)data_msg<key,value >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_recvOne_data_msg(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  impl_obj->recvOne((data_msg<key,value >*)impl_msg);
  CmiUnlock(impl_obj->__nodelock);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::handleOne(const wrap_ptr &msg, int sampleInd, int numsamples, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const wrap_ptr &msg, int sampleInd, int numsamples
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(wrap_ptr &)msg;
    implP|sampleInd;
    implP|numsamples;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(wrap_ptr &)msg;
    implP|sampleInd;
    implP|numsamples;
  }
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_handleOne_marshall9() {
  int epidx = CkRegisterEp("handleOne(const wrap_ptr &msg, int sampleInd, int numsamples)",
      _call_handleOne_marshall9, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_handleOne_marshall9);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_handleOne_marshall9);

  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_handleOne_marshall9(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const wrap_ptr &msg, int sampleInd, int numsamples*/
  PUP::fromMem implP(impl_buf);
  wrap_ptr msg; implP|msg;
  int sampleInd; implP|sampleInd;
  int numsamples; implP|numsamples;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->handleOne(msg, sampleInd, numsamples);
}
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::_callmarshall_handleOne_marshall9(char* impl_buf, void* impl_obj_void) {
  NodeManager < key, value > * impl_obj = static_cast< NodeManager < key, value >  *>(impl_obj_void);
  /*Unmarshall pup'd fields: const wrap_ptr &msg, int sampleInd, int numsamples*/
  PUP::fromMem implP(impl_buf);
  wrap_ptr msg; implP|msg;
  int sampleInd; implP|sampleInd;
  int numsamples; implP|numsamples;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->handleOne(msg, sampleInd, numsamples);
  return implP.size();
}
template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_marshallmessagepup_handleOne_marshall9(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const wrap_ptr &msg, int sampleInd, int numsamples*/
  PUP::fromMem implP(impl_buf);
  wrap_ptr msg; implP|msg;
  int sampleInd; implP|sampleInd;
  int numsamples; implP|numsamples;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("msg");
  implDestP|msg;
  if (implDestP.hasComments()) implDestP.comment("sampleInd");
  implDestP|sampleInd;
  if (implDestP.hasComments()) implDestP.comment("numsamples");
  implDestP|numsamples;
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::handleOne_9_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finishOne();
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::finishOne(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_finishOne_void() {
  int epidx = CkRegisterEp("finishOne()",
      _call_finishOne_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_finishOne_void(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_finishOne_void(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkFreeSysMsg(impl_msg);
  impl_obj->finishOne();
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::finishOne_10_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void localhist(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::localhist(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_localhist_data_msg() {
  int epidx = CkRegisterEp("localhist(data_msg<key,value >* impl_msg)",
      _call_localhist_data_msg, CMessage_data_msg<key,value >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)data_msg<key,value >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_localhist_data_msg(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  impl_obj->localhist((data_msg<key,value >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void depositHist();
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::depositHist(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetGroupID(),0);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_depositHist_void() {
  int epidx = CkRegisterEp("depositHist()",
      _call_depositHist_void, 0, __idx, 0);
  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_depositHist_void(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  if(CmiTryLock(impl_obj->__nodelock)) {
    CkSendMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_depositHist_void(),impl_msg,CkMyNode(),impl_obj->CkGetNodeGroupID());
    return;
  }
  CkFreeSysMsg(impl_msg);
  impl_obj->depositHist();
  CmiUnlock(impl_obj->__nodelock);
}
template < class key, class value > PUPable_def_template_nonInst(SINGLE_ARG(Closure_NodeManager < key, value > ::depositHist_12_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sendToBuckets(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxy_NodeManager < key, value > ::sendToBuckets(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     CkNodeGroupMsgPrep(CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetGroupID());
     ckDelegatedTo()->NodeGroupBroadcast(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetGroupID());
  } else CkBroadcastMsgNodeBranch(CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetGroupID(),0+CK_MSG_EXPEDITED);
}

// Entry point registration function
template < class key, class value > 

int CkIndex_NodeManager < key, value > ::reg_sendToBuckets_data_msg() {
  int epidx = CkRegisterEp("sendToBuckets(data_msg<key,value >* impl_msg)",
      _call_sendToBuckets_data_msg, CMessage_data_msg<key,value >::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)data_msg<key,value >::ckDebugPup);
  return epidx;
}

template < class key, class value > 

void CkIndex_NodeManager < key, value > ::_call_sendToBuckets_data_msg(void* impl_msg, void* impl_obj_void)
{
  NodeManager < key, value > * impl_obj = static_cast<NodeManager < key, value >  *>(impl_obj_void);
  impl_obj->sendToBuckets((data_msg<key,value >*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: NodeManager(const key &_minkey, const key &_maxkey);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|nElem;
    implP|pe;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Bucket<key,value > &)_bucket_arr;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|nElem;
    implP|pe;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Bucket<key,value > &)_bucket_arr;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Sorter<key,value > &)_sorter;
  }
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_registerLocalChare_marshall2(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void collectSamples(const sampleInfo &sI);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::collectSamples(const sampleInfo &sI, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const sampleInfo &sI
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(sampleInfo &)sI;
  }
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_collectSamples_marshall3(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0+CK_MSG_EXPEDITED);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void assembleSamples(const std::vector<key > &proc_sample);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::assembleSamples(const std::vector<key > &proc_sample, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const std::vector<key > &proc_sample
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<key > &)proc_sample;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<key > &)proc_sample;
  }
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_assembleSamples_marshall4(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void loadkeys(int dest, const sendInfo &inf);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::loadkeys(int dest, const sendInfo &inf, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int dest, const sendInfo &inf
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|dest;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)inf;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|dest;
    //Have to cast away const-ness to get pup routine
    implP|(sendInfo &)inf;
  }
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_loadkeys_marshall5(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sendOne(int dest);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::sendOne(int dest, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int dest
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|dest;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|dest;
  }
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_sendOne_marshall6(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void releaseBufMsgs();
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::releaseBufMsgs(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_releaseBufMsgs_void(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void recvOne(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::recvOne(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_recvOne_data_msg(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::handleOne(const wrap_ptr &msg, int sampleInd, int numsamples, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: const wrap_ptr &msg, int sampleInd, int numsamples
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(wrap_ptr &)msg;
    implP|sampleInd;
    implP|numsamples;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(wrap_ptr &)msg;
    implP|sampleInd;
    implP|numsamples;
  }
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_handleOne_marshall9(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void finishOne();
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::finishOne(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_finishOne_void(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void localhist(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::localhist(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_localhist_data_msg(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void depositHist();
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::depositHist(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_depositHist_void(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
/* DEFS: void sendToBuckets(data_msg<key,value >* impl_msg);
 */
template < class key, class value > 

void CProxySection_NodeManager < key, value > ::sendToBuckets(data_msg<key,value >* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
     ckDelegatedTo()->NodeGroupSectionSend(ckDelegatedPtr(),CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg, ckGetNumSections(), ckGetSectionIDs());
  } else {
    void *impl_msg_tmp;
    for (int i=0; i<ckGetNumSections(); ++i) {
       impl_msg_tmp= (i<ckGetNumSections()-1) ? CkCopyMsg((void **) &impl_msg):impl_msg;
       CkSendMsgNodeBranchMulti(CkIndex_NodeManager < key, value > ::idx_sendToBuckets_data_msg(), impl_msg_tmp, ckGetGroupIDn(i), ckGetNumElements(i), ckGetElements(i),0+CK_MSG_EXPEDITED);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */

#ifdef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > void CkIndex_NodeManager < key, value > ::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeGroup);
  CkRegisterBase(__idx, CkIndex_NodeGroup::__idx);
   CkRegisterGroupIrr(__idx,NodeManager < key, value > ::isIrreducible());
  // REG: NodeManager(const key &_minkey, const key &_maxkey);
  idx_NodeManager_marshall1();

  // REG: void registerLocalChare(int nElem, int pe, const CProxy_Bucket<key,value > &_bucket_arr, const CProxy_Sorter<key,value > &_sorter);
  idx_registerLocalChare_marshall2();

  // REG: void collectSamples(const sampleInfo &sI);
  idx_collectSamples_marshall3();

  // REG: void assembleSamples(const std::vector<key > &proc_sample);
  idx_assembleSamples_marshall4();

  // REG: void loadkeys(int dest, const sendInfo &inf);
  idx_loadkeys_marshall5();

  // REG: void sendOne(int dest);
  idx_sendOne_marshall6();

  // REG: void releaseBufMsgs();
  idx_releaseBufMsgs_void();

  // REG: void recvOne(data_msg<key,value >* impl_msg);
  idx_recvOne_data_msg();

  // REG: void handleOne(const wrap_ptr &msg, int sampleInd, int numsamples);
  idx_handleOne_marshall9();

  // REG: void finishOne();
  idx_finishOne_void();

  // REG: void localhist(data_msg<key,value >* impl_msg);
  idx_localhist_data_msg();

  // REG: void depositHist();
  idx_depositHist_void();

  // REG: void sendToBuckets(data_msg<key,value >* impl_msg);
  idx_sendToBuckets_data_msg();

}
#endif /* CK_TEMPLATES_ONLY */
#ifdef CK_TEMPLATES_ONLY
template < class key, class value > 
struct CBase_NodeManager : public NodeGroup, virtual CBase
 {
  CProxy_NodeManager < key, value >  thisProxy;
  CBase_NodeManager() : thisProxy(this)
    , NodeGroup()
  { }
  CBase_NodeManager(CkMigrateMessage* m) : thisProxy(this)
    , NodeGroup(m)  { }
  template <typename... Args>
  CBase_NodeManager(Args... args) : thisProxy(this)
    , NodeGroup(args...)  { }
  void pup(PUP::er &p) { }
  void _sdag_pup(PUP::er &p) { }
  void virtual_pup(PUP::er &p) {
    recursive_pup<NodeManager < key, value >  >(dynamic_cast<NodeManager < key, value > * >(this), p);
}
  void parent_pup(PUP::er &p) {
    recursive_pup< NodeGroup >(this, p);
    p|thisProxy;
  }
};
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerHistSort(void)
{
  static int _done = 0; if(_done) return; _done = 1;

  _registerInitCall(register_sum_uint64_t,1);

  _registerInitCall(register_minmax_uint64_t,1);












}
#endif /* CK_TEMPLATES_ONLY */
