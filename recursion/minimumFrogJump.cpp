/**********************
Program Name        : find minimum frog jump
Author              : Rajendra Pancholi
Date of creation    : 10/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;

int frogJump(int *arr, int h, int i)
{
    // base case
    if (i == h - 1)
    {
        return 0;
    }
    if (i == h - 2)
    {
        return frogJump(arr, h, i + 1) + abs(arr[i] - arr[i + 1]);
    }
    return min(frogJump(arr, h, i + 1) + abs(arr[i] - arr[i + 1]), frogJump(arr, h, i + 2) + abs(arr[i] - arr[i + 2]));
}

int main()
{

    // int arr[] = {10, 30, 40, 20};
    int arr[] = {20, 20, 20, 20};
    int minCost = frogJump(arr, 4, 0);
    cout << "min distance is: " << minCost << endl;
    return 0;
}