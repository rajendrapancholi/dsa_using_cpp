/**********************
Program Name        : Find target element index in the sorted rotated array.
Author              : Rajendra Pancholi
Date of creation    : 25/01/2025
Organization        : NIT Patna
***********************/
/**********************
 * Given the sorted rotated array of intergers. Which contains distinct elements, and an interger, return the index of target if it is in the array. Otherwise return -1
 * Input: Array = [3, 4, 5, 1, 2]
 * Target: 4
 * Output: 1
 ***********************/

#include <iostream>
using namespace std;

int findTarget(int *arr, int low, int high, int target)
{
    if (arr[low] < arr[high])
    {
        // Simple binary binary search
        return 10;
    }
    else
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] >= arr[low])
            {
                if (target >= arr[low] && target <= arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (target >= arr[mid] && target <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    // int arr[] = {3,4,5,1,2};
    // int arr[] = {2,3,4,5,1};
    // int arr[] = {4, 5, 1, 2, 3};
    int arr[] = {5, 1, 2, 3, 4};
    // int arr[] = {3,4,5,1,2};
    cout << findTarget(arr, 0, 4, 4) << endl;
    return 0;
}