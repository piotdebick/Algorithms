// Piotr Debicki
// Sorting Algorithm time test

#include "merge.h"
#include "insertion.h"
#include "heapSort.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

void runAlgorithms(int size) {
	//call both sorts
	int * anArray = new int[size];
	int * anotherArray = new int[size];
	int * heapArray = new int[size];
	for (int i = 0; i < size; i++) { // one set of rand nums for sorts
		anArray[i] = rand();
		anotherArray[i] = anArray[i];
		heapArray[i] = anArray[i];
	}
	//start merge sort
	clock_t mergeTime_start = clock();
	merge_sort(anArray, 0, size-1);
	//time for merge
	clock_t mergeTime_end = clock() - mergeTime_start;

	//start insertion sort
	clock_t insertionTime_start = clock();
	insertion_sort(anotherArray, size - 1);
	//time for insertion
	clock_t insertionTime_end = clock() - insertionTime_start;

	//start insertion sort
	clock_t heapSortTime_start = clock();
	heapSort(heapArray, size - 1);
	//time for insertion
	clock_t heapSortTime_end = clock() - heapSortTime_start;



	cout << setw(10) << fixed << setprecision(2) << size << setw(20) <<
		(float)insertionTime_end / CLOCKS_PER_SEC << setw(15) <<
		(float)mergeTime_end / CLOCKS_PER_SEC << setw(20) <<
		(float)heapSortTime_end / CLOCKS_PER_SEC << endl;

	delete[]anArray; // free mem
	delete[]anotherArray;
	delete[]heapArray;
}

int main()
{
	cout << setw(10) << "Input Size" << setw(20) << "Insertion Time" << setw(15) << "Merge Time" << setw(20) << "Heapsort Time"<< endl;
	runAlgorithms(100);
	runAlgorithms(1000);
	runAlgorithms(10000);
	runAlgorithms(50000);
	runAlgorithms(100000);
	runAlgorithms(200000);

	return 0;
}
