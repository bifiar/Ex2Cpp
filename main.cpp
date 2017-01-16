#include <iostream>
#include <cmath>
#include "MemoryManager.h"
#include "TypeDef.h"
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
    char* mm11=new char('3');char* mm12=new char('A');char* mm13=new char('a');int* mm91=new int(44);
    char* mm21=new char('3');char* mm22=new char('A');char* mm23=new char('a');
    char* mm31=new char('3');char* mm32=new char('A');char* mm33=new char('a');int* mm93=new int(44);
    cout<<"allocMap "<<endl;
    Console::printMap(allocatedMem);

    delete mm11; delete mm12; delete mm13;
    delete mm21;delete mm22;delete mm23;
    delete mm31;
    cout<<"free Map "<<endl;
    Console::printMapSet(freeMap);


    int* num11=new int(4334);

    cout<<"allocMap "<<endl;
    Console::printMap(allocatedMem);
    cout<<"free Map "<<endl;
    Console::printMapSet(freeMap);

//   char* mm11=new char('3');char* mm12=new char('A');char* mm13=new char('a');
//    int* mm21=new int(35);int* mm22=new int(454);int* mm23=new int(434);
//    double* mm31=new double(43.43);double* mm32=new double(434.43);double* mm33=new double(4375.5454);
//    cout<<"Boaz Check: "<<std::dec<<mm22<<endl;
//
//
//    //print allocated map
//    un_mapMem* allocatedMem=(mm->get_allocatedMem());
//
//    Console::printMap(allocatedMem);
//
//    delete mm12;delete mm22;delete mm32;
//
//    cout<<"after deleting.... "<<endl;
//    Console::printMap(allocatedMem);
//    freeMapMem* freeMap=mm->get_freeMap();
//    cout<<"free map:"<<endl;
//    //print freelist map
//    Console::printMapSet(freeMap);
//
//    char* mm7=new char;
//    cout<<"after adding memo from free map(mm3)"<<endl;
//    cout<<"Free MAP"<<endl;
//    Console::printMapSet(freeMap);
//    cout<<"Alloc MAP"<<endl;
//    Console::printMap(allocatedMem);
//    cout<<"Address mm7 is "<<(void*) mm7<<endl;
//
//    *mm11='C';*mm12='H';
//    *mm21=212;*mm22=313;
//    *mm31=4242.42;*mm32=3535.34;
//    arr[8]=121267868;
//    cout<<"after varibels balagan check"<<endl;
//    cout<<"m11,m12 "<<mm11<<" "<<mm12<<endl;
//    cout<<"m21,m22 "<<*mm21<<" "<<*mm22<<endl;
//    cout<<"m31,m32 "<<*mm31<<" "<<*mm32<<endl;
//    for (int j = 0; j <10 ; ++j) {
//        cout<<" "<<arr[j];
//    }
}

//    double_linked<int>* dlist = new double_linked<int> ( );
//    dlist->push_back( 11 );
//    dlist->push_back( 20 );
//    dlist->push_back( 33 );
//    dlist->push_back( 44);
//    dlist->push_back( 66 );
//    dlist->push_front( 100 );
//
//    un_mapMem* allocatedMem=(mm->get_allocatedMem());
//   Console::printMap(allocatedMem);






//int* arr=new int[10];
//    for (int i = 0; i <10 ; ++i) {
//        arr[i]=pow(2.0,i);
//    }
//
//   char* mm11=new char('3');char* mm12=new char('A');char* mm13=new char('a');
//    int* mm21=new int(35);int* mm22=new int(454);int* mm23=new int(434);
//    double* mm31=new double(43.43);double* mm32=new double(434.43);double* mm33=new double(4375.5454);
//    cout<<"Boaz Check: "<<std::dec<<mm22<<endl;
//
//
//
//
//    //print allocated map
//    un_mapMem* allocatedMem=(mm->get_allocatedMem());
//
//    Console::printMap(allocatedMem);
//
//    delete mm12;delete mm22;delete mm32;
//
//    cout<<"after deleting.... "<<endl;
//    Console::printMap(allocatedMem);
//    freeMapMem* freeMap=mm->get_freeMap();
//    cout<<"free map:"<<endl;
//    //print freelist map
//    Console::printMapSet(freeMap);
//
//    char* mm7=new char;
//    cout<<"after adding memo from free map(mm3)"<<endl;
//    cout<<"Free MAP"<<endl;
//    Console::printMapSet(freeMap);
//    cout<<"Alloc MAP"<<endl;
//    Console::printMap(allocatedMem);
//    cout<<"Address mm7 is "<<(void*) mm7<<endl;
//
//    *mm11='C';*mm12='H';
//    *mm21=212;*mm22=313;
//    *mm31=4242.42;*mm32=3535.34;
//    arr[8]=121267868;
//    cout<<"after varibels balagan check"<<endl;
//    cout<<"m11,m12 "<<mm11<<" "<<mm12<<endl;
//    cout<<"m21,m22 "<<*mm21<<" "<<*mm22<<endl;
//    cout<<"m31,m32 "<<*mm31<<" "<<*mm32<<endl;
//    for (int j = 0; j <10 ; ++j) {
//        cout<<" "<<arr[j];
//    }