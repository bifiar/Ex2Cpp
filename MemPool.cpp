//
//Created by boaz_bahat on 1/2/17.
//

#include <glob.h>
#include <malloc.h>
#include "MemPool.h"
#include <iostream>

using namespace std;
MemPool::MemPool(size_t poolSize) : _totalBitUse(0),_poolSize(poolSize) {
    _pool=(char*) malloc(poolSize);
    _currentLocation=_pool;
}

MemPool *MemPool::getInstance(size_t poolSize) {
    if(!_memPoolInstance){
        MemPool* mem=(MemPool*)malloc(sizeof(MemPool));
        if(mem== nullptr){
            cout<<"cannot alloc memory to pool"<<endl;
            return  nullptr;
        }
        _memPoolInstance=new (mem) MemPool(poolSize);
    }
    return _memPoolInstance;
}

size_t MemPool::get_totalBitUse() const {
    return _totalBitUse;
}

char *MemPool::get_currentLocation() const {
    return _currentLocation;
}

void MemPool::set_totalBitUse(size_t _totalBitUse) {
    MemPool::_totalBitUse = _totalBitUse;
}

void MemPool::set_currentLocation(char *_currentLocation) {
    MemPool::_currentLocation = _currentLocation;
}

size_t MemPool::get_poolSize() const {
    return _poolSize;
}
MemPool *MemPool::getInstance() {
    return _memPoolInstance;
}
MemPool *MemPool::_memPoolInstance= nullptr;



