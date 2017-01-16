//
//Created by boaz_bahat on 1/2/17.
//

#ifndef EX2CPP_MEMPOOL_H
#define EX2CPP_MEMPOOL_H


class MemPool {

public:
    /**
    *this function is for create a MemPool singelton
     * @param poolSize
    */
    static MemPool* getInstance(size_t poolSize);

    static MemPool* getInstance();
    size_t  get_totalBitUse() const;

    /**
   *this function is for get current adderess
     * @return address
   */
    char *get_currentLocation() const;

    /**
 *this function is for set the size of bites in use
   * @param _totalBitUse
 */
    void set_totalBitUse(size_t _totalBitUse);


    void set_currentLocation(char *_currentLocation);
    size_t get_poolSize() const;



private:
MemPool(size_t poolSize);
size_t  _poolSize;
size_t _totalBitUse;
char* _pool;
char* _currentLocation;
static MemPool* _memPoolInstance;
};


#endif //EX2CPP_MEMPOOL_H
