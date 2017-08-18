//standard header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "testsorting.decl.h"

//header files for libraries in Charm
#include "sortinglib/sortinglib.h"

#define DEBUG(a) //a

uint64_t m_w= 110101011;
uint64_t m_z= 1234567891;

unsigned int seed;

uint64_t getRandom(){
    if (sizeof(int) < sizeof(long))
        return (static_cast<long>(rand_r(&seed)) << (sizeof(int) * 8)) |
               rand_r(&seed);
    return rand_r(&seed);
}


/*
uint64_t getRandom(){
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w; 
}
*/

/*
uint64_t getRandom(uint64_t value){
    value *= 1664525;
    value += 1013904223;
    value ^= value >> 12;
    value ^= value << 25;
    value ^= value >> 27;
    value *= 1103515245;
    value += 12345;
    return value ^ getRandom();
}
*/

class testsorting : public CBase_testsorting{
  public:
    testsorting(CkArgMsg *m){
        srand (time(NULL));
        int num_elems = atoi(m->argv[1]);
        int rand_seed = atoi(m->argv[2]);
        int probe_max = -1;
        if(m->argc > 2)
            probe_max = atoi(m->argv[3]);
 
  	//Create this Node Mgr
        //*(Global<key, value>::nodemgr) = CProxy_NodeManager<key, value>::ckNew();
        //Call dataManager
        CProxy_dataManager dMProxy = CProxy_dataManager::ckNew(CkNumPes() ,num_elems, probe_max);
    }
};




//Box-Muller method
uint64_t getGaussianRandom(){
  double e=2.7182818284590452;
  double log_e=log(e);
  uint64_t mean = ((uint64_t)1)<<(sizeof(uint64_t) * 4);
  uint64_t std_dev = ((uint64_t)1)<<(sizeof(uint64_t) * 2);
  return mean + (sqrt(-2*log(rand_r(&seed)*1.0/RAND_MAX)/log_e)
                 * cos(rand_r(&seed)*2*M_PI/RAND_MAX)
                 * (double)std_dev);
}


class dataManager : public CBase_dataManager{
  private:
      uint64_t* dataIn;
      uint64_t* dataOut;
      int out_elems;
      CkCallback CB;
      double startTime, endTime;
  public:
    dataManager(int numBuckets, int numElem, int probe_max){
        //num_elems = num_elems*(1+newid);
        dataIn = new uint64_t[numElem];
        int peid = CkMyPe();
        seed = CkMyPe();
        for (int i = 0; i < numElem; i++){
            //dataIn[i]  = getRandom();
            dataIn[i]  = getGaussianRandom();
            //dataIn[i]  = getRandom() & getRandom();
            //dataIn[i].k  = getRandom() & getRandom((peid + i) ^ numElem);
            //ckout<<"dataIn["<<i<<"]: "<<dataIn[i].k<<"  ::  "<<peid<<endl;
            //dataIn[i].k = (numpes - peid)*1000 + (numElem - i);
            //dataIn[i].k = peid;
            //dataIn[i].k = 3;
        }
        DEBUG(printf("In elems on %d are %d\n",peid, numElem);)
        int entryMethodIndex = CkIndex_dataManager::SortingDone(); 
        CB = CkCallback(entryMethodIndex, thisProxy[CkMyPe()]);
        startTime = CmiWallTimer();
        HistSorting<uint64_t>(numElem, dataIn, &out_elems, &dataOut, probe_max, &CB);
    }

    void SortingDone(){
        delete[] dataIn;
        delete[] dataOut;
        endTime = CmiWallTimer();
        if(!CkMyPe()){
          printf("Time taken in first sorting %lf s\n", endTime - startTime);
  	  CkExit();
	}
    }
};




#include "testsorting.def.h"
