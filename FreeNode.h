//
//Created by boaz_bahat on 1/2/17.
//

#ifndef EX2CPP_FREENODE_H
#define EX2CPP_FREENODE_H


#include <glob.h>
#include <ostream>

class FreeNode {

public:
    /**
    *FreeNode constructor
    */
    FreeNode(size_t memSize, char *memAdd);
    /**
       *defult  constructor
       */
    FreeNode();

    size_t getMemSize() const;

    /**
       *@return address
       */
    char *getMemAdd() const;

    friend std::ostream &operator<<(std::ostream &os, const FreeNode &node);

private:
    size_t memSize;
    char* memAdd;
};


#endif //EX2CPP_FREENODE_H
