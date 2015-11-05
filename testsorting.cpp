/**  Example code to demonstrate Interoperability between MPI and Charm sorting.
     Author - Nikhil Jain
     Contact - nikhil@illinois.edu
 */

//standard header files
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
//header files for libraries in Charm I wish to use with MPI
#include "sortinglib/sortinglib.h"
//header file from Charm needed for Interoperation
#include "mpi-interoperate.h"

#define DEBUG(a) 


uint64_t m_w= 110101011;
uint64_t m_z= 1234567891;


uint64_t getRandom(){
  m_z = 36969 * (m_z & 65535) + (m_z >> 16);
  m_w = 18000 * (m_w & 65535) + (m_w >> 16);
  return (m_z << 16) + m_w; 
}

uint64_t getRandom(uint64_t value){
    value *= 1664525;
    value += 1013904223;
    value ^= value >> 12;
    value ^= value << 25;
    value ^= value >> 27;
    value *= 1103515245;
    value += 12345;
    return value;
}



int main(int argc, char **argv){
  int peid, numpes, newid;
  MPI_Comm newComm;

  //basic MPI initilization
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &peid);
  MPI_Comm_size(MPI_COMM_WORLD, &numpes);
  
  if(!peid) printf("Start program on %d pe\n", numpes);
  int num_elems = atoi(argv[1]), out_elems;
  int rand_seed = atoi(argv[2]);

  //create a new comm
  MPI_Comm_split(MPI_COMM_WORLD, 1, peid, &newComm);

  //initialize Charm for one set
  MPI_Comm_rank(newComm, &newid);
  CharmLibInit(newComm, argc, argv);
  MPI_Barrier(MPI_COMM_WORLD);

  //on the set, invoke sorting

  {
    kv_pair<uint64_t, int>* dataIn;
    kv_pair<uint64_t, int>* dataOut;
    //num_elems = num_elems*(1+newid);
    dataIn = new kv_pair<uint64_t, int>[num_elems];
    for (int i = 0; i < num_elems; i++){
      dataIn[i].k  = getRandom() & getRandom() & getRandom() & getRandom((peid + i) & num_elems);
      //dataIn[i].k = (numpes - peid)*1000 + (num_elems - i);
    }
    DEBUG(printf("In elems on %d are %d\n",peid, num_elems);)
    MPI_Barrier(newComm); //for timer
    double startTime = MPI_Wtime();
    HistSorting<uint64_t, int>(num_elems, dataIn, &out_elems, &dataOut);
    MPI_Barrier(newComm); //for timer
    double endTime = MPI_Wtime();
    if(!newid)
      printf("Time taken in first sorting %lf s\n", endTime - startTime);
    DEBUG(printf("Num elems on %d are %d\n",peid, out_elems);)
    /*if(newid == 2) {
      for (int i = 0; i < out_elems; i++){
        printf("%lu\n", dataOut[i].myKey);
      }   
    }
    //*/
    delete[] dataIn;
    //delete[] dataOut;
  }
  /****
  {
    kv_pair<uint64_t, int>* dataIn;
    kv_pair<uint64_t, int>* dataOut;
    //num_elems = num_elems*(newid);
    dataIn = new kv_pair<uint64_t, int>[num_elems];
    for (int i = 0; i < num_elems; i++){
      dataIn[i].k = peid % 20 + 1;
    }
    DEBUG(printf("In elems on %d are %d\n",peid, num_elems);)
    MPI_Barrier(newComm); //for timer
    double startTime = MPI_Wtime();
    HistSorting<uint64_t, int>(num_elems, dataIn, &out_elems, &dataOut);
    MPI_Barrier(newComm); //for timer
    double endTime = MPI_Wtime();
    if(!newid)
      printf("Time taken in second sorting %lf s\n", endTime - startTime);
    DEBUG(printf("Num elems on %d are %d\n",peid, out_elems);)
    /*if(newid == 2) {
      for (int i = 0; i < out_elems; i++){
        printf("%lu\n", dataOut[i].myKey);
      }   
    }*
    delete[] dataIn;
    //delete[] dataOut;
  }
  ***/
  CharmLibExit();
  
  //final synchronization
  MPI_Barrier(MPI_COMM_WORLD);
  if(!peid) printf("Done on %d pe\n", numpes);
  MPI_Finalize();
  return 0;  
}
