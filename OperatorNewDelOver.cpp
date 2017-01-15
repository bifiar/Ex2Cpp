//
// Created by ofir on 1/8/17.
//
//

#include <iostream>
#include "MemoryManager.h"
#define byte_size 8
using namespace std;
void * operator new(std::size_t n) throw(bad_alloc)
{
    std::bad_alloc exception;
    char* pointMem=MemoryManager::newMem(n*byte_size);
    if(!pointMem){
        throw exception;
    }
    return pointMem;

}
void operator delete(void * p) throw()
{
    MemoryManager::deleteMem((char*)p);
}

void *operator new[](size_t s) throw(bad_alloc)
{
    return ::operator new(s);
}
void operator delete[](void *p) throw()
{
    // TODO: implement
}
