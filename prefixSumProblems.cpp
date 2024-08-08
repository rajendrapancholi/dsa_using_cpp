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
// void prefixAndSufixSum(vector<int> &v)
// {
//     int preSum = 0;
//     bool isSumExists = false;
//     // total sum of the array.
//     int totalSum = 0;
//     for (int i = 0; i < v.size(); i++)
//     {
//         totalSum += v[i];
//     }
//     // total sum of first n prefix of the array.
//     for (int i = 0; i < v.size(); i++)
//     {
//         preSum += v[i];
//         int sufSum = totalSum - preSum;
//         if (preSum == sufSum)
//         {
//             isSumExists = true;
//             break;
//         }
//     }
//     if (isSumExists)
//     {
//         cout << "True" << endl;
//     }
//     else
//     {
//         cout << "False" << endl;
//     }
//     // Display array.
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     return;
// }

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v(n + 1, 0);
    // for (int i = 1; i < n; i++)
    // {
    //     int ele;
    //     cin >> ele;
    //     v.push_back(ele);
    // }

    // runningSum(v);
    // prefixAndSufixSum(v);

    // Q3: Given an array of integers of size n. Ansewer Q queries where you need to print the sum of values in a given range of indices from L to R (both indices).
    // Note: The value of L and R in query follow 1-based indexing.
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    // Calculate prefix sum of a vector v
    for (int i = 1; i <= n; i++)
    {
        v[i] += v[i - 1];
    }

    int q;
    cout << "Enter queries: ";
    cin >> q;
    while (q--)
    {
        int l, r;
        cout << "Enter r and l : ";
        // LIFO operation performed in the belove expression
        cin >> l >> r;
        cout << "Ans is: " << v[r] - v[l - 1] << endl;
        cout << "L = " << l << " and R = " << r << endl;
        ;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << "size is: " << v.size() << " and capacity is: " << v.capacity();
    cout << endl;
    return 0;
}