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
                 buckets(bucketArr), nBuckets(_nBuckets), minKey(min), maxKey(max){
    VERBOSEPRINTF("Setting up sort. From Constructor\n");
    params = new tuning_params();
    *params = par;
    firstUse = true;
    numProbes = 0;
}



template<class key, class value>
void Sorter<key, value>::Begin(){

    c1 = CmiWallTimer();

    ckout<<"comes here 1"<<endl;

    ckout<<params->probe_max<<" "<<nBuckets<<" "<<minKey<<" "<<maxKey<<endl;


    if(firstUse){
        lastProbe = new key[params->probe_max+1];
        scratch = new key[params->probe_max+1];
        finalSplitters = new key[nBuckets+2]; //required size is nBuckets+2
        achieved = new bool[nBuckets+2];
    }

    ckout<<"comes here 2"<<endl;


    if(firstUse || !params->reuse_probe_results){
        lastProbeSize = nBuckets; //to be tuned     
        buckets.firstProbe(this->thisProxy, minKey, maxKey, lastProbeSize);
        key step = (maxKey - minKey)/lastProbeSize;
        for(int i=0, s=step; i<lastProbeSize; i++, s+=step)
            lastProbe[i] = minKey + s;
        lastProbe[lastProbeSize-1] = maxKey;
    }
    else{
        lastProbeSize = nBuckets;    
        buckets.firstLocalProbe(lastProbeSize);
        memcpy(lastProbe, finalSplitters, nBuckets * sizeof(key));
    }

    ckout<<"comes here 3"<<endl;


    firstUse = false;
    
    //Don't use memset for non-inbuilt types

    memset(achieved+1, false, nBuckets);
    achieved[0] = achieved[nBuckets] = true;
    finalSplitters[0] = minKey;    
    finalSplitters[nBuckets] = maxKey;
    achievedSplitters = 2;
    ckout<<"comes here 4"<<endl;

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
    ckout<<lastProbeSize<<" ? "<<msg->getSize()<<endl;
    
    numProbes++;
    //uint64_t* histCounts = (uint64_t*)msg->getData();
    //int lenhist = (int)msg->getSize()/sizeof(uint64_t);
    
    int* histCounts = (int*)msg->getData();        
    int lenhist = (int)msg->getSize()/sizeof(int);
    
    ckout<<lenhist<<" = "<<lastProbeSize<<" ? "<<msg->getSize()<<endl;
    
    //store cumulative counts
    for(int i=1; i<lenhist; i++)
		  histCounts[i] += histCounts[i-1]; 
    
    CkAssert(lenhist == lastProbeSize);
    
    if(numProbes <= 1)
        nElements = histCounts[lastProbeSize-1];

    int p = 0; //currProbe
    int s = 1; //currSplitter
    std::vector<std::pair<key, int> > newachv; //splitters that were achieved in this round
    while(s < nBuckets){
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
    ckout<<"2"<<endl;
    nextProbes(newachv, histCounts);
   //delete msg
}



template <class key, class value>
//void Sorter<key, value>::nextProbes(std::vector<std::pair<key, int> > &newachv, uint64_t* histCounts){
void Sorter<key, value>::nextProbes(std::vector<std::pair<key, int> > &newachv, int* histCounts){
    int p = 0;
    int s = 1;
    key last = 0;
    int unresolved = 0;
    int scratchInd = 0;
    while(p < lastProbeSize && s<nBuckets){
                
        if(!achieved[s] && checkGoal(s, histCounts[p]) > 0){
            s++;
            unresolved++;
            continue;           
        }
                
        key next =  lastProbe[p];
        p++;         
        if(achieved[s] && (finalSplitters[s] < lastProbe[p])){
            next = finalSplitters[s];
            s++;
		    }		             
        
        //what if every splitter has been achieved : ensure works correctly
        int probes = (unresolved * params->probe_max)/(nBuckets + 2 - achievedSplitters);
        for(int i=0; i<probes; i++)
            scratch[scratchInd++] = last + (next-last)/(probes + 1);
        
        last = next;        
        unresolved = 0;   
   }
   scratch[scratchInd++] = maxKey;
   
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
   for(int i=0; i<r; i++){
	   pm->newachv_key[i] = newachv[i].first;
     pm->newachv_id[i] = newachv[i].second;
   }
   buckets.histCountProbes(pm);
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
