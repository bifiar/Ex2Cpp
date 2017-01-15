//
// Created by ofir on 1/4/17.
//

#ifndef EX2CPP_FREENODE_H
#define EX2CPP_FREENODE_H


#include <glob.h>
#include <ostream>

class FreeNode {

public:
    FreeNode(size_t memSize, char *memAdd);

    FreeNode();

    size_t getMemSize() const;

    char *getMemAdd() const;

    friend std::ostream &operator<<(std::ostream &os, const FreeNode &node);

private:
    size_t memSize;
    char* memAdd;
};


#endif //EX2CPP_FREENODE_H
