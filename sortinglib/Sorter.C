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


template<class key, class value>
Sorter<key, value>::Sorter(CkMigrateMessage *msg){}


template<class key, class value>
Sorter<key, value>::Sorter(const CkArrayID &bucketArr, int _nBuckets, key min, key max, tuning_params par) : 
                 buckets(bucketArr), nBuckets(_nBuckets), minkey(min), maxkey(max){
    VERBOSEPRINTF("Setting up sort. From Constructor\n");
    params = new tuning_params();
    *params = par;
    firstUse = true;
    numProbes = 0;
    ckout<<"CONS Params->probe_max: "<<params->probe_max<<endl;
    ckout<<"CONS Params->probe_max: "<<params->temp_probe_max<<endl;
}



template<class key, class value>
void Sorter<key, value>::Begin(){

    c1 = CmiWallTimer();

    ckout<<"Sorter Constructor : "<<endl; 
    ckout<<"Params->probe_max: "<<params->probe_max<<endl;
    ckout<<"Params->probe_max: "<<params->temp_probe_max<<endl;
    ckout<<"nBuckets: "<<nBuckets<<endl;;
    ckout<<"minkey: "<<minkey<<", maxkey: "<<maxkey<<endl;
    
    if(firstUse){
        lastProbe = new key[params->temp_probe_max+1];
        scratch = new key[params->temp_probe_max+1];
        finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
        achieved = new bool[nBuckets+2];
    }

    if(firstUse || !params->reuse_probe_results){
        lastProbeSize = nBuckets; //to be tuned     
        buckets.firstProbe(this->thisProxy, minkey, maxkey, lastProbeSize);
        key step = (maxkey - minkey + lastProbeSize-1)/lastProbeSize; 
        for(int i=0; i<lastProbeSize; i++)
            lastProbe[i] = minkey + ((i+1) * step);
        lastProbe[lastProbeSize-1] = maxkey;
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
    ckout<<"Exiting Sorter Constructor... "<<params->temp_probe_max<<endl;

}





template <class key, class value>
inline int Sorter<key, value>::checkGoal(int splitterInd, int histCount){
    int goal = (nElements * splitterInd)/nBuckets;
    int margin = (nElements * 5)/(100 * nBuckets); //5%
    return (histCount < goal-margin ? -1 : (histCount > goal+margin ? 1 : 0));
}



template <class key, class value>
void Sorter<key, value>::Histogram(CkReductionMsg *msg){
    VERBOSEPRINTF("Doing Histogramming %lf seconds after start.\n", (CmiWallTimer()-c1));   
    ckout<<"Histogramming started"<<endl;
    numProbes++;
    
    ckout<<"Probe Number : ######### : "<<numProbes<<" "<<params->temp_probe_max<<" : "<<nElements<<endl;
    //uint64_t* histCounts = (uint64_t*)msg->getData();
    //int lenhist = (int)msg->getSize()/sizeof(uint64_t);   
    int* histCounts = (int*)msg->getData();        
    int lenhist = (int)msg->getSize()/sizeof(int);
   
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
    
    nextProbes(newachv, histCounts, msg);
   //delete msg
}



template <class key, class value>
//void Sorter<key, value>::nextProbes(std::vector<std::pair<key, int> > &newachv, uint64_t* histCounts){
void Sorter<key, value>::nextProbes(std::vector<std::pair<key, int> > &newachv, int* histCounts, CkReductionMsg *msg){
    int s = 1;
    key lastkey = minkey;
    int scratchInd = 0;
    int unresolved = 0;
    
    //ckout<<"Next Probes, UnachievedSplitters : "<<nBuckets+1 - achievedSplitters<<" "<<params->temp_probe_max<<endl;

    typename std::map<key, uint64_t>::iterator it; 
    for(it = allPreviousProbes.begin(); it != allPreviousProbes.end() && s<nBuckets; it++){
      uint64_t histCount = it->second;
      //ckout<<s<<" ./././ "<<" : "<< histCount<<" : "<<it->first<<" : "<<achieved[s]<<endl;
      while(checkGoal(s, histCount) > 0){
        if(!achieved[s]){
          unresolved++;
        }
        s++;
      }
      int probes = (unresolved * params->temp_probe_max)/(nBuckets + 2 - achievedSplitters);
      key probeStep = (it->first-lastkey)/(probes + 1);
      //ckout<<"#Probes for next round "<<probes<<" "<<unresolved<<" "<<s;
      //ckout<<" "<<params->temp_probe_max<<" : "<<nBuckets<<" : "<<achievedSplitters<<endl;
      for(int i=0; i<probes; i++){
        scratch[scratchInd++] = lastkey + ((i+1)*probeStep);
      }
      lastkey = it->first;
      unresolved = 0;
    }

   scratch[scratchInd++] = maxkey;   
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
   buckets.histCountProbes(pm);
   if(lastProbeSize==1)
    for(int i=0; i<=nBuckets; i++)
     ckout<<"Splitter "<<i<<": "<<finalSplitters[i]<<endl;
   ckout<<"Sent !!"<<endl;

   delete(msg);
}



//Optionary reduction that informs the Sorter chare that sorting has completed
template <class key, class value>
void Sorter<key, value>::Done(CkReductionMsg *msg){
  c2 = CmiWallTimer();
  VERBOSEPRINTF("\nCompleted in %lf seconds.\n", (c2-c1));
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
