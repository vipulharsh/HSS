#include <assert.h>
/*global*/ CkReduction::reducerType sum_uint64_t_type; 

//epsilon  = 10% imbalance
#define EPS 2


///reduction for summing arrays of unsigned 64-bit integers
CkReductionMsg *sum_uint64_t(int nMsg,CkReductionMsg **msgs)
{
  ///Sum starts off at zero 
  int size = msgs[0]->getSize()/sizeof(uint64_t);
  uint64_t ret[size];
  for(int i=0; i<size; i++)
    ret[i] = 0;
  uint64_t *m;
  for (int i=0;i<nMsg;i++) {
    m=(uint64_t *)msgs[i]->getData();
    for (int j = 0; j <size;j ++) {
      ret[j]+=m[j];
      //CkPrintf("[wtf] m[%d]: %lu \n", j, m[j]);
    }
  }
  return CkReductionMsg::buildNew(size*sizeof(uint64_t),ret);
} 

/*initcall*/ void register_sum_uint64_t(void){
  sum_uint64_t_type = CkReduction::addReducer(sum_uint64_t);
} 


CkReductionMsg *minmax_uint64_t(int nMsg,CkReductionMsg **msgs){
  uint64_t ret[2];
  uint64_t *m=(uint64_t *)msgs[0]->getData();
  ret[0] = m[0]; 
  ret[1] = m[1];
  for (int i=1;i<nMsg;i++) {
    //CkAssert(msgs[i]->getSize()==sizeof(int));
    m=(uint64_t *)msgs[i]->getData();
    ret[0] = std::min(ret[0], m[0]);
    ret[1] = std::max(ret[1], m[1]);
  }
  return CkReductionMsg::buildNew(2*sizeof(uint64_t),ret);
}

CkReduction::reducerType minmax_uint64_t_type;

//initnode
void register_minmax_uint64_t(void){
  minmax_uint64_t_type=CkReduction::addReducer(minmax_uint64_t);
}





template<class key, class value>
Sorter<key, value>::Sorter(CkMigrateMessage *msg){}


template<class key, class value>
Sorter<key, value>::Sorter(const CkArrayID &bucketArr, int _nBuckets, key min,
            key max, tuning_params par, CProxy_Main<key, value> _mainproxy, CkNodeGroupID _nodeMgrID) : 
        mainproxy(_mainproxy), buckets(bucketArr), nBuckets(_nBuckets),  nodeMgrID(_nodeMgrID),
        minkey(min), maxkey(max){
    //VERBOSEPRINTF("Setting up sort. From Constructor\n");
    c1 = CmiWallTimer();
    nNodes = CkNumNodes();
    params = new tuning_params();
    *params = par;
    firstUse = true;
    numProbes = 0;
    ckout<<"CONS Params->probe_max: "<<params->probe_max<<endl;
    //should be a reset
    collectedSample.clear();
    Init();
}




template<class key, class value>
void Sorter<key, value>::finishBarrier(CkReductionMsg *msg)
{    c1 = CmiWallTimer();
    buckets.SetData();
}



/*
template <class key, class value>
void Sorter<key, value>::globalMinMax(CkReductionMsg *msg){
  key *m = (key *)msg->getData();
  globalmin = m[0];
  globalmax = m[1];
  ckout<<"In Sorter global Min Max "<<m[0]<<" "<<m[1]<<endl;
  Begin();
}
*/


extern int maxSampleSize();


template<class key, class value>
void Sorter<key, value>::Init(){
	      int maxprobe = std::max(params->probe_max, 2*maxSampleSize());
        ckout<<"maxprobe: "<<maxprobe<<endl;
        lastProbe = new key[maxprobe+1];
        scratch = new key[maxprobe+1];
        finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
        achieved = new bool[nBuckets+2];
        achievedCounts = new uint64_t[nBuckets+2];
        firstUse = false;

        lb_keys = new key[nBuckets+2];
        ub_keys = new key[nBuckets+2];
        lb_ranks = new uint64_t[nBuckets+2];
        ub_ranks = new uint64_t[nBuckets+2];
        
        
        //Don't use memset for non-inbuilt types
        memset(achieved+1, false, nBuckets);
        achieved[0] = achieved[nBuckets] = true;
        achievedCounts[0] = 0;
        finalSplitters[0] = minkey;    
        finalSplitters[nBuckets] = maxkey;
        achievedSplitters = 2;
        allPreviousProbes.clear();
        //allPreviousProbes[minkey] = 0;
        ckout<<"Exiting Sorter Init... "<<maxprobe<<endl;
}





