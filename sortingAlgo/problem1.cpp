/**********************
Program Name        : Given and integer array arr, move all 0s the end of it while maintaining the relative order of the non-zero element using the same array.
Author              : Rajendra Pancholi
Date of creation    : 12/12/2024
Organization        : NIT Patna
***********************/
/***********************
 Input: arr[]={3, 0, 2, 0, 1, 5}
 Output: 3 2 1 5 0 0
***********************/
#include <iostream>
using namespace std;

void result(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] <= arr[j + 1] && arr[j] == 0)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{

    int arr[] = {3, 0, 2, 0, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Befor sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    result(arr, n);
    cout << "\nAfter sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}