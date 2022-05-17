#include "MinHeap.h"
#include <exception>
#include "excpt.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap() {
    CurrentSize = 0;
    MaxSize = 0;
}

void MinHeap::Insert(const float &x) { 
    // Insert x into the Min heap.
    if (CurrentSize == MaxSize) {
        cout<<"Not enough space"<<endl; // no space
    }

    // find place for x
    // i starts at new leaf and moves up tree
    int i = ++CurrentSize;
    while (i != 1 && x < heap[i/2]) {
        // cannot put x in heap[i]
        heap[i] = heap[i/2]; // move element down
        i /= 2; // move to parent
    }
    heap[i] = x;
}


void MinHeap::DeleteMin(float &x) {
    // Set x to min element and delete
    // min element from heap.
    // check if heap is empty

    if (CurrentSize == 0) {
        cout<<"Hepa is empty"<<endl;// empty
    }
    x = heap[1]; // min element

    // restucture heap
    float y = heap[CurrentSize--]; // last element

    // find place for y starting at root
    // find place for y starting at root

    int i = 1, // current node of heap
    ci = 2; // child of i
    
    while (ci <= CurrentSize) {
        // heap[ci] should be smallest child of i 
        if (ci < CurrentSize && heap[ci] > heap[ci+1]) ci++;
        // can we put y in heap[i]?
        if (y <= heap[ci]) break; // yes
        // no
        heap[i] = heap[ci]; // move child up
        i = ci; 
        ci *= 2; // move down a level
    }
    heap[i] = y;
}

void MinHeap::Initialize(float a[], int size, int ArraySize) {
    // Initialize Min heap to array a.
    heap = a;
    CurrentSize = size;
    MaxSize = ArraySize;

    // make into a Min heap
    for (int i = CurrentSize/2; i >= 1; i--) {
        float y = heap[i]; // root of subtree

        // find place to put y
        int c = 2*i; // parent of c is target
        // location for y
        while (c <= CurrentSize) {
            // heap[c] should be larger sibling
            if (c < CurrentSize && heap[c] > heap[c+1]) c++;
            // can we put y in heap[c/2]?
            if (y <= heap[c]) break; // yes
            // no
            heap[c/2] = heap[c]; // move child up
            c *= 2; // move down a level
        }

        heap[c/2] = y;
    }
}

MinHeap::~MinHeap() { }