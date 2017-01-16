//
// Created by avishay on 1/15/17.
//

#include "FirstFit.h"


FirstFit::FirstFit(freeMapMem* freeMap):_freeMap(freeMap) {}

/**
 *
 * @return
 */
freeMapMem *FirstFit::get_freeMap() {
    return _freeMap;
}

/**
 *
 * @param _freeMap
 */
void FirstFit::set_freeMap(freeMapMem *_freeMap) {
    FirstFit::_freeMap = _freeMap;
}
/**
 *
 * @param memSizeBit
 * @return
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
