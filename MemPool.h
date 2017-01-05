//
// Created by ofir on 1/3/17.
//

#ifndef EX2CPP_MEMPOOL_H
#define EX2CPP_MEMPOOL_H


class MemPool {

public:
    static MemPool* getInstance(size_t poolSize);
    static MemPool* getInstance();
    size_t  get_totalByteInUse() const;
    char *get_currentLocation() const;
    void set_totalByteInUse(size_t _totalByteInUse);
    void set_currentLocation(char *_currentLocation);
    size_t get_poolSize() const;



private:
MemPool(size_t poolSize);
size_t  _poolSize;
size_t _totalByteInUse;
char* _pool;
char* _currentLocation;
static MemPool* _memPoolInstance;
};


#endif //EX2CPP_MEMPOOL_H
