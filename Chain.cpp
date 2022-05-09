#include "Chain.h"
#include <iostream>
using namespace std;

//Constructor
Chain::Chain() {                    
    first = 0;
    length = 0;
    maxL = 100;     //in case no different value is given with setLength()
}


int Chain::accessX(int k) const {
    if (k > 0 && k <=length) { 
        ChainNode *p;
        p = first;
        for (int i = 0; i < k && p->link != NULL; i++) {
            p = p->link;    //move p to k'th element
        }
        return p->data;     //return data
    } else {
        cout<<"Invalid position";   //error if k is illegal
    }
}

Chain &Chain::setLength(const int& x) {
    if (x > 0) {
        maxL = x;   //if x is a legal length, set maximum length of list
        return *this;
    }
}

void Chain::Insert(int k, const int& x) {
    // Insert x after the k'th element.
    // Pass NoMem exception if inadequate space.
    if ((k < 0) || (k >= length+1)) {
        cout<<"Invalid position"<<endl;
        return;
    } else if (length == maxL) {
        cout<<"Not enough space"<<endl;
        return;
    }
    // p will eventually point to k'th node
    ChainNode *p;
    p = first;
    for (int index = 1; (index < k && p->link != NULL); index++) {
        p = p->link; // move p to k'th
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
    length++;   //increase length
}

//Destructor
Chain::~Chain() { }