/**********************
Program Name        : Find Kth smallest element in an array using QuickSort Algorithm.
Author              : Rajendra Pancholi
Date of creation    : 14/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pvt = arr[low]; // Pivot element
    int i = low, j = high;

    while (i < j)
    {
        while (arr[i] <= pvt && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pvt && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void findKthSmallest(vector<int> &arr, int low, int high, int k)
{
    if (low >= high)
    {
        return;
    }
    int pvtIndex = partition(arr, low, high);
    if (pvtIndex == k)
    {
        cout << k + 1 << "th element is: " << arr[pvtIndex] << endl;
        return;
    }
    else if (k > pvtIndex)
    {
        findKthSmallest(arr, pvtIndex + 1, high, k);
    }
    else
    {
        findKthSmallest(arr, low, pvtIndex - 1, k);
    }
}

int main()
{
    vector<int> arr = {3, 5, 2, 1, 4, 7, 8, 6};
    int k = 5;
    findKthSmallest(arr, 0, arr.size() - 1, k - 1); // zero base index.
    for (auto ele : arr)
        cout << ele << " ";
    return 0;
}