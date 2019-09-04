//
// Created by daniel Shema on 06/01/2018.
//


#ifndef CPPA_EX3_MEMPOOL_H
#define CPPA_EX3_MEMPOOL_H

#include <iostream>

class MemPool{

private:
    static MemPool* instance;
    static void* startPtr;
    static void* endPtr;
    static size_t alocSize;
    MemPool();


public:
    ~MemPool();
    static MemPool* getInstance(size_t size=0);
    void setStartPtr(void* newptr);
    void* getStartPtr();
    void* getEndPtr();
    size_t size();
};
#endif //CPPA_EX3_MEMPOOL_H
