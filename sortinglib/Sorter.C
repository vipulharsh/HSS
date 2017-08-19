#include <assert.h>
#include <iostream>
/*global*/ CkReduction::reducerType sum_uint64_t_type; 

//epsilon  = 10% imbalance
#define EPS 5


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





template<class key>
Sorter<key>::Sorter(CkMigrateMessage *msg){}


template<class key>
Sorter<key>::Sorter(const CkArrayID &bucketArr, int _nBuckets, key min,
            key max, tuning_params par, CProxy_Main<key> _mainproxy, CkNodeGroupID _nodeMgrID) : 
        mainproxy(_mainproxy), buckets(bucketArr), nBuckets(_nBuckets),  nodeMgrID(_nodeMgrID),
        minkey(min), maxkey(max){
    //VERBOSEPRINTF("Setting up sort. From Constructor\n");
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




template<class key>
void Sorter<key>::finishBarrier(CkReductionMsg *msg)
{    c1 = CmiWallTimer();
     CkPrintf("$$$$$$$$$ [%d/%d]finishBarrier \n", CkMyPe(), CkMyNode()); 
     buckets.SetData();
}



/*
template <class key>
void Sorter<key>::globalMinMax(CkReductionMsg *msg){
  key *m = (key *)msg->getData();
  globalmin = m[0];
  globalmax = m[1];
  ckout<<"In Sorter global Min Max "<<m[0]<<" "<<m[1]<<endl;
  Begin();
}
*/


extern int maxSampleSize();
extern const int SAMPLE_FACTOR_MULTIPLIER;


template<class key>
void Sorter<key>::Init(){
	      int maxprobe = std::max(params->probe_max, 2*maxSampleSize());
        ckout<<"maxprobe: "<<maxprobe<<endl;
        lastProbe = new tagged_key<key>[maxprobe+1];
        finalSplitters = new tagged_key<key>[nBuckets+2]; //required size is nBuckets+2
        achieved = new bool[nBuckets+2];
        achievedCounts = new uint64_t[nBuckets+2];
        firstUse = false;

        lb_keys = new tagged_key<key>[nBuckets+2];
        ub_keys = new tagged_key<key>[nBuckets+2];
        lb_ranks = new uint64_t[nBuckets+2];
        ub_ranks = new uint64_t[nBuckets+2];
        
        
        //Don't use memset for non-inbuilt types
        memset(achieved+1, false, nBuckets);
        achieved[0] = achieved[nBuckets] = true;
        achievedCounts[0] = 0;
        finalSplitters[0] = getTaggedMinKey<key>(minkey);    
        finalSplitters[nBuckets] = getTaggedMaxKey<key>(maxkey);
        achievedSplitters = 2;
        ckout<<"Exiting Sorter Init... "<<nBuckets<<endl;
}


template<class key>
void Sorter<key>::recvSample(array_msg<key>* am){
  static int msgReceived = 0;

  //ckout<<"Received msg number "<<msgReceived<<" at "<<CkMyNode()<<endl;
  //ckout<<"Elts. recved "<<am->numElem<<endl;
  //for(int i=0; i<am->numElem; i++)
  //    ckout<<am->data[i]<<endl;
  collectedSample.insert(collectedSample.end(), am->data, am->data + am->numElem);  
  msgReceived++;
  delete(am); 
  if(msgReceived == CkNumNodes()){
    CkPrintf("Comes till here \n" );
    //CkExit();
    std::sort(collectedSample.begin(), collectedSample.end());

    int histSampleSize = 1 + collectedSample.size()/SAMPLE_FACTOR_MULTIPLIER;

    array_msg<key> *finalProbe = new (histSampleSize) array_msg<key>;
    finalProbe->numElem = histSampleSize;
    lastProbe = new tagged_key<key>[finalProbe->numElem];
  
    for(int i=0; i<histSampleSize-1;  i++)
      finalProbe->data[i] =  collectedSample[SAMPLE_FACTOR_MULTIPLIER*(i+1) - 1];
    //memcpy(finalProbe->data, &collectedSample[0], collectedSample.size() * sizeof(key));

    std::cout<<" maxkey: "<<maxkey<<", tagged maxkey: "<<getTaggedMaxKey<key>(maxkey)<<std::endl;
    finalProbe->data[finalProbe->numElem-1] = getTaggedMaxKey<key>(maxkey);
    memcpy(lastProbe, finalProbe->data, finalProbe->numElem * sizeof(tagged_key<key>));
    lastProbeSize = finalProbe->numElem;


    CkPrintf("******** [%d] Samples size: %d collected, sending for histogramming... %lf .\n", CkMyPe(), finalProbe->numElem, (CmiWallTimer()-c1));   
    //ckout<<"Initiating Probe from sorter: "<<probeSize<<endl;
    //for(int i=0; i<lastProbeSize; i++)
    //	 ckout<<"Sample #"<<i<<" : "<<lastProbe[i]<<endl;

    buckets.finalProbes(finalProbe);

    collectedSample.clear();
    msgReceived = 0;
    //CProxy_NodeManager<key> nodemgr = CProxy_NodeManager<key>(nodeMgrID);   
    //nodemgr.finalProbes(finalProbe);
    //(Global<key>::nodemgr)->finalProbes(finalProbe);   
  }
}




template <class key>
inline int Sorter<key>::checkGoal(int splitterInd, uint64_t histCount){
    uint64_t goal = (nElements * splitterInd)/nBuckets;
    uint64_t margin = (nElements * EPS)/(100 * nBuckets); //5%
    //ckout<<nElements<<" : "<<splitterInd<<" : "<<nBuckets<<" : "<<histCount<<endl;
    //ckout<<goal<<" : "<<margin<<" : "<<goal-margin<<" : "<<goal + margin<<endl;
    return (histCount < goal-margin ? -1 : (histCount > goal+margin ? 1 : 0));
}



template <class key>
void Sorter<key>::Histogram(CkReductionMsg *msg){
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

    std::vector<std::pair<tagged_key<key>, int> > newachv; //splitters that were achieved in this round
    if(numProbes <= 1){
      nElements = histCounts[lastProbeSize-1];
      achievedCounts[nBuckets] = nElements; 
      newachv.push_back(std::pair<tagged_key<key>, int>(getTaggedMaxKey<key>(maxkey), nBuckets));
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
              newachv.push_back(std::pair<tagged_key<key>, int>(lastProbe[p], s));
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
    ckout<<cc2-cc1<<" : "<< numProbes<<"  - srtr0 "<<endl;
    traceUserBracketEvent(3, startTime, CmiWallTimer());
   //delete msg
}


template <class key>
void Sorter<key>::updateBounds(CkReductionMsg *msg){
    if(numProbes <= 1){
      ckout<<"***************************************####################comes here"<<endl;
      for(int i=0; i<nBuckets; i++){
        ub_ranks[i] = nElements;
        lb_ranks[i] = 0;
        ub_keys[i] = getTaggedMaxKey<key>(maxkey);
        lb_keys[i] = getTaggedMinKey<key>(minkey);
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


template <class key>
void Sorter<key>::nextSamples(std::vector<std::pair<tagged_key<key>, int> > &newachv, uint64_t* histCounts, CkReductionMsg *msg){
    
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
            std::cout<<"#"<<i<<"("<<sm->lb[i]<<","<<sm->ub[i]<<")"<<std::endl;
          }
      }
      assert(achievedSplitters == nBuckets+1);
    }

    buckets.genNextSamples(sm);

   //ckout<<"Sent !!"<<endl;
   delete(msg);
}


//Optionary reduction that informs the Sorter chare that sorting has completed
template <class key>
void Sorter<key>::Done(CkReductionMsg *msg){ 
  c2 = CmiWallTimer();
  CkPrintf("\nCompleted in %lf seconds.\n", (c2-c1));
  CkPrintf("Elements sorted: %d (= %d MB)\n", nElements,  (nElements * sizeof(key))/(1024 * 1024));
  mainproxy.Exit();
}

//A sanity check that insures global sorted order
template <class key>
void Sorter<key>::SanityCheck(CkReductionMsg *msg){
  DEBUGPRINTF("Doing global order sanity check.\n");
  key* borderkeys = (key*)msg->getData();
  int lenhist = (int)msg->getSize()/sizeof(key);
  for (int i = 1; i < lenhist; i++){
    CkAssert(borderkeys[i] >= borderkeys[i-1]);
  }
}


#include "HistSort.def.h"
