#include <Chain.h>
#include <exception>
using namespace std;

template<class T> 
int Chain<T>::Search(const T &x) const {
    // Locate x. Return position of x if found.
    // Return 0 if x not in the chain.
    ChainNode<T> *current = first;
    int index = 1; // index of current
    while (current && current->data != x) {
        current = current->link;
        index++;
    }
    if (current) return index;
    return 0;
}

template<class T> 
Chain<T> & Chain<T>::Insert(int k, const T &x) {
    // Insert x after the k'th element.
    // Throw OutOfBounds exception if no k'th element.
    // Pass NoMem exception if inadequate space.
    if (k < 0) throw OutOfBounds();
    // p will eventually point to k'th node
    ChainNode<T> *p = first;
    for (int index = 1; Index < k && p; index++)
    p = p->link; // move p to k'th
    if (k > 0 && !p) throw OutOfBounds(); // no k'th
    // insert
    ChainNode<T> *y = new ChainNode<T>; 
    y->data = x;
    if (k) {
        // insert after p
        y->link = p->link; 
        p->link = y;
    } else {
        // insert as first element
        y->link = first; 
        first = y;
    }
    return *this;
}