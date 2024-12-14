/**********************
Program Name        : Quick Sort
Author              : Rajendra Pancholi
Date of creation    : 14/12/2024
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while ((arr[i] <= pivot) && (i <= high - 1))
        {
            i++;
        }
        while ((arr[j] > pivot) && (j >= low + 1))
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main()
{

    vector<int> arr = {8, 6, 78, 2, 32, 14};
    quickSort(arr, 0, arr.size() - 1);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}