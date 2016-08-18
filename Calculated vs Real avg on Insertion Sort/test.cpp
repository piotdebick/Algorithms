//Piotr Debicki

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int insertion(int A[], int n) {
	int i, j, temp, numSteps = 0;
	A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++) {
		numSteps++;
		j = i;
		while (A[j] < A[j - 1]) { // swap
			numSteps++;
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
	return(numSteps);
}
void testInput(int n) {
	int bound = 5323;
	float tot_steps = 0, calc_avg = 0;
	int anArray[3500]; //change to 3500 to run all inputs
	srand(time(NULL));
	calc_avg = (pow(n, 2) / 4) + (3 * n / 4);
	for (int i = 0; i < 100000; i++) { //calculating real avg using montecarlo
		for (int j = 0; j <= n; j++) {
			anArray[j] = rand() % bound;
		}
		tot_steps += insertion(anArray, n);
	}
	cout << fixed << setprecision(1) << setw(10) << n << setw(25) << calc_avg << setw(25) << tot_steps / 100000 << endl;
}
int main() {
	cout << setw(10) << "Input" << setw(25) << "Calculated AVG" << setw(25) << "Real AVG" << endl;

	testInput(100);
	testInput(500);
	testInput(1000);
	testInput(2500);
	testInput(3000);
	testInput(3500);
	return 0;
}
