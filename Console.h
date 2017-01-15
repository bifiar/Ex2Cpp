//
//Created by boaz_bahat on 1/2/17.
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
struct FreeNodeCompAdd
{
    bool operator()(const FreeNode* lhs, const FreeNode* rhs) const  {
        return (int)(lhs->getMemAdd() - rhs->getMemAdd()) < 0;
    }
};

class Console {
public:
    static void printMap(un_mapMem* allocatedMem);
    static void printMapSet(freeMapMem* freeMap);

private:

};


#endif //EX2CPP_Console_H
