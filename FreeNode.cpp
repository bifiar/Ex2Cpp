//
// Created by ofir on 1/4/17.
//

#include "FreeNode.h"

FreeNode::FreeNode(size_t memSize, char *memAdd) : memSize(memSize), memAdd(memAdd) {}

size_t FreeNode::getMemSize() const {
    return memSize;
}

char *FreeNode::getMemAdd() const {
    return memAdd;
}

