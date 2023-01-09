//
// Created by Luka Radoicic on 21.12.22..
//

#ifndef ASP2_DZ3_HEAP_H
#define ASP2_DZ3_HEAP_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Heap {
    int m; // m parameter of the heap
    vector<int> arr; // vector instead of an array
public:
    Heap(int m){
        this->m = m;
        // this->arr = new vector<int>;
    }

    ~Heap(){}




    // heap must be created empty and elements may be added afterwards

    // Parent of heap[i] is heap[ (i - 1) / k ]
    // Children of heap[i] are heap[ k * i + 1 ], heap[ k * i + 2 ], ... , heap[ k * i + k]

    Heap* init(int m);

    void add(int elem, int &steps);
    
    int get(); // get min element
    
    int deleteMin(int &steps); // delete min element
    
    void convertTo(int newM);
    
    void unite(Heap* h, int &steps); // word union is reserved
    
    // override operator<<
    
    void destroy();
    
    int deleteElem(int &steps, int elem); // delete specific element

    bool isEmpty(){ return this->arr.size() == 0; }

    void filterUp(int index);

    void filterDown(int index);

    int getParentIndex(int childIndex);

    int getSize();

    int getElement(int index);

    void clean();

    void print(string prefix, int index, bool first);
};


#endif //ASP2_DZ3_HEAP_H
