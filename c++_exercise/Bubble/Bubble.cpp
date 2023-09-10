// Carson Gedeus, 10/03/2022
// Bubble sort algorithm Bubble.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *bubbleSort(int array[], int length) {

	int i;
	int tmp;

	// BASE CASE
	if (length == 1) {
		return array;
	}

	for (i = 0; i < (length - 1); i++) {

		if (array[i] > array[i + 1]) {
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
		}
	}

	length--;

	bubbleSort(array, length);
}

void printIt(int array[], int length) {

	int i;

	cout << "Sorted: ";
	for (i = 0; i < (length - 1); i++)
		cout << array[i] << " ";

	cout << endl;
}

int main(void) {

	int i, length;
	int *ptr, *array;

	srand(time(NULL));
	length = rand() % 100;

	array = new int[length];

	for (i = 0; i < length; i++) {
		array[i] = rand() % 100;
	}

	ptr = bubbleSort(array, length);
	printIt(ptr, length);
	return 0;
}