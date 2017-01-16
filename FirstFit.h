//
// Created by avishay on 1/15/17.
//

#ifndef EX2CPP_FIRSTFIT_H
#define EX2CPP_FIRSTFIT_H


#include "FitAlgo.h"
#include "TypeDef.h"

class FirstFit : public FitAlgo {
public:
    /**
    *FirstFit constructor
    */
    FirstFit(freeMapMem* freeMap);

    /**
    *implement function from fitAlgo that check if there is free memory on freeMap
     * * @return memSizeBit
    * @return address
    */
    char *searchFreeMemAlgo(size_t memSizeBit) override;

     /**
     *get freeMap list
     * @return _freeMap
     */

    freeMapMem *get_freeMap();

    /**
     *set freeMap in _freeMap
     * @param _freeMap
     */
    void set_freeMap(freeMapMem *_freeMap);

private:
    //static un_mapMem* _allocatedMem;
    freeMapMem* _freeMap;


};

#endif //EX2CPP_FIRSTFIT_H
