#include <iostream>
#include "MemoryManager.h"
#include "MyAllocator.h"


using namespace std;
using namespace mystd;
int main() {
    typedef MyAllocator<FreeNode*> setAllocator;
    typedef set<FreeNode*,FreeNodeCompAdd,setAllocator> setDeclare;

    typedef MyAllocator<std::pair<size_t, setDeclare>> mapAllocator;
    typedef map<size_t ,setDeclare, std::less<size_t> , mapAllocator> mapDeclare;


    typedef MyAllocator<std::pair<char*, size_t >> un_mapAllocator;
    typedef unordered_map<char*,size_t,std::hash<char*>, std::equal_to<char*>,un_mapAllocator> un_mapDeclare;


    typedef set<FreeNode*> simpleSet;
    typedef MyAllocator<std::pair<size_t, simpleSet>> simpleMapAllocator;
    typedef map<size_t ,simpleSet, std::less<size_t> , mapAllocator> simpleMapDeclare;







    MemoryManager* mm=new MemoryManager(1000);

    char* mm1=mm->newMem(30);char* mm2=mm->newMem(15);char* mm3=mm->newMem(2);
    char* mm4=mm->newMem(14);char* mm5=mm->newMem(50); char* mm6=mm->newMem(80);
    char* mm10=mm->newMem(15);char* mm11=mm->newMem(15);char* mm12=mm->newMem(15);
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

    char* mm7=mm->newMem(15);
    cout<<"after adding memo from free map(mm3)"<<endl;
    ConsolePrinter::printMapSet(freeMap);

    cout<<"Address mm7 is "<<(void*) mm7<<endl;

    //Allocator Test
    un_mapDeclare* testMapUnorderd = new un_mapDeclare();
    setDeclare* testSet= new setDeclare();
    mapDeclare* testMap = new mapDeclare();
    // map<size_t ,set<FreeNode*,FreeNodeCompAdd,MyAllocator<FreeNode*>>,std::less<size_t >,MyAllocator<std::pair<size_t ,set<FreeNode*,FreeNodeCompAdd,MyAllocator<FreeNode*>>>>>* mapTest = new map<size_t ,set<FreeNode*,FreeNodeCompAdd,MyAllocator<FreeNode*>>,std::less<size_t >,MyAllocator<std::pair<size_t ,set<FreeNode*,FreeNodeCompAdd,MyAllocator<FreeNode*>>>>>();
    testMapUnorderd->insert(make_pair((char*)700,8));
    testSet->insert(new FreeNode(10,(char*)45));

    simpleMapDeclare* smd = new simpleMapDeclare();
    simpleSet* sms=new simpleSet();
    sms->insert(new FreeNode(10,(char*)45));
    smd->insert(make_pair(700,*sms ));


    //Function sets Test



   // set<char*,size_t>* testSet2= new set<char*,size_t>();
    testMap->insert(make_pair(10,*testSet));



    set<FreeNode*,FreeNodeCompAdd,setAllocator>* myset = new set<FreeNode*,FreeNodeCompAdd,setAllocator>();
    myset->insert(new FreeNode(10,(char*)700));
    //mapTest->insert(make_pair(8,*myset));

    for (auto iter = testMapUnorderd->begin(); iter != testMapUnorderd->end(); iter++)
    {
        cout << "testMap_unorderd Key: " <<(void*)iter->first <<"testMap_unorderd Value: " <<iter->second<< endl;
    }

    for (auto iter = testMap->begin(); iter != testMap->end(); iter++)
    {
        cout << " testSet Key: " <<iter->first<<" Value: " <<endl;
        for (auto list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++){
            cout << " " <<(*(*list_iter))<< endl;
        }
    }

    for (auto iter = testSet->begin(); iter != testSet->end(); iter++)
    {
        cout << "testSet Key: " <<*iter<<endl;
    }

}