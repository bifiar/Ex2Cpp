#include <iostream>
#include <cmath>
#include "MemoryManager.h"
#include "sharedTypeDeffs.h"

#define byte_size 8

using namespace std;
using namespace JVC;
int main() {


    MemoryManager* mem=(MemoryManager*)malloc(sizeof(MemoryManager));
    MemoryManager* mm=new (mem) MemoryManager(100000);

    int* arr=new int[10];
    for (int i = 0; i <10 ; ++i) {
        arr[i]=pow(2.0,i);
    }

    char* mm11=new char('3');char* mm12=new char('A');char* mm13=new char('a');
    int* mm21=new int(35);int* mm22=new int(454);int* mm23=new int(434);
    double* mm31=new double(43.43);double* mm32=new double(434.43);double* mm33=new double(4375.5454);




    cout<<"Address mm12 is "<<(void*) mm12<<endl;

    //print allocated map
    un_mapMem* allocatedMem=(mm->get_allocatedMem());

    ConsolePrinter::printMap(allocatedMem);

    delete mm12;delete mm22;delete mm32;

    cout<<"after deleting.... "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    freeMapMem* freeMap=mm->get_freeMap();
    cout<<"free map:"<<endl;
    //print freelist map
    ConsolePrinter::printMapSet(freeMap);

    char* mm7=new char;
    cout<<"after adding memo from free map(mm3)"<<endl;
    cout<<"Free MAP"<<endl;
    ConsolePrinter::printMapSet(freeMap);
    cout<<"Alloc MAP"<<endl;
    ConsolePrinter::printMap(allocatedMem);
    cout<<"Address mm7 is "<<(void*) mm7<<endl;

    *mm11='C';*mm12='H';
    *mm21=212;*mm22=313;
    *mm31=4242.42;*mm32=3535.34;
    arr[8]=1212;
    cout<<"after varibels balagan check"<<endl;
    cout<<"m11,m12 "<<mm11<<" "<<mm12<<endl;
    cout<<"m21,m22 "<<*mm21<<" "<<*mm22<<endl;
    cout<<"m31,m32 "<<*mm31<<" "<<*mm32<<endl;
    for (int j = 0; j <10 ; ++j) {
        cout<<" "<<arr[j];
    }
}