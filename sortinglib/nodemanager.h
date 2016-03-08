#ifndef __NODEMANAGER_H__
#define __NODEMANAGER_H__




template <class key, class value>
class NodeManager : public CBase_NodeManager<key, value> {
private:
  int numnodes;
  int numpes;
  int* pelist;
  int* numElem;
  int sampleSize;
  CProxy_Sorter<key, value> sorter;
  CProxy_Bucket<key, value> bucket_arr;
  array_msg<key> *sample;
  int samplesRcvd;

public:    
  NodeManager(){
      *(Global<key, value>::nodemgr) = this->thisProxy;
      ckout<<"Node Manager created at "<<CkMyNode()<<endl;
      numnodes = CkNumNodes();
      numpes = CkNodeSize(CkMyNode());
      numElem = new int[numpes];
      pelist = new int[numpes];
  }

  void registerLocalChare(int nElem, int pe, CProxy_Bucket<key, value> _bucket_arr,
                          CProxy_Sorter<key, value> _sorter){
      ckout<<"registerLocalchare called from PE "<<pe<<" at "<<CkMyNode()<<endl;
      ckout<<"numnodes :"<<numnodes<<" numpes:"<<numpes<<endl;
      bucket_arr = _bucket_arr;
      sorter = _sorter;
      static int currnpes = 0;
      pelist[currnpes] = pe;
      numElem[currnpes++] = nElem;
      if(currnpes == numpes){ //all PE's registered
          sampleSize = 2 * numnodes;
          genSampleIndices();
      }
  }

  //call this function
  void genSampleIndices(){
      int *randIndices = new int[sampleSize];
      int cum = numElem[0];
      for(int i=1; i<numpes; i++)
          cum += numElem[i]; 

      typedef std::chrono::high_resolution_clock myclock;
      myclock::time_point beginning = myclock::now();
      myclock::duration d = myclock::now() - beginning;
      unsigned seed = d.count();
      seed = CkMyNode();
      ckout<<"Seed is "<<seed<<endl;

      std::default_random_engine generator(seed);
      std::uniform_int_distribution<int> distribution(0,cum-1);

      distribution(generator);

      for(int i=0; i<sampleSize; i++){
          randIndices[i] = distribution(generator); 
          //ckout<<"randIndices "<<randIndices[i]<<endl;
          distribution.reset();
      }


      sample= new (sampleSize) array_msg<key>;
      sample->numElem = sampleSize;

      std::sort(randIndices, randIndices + sampleSize);
      int cumIndex = 0, cumFreq = 0;
      samplesRcvd = 0;
      for(int i=0; i<numpes; i++){
          int ub = std::upper_bound(randIndices + cumIndex, 
            randIndices + sampleSize, cumFreq + numElem[i]) - randIndices;   
          //send  randIndices[cumIndex, ub) - cumFreq to PE pelist[i]
          array_msg<int> *am = new (ub-cumIndex) array_msg<int>;
          am->numElem = ub-cumIndex;
          for(int i=0; i<am->numElem; i++){
            am->data[i] = randIndices[cumIndex+i] - cumFreq;
          }
          ckout<<"Sending randIndices["<<cumIndex<<","<<ub<<") - ";
          ckout<<cumFreq<<" to PE "<<pelist[i]<<endl;
          bucket_arr[pelist[i]].genSample(am);
          cumIndex = ub;
          cumFreq += numElem[i];
      }
  }

  void collectSamples(array_msg<key> *s){
    static int count = 0;
    memcpy(sample->data + samplesRcvd, s->data, s->numElem * sizeof(key));
    samplesRcvd += s->numElem;
    count++;
    //can enter here twice, check on the basis of number of msgs received
    if(count == numpes){
      //ckout<<"Sending ******************* to Sorter **************from "<<CkMyNode()<<endl;
      //for(int i=0; i<sample->numElem; i++)
      //    ckout<<"From nodemgr "<<CkMyNode()<<" : "<<sample->data[i]<<endl;
      sorter.recvSample(sample);
    }
  }


  void finalProbes(array_msg<key> *s){
    //ckout<<"Recieved final probes from sorter, size "<<s->numElem<<" : "<<CkMyNode()<<endl;
    //for(int i=0; i<s->numElem; i++)
    //    ckout<<"Probe #"<<i<<" : "<<s->data[i]<<"  "<<CkMyNode()<<endl;
    for(int i=0; i<numpes; i++){
        //Send probes to pelist[i]
        //This is totally a waste, find another way to circumvent around this
        //ckout<<"Sending finalprobes to bucket ::::: "<<pelist[i]<<endl;
        array_msg<key>* prb = new(s->numElem) array_msg<key>;
        prb->numElem = s->numElem;
        memcpy(prb->data, s->data, s->numElem * sizeof(key));
        bucket_arr[pelist[i]].finalProbes(prb);
    }
  }

};

#endif
