#include <iostream>
#include "MemoryManager.h"


using namespace std;
int main() {

    MemoryManager* mm=new MemoryManager(1000);

    char* mm1=mm->newMem(6);char* mm2=mm->newMem(6);char* mm3=mm->newMem(10);
    char* mm4=mm->newMem(10);char* mm5=mm->newMem(30);
    /*char* mm5=mm->newMem(50); char* mm6=mm->newMem(80);
    char* mm10=mm->newMem(15);char* mm11=mm->newMem(15);char* mm12=mm->newMem(15);*/
    cout<<(void*)(mm2-mm1)<<endl;
    cout<<(void*)(mm1-mm2)<<endl;
    cout<<(int)(mm1-mm2)<<endl;

    cout<<"Address mm2 is "<<(void*) mm2<<endl;

    //print allocated map
    unordered_map<char*,size_t>* allocatedMem=(mm->get_allocatedMem());

    ConsolePrinter::printMap(allocatedMem);

  MemoryManager::deleteMem(mm1);MemoryManager::deleteMem(mm2);MemoryManager::deleteMem(mm3);
    MemoryManager::deleteMem(mm4);MemoryManager::deleteMem(mm5);//MemoryManager::deleteMem(mm12);
    cout<<"after deleting.... "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    map<size_t ,set<FreeNode*,FreeNodeCompAdd>>* freeMap=mm->get_freeMap();
    cout<<"free map:"<<endl;
    //print freelist map
    ConsolePrinter::printMapSet(freeMap);


    char* mm11=mm->newMem(6);
    cout<<"Address mm11 is "<<(void*) mm11<<endl;
    char* mm7=mm->newMem(30);
    cout<<"Address mm7 is "<<(void*) mm7<<endl;
    ConsolePrinter::printMapSet(freeMap);

    char* mm8=mm->newMem(30);
    cout<<"Address mm8 is "<<(void*) mm8<<endl;
    //cout<<"after adding memo from free map(mm3)"<<endl;
    ConsolePrinter::printMapSet(freeMap);




}