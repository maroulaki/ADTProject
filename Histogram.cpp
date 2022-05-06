#include <Histogram.h>
#include <exception>
using namespace std;

template<class T> 
Histogram<T>::Histogram() {
    first = 0;
    last = 0;
}

template<class T> 
HistoNode<T>* &Histogram<T>::Exists(const T &x) const {
    if (last == 0) return 0; //histogram is empty
    HistoNode<T> ptr* = first;
    while (ptr && ptr->data < x) {
        ptr = ptr->link;
    }
    if (ptr->link == x) {
        return ptr; //return pointer to the element
    } else {
        return 0; //element does not exist
    }
}

template<class T> 
void Histogram<T>::Increase(const HistoNode<T> *ptr) {
    ptr->times = times++; //add to the number of times a number is found, using a pointer to that Histonode
}

template<class T> 
int Histogram<T>::getMax() const {
    return last->data; //return the max number in the histogram, using the last Histonode pointer
}

template<class T> Histogram<T> &Histogram<T>::Insert(const T &x) {
    HistoNode<T> *h = new HistoNode();
    h->data = x;
    h->times = 1;
    if (last == 0) {
        h->link = 0;
        first = h;
        last = h;
    } else {
        
    }
}


