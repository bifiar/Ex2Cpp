#include <iostream>
#include "MemoryManager.h"
#include "sharedTypeDeffs.h"

#define byte_size 8

using namespace std;
using namespace JVC;
int main() {
   //FreeNode* testNew2=(FreeNode*)(malloc(sizeof(FreeNode)));
  //  FreeNode* test=(FreeNode*)::operator new(10) ;

    MemoryManager* mem=(MemoryManager*)malloc(sizeof(MemoryManager));
    MemoryManager* mm=new (mem) MemoryManager(100000);


    char* mm11=new char;char* mm12=new char;char* mm13=new char;
    int* mm21=new int;int* mm22=new int;int* mm23=new int;
    double* mm31=new double;double* mm32=new double;double* mm33=new double;


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

}