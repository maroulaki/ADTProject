#include "MaxHeap.h"
#include <exception>
#include "excpt.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap() {
    CurrentSize = 0;
    MaxSize = 0;
}

void MaxHeap::Insert(const float &x) { 
    // Insert x into the max heap.
    if (CurrentSize == MaxSize) {
        cout<<"Not enough memory"<<endl;// no space 
        return;
    }

    // find place for x
    // i starts at new leaf and moves up tree
    int i = ++CurrentSize;
    while (i != 1 && x > heap[i/2]) {
        // cannot put x in heap[i]
        heap[i] = heap[i/2]; // move element down
        i /= 2; // move to parent
    }
    heap[i] = x;
}

void MaxHeap::DeleteMax(float &x) {
    // Set x to max element and delete
    // max element from heap.
    // check if heap is empty

    if (CurrentSize == 0) {
        cout<<"Heap is empty"<<endl;
        return;
    }
    
    x = heap[1]; // max element

    // restucture heap
    float y = heap[CurrentSize--]; // last element

    // find place for y starting at root
    // find place for y starting at root

    int i = 1, // current node of heap
    ci = 2; // child of i
    
    while (ci <= CurrentSize) {
        // heap[ci] should be largest child of i
        if (ci < CurrentSize && heap[ci] < heap[ci+1]) ci++;
        // can we put y in heap[i]?
        if (y >= heap[ci]) break; // yes
        // no
        heap[i] = heap[ci]; // move child up
        i = ci; 
        ci *= 2; // move down a level
    }
    heap[i] = y;
}

void MaxHeap::Initialize(float a[], int size, int ArraySize) {
    // Initialize max heap to array a.
    heap = a;
    CurrentSize = size;
    MaxSize = ArraySize;
    // make into a max heap
    for (int i = CurrentSize/2; i >= 1; i--) {
        float y = heap[i]; // root of subtree

        // find place to put y
        int c = 2*i; // parent of c is target
        // location for y
        while (c <= CurrentSize) {
            // heap[c] should be larger sibling
            if (c < CurrentSize && heap[c] < heap[c+1]) c++;
            // can we put y in heap[c/2]?
            if (y >= heap[c]) break; // yes
            // no
            heap[c/2] = heap[c]; // move child up
            c *= 2; // move down a level
        }

        heap[c/2] = y;
    }
}

MaxHeap::~MaxHeap() { }
