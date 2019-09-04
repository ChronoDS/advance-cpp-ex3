//
// Created by Daniel Shema on 17/01/2018.
//

#ifndef CPPA_EX3_FREELIST_H
#define CPPA_EX3_FREELIST_H

#include "Node.h"

class FreeList{

private:
    Node* head;
    size_t listSize;

public:
    FreeList();
    void setHead(Node* head);
    Node* getHead();
    void add(Node* node);
    Node* pop(size_t n);
    void display();



};
#endif //CPPA_EX3_FREELIST_H
