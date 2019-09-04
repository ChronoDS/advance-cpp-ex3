//
// Created by Daniel Shema on 17/01/2018.
//

#ifndef CPPA_EX3_NODE_H
#define CPPA_EX3_NODE_H

#include <iostream>

class Node{

private:
    Node* Next; // Next Node is For list of free Memory Nodes;
    void* PtrToMemStart; // starting point of usable memory;
    size_t size; // Size Of memory to use;

public:
    Node(void* mStartPtr);
    ~Node();
    void setNext(Node* Next);
    void setMemStart(void* memStart);
    void setSize(size_t size);

    Node* getNext();
    void* getMemStart();
    size_t getSize();


};
#endif //CPPA_EX3_NODE_H
