/**********************
Program Name        : Print maximum element of the array using recursion.
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

int printMaxOfArray(int *arr, int idx, int len)
{
    if (idx == len - 1)
        return arr[idx];
    return max(arr[idx], printMaxOfArray(arr, idx + 1, len));
}
int main()
{
    int arr[] = {2, 3, 4, 12, 45, 7, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    int ans = printMaxOfArray(arr, 0, len);
    cout << "Maximum no is: " << ans << endl;
    return 0;
}