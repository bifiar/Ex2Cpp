#include <iostream>
#include <cmath>
#include <cstring>
#include "MemoryManager.h"
#include "sharedTypeDeffs.h"
#include "BestFIt.h"
#include "FirstFit.h"
#include "double_linked.h"

#define byte_size 8
#define VALGRIND_FLAG "-v"
#define SIZE_FLAG "-S"
using namespace std;
using namespace JVC;

int main(int argc,char *argv[]) {

bool valgFlag=false;
    long memSize=0;

    for (int i = 0; i < argc; ++i) {
        if(strcmp(argv[i],VALGRIND_FLAG)==0){
            valgFlag=true;
        }
        else if(strcmp(argv[i], SIZE_FLAG)==0){
            memSize = stol(argv[i+1]);
        }

    }

    cout<<memSize<<endl;
    MemoryManager* mem=(MemoryManager*)malloc(sizeof(MemoryManager));
    MemoryManager* mm=new (mem) MemoryManager(memSize);

    FitAlgo* bestFitLoc = (FitAlgo*)malloc(sizeof(FitAlgo));
    FitAlgo* bestFit = new(bestFitLoc)BestFIt(mm->get_freeMap());

//    FitAlgo* firstFitLoc = (FitAlgo*)malloc(sizeof(FitAlgo));
//    FitAlgo* firstFit = new(firstFitLoc)FirstFit(mm->get_freeMap());

    mm->set_strategy(bestFit);
    freeMapMem* freeMap=mm->get_freeMap();
    un_mapMem* allocatedMem=(mm->get_allocatedMem());

    double_linked<std::pair<char*,long*>*>* dlist = new double_linked<std::pair<char*,long*>*> ( );
    char * c1=new char('a');long* l1=new long(468468);
    std::pair<char*,long*> p1=make_pair(c1,l1);
    std::pair<char*,long*> p2=make_pair(c1,l1);
    std::pair<char*,long*> p3=make_pair(c1,l1);
    std::pair<char*,long*> p4=make_pair(c1,l1);
    std::pair<char*,long*> p5=make_pair(c1,l1);

    dlist->push_back( &p1);
    dlist->push_back( &p2);
    dlist->push_back( &p3);
    dlist->push_back( &p4);
    dlist->push_back( &p5);


    cout<<"alloc Map after alloc List "<<endl;
    ConsolePrinter::printMap(allocatedMem);

    dlist->pop_back();dlist->pop_back();dlist->pop_back();



    cout<<"alloc Map after delete pop from list "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    cout<<"free Map  pop from list"<<endl;
    ConsolePrinter::printMapSet(freeMap);

  // Check merge

    char*mm11=new char('d');char*mm12=new char('d');char*mm13=new char('d');
    char*mm14=new char('d');
    cout<<"alloc Map after alloc chars"<<endl;
    ConsolePrinter::printMap(allocatedMem);
    delete mm11;delete mm12;delete mm13;delete mm14;
    cout<<"free Map after delete chars"<<endl;
    ConsolePrinter::printMapSet(freeMap);

    int* mm2=new int(3);
    cout<<"free Map after alloc int(check merge)"<<endl;
    ConsolePrinter::printMapSet(freeMap);




    dlist->pop_back();dlist->pop_back();
    delete dlist; delete mm2;
    delete c1;delete l1;
    if(valgFlag)
    {
        ConsolePrinter::valgrindPrint(allocatedMem);
    }




}

