//
// Created by avishay on 1/15/17.
//

#ifndef EX2CPP_BESTFIT_H
#define EX2CPP_BESTFIT_H
#define MIN_MEM_SIZE 8
#define POW_BASE 2.0


#include "FitAlgo.h"
#include "sharedTypeDeffs.h"

class BestFIt : public FitAlgo{
public:
    BestFIt(freeMapMem* freeMap);

    char *searchFreeMemAlgo(size_t memSizeBit) override;


    freeMapMem *get_freeMap();
    /**
     *
     * @param _freeMap
     */
    void set_freeMap(freeMapMem *_freeMap);

    char* canMerge(size_t memSize);

private:
    //static un_mapMem* _allocatedMem;
    freeMapMem* _freeMap;


};


#endif //EX2CPP_BESTFIT_H
