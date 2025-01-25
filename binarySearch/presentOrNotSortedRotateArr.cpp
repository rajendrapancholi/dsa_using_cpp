/**********************
Program Name        : Sorted rotated array
Author              : Rajendra Pancholi
Date of creation    : 26/01/2025
Organization        : NIT Patna
***********************/
/**********************
 * Search element in rotated sorted array with duplicate elements. Return 1 if the element is found, else return 0.
 * Input: Arr = [0,0,0,0,1,1,2,0,0,0]
 * Target: 2
 * Output: 1
 ***********************/

#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n) -> n is no of input size
bool isPresent(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[left] == arr[right])
        {
            if (arr[left] == target)
                return true;
            left++;
            right--;
            continue;
        }
        if (arr[mid] == target)
        {
            return true;
        }
        if (arr[left] <= arr[mid])
        {
            if (target >= arr[left] && target <= arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target >= arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {0, 0, 0, 0, 1, 1, 2, 0, 0, 0};
    cout << isPresent(arr, 4) << endl;
    return 0;
}