/**********************
Program Name        : Find the peak of element in the mountain array.ADJ_FREQUENCY
Author              : Rajendra Pancholi
Date of creation    : 26/01/2025
Organization        : NIT Patna
***********************/
/**********************
 * Given a montain array 'a' of length greater than 3, return the index 'i' such that arr[0] < arr[1]<....<arr[i-1]<arr[i]>arr[i+1]>arr[i+2]>.....>arr[arr.lengh-1]. This index is known as the peak index.
 * Input: Array = [0,4,1,0]
 * Output: 1
 ***********************/

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &mountainArr)
{
    int left = 0, right = mountainArr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mountainArr[mid] > mountainArr[mid - 1] && mountainArr[mid] > mountainArr[mid + 1])
            return mid;
        if (mountainArr[mid] > mountainArr[mid - 1] && mountainArr[mid] < mountainArr[mid + 1])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> mountainArr = {0, 4, 1, 0};
    // vector<int> mountainArr = {0, 1, 2, 3, 5, 1, 0};
    // vector<int> mountainArr = {0, 1, 2, 3, 5, 7, 0};
    cout << findPeak(mountainArr) << endl;
    return 0;
}