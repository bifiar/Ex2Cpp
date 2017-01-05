//
// Created by ofir on 1/3/17.
//

#ifndef EX2CPP_MEMORYMANAGER_H
#define EX2CPP_MEMORYMANAGER_H


#define MIN_MEM_SIZE 8
#include <cstddef>
#include <unordered_map>
#include <set>
#include <map>
#include <iostream>


class MemPool;
class FreeNode;
using namespace std;
class MemoryManager {
public:
    MemoryManager(size_t size);
    static char* newMem(size_t memSizeBit);
    static void deleteMem(char* add);

    static unordered_map<char *, size_t> *get_allocatedMem();

    static map<size_t, set<FreeNode *>> *get_freeMap();

private:
    static size_t normalizeTwoPower(size_t memSizeBit);
    static unordered_map<char*,size_t>* _allocatedMem;
    static map<size_t ,set<FreeNode*>>* _freeMap;
    static MemPool* _pool;


};



#endif //EX2CPP_MEMORYMANAGER_H
