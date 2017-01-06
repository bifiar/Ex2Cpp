//
// Created by ofir on 1/3/17.
//

#include <cmath>
#include <cstring>
#include "MemoryManager.h"
#include "MemPool.h"
#include "FreeNode.h"

MemoryManager::MemoryManager(size_t size){
    _pool=MemPool::getInstance(size);
}

size_t MemoryManager::normalizeTwoPower(size_t memSizeBit) {
    if(memSizeBit<=MIN_MEM_SIZE){
        return MIN_MEM_SIZE;
    }
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
void MemoryManager::deleteMem(char *add) {//TODO Memory leak
    size_t elemSize=0;
    char* toDelete=0;
    //size_t elemSize=_allocatedMem->erase(add);
    auto itr = _allocatedMem->begin();
    while (itr != _allocatedMem->end()) {
        if (itr->first==add) {
            elemSize=itr->second;
             _allocatedMem->erase(itr++);

        } else {
            ++itr;
        }
    }
    FreeNode* fn=new FreeNode(elemSize,add);
    auto iter=_freeMap->find(elemSize);
    if ( iter ==_freeMap->end() ) {
        // not found
        set<FreeNode*>* freeSet=new set<FreeNode*>();
        freeSet->insert(fn);
        _freeMap->insert(make_pair(elemSize,*freeSet));
    } else {
        iter->second.insert(fn);
    }
}


unordered_map<char *, size_t> *MemoryManager::get_allocatedMem() {
    return _allocatedMem;
}

map<size_t, set<FreeNode *>> *MemoryManager::get_freeMap() {
    return _freeMap;
}

//initilize static members
unordered_map<char*,size_t> *MemoryManager::_allocatedMem= new unordered_map<char*,size_t>();
map<size_t ,set<FreeNode*>> *MemoryManager::_freeMap= new map<size_t ,set<FreeNode*>>();
MemPool *MemoryManager::_pool=nullptr;


