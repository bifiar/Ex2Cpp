//
// Created by ofir on 1/4/17.
//

#ifndef EX2CPP_FREENODE_H
#define EX2CPP_FREENODE_H


#include <glob.h>

class FreeNode {
public:
    FreeNode(size_t memSize, char *memAdd);

    size_t getMemSize() const;

    char *getMemAdd() const;

private:
    size_t memSize;
    char* memAdd;
};


#endif //EX2CPP_FREENODE_H
