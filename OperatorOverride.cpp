//
//Created by boaz_bahat on 1/2/17.
//


#include <iostream>
#include "MemoryManager.h"
#define byte_size 8
using namespace std;

/**
*override new
* @param size_t n
*/
void * operator new(std::size_t n) throw(bad_alloc)
{
    std::bad_alloc exception;
    char* pointMem=MemoryManager::newMem(n*byte_size);
    if(!pointMem){
        throw exception;
    }
    return pointMem;

}

/**
*override delete
* @param *p
*/
void operator delete(void * p) throw()
{
    MemoryManager::deleteMem((char*)p);
}
/**
*override new []
* @param size_t arr
*/
void *operator new[](size_t s) throw(bad_alloc)
{
    return ::operator new(s);
}
/**
*override delete []
* @param size_t arr
*/
void operator delete[](void *p) throw()
{
    ::operator delete(p);
}
