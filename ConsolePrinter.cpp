//
// Created by ofir on 1/6/17.
//

#include "ConsolePrinter.h"

#include <iostream>
using namespace std;

void ConsolePrinter::printMap(unordered_map<char *, size_t> *allocatedMem) {
    for (auto iter = allocatedMem->begin(); iter != allocatedMem->end(); iter++)
    {
        cout << "Key: " <<(void*)iter->first <<" Value: " <<iter->second<< endl;
    }

}

void ConsolePrinter::printMapSet(map<size_t, set<FreeNode*,FreeNodeCompAdd>> *freeMap) {
    for (auto iter= freeMap->begin(); iter != freeMap->end(); iter++)
    {
        cout << "Key: " << iter->first << endl << "Values:" << endl;

        for (auto list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++){
            cout << " " <<(*(*list_iter))<< endl;
        }
    }
}
