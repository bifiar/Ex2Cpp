//
// Created by ofir on 1/6/17.
//

#ifndef EX2CPP_CONSOLEPRINTER_H
#define EX2CPP_CONSOLEPRINTER_H


#include <glob.h>
#include "FreeNode.h"
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
class ConsolePrinter {
public:
    static void printMap(unordered_map<char*,size_t>* allocatedMem);
    static void printMapSet(map<size_t ,set<FreeNode*>>* freeMap);

private:

};


#endif //EX2CPP_CONSOLEPRINTER_H
