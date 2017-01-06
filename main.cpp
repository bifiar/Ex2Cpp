#include <iostream>
#include "MemoryManager.h"
#include "FreeNode.h"
#include "ConsolePrinter.h"

using namespace std;
int main() {
    MemoryManager* mm=new MemoryManager(1000);
    char* mm1=mm->newMem(30);char* mm2=mm->newMem(15);char* mm3=mm->newMem(2);
    char* mm4=mm->newMem(14);char* mm5=mm->newMem(50); char* mm6=mm->newMem(80);

    cout<<"Address mm3 is "<<(void*) mm3<<endl;

    //print allocated map
    unordered_map<char*,size_t>* allocatedMem=(mm->get_allocatedMem());

    ConsolePrinter::printMap(allocatedMem);

    MemoryManager::deleteMem(mm2);MemoryManager::deleteMem(mm3);MemoryManager::deleteMem(mm4);
    cout<<"after deleting.... "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    map<size_t ,set<FreeNode*>>* freeMap=mm->get_freeMap();
    cout<<"free map:"<<endl;
    //print freelist map
    ConsolePrinter::printMapSet(freeMap);

    char* mm7=mm->newMem(15);
    cout<<"after adding memo from free map"<<endl;
    ConsolePrinter::printMapSet(freeMap);
    cout<<"Address mm3 is "<<(void*) mm3<<endl;

}