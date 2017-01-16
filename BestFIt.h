//
// Created by boaz_bahat on 1/15/17.
//

#ifndef EX2CPP_BESTFIT_H
#define EX2CPP_BESTFIT_H
#define MIN_MEM_SIZE 8
#define POW_BASE 2.0


#include "FitAlgo.h"
#include "TypeDef.h"

class BestFIt : public FitAlgo{
public:
    /**
    *BestFIt constructor
    */
    BestFIt(freeMapMem* freeMap);

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

    /**
     *this function check if you can merge freeNodes on freeMap before allocated
     * @param memSize
     */
    char* canMerge(size_t memSize);

private:

/**
  *this function check if nodes address is by order for merge
  * @param memSize
  * @return  setForMap::iterator
  */
    setForMap::iterator isAddressSequence(setForMap currentIter,size_t numOfNodes,int* isSuccess);
    //static un_mapMem* _allocatedMem;
    freeMapMem* _freeMap;


};


#endif //EX2CPP_BESTFIT_H
