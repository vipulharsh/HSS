#ifndef __BUCKET_H__
#define __BUCKET_H__


template <class key, class value>
class Bucket : public CBase_Bucket<key, value> {
  private:
    
};

//need to include .C file in order to have it instantiated when the .h file is included externally
//such instantiation is necessary here since the compiler generates templated code on demand
#include "Bucket.C"
#endif
