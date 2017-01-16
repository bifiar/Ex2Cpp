//
// Created by avishay on 1/15/17.
//

#include "FirstFit.h"

/**
    *FirstFit constructor
    */
FirstFit::FirstFit(freeMapMem* freeMap):_freeMap(freeMap) {}

/**
    *get freeMap list
    * @return _freeMap
    */

freeMapMem *FirstFit::get_freeMap() {
    return _freeMap;
}

/**
    *set freeMap in _freeMap
    * @param _freeMap
    */
void FirstFit::set_freeMap(freeMapMem *_freeMap) {
    FirstFit::_freeMap = _freeMap;
}

/**
    *implement function from fitAlgo that check if there is free memory on freeMap
     * * @return memSizeBit
    * @return address
    */
char *FirstFit::searchFreeMemAlgo(size_t memSizeBit) {
    auto iter=_freeMap->find(memSizeBit);
    if ( iter ==_freeMap->end() ) {
        // not found
        return nullptr;
    } else {
        FreeNode* memFromFreeList=(*((iter->second).begin()));
        char* mmAdd=memFromFreeList->getMemAdd();
        (iter->second).erase(memFromFreeList);
        return mmAdd;
    }
}
