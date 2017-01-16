//
//Created by boaz_bahat on 1/2/17.
//

#include "FreeNode.h"

FreeNode::FreeNode(size_t memSize, char *memAdd) : memSize(memSize), memAdd(memAdd) {}

/**
   *FreeNode constructor
   */
size_t FreeNode::getMemSize() const {
    return memSize;
}

/**
       *@return address
       */
char *FreeNode::getMemAdd() const {
    return memAdd;
}

std::ostream &operator<<(std::ostream &os, const FreeNode &node) {
    os << "memSize: " << node.memSize << " memAdd: " << (void*)node.memAdd;
    return os;
}

FreeNode::FreeNode() {}

