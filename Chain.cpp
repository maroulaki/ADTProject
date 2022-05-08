#include <Chain.h>
#include <iostream>
#include <exception>
using namespace std;

Chain::Chain() {
    first = 0;
    last = 0;
}

Chain &Chain::setLength(const int& x) {
    if (x > 0) {
        maxL = x;
    }
}

Chain & Chain::Insert(int k, const int &x) {
    // Insert x after the k'th element.
    // Throw OutOfBounds exception if no k'th element.
    // Pass NoMem exception if inadequate space.
    if ((k < 0) || (k >= length+1)) {
        cout<<"Invalid k position"<<endl;
        return;
    } else if (length == maxL) {
        cout<<"Not enough space"<<endl;
        return;
    }
    // p will eventually point to k'th node
    //-------------------------------------
    // according to k value, there is the option to move p directly 
    // to the first or the last node for insertion
    ChainNode *p;
    
    if ((k > 0) && (k < length)) {
        for (int index = 1; index < k && p; index++) {
            p = p->link; // move p to k'th
        }
    }
    
    if (k > 0 && !p) {
        cout<<"k'th element not found"<<endl; // no k'th
        return;
    }
    
    
    // insert
    ChainNode *y = new ChainNode; 
    y->data = x;
    if (k == 0) {
        // insert as first element
        y->link = first; 
        first = y;
    } else if (k == length) {
        //insert after last element
        y->link = NULL;
        p->link = y;
    } else {
        // insert after p
        y->link = p->link; 
        p->link = y;
    }
    return *this;
}