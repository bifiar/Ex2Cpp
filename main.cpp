#include <iostream>
#include "MemPool.h"
#include "MemoryManager.h"

using namespace std;
int main() {
    MemoryManager* mm=new MemoryManager(1000);
    cout<<mm->normalizeTwoPower(30)<<endl;
}