/**********************
Program Name        : Given an array of n integers and a target value x. Print whether x exits in the array or not.
Author              : Rajendra Pancholi
Date of creation    : 10/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;
bool isFind(int *arr, int n, int x, int i)
{
    // Base case
    if (i == n)
    {
        return false;
    }

    return (x == arr[i]) || isFind(arr, n, x, i + 1);
}

int main()
{

    // Test input-1
    int arr[] = {4, 12, 54, 14, 3, 8, 6, 1};
    int x = 6;
    // Output: YES
    // Test input-2
    // int arr[] = {2};
    // int x = 9;
    // Output: NO
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = isFind(arr, n, x, 0);
    if (res)
    {
        cout << "YES" << endl;
    }

    else
        cout << "NO" << endl;

    return 0;
}