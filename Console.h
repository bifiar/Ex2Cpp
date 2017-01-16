//
// Created by ofir on 1/6/17.
//

#ifndef EX2CPP_Console_H
#define EX2CPP_Console_H


#include <glob.h>
#include "FreeNode.h"
#include "TypeDef.h"
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class Console {
public:
    /**
  *this function print the allocated memory list
  * @param allocatedMem
  */
    static void printMap(un_mapMem* allocatedMem);

    /**
  *this function print the free memory list
  * @param freeMap
  */
    static void printMapSet(freeMapMem* freeMap);

private:

};


#endif //EX2CPP_Console_H
