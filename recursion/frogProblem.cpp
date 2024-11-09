/**********************
Program Name        : Frog problem-1
Author              : Rajendra Pancholi
Date of creation    : 10/11/2024
Organization        : NIT Patna
***********************/
/* Problem-1
There are N stones, numbered 1,2,3,...,N for each i (1 <= i <= N), the height of stone i is hi. There is a frog who is initially on stone 1. He will repeat the following action same number of times to reach stone N.
If the frog is currently on stone i, jum ot stone i+1 or stone i+2. Here a cost of |hi- hj| is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches stone N.

Input n = 4,
arr[] = {10, 30, 40, 20}
Output = 30
 */

#include <iostream>
using namespace std;

int minDist(int *h, int len, int i)
{
    // Base case: only one element in the array (reached top of the call stack i == len-1)
    if (i == len - 1)
        return 0;
    // only two element in the array and compare them
    if (i == len - 2)
        return min(minDist(h, len, i + 1), abs(h[i] - h[i + 1]));

    return min(minDist(h, len, i + 1) + abs(h[i] - h[i + 1]), minDist(h, len, i + 2) + abs(h[i] - h[i + 2]));
}
int main()
{
    int arr[] = {10, 30, 40, 20};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << minDist(arr, len, 0) << endl;
    return 0;
}