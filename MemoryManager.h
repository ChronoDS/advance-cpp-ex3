//
// Created by daniel Shema on 06/01/2018.
//
#ifndef CPPA_EX3_MEMORYMANAGER_H
#define CPPA_EX3_MEMORYMANAGER_H

#include <cstdlib>
#include "MemPool.h"
#include "FreeList.h"

class MemoryManager{

private:
    MemPool* mp;
    FreeList* fl;
    size_t lSize;
    Node* lHead;


public:
    MemoryManager();
    ~MemoryManager();
    void init(size_t size);
    void* assignMemory(size_t size);
    void releaseMemory(void* memPtr);

};
#endif //CPPA_EX3_MEMORYMANAGER_H
