#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>
#include <random>
#include <functional>
/* I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
 I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
 ░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄░░░░░░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄░░░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█░░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░░█░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░▄▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░░█░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
█░▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒░█ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
█░▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░█░▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░█░░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░█░░░░██░░▀█▄▄▄█▄▄█▄████░█░░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░█░░░░▀▀▄░█░░░█░█▀██████░█░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░░▀▄░░░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█░░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░▒░░░█░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░░░░█░ I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO I HATE VISUAL STUDIO
░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░░░░█░░ WHY CAN'T IT JUST LET ME COMPILE NON SOLUTION FILES LIKE A NORMAL IDE
*/

std::default_random_engine generator;
std::chi_squared_distribution<float> my_distribution(0.5);
auto random_num = std::bind(my_distribution, generator);
//RNG as shown in the provided instruction


int main(){
	int size;
	std::cout << "What size do you want your heaps to be \n";
	std::cin >> size;

	MaxHeap* maxheap = new MaxHeap;
	MinHeap* minheap = new MinHeap;

	float* minheaparray = new float[size]; //creates the heaps
	float* maxheaparray = new float[size];



	maxheap->MaxHeap::Initialize(maxheaparray, 0 , size); //initializes the heaps
	minheap->MinHeap::Initialize(minheaparray, 0 , size);

	float tem;
	for (int i = 0; i < size; i++) // inserts random numbers to the heaps
	{
		tem = random_num();
		maxheap->MaxHeap::Insert(tem);
		minheap->MinHeap::Insert(tem);
	}
	float tem2 = 0;
	float maxheapmax;// the max from the max
	//go through the max heap
	for (int i = 0; i < size/2; i++)
	{
		if (i % 2 == 0)// picks the first max when i is odd
		{
			maxheap->MaxHeap::DeleteMax(tem);
		}
		else { // the second when tis even and it adds them
			maxheap->MaxHeap::DeleteMax(tem2);
			tem = tem + tem2;
			maxheap->MaxHeap::Insert(tem);
		}
	}// since we only add between them the final result will be the biggest
	if (!(tem > tem2)) {
		float maxheapmax = tem2;
	}
	else {
		float maxheapmax = tem;
	}



	float minheapmax;// the biggest from the min
	//go through the min heap
	for (int i = 0; i < size / 2; i++)
	{
		if (i % 2 == 0)
		{
			minheap->MinHeap::DeleteMin(tem);
		}
		else {
			minheap->MinHeap::DeleteMin(tem2);
			tem = tem + tem2;
			minheap->MinHeap::Insert(tem);
		}
	}
	if (!(tem > tem2)) {
		float minheapmax = tem2;
	}
	else {
		float minheapmax = tem;
	}



	if (maxheapmax == minheapmax) {
		std::cout << "The max heap and the min heap create the same results \n";
	}
	else if (maxheapmax > minheapmax) {
		std::cout << "The max heap greatest element is bigger than the min heap greatest element\n";
	}
	else {
		std::cout << "The min heap greatest element is bigger than the max heap greatest element\n";
	}






	return 0;
}
