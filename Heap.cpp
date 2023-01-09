//
// Created by Luka Radoicic on 21.12.22..
//

#include "Heap.h"

Heap *Heap::init(int m)
{
    Heap* h = new Heap(m);
}

void Heap::add(int elem, int &steps) // brojanje koraka kroz steps 
{
    arr.push_back(elem);
    filterUp(arr.size() - 1);
}

int Heap::get() 
{ 
    return arr[0]; 
}

int Heap::deleteMin(int &steps)
{
    int min = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    if (!arr.empty()){
        filterDown(0);
    }
    return min;
}

void Heap::convertTo(int newM)
{
    m = newM;
    clean();
}

void Heap::unite(Heap* h, int &steps)
{
    for (int i = 0; i < h->getSize(); i++){
        arr.push_back(h->getElement(i));
    }
    clean();
}

void Heap::destroy()
{
    delete this;
}

void Heap::filterDown(int index){
    vector<int> children;
    while(true){
        for (int i = 0; i < m; i++){
            if (m * index + i < arr.size()) children[i] = m * index + i;
            else children[i] = -1; 
        }
        int minChild = 0x7fffffff;
        int minChildIndex;

        for (int i = 0; i < m; i++){
            if(children[i] != -1 && arr[children[i]] < minChild){
                minChildIndex = children[i];
                minChild = arr[children[i]];
            }
        }

        if (minChild == 0x7fffffff) break;

        if (arr[index] < arr[minChildIndex]) {
            int temp = arr[index];
            arr[index] = arr[minChildIndex];
            arr[minChildIndex] = temp;
        }

        index = minChildIndex;
    }
}

void Heap::filterUp(int i)
{
    if (i != 0) return;
    int par = getParentIndex(i);
    int temp = 0;
    while (arr[par] > arr[i]){
        temp = arr[par];
        arr[par] = arr[i];
        arr[i] = temp;
        i = par;
        par = getParentIndex(i);
   }
}

int Heap::getParentIndex(int childIndex)
{
    return (childIndex == 0)? 0 : (childIndex - 1) / m;
}

int Heap::getSize()
{
    return arr.size();
}

int Heap::getElement(int index)
{
    return arr[index];
}

void Heap::clean() // cleans up an array so it satisfies heap property
{
    for (int i = arr.size() - 1; i > 0; i--){
        int parentI = getParentIndex(i);
        if (arr[i] < arr[parentI]){
            int temp = arr[i];
            arr[i] = arr[parentI];
            arr[parentI] = temp;
        }
    }
}

void Heap::print(string prefix, int index, bool first) // ("", 0, false)
{
    cout << prefix;
    cout << (first? "|--" : "'--");
    cout << arr[index] << endl;
    for (int i = 0; i < arr.size(); i++){
        print(prefix + (first? "|   " : "    "), m * index + i, (i == 0));
    }
}
