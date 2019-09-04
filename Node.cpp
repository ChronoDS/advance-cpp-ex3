//
// Created by Daniel Shema on 17/01/2018.
//

#include "Node.h"

Node::Node(void* mStartPtr): PtrToMemStart(mStartPtr) {}

Node::~Node(){}

void Node::setNext(Node* Next){
    this->Next = Next;
}
void Node::setMemStart(void* memStart){
    PtrToMemStart = memStart;
}
void Node::setSize(size_t size){
    this->size = size;
    std::cout << "in set size method: " << std::endl;
}

Node* Node::getNext(){
    return Next;
}
void* Node::getMemStart(){
    return PtrToMemStart;
}
size_t Node::getSize(){
    return size;
}



