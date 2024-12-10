/**********************
Program Name        : Given an array of integers, print sum of all subsets in it.
Author              : Rajendra Pancholi
Date of creation    : 10/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

void sumOfSubset(int *arr, int ln, int sum, vector<int> &result, int i)
{
    if (i == ln)
    {
        result.push_back(sum);
        return;
    }
    sumOfSubset(arr, ln, sum + arr[i], result, i + 1);
    sumOfSubset(arr, ln, sum, result, i + 1);
    return;
}
int main()
{
    int arr[] = {2, 3};
    int ln = sizeof(arr) / sizeof(arr[0]);
    vector<int> result;
    sumOfSubset(arr, ln, 0, result, 0);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}