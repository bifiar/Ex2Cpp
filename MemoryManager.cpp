//
// Created by ofir on 1/3/17.
//

#include <cmath>
#include <cstring>
#include "MemoryManager.h"
#include "MemPool.h"


MemoryManager::MemoryManager(size_t size){
    _pool=MemPool::getInstance(size);
    un_mapMem * allocMemLoc=(un_mapMem *)malloc(sizeof(un_mapMem));
    _allocatedMem=new (allocMemLoc) un_mapMem();
    freeMapMem * freeMapLoc=(freeMapMem *)malloc(sizeof(freeMapMem));
    _freeMap=new (freeMapLoc) freeMapMem();

}

size_t MemoryManager::normalizeTwoPower(size_t memSizeBit) {
    if(memSizeBit<=MIN_MEM_SIZE){
        return MIN_MEM_SIZE;
    }
    return (size_t)pow(POW_BASE,ceil(log2(memSizeBit)));
}

char *MemoryManager::newMem(size_t memSizeBit) {
    size_t sizeOnBits=normalizeTwoPower(memSizeBit);// normalize to 2^x
    char* memToGive=getMemFromFreeList(sizeOnBits);//check if there is place on the free list
    if(!memToGive) {
        size_t bitInUse = _pool->get_totalBitUse();
        if (_pool->get_poolSize() < bitInUse + sizeOnBits) {// if out of memory
            return nullptr;
        } else {
             memToGive = _pool->get_currentLocation();
            _pool->set_currentLocation(memToGive + sizeOnBits);
            _pool->set_totalBitUse(bitInUse + sizeOnBits);
            _allocatedMem->insert(make_pair(memToGive, sizeOnBits)); // save header on allocated mem
        }
    }


    return memToGive;
}
void MemoryManager::deleteMem(char *add) {//TODO Memory leak
    size_t elemSize=0;
    char* toDelete= nullptr;
    auto itr = _allocatedMem->begin();
    while (itr != _allocatedMem->end()) {
        if (itr->first==add) {
            elemSize=itr->second;
             _allocatedMem->erase(itr++);

        } else {
            ++itr;
        }
    }
    FreeNode* fnlloc=(FreeNode*)malloc(sizeof(FreeNode));
    FreeNode* fn=new (fnlloc)FreeNode(elemSize,add);
    auto iter=_freeMap->find(elemSize);
    if ( iter ==_freeMap->end() ) {
        // not found
        setForMap* setForMapAlocc=(setForMap*)malloc(sizeof(setForMap));
        setForMap* freeSet=new (setForMapAlocc)setForMap();
        freeSet->insert(fn);
        _freeMap->insert(make_pair(elemSize,*freeSet));

    } else {
        iter->second.insert(fn);
    }
}


un_mapMem *MemoryManager::get_allocatedMem() {
    return _allocatedMem;
}

freeMapMem* MemoryManager::get_freeMap() {
    return _freeMap;
}
char *MemoryManager::getMemFromFreeList(size_t memSize) {
    auto iter=_freeMap->find(memSize);
    if ( iter ==_freeMap->end() ) {
        // not found
        return nullptr;
    } else {
        FreeNode* memFromFreeList=(*((iter->second).begin()));
       char* mmAdd=memFromFreeList->getMemAdd();
        (iter->second).erase(memFromFreeList);
        _allocatedMem->insert(make_pair(mmAdd, memSize));

       return mmAdd;
    }


}
//initilize static members
un_mapMem *MemoryManager::_allocatedMem= nullptr;
freeMapMem *MemoryManager::_freeMap= nullptr;
MemPool *MemoryManager::_pool=nullptr;




