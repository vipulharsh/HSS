/*global*/ CkReduction::reducerType sum_uint64_t_type; 

///reduction for summing arrays of unsigned 64-bit integers
CkReductionMsg *sum_uint64_t(int nMsg,CkReductionMsg **msgs)
{
  ///Sum starts off at zero 
  int size = msgs[0]->getSize()/sizeof(uint64_t);
  uint64_t ret[size];
  memset(ret, 0, sizeof(uint64_t)*size);
  uint64_t *m;
  for (int i=0;i<nMsg;i++) {
    m=(uint64_t *)msgs[i]->getData();
    for (int j = 0; j <size;j ++) 
      ret[j]+=m[j];
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
Sorter<key, value>::Sorter(const CkArrayID &bucketArr, int _nBuckets, key min, key max, 
            tuning_params par, CProxy_Main<key, value> _mainproxy) : 
        mainproxy(_mainproxy), buckets(bucketArr), nBuckets(_nBuckets), minkey(min), maxkey(max){
    VERBOSEPRINTF("Setting up sort. From Constructor\n");
    params = new tuning_params();
    *params = par;
    firstUse = true;
    numProbes = 0;
    ckout<<"CONS Params->probe_max: "<<params->probe_max<<endl;
}


template <class key, class value>
void Sorter<key, value>::globalMinMax(CkReductionMsg *msg){
  key *m = (key *)msg->getData();
  globalmin = m[0];
  globalmax = m[1];
  Begin();
}



template<class key, class value>
void Sorter<key, value>::Begin(){

    c1 = CmiWallTimer();

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
    }

    if(firstUse || !params->reuse_probe_results){
        lastProbeSize = nBuckets; //to be tuned     
        key firstkey = globalmin;
        key lastkey = globalmax+1;
        buckets.firstProbe(firstkey, lastkey, lastProbeSize);
        key step = (lastkey - firstkey + lastProbeSize-1)/lastProbeSize; 
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
    finalSplitters[0] = minkey;    
    finalSplitters[nBuckets] = maxkey;
    achievedSplitters = 2;
    allPreviousProbes.clear();
    //allPreviousProbes[minkey] = 0;
    ckout<<"Exiting Sorter Constructor... "<<params->probe_max<<endl;

}





template <class key, class value>
inline int Sorter<key, value>::checkGoal(int splitterInd, uint64_t histCount){
    uint64_t goal = (nElements * splitterInd)/nBuckets;
    uint64_t margin = (nElements * 5)/(100 * nBuckets); //5%
    return (histCount < goal-margin ? -1 : (histCount > goal+margin ? 1 : 0));
}



template <class key, class value>
void Sorter<key, value>::Histogram(CkReductionMsg *msg){
    VERBOSEPRINTF("Doing Histogramming %lf seconds after start.\n", (CmiWallTimer()-c1));   
    double cc1 = CmiWallTimer();
    numProbes++;    
    //ckout<<"Probe Number : ######### : "<<numProbes<<" "<<params->probe_max<<" : "<<nElements<<endl;
    uint64_t* histCounts = (uint64_t*)msg->getData();
    int lenhist = (int)msg->getSize()/sizeof(uint64_t);   
    
    //store cumulative counts
    for(int i=1; i<lenhist; i++){
		  histCounts[i] += histCounts[i-1];
    }
  
    
    for(int i=0; i<lastProbeSize; i++){
      allPreviousProbes[lastProbe[i]] = histCounts[i];
      //ckout<<lastProbe[i]<<" :-: "<<histCounts[i]<<endl;
    }

    CkAssert(lenhist == lastProbeSize);
    
    if(numProbes <= 1)
        nElements = histCounts[lastProbeSize-1];

    int p = 0; //currProbe
    int s = 1; //currSplitter
    std::vector<std::pair<key, int> > newachv; //splitters that were achieved in this round
    while(s < nBuckets){
        //ckout<<s<<" : "<<p<<" : "<<histCounts[p]<<endl;
        if(!achieved[s]){
          //relative position of  histCounts[currProbe] w.r.t. currSplitter 
          while(checkGoal(s, histCounts[p]) < 0)
              p++;
          if(checkGoal(s, histCounts[p]) == 0){ //achieved
              achievedSplitters++;
              finalSplitters[s] = lastProbe[p];
              achieved[s] = true;
              newachv.push_back(std::pair<key, int>(lastProbe[p], s));
          }
        }
        s++;                        
    }    
    //double cc2 = CmiWallTimer();
    //ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr0 <<"<<endl;
    nextProbes(newachv, histCounts, msg);
    double cc2 = CmiWallTimer();
    ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr0 "<<" : "<<allPreviousProbes.size()<<endl;
    
   //delete msg
}



template <class key, class value>
void Sorter<key, value>::nextProbes(std::vector<std::pair<key, int> > &newachv, uint64_t* histCounts, CkReductionMsg *msg){
    //double cc1 = CmiWallTimer();
    int s = 1;
    key lastkey = globalmin;
    int scratchInd = 0;
    int unresolved = 0;
    int lastunresolved = -1;
    //ckout<<"Next Probes, UnachievedSplitters : "<<nBuckets+1 - achievedSplitters<<" "<<params->probe_max<<endl;
    
    typename std::map<key, uint64_t>::iterator it, previt; 
    for(it = allPreviousProbes.begin(); it != allPreviousProbes.end() && s<nBuckets; it++){
      uint64_t histCount = it->second;
      //ckout<<s<<" ./././ "<<" : "<< histCount<<" : "<<it->first<<" : "<<achieved[s]<<endl;
      while(checkGoal(s, histCount) > 0){
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
   scratch[scratchInd++] = globalmax + 1;   
   //ckout<<"Probes are **************************: "<<scratchInd<<endl;
   //for(int i=0; i<scratchInd; i++)
   //   ckout<<scratch[i]<<endl;

   //swap lastProbe and scratch
   key *temp = lastProbe;
   lastProbe = scratch;
   scratch = temp;
   lastProbeSize = scratchInd;
   
   int r = newachv.size();
   probeMessage<key> *pm = new (lastProbeSize, r, r) probeMessage<key>;
   pm->probeSize = lastProbeSize;
   pm->num_newachv = r;
   memcpy(pm->probe, lastProbe, lastProbeSize * sizeof(key));
   //ckout<<"r is :"<<r<<" lastprobeSize: "<<lastProbeSize<<endl;
   for(int i=0; i<r; i++){
	   pm->newachv_key[i] = newachv[i].first;
     pm->newachv_id[i] = newachv[i].second;
   }  

//   if(numProbes <= 15)
    buckets.histCountProbes(pm);

   if(lastProbeSize==1)
     for(int i=0; i<=nBuckets; i++)
       ckout<<"Splitter "<<i<<": "<<finalSplitters[i]<<" "<<achieved[i]<<endl;
   
   //ckout<<"Sent !!"<<endl;
   delete(msg);

  //double cc2 = CmiWallTimer();
  //ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr <<"<<endl;
}



//Optionary reduction that informs the Sorter chare that sorting has completed
template <class key, class value>
void Sorter<key, value>::Done(CkReductionMsg *msg){ 
  c2 = CmiWallTimer();
  printf("\nCompleted in %lf seconds.\n", (c2-c1));
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
