#include <iostream>
#include "MemPool.h"
using namespace std;
int main() {
    MemPool* memory=MemPool::getInstance(1000);
    cout<<memory->get_poolSize()<<endl;
    MemPool* memory2=MemPool::getInstance(2000);
    cout<<memory2->get_poolSize()<<endl;
}