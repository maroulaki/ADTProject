#include <iostream>
#include <random>
#include <functional>
#include "Chain.h"
#include "Histogram.h"
using namespace std;

int main() {
    //Random generator
    default_random_engine generator;
    uniform_int_distribution<int> data_element_distribution(0, 100);
    auto random_element = bind(data_element_distribution, generator);

    //Create a list and set the maximum length
    Chain L = Chain();
    L = L.setLength(100);
    cout<<100<<endl;

    //Create the histogram
    Histogram histogram = Histogram();
    for (int i = 0; i<100; i++) {
        int x = random_element();
        cout<<"rand:"<<x<<endl;
        L.Insert(i, x);
        cout<<histogram.Exists(x)<<endl;
        if (histogram.Exists(x)) {
            histogram.Increase(x);
        } else {
            histogram = histogram.Insert(x);
        }
    }
    histogram.printHistogram();
    
    L.~Chain();
    histogram.~Histogram();

    return 0;
}