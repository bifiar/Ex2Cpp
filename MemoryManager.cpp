//
// Created by ofir on 1/3/17.
//

#include <cmath>
#include <cstring>
#include "MemoryManager.h"
#include "MemPool.h"


MemoryManager::MemoryManager(size_t size){
    _pool=MemPool::getInstance(size);
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
        set<FreeNode*,FreeNodeCompAdd>* freeSet=new set<FreeNode*,FreeNodeCompAdd>();
        freeSet->insert(fn);
        _freeMap->insert(make_pair(elemSize,*freeSet));
        delete freeSet;//delete fn;
    } else {
        iter->second.insert(fn);
    }
}


unordered_map<char *, size_t> *MemoryManager::get_allocatedMem() {
    return _allocatedMem;
}

map<size_t, set<FreeNode *,FreeNodeCompAdd>>* MemoryManager::get_freeMap() {
    return _freeMap;
}
char *MemoryManager::getMemFromFreeList(size_t memSize) {
    auto iter=_freeMap->find(memSize);
    if ( iter ==_freeMap->end() ) {
        // not found
        return nullptr;
    } else {
        FreeNode* memFromFreeList=(*((iter->second).begin()));
       char* mmAdd=(*((iter->second).begin()))->getMemAdd();
        (iter->second).erase(memFromFreeList);//TODO insert to allocMem
       return mmAdd;
    }


}
//initilize static members
unordered_map<char*,size_t> *MemoryManager::_allocatedMem= new unordered_map<char*,size_t>();
map<size_t ,set<FreeNode*,FreeNodeCompAdd>> *MemoryManager::_freeMap= new map<size_t ,set<FreeNode*,FreeNodeCompAdd>>();
MemPool *MemoryManager::_pool=nullptr;




