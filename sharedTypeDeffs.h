//
// Created by ofir on 1/11/17.
//




#include <utility>

#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include "MyAllocator.h"
#include "FreeNode.h"


#ifndef EX2CPP_SHAREDTYPEDEFFS_H
#define EX2CPP_SHAREDTYPEDEFFS_H
using namespace JVC;
using namespace std;

struct FreeNodeCompAdd
{
    bool operator()(const FreeNode* lhs, const FreeNode* rhs) const  {
        return (int)(lhs->getMemAdd() - rhs->getMemAdd()) < 0;
    }
};

#endif //EX2CPP_SHAREDTYPEDEFFS_H

typedef MyAllocator<FreeNode*> setAllocator;
typedef set<FreeNode*,FreeNodeCompAdd,setAllocator> setForMap;

typedef MyAllocator<std::pair<size_t, setForMap>> mapAllocator;
typedef map<size_t ,setForMap, std::less<size_t> , mapAllocator> freeMapMem;


typedef MyAllocator<std::pair<char*, size_t >> un_mapAllocator;
typedef unordered_map<char*,size_t,std::hash<char*>, std::equal_to<char*>,un_mapAllocator> un_mapMem;


typedef set<FreeNode*> simpleSet;
typedef MyAllocator<std::pair<size_t, simpleSet>> simpleMapAllocator;
typedef map<size_t ,simpleSet, std::less<size_t> , mapAllocator> simpleMapDeclare;

