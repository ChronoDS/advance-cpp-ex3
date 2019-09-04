//
// Created by daniel Shema on 06/01/2018.
//
#include "MemPool.h"

MemPool* MemPool::instance = nullptr;
void* MemPool::startPtr = nullptr;
void* MemPool::endPtr = nullptr;
size_t MemPool::alocSize;

MemPool::MemPool() {}

MemPool::~MemPool() {
}

MemPool* MemPool::getInstance(size_t size) {
    if(instance== nullptr){
        alocSize = size;
        void* temp = malloc(size);
        instance = new(temp)MemPool();
        startPtr = (void*)(char*)(instance+ sizeof(instance));
        endPtr = (void*)((char*)instance+size);
    }
    return instance;
}

void* MemPool::getEndPtr() {
    return endPtr;
}

void* MemPool::getStartPtr() {
    return startPtr;
}

void MemPool::setStartPtr(void *newptr) {
    startPtr = newptr;
}

size_t MemPool::size(){
    return alocSize;
}

