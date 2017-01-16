//
// Created by ofir on 1/6/17.
//

#ifndef EX2CPP_CONSOLEPRINTER_H
#define EX2CPP_CONSOLEPRINTER_H


#include <glob.h>
#include "FreeNode.h"
#include "sharedTypeDeffs.h"
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class ConsolePrinter {
public:
    static void printMap(un_mapMem* allocatedMem);
    static void printMapSet(freeMapMem* freeMap);
    static void valagrinPring(un_mapMem* allocatedMem);

private:

};


#endif //EX2CPP_CONSOLEPRINTER_H
