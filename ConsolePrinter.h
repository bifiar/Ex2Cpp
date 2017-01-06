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
struct FreeNodeCompAdd
{
    bool operator()(const FreeNode* lhs, const FreeNode* rhs) const  {
        return (int)(lhs->getMemAdd() - rhs->getMemAdd()) < 0;
    }
};
class ConsolePrinter {
public:
    static void printMap(unordered_map<char*,size_t>* allocatedMem);
    static void printMapSet(map<size_t ,set<FreeNode*,FreeNodeCompAdd>>* freeMap);

private:

};


#endif //EX2CPP_CONSOLEPRINTER_H
