//
// Created by avishay on 1/15/17.
//

#ifndef EX2CPP_FIRSTFIT_H
#define EX2CPP_FIRSTFIT_H


#include "FitAlgo.h"
#include "sharedTypeDeffs.h"

class FirstFit : public FitAlgo {
public:
    FirstFit(freeMapMem* freeMap);

    char *searchFreeMemAlgo(size_t memSizeBit) override;


    freeMapMem *get_freeMap();
    /**
     *
     * @param _freeMap
     */
    void set_freeMap(freeMapMem *_freeMap);

private:
    //static un_mapMem* _allocatedMem;
    freeMapMem* _freeMap;


};

#endif //EX2CPP_FIRSTFIT_H
