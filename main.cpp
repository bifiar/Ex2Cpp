#include <iostream>
#include "MemoryManager.h"

using namespace std;
int main() {
    MemoryManager* mm=new MemoryManager(1000);
    char* mm1=mm->newMem(30);
    char* mm2=mm->newMem(15);
    char* mm3=mm->newMem(2);
    cout<<"Address mm1 is "<<(void*) mm1<<endl;
    cout<<"Address mm2 is "<<(void*) mm2<<endl;
    cout<<"Address mm3 is "<<(void*) mm3<<endl;

    //print allocated map
    unordered_map<char*,size_t> allocatedMem=*(mm->get_allocatedMem());
    typedef unordered_map<char*,size_t>::const_iterator MapIterator;
    for (MapIterator iter = allocatedMem.begin(); iter != allocatedMem.end(); iter++)
    {
        cout << "Key: " <<(void*)iter->first <<" Value: " <<iter->second<< endl;
    }

    MemoryManager::deleteMem(mm2);

    map<size_t ,set<FreeNode*>> freeMap=*(mm->get_freeMap());
    cout<<"free map:"<<endl;

    //print freelist map
    typedef map<unsigned long, std::set<FreeNode *>>::const_iterator MapSetIterator;
    for (MapSetIterator iter= freeMap.begin(); iter != freeMap.end(); iter++)
    {
        cout << "Key: " << iter->first << endl << "Values:" << endl;
        typedef set<FreeNode*>::const_iterator setIterator;
        for (setIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
            cout << " " << *list_iter << endl;
    }


}