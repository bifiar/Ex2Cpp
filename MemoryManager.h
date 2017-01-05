//
// Created by ofir on 1/3/17.
//

#ifndef EX2CPP_MEMORYMANAGER_H
#define EX2CPP_MEMORYMANAGER_H


#include <cstddef>
#include <unordered_map>
#include <set>
#include <map>
#include "MemPool.h"


class FreeNode;
using namespace std;
class MemoryManager {


private:
    unordered_map<char*,size_t> _allocatedMem;
    map<size_t ,set<FreeNode>> _freeMap;
    MemPool _pool;

};


#endif //EX2CPP_MEMORYMANAGER_H
