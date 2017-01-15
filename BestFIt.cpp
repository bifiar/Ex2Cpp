//
// Created by avishay on 1/15/17.
//

#include <cmath>
#include "BestFIt.h"

BestFIt::BestFIt(freeMapMem* freeMap):_freeMap(freeMap) {}

/**
 *
 * @return
 */
freeMapMem *BestFIt::get_freeMap() {
    return _freeMap;
}

/**
 *
 * @param _freeMap
 */
void BestFIt::set_freeMap(freeMapMem *_freeMap) {
    BestFIt::_freeMap = _freeMap;
}
/**
 *
 * @param memSizeBit
 * @return
 */
char *BestFIt::searchFreeMemAlgo(size_t memSizeBit) {
    auto iter=_freeMap->find(memSizeBit);
    if ( iter ==_freeMap->end() ) {
        // not found
        return nullptr;
    } else {
        FreeNode* memFromFreeList=(*((iter->second).begin()));
        char* mmAdd=memFromFreeList->getMemAdd();
        (iter->second).erase(memFromFreeList);
        return mmAdd;
    }
}

/**
 *
 * @param memSize
 * @return
 */
char* BestFIt::canMerge(size_t memSize){
    size_t newSize=memSize;
    size_t countNodes=1;
    //FreeNode* memNode= nullptr;
    FreeNode* fn=nullptr;
    while((newSize)>=MIN_MEM_SIZE) {
        auto iter = _freeMap->find(newSize);
        if (iter == _freeMap->end()) {
            newSize /= 2;
            countNodes*=2;
        }else {
            // auto iterForSplit=iter->second.begin();
            FreeNode* FirstNodeAtSet = (*((iter->second).begin()));
            if(FirstNodeAtSet!=nullptr) {
                if (*((iter->second).begin())) {
                    auto setSize = iter->second.size();
                    auto iterSet = iter->second.begin();
                    auto iterSetAddress = iter->second.begin();
                    long adress = (long)(*iterSetAddress)->getMemAdd();//the first address in the set
                    iterSetAddress++;
                    bool flagAdress=true;

                    if (setSize != 0) {
                        if (((*iterSet)->getMemSize()) * setSize >= memSize) { //number of nodes are fine for merging

                            for (int j = 1; j <setSize ; ++j) {//check that address of nodes by order

                                adress+=((*iterSetAddress)->getMemSize());
                                //iterSetAddress++;

                                //(adress + ((*iterSetAddress)->getMemSize()))
                                if(adress!=((long)(*iterSetAddress)->getMemAdd())){
                                    flagAdress=false;
                                    break;

                                }
                                iterSetAddress++;
                            }

                            if(flagAdress) {//nodes by orders
                                FreeNode* fnlloc=(FreeNode*)malloc(sizeof(FreeNode));
                                fn=new (fnlloc)FreeNode(memSize,FirstNodeAtSet->getMemAdd());
                                //memNode = new FreeNode(memSize, FirstNodeAtSet->getMemAdd());//TODO check new
                                for (int i = 0; i < countNodes; ++i) {
                                    iter->second.erase(iterSet++);
                                }
                                // _allocatedMem->insert(make_pair(FirstNodeAtSet->getMemAdd(), memSize));

                                break;
                            }else{
                                if(newSize==8){
                                    newSize /= 2;
                                }
                            }
                        }else{
                            newSize /= 2;
                        }

                    }
                }
            }else{
                newSize /= 2;
                countNodes*=2;
            }

        }

    }
    if(fn!=nullptr) {
        return fn->getMemAdd();
    }
//    }else{
//        //check here for split!
//        return split(memSize);
//    }
    return nullptr;

}


//char *MemoryManager::getMemFromFreeList(size_t memSize) {
//
//    //if ( iter ==_freeMap->end() ) {
//    // not found - need to check if we can merge Nodes
//    char *mmAddress= nullptr;
//    mmAddress = canMerge(memSize);
//    if (mmAddress) {
//        return mmAddress;
//    } else {
//        auto iter=_freeMap->find(memSize);
//        if (iter !=_freeMap->end() ) {
//            FreeNode memFromFreeList = (((iter->second).begin()));
//            char mmAdd = (((iter->second).begin()))->getMemAdd();
//            (iter->second).erase(memFromFreeList);//TODO insert to allocMem
//            // _allocatedMem->insert(make_pair(mmAdd, memSize));
//            return mmAdd;
//        }
//        return nullptr;
//    }
//
//
//}
