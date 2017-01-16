//
// Created by avishay on 1/15/17.
//

#ifndef EX2CPP_FITALGO_H
#define EX2CPP_FITALGO_H


#include <glob.h>

class FitAlgo {

public:

    /**
    *this function is to check if there is free memory on freeMap, and  which algorithm  to use
     * @return memSizeBit
    * @return address
    */
    virtual char* searchFreeMemAlgo(size_t memSizeBit)=0;
};


#endif //EX2CPP_FITALGO_H
