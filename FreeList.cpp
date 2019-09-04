//
// Created by Daniel Shema on 17/01/2018.
//

#include "FreeList.h"

FreeList::FreeList(){}
void FreeList::setHead(Node* head){
    this->head = head;
}
Node* FreeList::getHead(){
    return head;
}

void FreeList::add(Node* node){
    Node* h = head;

    if(h != nullptr){
        while(h->getNext() != nullptr){
            h = h->getNext();

        }
        h->setNext(node);
        return;
    }
    else {
        head = node;
    }
}

void FreeList::display() {
    Node* temp = head;

    std::cout << "Im in display" << std::endl;
    if(temp == nullptr){
        std::cout << "No Nodes" << std::endl;
        return;
    }
    while (temp->getNext()!= nullptr){
        std::cout << "|Node: " << temp->getMemStart() << "\n|Size: " << temp->getSize() << "\n   V" << std::endl;
        temp = temp->getNext();
    }
    if(temp->getNext() == nullptr && temp != nullptr){
        std::cout << "|Node: " << temp->getMemStart() << "\n|Size: " << temp->getSize() << std::endl;
    }
}

Node* FreeList::pop(size_t n){
    Node* temp = head;

    if(head == nullptr){
        std::cout << "No Nodes" << std::endl;
        return 0;
    }

    auto blockSize = (size_t*)(static_cast<char*>(temp->getMemStart()) - sizeof(size_t));

    if(*blockSize >= n){
        head = head->getNext();
        return temp;
    }

    while (temp->getNext()!= nullptr){
        Node* Next = temp->getNext();
        blockSize = (size_t*)(static_cast<char*>(Next->getMemStart()) - sizeof(size_t));
        if(*blockSize <= n){
            temp->setNext(Next->getNext());
            Next->setNext(nullptr);
            return Next;
        }
    }
    return nullptr;
}