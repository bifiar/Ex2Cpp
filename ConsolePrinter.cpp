//
// Created by ofir on 1/6/17.
//

#include "ConsolePrinter.h"

#include <iostream>
using namespace std;

void ConsolePrinter::printMap(un_mapMem* allocatedMem) {
    for (auto iter = allocatedMem->begin(); iter != allocatedMem->end(); iter++)
    {
        cout << "Key: " <<(void*)iter->first <<" Value: " <<iter->second<< endl;
    }

}

void ConsolePrinter::printMapSet(freeMapMem* freeMap) {
    for (auto iter= freeMap->begin(); iter != freeMap->end(); iter++)
    {
        cout << "Key: " << iter->first << endl << "Values:" << endl;

        for (auto list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++){
            cout << " " <<(*(*list_iter))<< endl;
        }
    }
}

void ConsolePrinter::valgrindPrint(un_mapMem *allocatedMem) {
    cout<<"valgrind:"<<endl;
    cout<<"there is "<<(int)allocatedMem->size()<<" block in use"<<endl;
    cout<<"details:"<<endl;
    for (auto iter = allocatedMem->begin(); iter != allocatedMem->end(); iter++)
    {
        cout << "address " <<(void*)iter->first <<" size on bits: " <<iter->second<< endl;
    };

}
