#include <iostream>
#include <string>
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
    
    int x = 0; //variable to store data
    cout<<"Length of the list:"<<endl;
    cin>>x;
    const int L_LENGTH = x;

    //Create a list and set the maximum length
    Chain L = Chain();
    L = L.setLength(L_LENGTH);

    //Create the histogram
    Histogram histogram = Histogram();
    
    for (int i = 0; i < L_LENGTH; i++) {
        x = random_element();
        L.Insert(i, x);
    }
    
    for (int i = 1; i < L_LENGTH; i++) {
        x = L.accessX(i);
        if (histogram.Exists(x)) {
            histogram.Increase(x);
        } else {
            histogram = histogram.Insert(x);
        }
    }
    
    string answer;
    cout<<"Print histogram? Y/N"<<endl;
    cin>>answer;
    if (answer == "Y") histogram.printHistogram();
   
    L.~Chain();
    histogram.~Histogram();

    return 0;
}