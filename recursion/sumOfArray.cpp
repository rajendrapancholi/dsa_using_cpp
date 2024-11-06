/**********************
Program Name        : Find the sum of all elements of the array using recursion.
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

int sumOfArray(int *arr, int idx, int len)
{
    if (idx == len)
        return 0;
    return arr[idx] + sumOfArray(arr, idx + 1, len);
}
int main()
{
    int arr[] = {2, 3, 4, 10, 20, 7, 9, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    int ans = sumOfArray(arr, 0, len);
    cout << "Sum is: " << ans << endl;
    return 0;
}