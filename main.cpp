#include <iostream>
#include <cmath>

#include "MemoryManager.h"
#include "TypeDef.h"

#define byte_size 8

using namespace std;
using namespace JVC;

int main() {

    MemoryManager* mem=(MemoryManager*)malloc(sizeof(MemoryManager));
    MemoryManager* mm=new (mem) MemoryManager(100000);

//    int* arr=new int[10];
//    for (int i = 0; i <10 ; ++i) {
//        arr[i]=pow(2.0,i);
//    }

    char* mm11=new char('3');char* mm12=new char('A');char* mm13=new char('a');
    char* mm21=new char('6');
    int* mm22=new int(16);int* mm23=new int(16); double* mm31=new double(43.43);
//    double* mm31=new double(43.43);double* mm32=new double(434.43);double* mm33=new double(4375.5454);
    //cout<<(int)(mm22-mm23)<<endl;
    cout<<"Address mm12 is "<<(void*) mm12<<endl;

    //print allocated map
    un_mapMem* allocatedMem=(mm->get_allocatedMem());

    Console::printMap(allocatedMem);

    //delete mm12;delete mm22;delete mm32;
    delete mm22;delete mm23;delete mm11;delete mm12;//delete mm31;


    cout<<"after deleting.... "<<endl;
    Console::printMap(allocatedMem);
    freeMapMem* freeMap=mm->get_freeMap();
    cout<<"free map:"<<endl;
    //print freelist map
    Console::printMapSet(freeMap);
    cout<<"alloc map before"<<endl;
    Console::printMap(allocatedMem);
    //char* mm7=new char;
    char* mm7=new char('32.9');
    /*cout<<"after adding memo from free map(mm3)"<<endl;
    cout<<"Free MAP"<<endl;
    Console::printMapSet(freeMap);*/
    cout<<"Alloc MAP after"<<endl;
    Console::printMap(allocatedMem);
    cout<<"Address mm7 is "<<(void*) mm7<<endl;
    cout<<"Free MAP"<<endl;

    Console::printMapSet(freeMap);

   /* *mm11='C';*mm12='H';
    *mm21=212;*mm22=313;
    *mm31=4242.42;*mm32=3535.34;
    arr[8]=1212;
    cout<<"after varibels balagan check"<<endl;
    cout<<"m11,m12 "<<mm11<<" "<<mm12<<endl;
    cout<<"m21,m22 "<<*mm21<<" "<<*mm22<<endl;
    cout<<"m31,m32 "<<*mm31<<" "<<*mm32<<endl;
    for (int j = 0; j <10 ; ++j) {
        cout<<" "<<arr[j];
    }*/
}