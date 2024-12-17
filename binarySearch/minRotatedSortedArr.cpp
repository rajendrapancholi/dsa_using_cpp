/**********************
Program Name        : Find the index of minimum element in the array.
Author              : Rajendra Pancholi
Date of creation    : 17/12/2024
Organization        : NIT Patna
***********************/
/**********************
 * A rotated sorted array is a sorted array on which rotation opearation has been performed some number of times. Given a rotated sorted array, Find the index of minimum element in the array. Follow 0-based indexing.
 * It is guaranteed that all the elements in the array are unique.
 * Input: array = [3, 4, 5, 1, 2]
 * Output: 3
 ***********************/
#include <iostream>
#include <vector>
using namespace std;

int minSortedRotatedArr(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int mid = 0;
    if (arr[low] < arr[high])
    {
        return low;
    }

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
            return mid + 1;
        if (arr[mid] < arr[mid - 1])
            return mid;
        if (arr[mid] > arr[low])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{

    // vector<int> arr = {3, 4, 5, 1, 2};
    // vector<int> arr = {2, 3, 4, 5, 1};
    vector<int> arr = {4, 5, 1, 2, 3};
    // vector<int> arr = {7, 8, 9, 2, 3, 4, 5, 6};
    int minIdx = minSortedRotatedArr(arr);
    cout << "Minimum element at: " << minIdx << endl;
    return 0;
}