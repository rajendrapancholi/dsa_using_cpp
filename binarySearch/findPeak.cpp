/**********************
Program Name        : Find the peak element in the given unsorted array.
Author              : Rajendra Pancholi
Date of creation    : 26/01/2025
Organization        : NIT Patna
***********************/
/***********************
 * A peak element is an element that is strictly greater than its neighbors. Given a 0-indexed interger array nums, find a peak element, and return its index if the array contains multiple peaks, return the index to any of the peaks, You may imagine that nums[-1]=nums[n]=-infite. In other words, and element is always considered to be strictly greater than a neightbor that is outside the array.
 * Input: arr = [1,2,1,2,6,10,3]
 * Output: Either index 1 or index 5 are the correct output. At index 1,2 is the peak element and at index 5, 10 is the peak element.
 ***********************/

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> arr)
{
    int left = 0, n = arr.size();
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // if array of length is 2
        if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
                return 0;
            else
                return 1;
        }
        // if mid, pints to the last of the array
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return n - 1;
            else
                return n - 2;
        }
        else
        {
            // if mountain
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            // left (context of mid) part of the array will be discart
            else if (arr[mid] > arr[mid - 1])
                left = mid + 1;
            // right(context of mid) part of the array will be discart
            else
                right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 1, 2, 6, 10, 3};
    // vector<int> arr = {1, 2};
    // vector<int> arr = {1, 2, 1, 4, 1, 1, 1};
    cout << findPeak(arr) << endl;
    return 0;
}