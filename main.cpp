#include <iostream>
#include "Heap.h"

int main() {
    
    Heap* h = new Heap(3);
    int steps;
    h->add(3, steps);
    h->add(12, steps);
    h->add(10, steps);
    h->add(20, steps);
    h->add(5, steps);
    h->add(6, steps);
    h->add(8, steps);
    h->add(18, steps);
    h->add(9, steps);

    h->print("",0,false);
    return 0;
}
