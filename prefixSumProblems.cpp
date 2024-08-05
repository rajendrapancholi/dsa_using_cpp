#include <iostream>
#include <vector>

using namespace std;

// Q1: Given an integer array 'a', return the prefix sum/running sum in the same array without creating new array.
// void runningSum(vector<int> &v)
// {
//     for (int i = 1; i < v.size(); i++)
//     {
//         v[i] += v[i - 1];
//     }
//     for (int e : v)
//     {
//         cout << e << " ";
//     }
//     return;
// }

// Q2: Check if we can partition the array into two subarrays with equal sum. More formally, check that the prefix sum of a part of the array is equal to the suffix sum of rest of the array.
void prefixAndSufixSum(vector<int> &v)
{
    int preSum = 0;
    bool isSumExists = false;
    // total sum of the array.
    int totalSum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        totalSum += v[i];
    }
    // total sum of first n prefix of the array.
    for (int i = 0; i < v.size(); i++)
    {
        preSum += v[i];
        int sufSum = totalSum - preSum;
        if (preSum == sufSum)
        {
            isSumExists = true;
            break;
        }
    }
    if (isSumExists)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    // Display array.
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    // runningSum(v);
    prefixAndSufixSum(v);
    cout << endl;
    return 0;
}