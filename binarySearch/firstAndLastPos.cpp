/**********************
Program Name        : Find the first and the last position of the gien 'target' element in the sorted array.
Author              : Rajendra Pancholi
Date of creation    : 17/12/2024
Organization        : NIT Patna
***********************/
/***********************
 * Given an arrayof integers 'a' that is sorted in non-decreasing order. Find the first and the last position of the gien 'target' element in the sorted array. follow 0-based indexing.
 * if target is not found in the array, return [-1, -1].
 * Input: array = [1, 2, 3, 3, 3, 5, 11]
 * target = 3
 * Output = [2, 4]
 ***********************/
#include <iostream>
using namespace std;

int findLowerPos(int *arr, int &target, int n)
{
    int low = 0, high = n;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
        {
            if (arr[mid] == target)
                ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int findUpperPos(int *arr, int &target, int n)
{
    int low = 0, high = n;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
        {
            if (arr[mid] == target)
                ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 5, 11};
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    int pos[] = {-1, -1};
    int target = 3;
    pos[0] = findLowerPos(arr, target, n);
    pos[1] = findUpperPos(arr, target, n);
    cout << "[" << pos[0] << " " << pos[1] << "]" << endl;
    return 0;
}
