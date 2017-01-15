//
// Created by avishay on 1/15/17.
//

#include <cmath>
#include "BestFIt.h"

BestFIt::BestFIt(freeMapMem* freeMap):_freeMap(freeMap) {}

/**
 *
 * @return
 */
freeMapMem *BestFIt::get_freeMap() {
    return _freeMap;
}

/**
 *
 * @param _freeMap
 */
void BestFIt::set_freeMap(freeMapMem *_freeMap) {
    BestFIt::_freeMap = _freeMap;
}
/**
 *
 * @param memSizeBit
 * @return
 */
char *BestFIt::searchFreeMemAlgo(size_t memSizeBit) {
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
