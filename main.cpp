#include <iostream>
#include "MemoryManager.h"


using namespace std;
int main() {

    MemoryManager* mem=(MemoryManager*)malloc(sizeof(MemoryManager));
    MemoryManager* mm=new (mem) MemoryManager(10000);

    FreeNode* testNew=new FreeNode(12,(char*)13);
    char* mm1=new char;
    char* mm2=new char;
    char* mm3=new char;
    char* mm4=new char;char* mm5=new char; char* mm6=new char;
    char* mm10=new char;char* mm11=new char;char* mm12=new char;
    cout<<(void*)(mm2-mm1)<<endl;
    cout<<(void*)(mm1-mm2)<<endl;
    cout<<(int)(mm1-mm2)<<endl;

    cout<<"Address mm2 is "<<(void*) mm2<<endl;

    //print allocated map
    unordered_map<char*,size_t>* allocatedMem=(mm->get_allocatedMem());

    ConsolePrinter::printMap(allocatedMem);

    MemoryManager::deleteMem(mm2);MemoryManager::deleteMem(mm3);MemoryManager::deleteMem(mm4);
    MemoryManager::deleteMem(mm10);MemoryManager::deleteMem(mm11);MemoryManager::deleteMem(mm12);
    cout<<"after deleting.... "<<endl;
    ConsolePrinter::printMap(allocatedMem);
    map<size_t ,set<FreeNode*,FreeNodeCompAdd>>* freeMap=mm->get_freeMap();
    cout<<"free map:"<<endl;
    //print freelist map
    ConsolePrinter::printMapSet(freeMap);

    char* mm7=new char;
    cout<<"after adding memo from free map(mm3)"<<endl;
    ConsolePrinter::printMapSet(freeMap);

    cout<<"Address mm7 is "<<(void*) mm7<<endl;

}