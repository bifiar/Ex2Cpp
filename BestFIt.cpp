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
        return canMerge(memSizeBit);
    } else {
        FreeNode* memFromFreeList=(*((iter->second).begin()));
        char* mmAdd=memFromFreeList->getMemAdd();
        (iter->second).erase(memFromFreeList);
        return mmAdd;
    }
}

/**
 *
 * @param memSize
 * @return
 */
char* BestFIt::canMerge(size_t memSize){
    char* addressToAlloc= nullptr;
    auto currentIter=_freeMap->begin();
    if(_freeMap->size()==0){
        return nullptr;
    }
    while(currentIter != _freeMap->end() && currentIter->first< memSize){
        size_t numOfNodes=memSize/(currentIter->first);
        int isSuccess=0;
        setForMap::iterator iterToAllocAddress=isAddressSequence(currentIter->second, numOfNodes,&isSuccess);
        setForMap::iterator tempTest=currentIter->second.end();
        if(isSuccess) {
            addressToAlloc=(*iterToAllocAddress)->getMemAdd();
            for(int i=0;i<numOfNodes;i++) {
                FreeNode* toDel=*iterToAllocAddress;
                currentIter->second.erase(toDel);
                iterToAllocAddress++;
            }
            break;
        }
        currentIter++;
    }
    return addressToAlloc;
}

setForMap::iterator BestFIt::isAddressSequence(setForMap currentSet, size_t numOfNodes,int* isSuccess) {
    size_t sizeLeft=currentSet.size();
    if(sizeLeft==0) {return currentSet.end();}
    size_t currentSuccess=1;
    auto currentSetIter = currentSet.begin();
    size_t memSize=(*currentSetIter)->getMemSize();
    long address = (long)(*currentSetIter)->getMemAdd();
    while (sizeLeft >= numOfNodes && currentSuccess < numOfNodes) {
        address += memSize;
        long currentAddress=(long) (*(++currentSetIter))->getMemAdd();
        if (address == currentAddress) {
            currentSuccess++;
        } else {
            sizeLeft -= currentSuccess;
            currentSuccess = 1;
            address = currentAddress;
        }
    }
    if (currentSuccess == numOfNodes) {
        for (int i = 0; i <numOfNodes-1 ; ++i) {
            currentSetIter--;
        }
        *isSuccess=1;
        return currentSetIter;
    }
    return currentSet.end();
