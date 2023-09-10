#include <iostream>

#define SIZE 11

using namespace std;

int BinarySearch(int* array, int item)
{
	int low = 0;
	int high = SIZE;
	int mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (array[mid] == item)
		{
			cout << array[mid] << " was found at index " << mid;
			return mid;
		}
		else if (array[mid] > item)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}

int main(void)
{
	int array[SIZE] = { 11, 13, 22, 24, 33, 34, 38, 45, 47, 55, 88 };
	int item;

	cout << "Enter item to search for: ";
	cin >> item;

	BinarySearch(array, item);

	return 0;
}