/*
template<class key, class value>
void Sorter<key, value>::Begin(){


    CkAbort("Should not come here");
    CkExit();

    ckout<<"Sorter Constructor : "<<endl; 
    ckout<<"Params->probe_max: "<<params->probe_max<<endl;
    ckout<<"nBuckets: "<<nBuckets<<endl;;
    ckout<<"minkey: "<<minkey<<", maxkey: "<<maxkey<<endl;
    ckout<<"globalmin: "<<globalmin<<", globalmax: "<<globalmax<<endl;
    

    if(firstUse){
        lastProbe = new key[params->probe_max+1];
        scratch = new key[params->probe_max+1];
        finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
        achieved = new bool[nBuckets+2];
        achievedCounts = new uint64_t[nBuckets+2];
    }

    if(firstUse || !params->reuse_probe_results){
        key firstkey = globalmin;
        key lastkey = globalmax+1;
        int prbmaxBy2 = params->probe_max/2;
        std::pair<int, key> p2= grtstPow2((lastkey-firstkey + prbmaxBy2 - 1)/prbmaxBy2 + 1);
        key step = p2.second;
        lastProbeSize = (lastkey - firstkey)/step + 1;
        ckout<<step<<" "<<lastProbeSize<<" First sorter "<<endl;
        buckets.firstProbe(firstkey, lastkey, step, lastProbeSize);
        for(int i=0; i<lastProbeSize; i++)
            lastProbe[i] = firstkey + ((i+1) * step);
        lastProbe[lastProbeSize-1] = lastkey; //this is fine
    }
    else{
        lastProbeSize = nBuckets;    
        buckets.firstLocalProbe(lastProbeSize);
        memcpy(lastProbe, finalSplitters, nBuckets * sizeof(key));
    }

    firstUse = false;
    
    //Don't use memset for non-inbuilt types
    memset(achieved+1, false, nBuckets);
    achieved[0] = achieved[nBuckets] = true;
    achievedCounts[0] = 0;
    finalSplitters[0] = minkey;    
    finalSplitters[nBuckets] = maxkey;
    achievedSplitters = 2;
    allPreviousProbes.clear();
    //allPreviousProbes[minkey] = 0;
    ckout<<"Exiting Sorter Constructor... "<<params->probe_max<<endl;
}
*/

template<class key, class value>
void Sorter<key, value>::recvSample(array_msg<key>* am){
  static int msgReceived = 0;

  //ckout<<"Received msg number "<<msgReceived<<" at "<<CkMyNode()<<endl;
  //ckout<<"Elts. recved "<<am->numElem<<endl;
  //for(int i=0; i<am->numElem; i++)
  //    ckout<<am->data[i]<<endl;
  collectedSample.insert(collectedSample.end(), am->data, am->data + am->numElem);  
  msgReceived++;
  delete(am); 
  if(msgReceived == CkNumNodes()){
    std::sort(collectedSample.begin(), collectedSample.end());
    array_msg<key> *finalProbe = new (collectedSample.size() + 1) array_msg<key>;
    finalProbe->numElem = collectedSample.size() + 1;
    lastProbe = new key[finalProbe->numElem];
    memcpy(finalProbe->data, &collectedSample[0], collectedSample.size() * sizeof(key));
    ckout<<" maxkey: "<<maxkey<<endl;
    finalProbe->data[finalProbe->numElem-1] = maxkey;
    memcpy(lastProbe, finalProbe->data, finalProbe->numElem * sizeof(key));
    lastProbeSize = finalProbe->numElem;


    CkPrintf("[%d]Samples collected, sending for histogramming... %lf .\n", CkMyPe(), (CmiWallTimer()-c1));   
    //ckout<<"Initiating Probe from sorter: "<<probeSize<<endl;
    //for(int i=0; i<lastProbeSize; i++)
    //	 ckout<<"Sample #"<<i<<" : "<<lastProbe[i]<<endl;

    buckets.finalProbes(finalProbe);

    collectedSample.clear();
    msgReceived = 0;
    //CProxy_NodeManager<key, value> nodemgr = CProxy_NodeManager<key, value>(nodeMgrID);   
    //nodemgr.finalProbes(finalProbe);
    //(Global<key, value>::nodemgr)->finalProbes(finalProbe);   
  }
}




