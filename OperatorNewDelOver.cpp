//
//// Created by ofir on 1/8/17.
//
//
//
//#include <iostream>
//#include "MemoryManager.h"
//
//using namespace std;
//void * operator new(std::size_t n) throw(bad_alloc)
//{
//    std::bad_alloc exception;
//    char* pointMem=MemoryManager::newMem(n);
//    if(!pointMem){
//        throw exception;
//    }
//    return pointMem;
//}
//void operator delete(void * p) throw()
//{
//  cout<<"Mother fucker  "<<p<<endl;
//}
//
//void *operator new[](size_t s) throw(bad_alloc)
//{
//    // TODO: implement
//    return NULL;
//}
//void operator delete[](void *p) throw()
//{
//    // TODO: implement
//}
