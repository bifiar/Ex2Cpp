//
// Created by ofir on 1/3/17.
//

#ifndef EX2CPP_MEMORYMANAGER_H
#define EX2CPP_MEMORYMANAGER_H


#define MIN_MEM_SIZE 8
#define POW_BASE 2.0
#include <cstddef>
#include <unordered_map>
#include <set>
#include <map>
#include <iostream>
#include "ConsolePrinter.h"
#include "FitAlgo.h"


class MemPool;
class FreeNode;
using namespace std;
class MemoryManager {
public:
    MemoryManager(size_t size);
    static char* newMem(size_t memSizeBit);
    static void deleteMem(char* add);

    static un_mapMem* get_allocatedMem();

    static freeMapMem *get_freeMap();

    static void set_strategy(FitAlgo* _strategy);

private:

    static FitAlgo* _strategy;
    static un_mapMem* _allocatedMem;
    static freeMapMem* _freeMap;
    static MemPool* _pool;

   // static char* getMemFromFreeList(size_t memSize);
    static size_t normalizeTwoPower(size_t memSizeBit);


};



#endif //EX2CPP_MEMORYMANAGER_H