template <class key, class value>
inline int Sorter<key, value>::checkGoal(int splitterInd, uint64_t histCount){
    uint64_t goal = (nElements * splitterInd)/nBuckets;
    uint64_t margin = (nElements * EPS)/(100 * nBuckets); //5%
    //ckout<<nElements<<" : "<<splitterInd<<" : "<<nBuckets<<" : "<<histCount<<endl;
    //ckout<<goal<<" : "<<margin<<" : "<<goal-margin<<" : "<<goal + margin<<endl;
    return (histCount < goal-margin ? -1 : (histCount > goal+margin ? 1 : 0));
}



template <class key, class value>
void Sorter<key, value>::Histogram(CkReductionMsg *msg){
    traceRegisterUserEvent("Histogram: Sorter", 1);
    double startTime = CmiWallTimer();
    VERBOSEPRINTF("Doing Histogramming %lf seconds after start.\n", (CmiWallTimer()-c1));   
    double cc1 = CmiWallTimer();
    numProbes++;    
    ckout<<"Probe Number : #### : "<<numProbes<<", maxprobesize: "<<params->probe_max<<",  lastProbeSize: "<<lastProbeSize<<endl;
    uint64_t* histCounts = (uint64_t*)msg->getData();
    int lenhist = (int)msg->getSize()/sizeof(uint64_t);   

/*
    for(int i=0; i<lenhist; i++){
      CkPrintf("*************** lastProbe[%lu], histcount: %lu \n", lastProbe[i], histCounts[i]);
    }
*/    

    //store cumulative counts
    for(int i=1; i<lenhist; i++){
      histCounts[i] += histCounts[i-1];
    }  
    
    assert(lenhist == lastProbeSize);

    std::vector<std::pair<key, int> > newachv; //splitters that were achieved in this round
    if(numProbes <= 1){
      nElements = histCounts[lastProbeSize-1];
      achievedCounts[nBuckets] = nElements; 
      newachv.push_back(std::pair<key, int>(maxkey, nBuckets));
    }


    int p = 0; //currProbe
    int s = 1; //currSplitter
    while(s < nBuckets){
        //ckout<<s<<" : "<<p<<" : "<<histCounts[p]<<endl;
        if(!achieved[s]){
          //relative position of  histCounts[currProbe] w.r.t. currSplitter 
          while(checkGoal(s, histCounts[p]) < 0){
              p++;
          }
          if(checkGoal(s, histCounts[p]) == 0){ //achieved
              achievedSplitters++;
              finalSplitters[s] = lastProbe[p];
              achieved[s] = true;
              achievedCounts[s] = histCounts[p];
              newachv.push_back(std::pair<key, int>(lastProbe[p], s));
          }
        }
        s++;                        
    }
    //double cc2 = CmiWallTimer();
    //ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr0 <<"<<endl;

    traceUserBracketEvent(1, startTime, CmiWallTimer());
    traceRegisterUserEvent("Histogram: Before checking goals and updating bounds", 2);
    startTime = CmiWallTimer();


    /* Update lower, upper bounds */
    updateBounds(msg);


//****************FOR DEBUG ******************
    int spltridx = 1;
    for(int i=0; i<lastProbeSize; i++){
      //!!! No need to store in hash-table for HSS
      //allPreviousProbes[lastProbe[i]] = histCounts[i];
      
      while(checkGoal(spltridx, histCounts[i]) > 0){
          spltridx++;
      }

      uint64_t goal = (nElements * spltridx)/nBuckets;
      //ckout<<lastProbe[i]<<" :-: "<<histCounts[i]<<",   Goal: "<<goal<<", "<<achieved[spltridx]<<endl;
    }
//**********************************************
    traceUserBracketEvent(2, startTime, CmiWallTimer());
    traceRegisterUserEvent("Histogram: Before nextSamples", 3);
    startTime = CmiWallTimer();
    assert(histCounts[lastProbeSize-1] == nElements);
    nextSamples(newachv, histCounts, msg);
    //nextProbes(newachv, histCounts, msg);
    double cc2 = CmiWallTimer();
    ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr0 "<<" : "<<allPreviousProbes.size()<<endl;
    traceUserBracketEvent(3, startTime, CmiWallTimer());
   //delete msg
}


