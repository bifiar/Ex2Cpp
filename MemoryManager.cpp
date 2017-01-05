//
// Created by ofir on 1/3/17.
//

#include <cmath>
#include "MemoryManager.h"
#include "MemPool.h"
MemoryManager::MemoryManager(size_t size): _pool(MemPool::getInstance(size)),
                                           _allocatedMem(new unordered_map<char*,size_t>() ),
                                           _freeMap(new map<size_t ,set<FreeNode*>>()){}

size_t MemoryManager::normalizeTwoPower(size_t memSizeBit) {
    return (size_t)pow(2.0,ceil(log2(memSizeBit)));
}

char *MemoryManager::newMem(size_t memSizeBit) {
    size_t sizeOnBits=normalizeTwoPower(memSizeBit);
    //TODO check if there is place on the free list!


    size_t byteInuse=_pool->get_totalByteInUse();
    if(_pool->get_poolSize()<byteInuse+sizeOnBits){// if out of memory
        return nullptr;
    }
    char * currentLocation=_pool->get_currentLocation();
    _pool->set_currentLocation(currentLocation+sizeOnBits);
    _pool->set_totalByteInUse(byteInuse+sizeOnBits);

    _allocatedMem->insert(make_pair(currentLocation,sizeOnBits)); // save header on allocated mem


    return currentLocation;
}
