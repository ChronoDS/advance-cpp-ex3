//
// Created by daniel Shema on 06/01/2018.
//

#include <cmath>
#include <cassert>
#include "MemoryManager.h"


MemoryManager::MemoryManager(){}
MemoryManager::~MemoryManager(){

}

void MemoryManager::init(size_t size){

    mp = mp->getInstance(size);
    lSize = std::ceil(std::log(mp->size()));
    if(lSize*sizeof(FreeList) > mp->size()){
        std::cout << "Initialization Failed - Not Enough Memory(fl)" << std::endl;
        assert(0);
    }
    else{
        std::cout << "Initialization Succeed - Memory Set" << std::endl;
        fl = new FreeList[lSize];
    }
}

void* MemoryManager::assignMemory(size_t size){
    Node* temp;
    std::cout << "in assign" << std::endl;

    if(mp->size() >= size) {
        for (size_t i = std::floor(log2(size)); fl != nullptr && i < lSize; i++) {
            if (fl[i].getHead() != nullptr) {
                temp = fl[i].pop(size);
                if (temp != nullptr) {
                    std::cout << "Retrieving Node.." << std::endl;
                    temp->setNext(lHead);
                    lHead = temp;
                    return temp->getMemStart();
                }
            }
        }
    }
    else{
        std::cout << "Memory Assignment Error - Not Enough Space." << std::endl;
        return 0;
    }
    void* mChunk = mp->getStartPtr();
    new(mChunk)size_t(size);
    mp->setStartPtr(static_cast<void*>(static_cast<char*>(mChunk) + sizeof(size_t) +size)+size);
    return mChunk;
}

void MemoryManager::releaseMemory(void* memPtr){
    size_t* mSize = (size_t*)(static_cast<char*>(memPtr));
    size_t whereInFL = std::floor(std::log2(*mSize));
    Node* temp;
    if(lHead != nullptr){
        temp = lHead;
        lHead = lHead->getNext();
        fl[whereInFL].add(temp);
    }
    else{
        if(mp->getInstance()->size() < sizeof(Node)){
            std::cout << "Memory Release Error - Unable to Release Memory, unable to assign memory for node(fl)" << std::endl;
            assert(0);
        }
        temp = new(mp->getInstance()->getStartPtr()) Node(memPtr);
        mp->getInstance()->setStartPtr(static_cast<char*>(mp->getInstance()->getStartPtr()) + sizeof(Node));
        fl[whereInFL].add(temp);
    }
}