template <class key, class value>
void Sorter<key, value>::updateBounds(CkReductionMsg *msg){
    if(numProbes <= 1){
      ckout<<"***************************************####################comes here"<<endl;
      for(int i=0; i<nBuckets; i++){
        ub_ranks[i] = nElements;
        lb_ranks[i] = 0;
        ub_keys[i] = maxkey;
        lb_keys[i] = minkey;
      }
    }
//NOTE: histCounts should be cumulative counts, call only after updating reduction msg to cumulative msg
    uint64_t* histCounts = (uint64_t*)msg->getData();
    int lenhist = (int)msg->getSize()/sizeof(uint64_t);


    int cs = 0; //current splitter
    for(int i=0; i<lenhist; i++){
        //ckout<<histCounts[i]<<endl;
        while(cs < nBuckets  &&  ub_ranks[cs] <= histCounts[i]) cs++;
        while(cs < nBuckets && idealSplitterRank(cs) <= histCounts[i]){
          ub_ranks[cs] = histCounts[i];
          ub_keys[cs] = lastProbe[i];
          cs++;
        }
    }      

    cs = nBuckets; //current splitter
    for(int i=lenhist-1; i>=0; i--){
        while(cs > 0  &&  lb_ranks[cs] >= histCounts[i]) cs--;
        while(cs > 0 && idealSplitterRank(cs) >= histCounts[i]){
          lb_ranks[cs] = histCounts[i];
          lb_keys[cs] = lastProbe[i];
          cs--;
        }
    }
}


