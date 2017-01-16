#include <iostream>
#include <cmath>
#include "MemoryManager.h"
#include "sharedTypeDeffs.h"
#include "BestFIt.h"
#include "FirstFit.h"
#include "double_linked.h"

#define byte_size 8

using namespace std;
using namespace JVC;
int main() {


    MemoryManager* mem=(MemoryManager*)malloc(sizeof(MemoryManager));
    MemoryManager* mm=new (mem) MemoryManager(100000);

    FitAlgo* bestFitLoc = (FitAlgo*)malloc(sizeof(FitAlgo));
    FitAlgo* bestFit = new(bestFitLoc)BestFIt(mm->get_freeMap());

//    FitAlgo* firstFitLoc = (FitAlgo*)malloc(sizeof(FitAlgo));
//    FitAlgo* firstFit = new(firstFitLoc)FirstFit(mm->get_freeMap());

    mm->set_strategy(bestFit);
    freeMapMem* freeMap=mm->get_freeMap();
    un_mapMem* allocatedMem=(mm->get_allocatedMem());

    double_linked<std::pair<char*,long*>>* dlist = new double_linked<std::pair<char*,long*>> ( );
    dlist->push_back( make_pair(new char(5),new long(7)) );
    dlist->push_back( make_pair(new char(5),new long(54)) );
    dlist->push_back( make_pair(new char(5),new long(7))  );
    dlist->push_back( make_pair(new char(5),new long(53)) );
    dlist->push_back( make_pair(new char(5),new long(7)) );
    dlist->push_front( make_pair(new char(5),new long(53))  );

    cout<<"allocMap "<<endl;
    ConsolePrinter::printMap(allocatedMem);

    dlist->pop_back();dlist->pop_back();dlist->pop_back();
    dlist->pop_back();dlist->pop_back();dlist->pop_back();


    cout<<"allocMap "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    cout<<"free Map "<<endl;
    ConsolePrinter::printMapSet(freeMap);

    dlist->push_back( make_pair(new char(5),new long(7)) );
    dlist->push_front( make_pair(new char(5),new long(53))  );

    cout<<"allocMap "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    cout<<"free Map "<<endl;
    ConsolePrinter::printMapSet(freeMap);




}

