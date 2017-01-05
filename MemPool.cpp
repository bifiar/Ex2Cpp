//
// Created by ofir on 1/3/17.
//

#include <glob.h>
#include <malloc.h>
#include "MemPool.h"
#include <iostream>

using namespace std;
MemPool::MemPool(size_t poolSize) : _totalByteInUse(0),_poolSize(poolSize) {
    _pool=(char*) malloc(poolSize* sizeof(char));
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

int MemPool::get_totalByteInUse() const {
    return _totalByteInUse;
}

char *MemPool::get_currentLocation() const {
    return _currentLocation;
}

void MemPool::set_totalByteInUse(int _totalByteInUse) {
    MemPool::_totalByteInUse = _totalByteInUse;
}

void MemPool::set_currentLocation(char *_currentLocation) {
    MemPool::_currentLocation = _currentLocation;
}

size_t MemPool::get_poolSize() const {
    return _poolSize;
}
MemPool *MemPool::_memPoolInstance= nullptr;