template <class key, class value>
void Sorter<key, value>::nextSamples(std::vector<std::pair<key, int> > &newachv, uint64_t* histCounts, CkReductionMsg *msg){
    
    uint64_t totalLength = 0;
    uint64_t totalLength2 = 0;
    uint64_t prevLb = 0;
    int nIntervals = 0;

    traceRegisterUserEvent("nextSamples: Before for loop 1", 21);
    double startTime = CmiWallTimer();

    for(int i=1; i<nBuckets; i++){
      totalLength2 += ub_ranks[i] - lb_ranks[i];
      if(!achieved[i] && (lb_ranks[i] != prevLb || i==1)){
          totalLength += ub_ranks[i] - lb_ranks[i];
          nIntervals++;
      }
      prevLb = lb_ranks[i];
    }
    ckout<<"Fraction of input to be sampled: "<<((double)totalLength)/nElements<<", "<<((double)totalLength2)/nElements<<" achieved: "<<newachv.size()<<endl;

    traceUserBracketEvent(21, startTime, CmiWallTimer());
    traceRegisterUserEvent("nextSamples: Before creating message", 22);
    startTime = CmiWallTimer();

    int r = newachv.size();
    sampleMessage<key> *sm = new (nIntervals, nIntervals, r, r, r) sampleMessage<key>;
    sm->nIntervals = nIntervals;
    sm->num_newachv = r;
    sm->f = ((double)totalLength)/nElements;
    nIntervals = 0;

    traceUserBracketEvent(22, startTime, CmiWallTimer());
    traceRegisterUserEvent("nextSamples: Before updating splitter intervals", 23);
    startTime = CmiWallTimer();

    for(int i=1; i<nBuckets; i++){
      if(!achieved[i]){
        if(lb_ranks[i] != prevLb || i==1){
            sm->lb[nIntervals] = lb_keys[i];
            sm->ub[nIntervals] = ub_keys[i];
            nIntervals++;
        }
        prevLb = lb_ranks[i];
      }
    }


    traceUserBracketEvent(23, startTime, CmiWallTimer());
    traceRegisterUserEvent("nextSamples: Before populating message", 24);
    startTime = CmiWallTimer();


    for(int i=0; i<r; i++){
       sm->newachv_key[i] = newachv[i].first;
       sm->newachv_id[i] = newachv[i].second;
       sm->newachv_count[i] = achievedCounts[newachv[i].second];
    }  


    if(achievedSplitters == nBuckets+1){
      assert(sm->nIntervals == 0);
      //!!! Printing all splitters takes up a lot of time
      ckout<<"Done Histogramming in "<<CmiWallTimer()-c1<<" seconds, numprobes: "<< numProbes << endl;
      //uint64_t cum = 0;
      //for(int i=0; i<=nBuckets; i++){
      //  ckout<<"Splitter "<<i<<": "<<finalSplitters[i]<<" "<<achieved[i]<<" : "<<achievedCounts[i] - cum<<endl;
      //  cum = achievedCounts[i];
      //}
      //CkExit();
    }

/*
    if(numProbes >= 10)
        CkExit();
*/
    traceUserBracketEvent(24, startTime, CmiWallTimer());


    ckout<<"Sending sample intervals to buckets, nIntervals: "<<sm->nIntervals<<" frac: ";
    ckout<<sm->f<<" Not achieved: "<<nBuckets+1-achievedSplitters<<" - "<<CkMyPe()<<endl;
    for(int i=0; i<sm->nIntervals; i++){
      //ckout<<"#"<<i<<"("<<sm->lb[i]<<","<<sm->ub[i]<<")"<<endl;
    }

    for(int i=0; i<=nBuckets; i++){
        //  CkPrintf("[%d] ##%d, rank(%ld, %ld), keys(%lu, %lu), achieved: %d\n", CkMyPe(), i, lb_ranks[i], ub_ranks[i], lb_keys[i], ub_keys[i], achieved[i]);
    }

    if(sm->nIntervals == 0){
      if(achievedSplitters != nBuckets+1){
          for(int i=0; i<sm->nIntervals; i++){
            ckout<<"#"<<i<<"("<<sm->lb[i]<<","<<sm->ub[i]<<")"<<endl;
          }
      }
      assert(achievedSplitters == nBuckets+1);
    }

    buckets.genNextSamples(sm);

   //ckout<<"Sent !!"<<endl;
   delete(msg);
}




