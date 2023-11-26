/**
 * @file binary_search.cpp
 * @author Carson Gedeus (https://github.com/CGedeus)
 * @brief Binary search example using string
 * @version 0.1
 * @date 2023-11-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int binarySearch(int* array, int target, int high, int low)
{
    int mid = (high + low) / 2;

    if (high < low)
    {
        return 0;
    }

    if (target == array[mid])
    {
        return target;
    }
    if (target < array[mid])
    {
        high = mid - 1;
    }
    if (target > array[mid])
    {
        low = mid + 1;
    }
    
    return binarySearch(array, target, high, low);
}

int main(void)
{
    int input;
    int array[] = {2, 4, 12, 34, 54, 78, 89, 92, 101, 127};

    cout << "Enter wanted number: ";
    cin >> input;

    binarySearch(array, input, sizeof(array)/sizeof(array[0]), 0);

    return 0;
}