/**********************
Program Name        : Print all the elements of the array using recursion.
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

void printArray(int *arr, int idx, int len)
{
    if (idx == len)
        return;
    cout << arr[idx++] << " ";
    printArray(arr, idx, len);
}
int main()
{
    int arr[] = {2, 3, 4, 5, 8, 7, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, 0, len);
    return 0;
}