template <class key, class value>
void Sorter<key, value>::nextProbes(std::vector<std::pair<key, int> > &newachv, uint64_t* histCounts, CkReductionMsg *msg){
    //double cc1 = CmiWallTimer();
    int s = 1;
    key lastkey = globalmin;
    int scratchInd = 0;
    int unresolved = 0;
    int lastunresolved = -1;
    ckout<<"Next Probes, UnachievedSplitters : "<<nBuckets+1 - achievedSplitters<<" "<<params->probe_max<<endl;

    c2 = CmiWallTimer();
    //CkPrintf("\nCompleted in %lf seconds.\n", (c2-c1));
    //    mainproxy.Exit();
    //    return;

    typename std::map<key, uint64_t>::iterator it, previt; 
    for(it = allPreviousProbes.begin(); it != allPreviousProbes.end() && s<nBuckets; it++){
      uint64_t histCount = it->second;
      //ckout<<s<<" ./././ "<<" : "<< histCount<<" : "<<it->first<<" : "<<achieved[s]<<endl;
      while(checkGoal(s, histCount) > 0){
        //ckout<<s<<" ?>;? "<<unresolved<<" : "<<histCount<<endl;
        if(!achieved[s])
          unresolved++;
        s++;
      }
      int probes = (unresolved * params->probe_max)/(nBuckets + 2 - achievedSplitters);
      key probeStep = (it->first-lastkey)/(probes + 1);
      if(probeStep == 0){
        probeStep = 1;
        probes = it->first - lastkey;
      }
      //!something still needs to be done
      if(probes==1 && probeStep==1){
        for(int i=0; i<unresolved; i++){
          int spltr = s-(1+i);
          achieved[spltr] = true;
          finalSplitters[spltr] = lastkey;
          //do Something here
          //newachv.push_back(std::pair<key, int>(lastkey, spltr));
          ckout<<"Can't do sorting : Too many Duplicates"<<endl;
          CkExit();
        }
        probes = 0;
      }      
      //ckout<<"#Probes for next round "<<probes<<" "<<unresolved<<" "<<s<<" "<<probeStep<<endl;
      //ckout<<" "<<params->probe_max<<" : "<<nBuckets<<" : "<<achievedSplitters<<endl;
      for(int i=0; i<probes; i++)
        scratch[scratchInd++] = lastkey + ((i+1)*probeStep);
      
      lastkey = it->first;
      if(lastunresolved==0 && unresolved==0)
        allPreviousProbes.erase(previt);
      previt = it;
      lastunresolved = unresolved;
      unresolved = 0;
    }
   scratch[scratchInd++] = maxkey;   

   ckout<<"Probes are **************************: "<<scratchInd<< " ::: maxkey ::: " << maxkey << " - "<< CkMyPe() << endl;
   //for(int i=0; i<scratchInd; i++)
   //   ckout<<scratch[i]<<endl;


/*/ To be removed later
    if(nNodes+1 - achievedSplitters > 0){
       CkAbort("Not achieved in the first step \n");
       CkExit();
    }
/*/

   //swap lastProbe and scratch
   key *temp = lastProbe;
   lastProbe = scratch;
   scratch = temp;
   lastProbeSize = scratchInd;
   
   int r = newachv.size();
   probeMessage<key> *pm = new (lastProbeSize, r, r, r) probeMessage<key>;

   pm->probeSize = lastProbeSize;
   pm->num_newachv = r;
   memcpy(pm->probe, lastProbe, lastProbeSize * sizeof(key));
   ckout<<"r is :"<<r<<" lastprobeSize: "<<lastProbeSize<<endl;
   for(int i=0; i<r; i++){
	   pm->newachv_key[i] = newachv[i].first;
     pm->newachv_id[i] = newachv[i].second;
     pm->newachv_count[i] = achievedCounts[newachv[i].second];
   }  

   buckets.histCountProbes(pm);

   if(lastProbeSize==1){
     ckout<<"Done Histogramming in "<<CmiWallTimer()-c1<<" seconds, numprobes: "<< numProbes << endl;
     uint64_t cum = 0;
     for(int i=0; i<=nBuckets; i++){
       ckout<<"Splitter "<<i<<": "<<finalSplitters[i]<<" "<<achieved[i]<<" : "<<achievedCounts[i] - cum<<endl;
       cum = achievedCounts[i];
     }
   }
   
   //ckout<<"Sent !!"<<endl;
   delete(msg);
  //double cc2 = CmiWallTimer();
  //ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr <<"<<endl;
}

//Optionary reduction that informs the Sorter chare that sorting has completed
template <class key, class value>
void Sorter<key, value>::Done(CkReductionMsg *msg){ 
  c2 = CmiWallTimer();
  VERBOSEPRINTF("\nCompleted in %lf seconds.\n", (c2-c1));
  mainproxy.Exit();
}

//A sanity check that insures global sorted order
template <class key, class value>
void Sorter<key, value>::SanityCheck(CkReductionMsg *msg){
  DEBUGPRINTF("Doing global order sanity check.\n");
  key* borderkeys = (key*)msg->getData();
  int lenhist = (int)msg->getSize()/sizeof(key);
  for (int i = 1; i < lenhist; i++){
    CkAssert(borderkeys[i] >= borderkeys[i-1]);
  }
}


#include "HistSort.def.h"
