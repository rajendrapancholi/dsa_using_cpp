/**********************
Program Name        : Find the index of target if it is in teh array. Otherwise return -1.
Author              : Rajendra Pancholi
Date of creation    : 17/12/2024
Organization        : NIT Patna
***********************/
/***********************
 *  Given the rotated sorted array of integers, which contains distinct elements, and an interger target return the index of target if it is in teh array. Otherwise return -1.
 * Input: arr = [3, 4, 5, 1, 2]
 * target = 4
 * Output: 1
 ***********************/
#include <iostream>
#include <vector>
using namespace std;

int findIndex(vector<int> &arr, int &target)
{
    int low = 0, high = arr.size() - 1, mid = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (target == arr[mid])
            return mid;
        if (arr[mid] >= arr[low])
        {
            if (target >= arr[low] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (target <= arr[low] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return mid;
}
int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    // vector<int> arr = {1, 2, 3, 4, 5};
    // vector<int> arr = {4, 5, 1, 2, 3};
    // vector<int> arr = {2, 3, 4, 5, 6, 1};
    // vector<int> arr = {2, 3, 4, 5, 1};
    // vector<int> arr = {5, 1, 2, 3, 4};
    int target = 4;
    int idx = findIndex(arr, target);
    cout << target << " is at index: " << idx << endl;
    return 0;
}