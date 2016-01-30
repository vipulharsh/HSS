#ifndef __DEFS_H__
#define __DEFS_H__

#include "pup.h"

//prints a lot of information, will generate large logs, will also perform sanity checks on data
#define DEBUG 0

#ifdef DEBUG
#define DEBUGPRINTF(format, ...) CkPrintf(format, ## __VA_ARGS__)
#else
#define DEBUGPRINTF(format, ...) //do not print anything
#endif

//prints basic executing information
#define VERBOSE 0

#ifdef VERBOSE
#define VERBOSEPRINTF(format, ...) CkPrintf(format, ## __VA_ARGS__)
#else
#define VERBOSEPRINTF(format, ...) //do not print anything
#endif

//this is before the includes in order to correct dependencies (might be better to put in separate file)
///efficiency parameters, which can potentially be tuned to improve performance
class tuning_params{
  public:
    ///maximum total number of splitter guesses
    int probe_size;
    ///maximum number of splter guesses in one range
    int probe_max;
    ///the threshold for the max deviation from the average in the number of elements any target will receive
    int hist_thresh;
    ///The minimum number of elements for which an array will be spliced. If the number of elements in array is smaller, it will be sorted instead.
    int splice_thresh;
    ///number of processors to send message to target immediately
    int eager_send;
    ///whether to reuse the old converged probe when another iteration of sortin is needed on the same section
    bool reuse_probe_results;

    void pup(PUP::er &p) {
      p | probe_size; 
      p | probe_max;
      p | hist_thresh;
      p | splice_thresh;
      p | eager_send;
      p | reuse_probe_results;
    }

};


#endif
