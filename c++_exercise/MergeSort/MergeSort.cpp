// Carson Gedeus, MergeSort.cpp
// Merge Sort Algorithm

#include <iostream>
#include <ctime>

#define SIZE 10

using namespace std;

void printArray(int* array)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int* merge(int* array, int low, int mid, int high)
{
	int leftSize = (mid - low + 1);
	int rightSize = (high - mid);


}

int* mergeSort(int* array, int low, int high)
{
	if (low >= high)
	{
		return array;
	}
	
	auto mid = (low + high) / 2;

	mergeSort(array, low, mid);
	mergeSort(array, (mid + 1), high);

	return merge(array, low, mid, high);
}
int main(void)
{
	int i;
	int low = 0;
	int high = SIZE;
	int mid = (low + high) / 2;
	int array[SIZE];

	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 50;
	}

	cout << "Current Array: ";
	printArray(array);
	mergeSort(array, low, high);

	return 0;
}