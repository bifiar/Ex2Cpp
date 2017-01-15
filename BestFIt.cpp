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
        return canMerge(memSizeBit);
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
    char* addressToAlloc= nullptr;
    auto currentIter=_freeMap->begin();
    if(_freeMap->size()==0){
        return nullptr;
    }
    while(currentIter != _freeMap->end() && currentIter->first< memSize){
        size_t numOfNodes=memSize/(currentIter->first);
        int isSuccess=0;
        setForMap::iterator iterToAllocAddress=isAddressSequence(currentIter->second, numOfNodes,&isSuccess);
        setForMap::iterator tempTest=currentIter->second.end();
        if(isSuccess) {
            addressToAlloc=(*iterToAllocAddress)->getMemAdd();
            for(int i=0;i<numOfNodes;i++) {
                FreeNode* toDel=*iterToAllocAddress;
                currentIter->second.erase(toDel);
                iterToAllocAddress++;
            }
            break;
        }
        currentIter++;
    }
    return addressToAlloc;
}

setForMap::iterator BestFIt::isAddressSequence(setForMap currentSet, size_t numOfNodes,int* isSuccess) {
    size_t sizeLeft=currentSet.size();
    if(sizeLeft==0) {return currentSet.end();}
    size_t currentSuccess=1;
    auto currentSetIter = currentSet.begin();
    size_t memSize=(*currentSetIter)->getMemSize();
    long address = (long)(*currentSetIter)->getMemAdd();
    while (sizeLeft >= numOfNodes && currentSuccess < numOfNodes) {
        address += memSize;
        long currentAddress=(long) (*(++currentSetIter))->getMemAdd();
        if (address == currentAddress) {
            currentSuccess++;
        } else {
            sizeLeft -= currentSuccess;
            currentSuccess = 1;
            address = currentAddress;
        }
    }
    if (currentSuccess == numOfNodes) {
        for (int i = 0; i <numOfNodes-1 ; ++i) {
            currentSetIter--;
        }
        *isSuccess=1;
        return currentSetIter;
    }
    return currentSet.end();
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


//
//
//
//
//            FreeNode *FirstNodeAtSet = (*((currentIter->second).begin()));
//            if (FirstNodeAtSet != nullptr) {
//                size_t setSize = iter->second.size();
//                auto iterSet = iter->second.begin();
//                auto iterSetAddress = iter->second.begin();
//                long adress = (long) (*iterSetAddress)->getMemAdd();//the first address in the set
//                iterSetAddress++;
//                bool flagAdress = true;
//                if (setSize != 0) {
//                    if (((*iterSet)->getMemSize()) * setSize >= memSize) { //number of nodes are fine for merging
//
//                        for (int j = 1; j < setSize; ++j) {//check that address of nodes by order
//                            adress += ((*iterSetAddress)->getMemSize());
//                            if (adress != ((long) (*iterSetAddress)->getMemAdd())) {
//                                flagAdress = false;
//                                break;
//                            }
//                            iterSetAddress++;
//                        }
//                        if (flagAdress) {//nodes by orders
//                            FreeNode *fnlloc = (FreeNode *) malloc(sizeof(FreeNode));
//                            fn = new(fnlloc)FreeNode(memSize, FirstNodeAtSet->getMemAdd());
//                            for (int i = 0; i < countNodes; ++i) {
//                                iter->second.erase(iterSet++);//TODO mem leak
//                            }
//                            break; //while break after merge
//                        }
//                    }
//
//                }
//            }
//        }
//
//        countNodes*=2;
//        newSize /= 2;
