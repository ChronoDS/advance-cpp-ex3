#include <iostream>
#include "MemPool.h"
#include "FreeList.h"
#include "MemoryManager.h"
#include "Complex.h"

static MemoryManager mManager;

int main(int argc, char* argv[]){
    size_t t = 1024;

    mManager.init(t);
//    MemPool* mp;
//    mp->getInstance(t);
//    std::cout << "&mp: " << &mp << std::endl;
//    std::cout << "mp: " << (void*)mp << std::endl;
//
//    std::cout << "get instance: " << (void*)mp->getInstance(100) << std::endl;
//    std::cout << "start ptr: " << (void*)mp->getStartPtr() << std::endl;
//    std::cout << "end ptr: " << (void*)mp->getEndPtr() << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Nodes Tests and insertion tests: \n----" << std::endl;
    FreeList* fl = new FreeList();
    std::cout << "fl: "<< (void*)fl << std::endl;
    Complex* c1 = new Complex(5,2);
//    fl->add(n1);
//    fl->display();
//    Node* n2;
//    std::cout << "Final Before stop printing: \n----" << std::endl;
    std::cout << "c1: " << c1 << std::endl;
    Complex* c2 = new Complex(2,5);
    std::cout << "c2: " << c2 << std::endl;
    Complex* c3 = new Complex(1,1);
    std::cout << "c3: " << c3 << std::endl;
    Complex* c4 = new Complex(4,3);
    std::cout << "c4: " << c4 << std::endl;
//    std::cout << "n1 size: " << c1->getSize() << std::endl;
//    std::cout << "n1->next: " << c1->getNext() << std::endl;
//    std::cout << "fl->head: " << cl->getHead() << "\n----" << std::endl;
//    std::cout << "n2: " << (void*)n2 << std::endl;
//    n2->setSize(7);
//    std::cout << "now at stadium" << std::endl;
//    fl->add(n2);
//    std::cout << "Is the second addition fine?" << std::endl;
//    std::cout << "here" << std::endl;


    Complex* c5 = new Complex();
    std::cout << "c5: " << c5 << std::endl;

    Complex* c6 = new Complex();
    std::cout << "c6: " << c6 << std::endl;


    fl->display();

    return 0;
}


void* operator new (size_t size) {
    std::cout << "Test New Overload" << std::endl;
    std::cout << size << std::endl;
    void* mem = mManager.assignMemory(size);
    return mem;
}

void* operator new[ ] (size_t size){
    std::cout << "Test New[] Overload" << std::endl;
    void* mem = mManager.assignMemory(size);
    return mem;
}


void operator delete (void* pointerToDelete) {
    std::cout << "Test Delete Overload" << std::endl;
    mManager.releaseMemory(pointerToDelete);
}

void operator delete[ ] (void* arrayToDelete) {
    std::cout << "Test Delete[] Overload" << std::endl;
    mManager.releaseMemory(arrayToDelete);
}