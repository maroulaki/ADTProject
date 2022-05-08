#include "Histogram.h"
#include <iostream>
#include <stdio.h>
using namespace std;


Histogram::Histogram() {
    first = 0;
    last = 0;
}

bool Histogram::Exists(int x) const {
    if (last == 0) return false; //histogram is empty
    HistoNode *ptr;
    ptr = first;
    while (ptr && ptr->data < x) {
        ptr = ptr->link;
    }
    if (ptr->data == x) {
        return true; //return pointer to the element
    } else {
        return false; //element does not exist
    }
}


void Histogram::Increase(int x) {
    HistoNode *ptr;
    ptr = first;
    while (ptr && ptr->data < x) {
        ptr = ptr->link;
    }
    if (ptr->data == x) {
        ptr->times++;
        return;
    }
    return;
}

Histogram &Histogram::Insert(int x) {
    HistoNode *h = new HistoNode();
    h->data = x;
    h->times = 1;
    if (first == 0) {
        //first element in the histogram
        h->link = first;
        first = h;
        last = h;
    } else if (first->data > x) {
        //insert before first element
        h->link = first;
        first = h;
    } else if (last->data < x) {
        //insert at the end of the histogram
        h->link = NULL;
        last->link = h;
        last = h;
    } else {
        HistoNode *p;
        HistoNode *next;
        p = first;
        next = p->link;
        if (next != 0) {
            while (p && next->data < x) {
                p = p->link;
                next = p->link;
                if (next == 0) {
                    break;
                }
            }
        }
       
        //insert between the largest number smaller than x
        //and the smallest number larger than x;
        h->link = p->link;
        p->link = h;
    }
        
    return *this;
}

void Histogram::printHistogram() const {
    cout<<"Current histogram"<<endl;
    if (first == 0) {
        cout<<"histogram is empty"<<endl;
        return;
    } else {
        HistoNode *current;
        current = first;
        cout<<"Head->";
        while(current) {
            cout<<"["<<current->data<<"|"<<current->times<<"]->";
        }
        cout<<"NULL"<<endl;
    }
}

Histogram::~Histogram() { }
