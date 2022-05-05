#include <iostream>
#include <Chain.h>
#include <exception>
#include <random>
using namespace std;

template<class T>
bool Chain<T>::IsEmpty() const {
    first == 0;
}

template<class T>
int Chain<T>::Length() const {
    if (first == 0) {
        return 0;
    } else {
        ChainNode<T> *current = first;
        int len=1;
        while (current->link != NULL) {
            len++;
            current = current->link;
        }
        return len;
    }
}

template<class T>
bool Chain<T>::Find(int k, T &x) const {
    if (k<1) { return false; }
    else {
        ChainNode<T> *current = first;
        int index=1;
        while ((index < k)&&(current->link != NULL)) {
            current = current->link;
            index++;
        }
        if (current) {
            x = current->data; 
            return true;
        }
        return false; // no k'th element
            }


}


