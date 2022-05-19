#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>
#include <random>
using namespace std;
#include <functional>

default_random_engine generator;
chi_squared_distribution<float> my_distribution(0.5);
auto random_num = bind(my_distribution, generator);
//RNG as shown in the provided instruction


int main(){
	int temp_int; //temporarily storing numbers
	cout<<"What size do you want your heaps to be \n";
	cin>>temp_int;
	int const size = temp_int;

	MaxHeap maxheap = MaxHeap();
	MinHeap minheap = MinHeap();

	float* minheaparray = new float[size]; //creates the heaps
	float* maxheaparray = new float[size];

	maxheap.Initialize(maxheaparray,0,size); //initializes the heaps
	minheap.Initialize(minheaparray,0,size);

	float temp_float;
	for (int i = 0; i < size; i++) // inserts random numbers to the heaps
	{
		temp_float = random_num();
		maxheap.Insert(temp_float);
		minheap.Insert(temp_float);
	}
	
	float temp_float2 = 0;
	float MaxHeapMAX;	// the max from the max
	float MinHeapMIN;	// the smallest from the min
	float temp_float_sum; //sum for temp floats

	for (int i = 0; i < size-1; i++) {
		//Repeating the process of adding 2 floats together and 
		//inseting the sum back for both heaps
		maxheap.DeleteMax(temp_float);
		maxheap.DeleteMax(temp_float2);
		temp_float_sum = temp_float + temp_float2;
		maxheap.Insert(temp_float_sum);

		minheap.DeleteMin(temp_float);
		minheap.DeleteMin(temp_float2);
		temp_float_sum = temp_float + temp_float2;
		minheap.Insert(temp_float_sum);
	}

	maxheap.DeleteMax(MaxHeapMAX);
	minheap.DeleteMin(MinHeapMIN);

	if (MaxHeapMAX == MinHeapMIN) {
		cout<<"The max heap and the min heap create the same results \n";
	}
	else if (MaxHeapMAX > MinHeapMIN) {
		cout<<"The max heap sum is bigger than the min heap sum\n";
	}
	else {
		cout<<"The min heap sum is bigger than the max heap sum\n";
	}

	return 0;
}
