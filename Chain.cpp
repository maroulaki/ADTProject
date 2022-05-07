#include <Chain.h>
#include <iostream>
#include <exception>
using namespace std;

Chain::Chain() {
    first = 0;
    last = 0;
}

int Chain::Search(const int &x) const {
    // Locate x. Return position of x if found.
    // Return 0 if x not in the chain.
    ChainNode *current = first;
    int index = 1; // index of current
    while (current && current->data != x) {
        current = current->link;
        index++;
    }
    if (current) return index;
    return 0;
}


Chain & Chain::Insert(int k, const int &x) {
    // Insert x after the k'th element.
    // Throw OutOfBounds exception if no k'th element.
    // Pass NoMem exception if inadequate space.
    if (k < 0) {
        cout<<"Invalid k position"<<endl;
        throw __throw_range_error;
    }
    // p will eventually point to k'th node
    ChainNode *p;
    if (k == 0) {
        p = first;
    } else if (k == length) {
        p = last;
    } else {
        for (int index = 1; index < k && p; index++) {
            p = p->link; // move p to k'th
        }
    }
    
    if (k > 0 && !p) {
        cout<<"k'th element not found"<<endl; // no k'th
        throw __throw_range_error;
    }
    
    // insert
    ChainNode *y = new ChainNode; 
    y->data = x;
    if (k == 0) {
        // insert as first element
        y->link = NULL; 
        first = y;
    } else if (k == length) {
        y->link = NULL;
        p->link = y;
    } else {
        // insert after p
        y->link = p->link; 
        p->link = y;
    }
    return *this;
}