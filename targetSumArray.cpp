#include <iostream>
#include <vector>
#include <algorithm> //for reverse() method
using namespace std;

// Q:4
// int secondLargestEle(int arr[], int size)
// {
//     int max = INT16_MIN;
//     int secondMax = INT16_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > secondMax && arr[i] != max)
//         {
//             secondMax = arr[i];
//         }
//     }
//     return secondMax;
// }

int main()
{
    // int arr1[] = {1, 2, 4, 5, 3, 6};
    // int ln = sizeof(arr1) / sizeof(arr1[0]);
    // int x;
    // int count = 0;
    // cout << "Enter x: ";
    // cin >> x;

    // Q1: Find the total number of pairs in the array whose sum is equal to the given value of x.
    // for (int i = 0; i < ln; i++)
    // {
    //     for (int j = i + 1; j < ln; j++)
    //     {
    //         if (arr1[i] + arr1[j] == x)
    //         {
    //             count++;
    //         }
    //     }
    // }
    // cout << "Total number of pairs is: " << count << endl;

    // Q2: Find the total number of triplets in the array whose sum is equal to the given value of x.
    // for (int i = 0; i < ln; i++)
    // {
    //     for (int j = i + 1; j < ln; j++)
    //     {
    //         for (int k = j + 1; k < ln; k++)
    //         {
    //             if (arr1[i] + arr1[j] + arr1[k] == x)
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    // }
    // cout << "Total triplet is: " << count << endl;

    // Q3: Find the unique number in given array where all the elements are being repeated twice with one value being unique.
    // int arr2[] = {1, 2, 3, 2, 3, 4, 1, 5};
    // int ln2 = sizeof(arr2) / sizeof(arr2[0]);
    // for (int i = 0; i < ln2; i++)
    // {
    //     for (int j = i + 1; j < ln2; j++)
    //     {
    //         if (arr2[i] == arr2[j])
    //         {
    //             arr2[i] = arr2[j] = -1;
    //         }
    //     }
    // }
    // for (int i = 0; i < ln2; i++)
    // {
    //     if (arr2[i] > 0)
    //     {
    //         cout << arr2[i] << " ";
    //     }
    // }

    // Q4: Find the second largest number in the given array.
    // int arr[] = {2, 3, 5, 7, 6, 1, 7};
    // int ln = sizeof(arr) / sizeof(arr[0]);
    // cout << secondLargestEle(arr, ln);

    // Q5: Rotate the given array 'a' by k steps, where k is non-negative. Note: k can be greater than n as well where n is the size of array 'a'.
    // vector<int> v2 = {1, 2, 3, 4, 5, 6};
    // int k = 2;
    // k %= v2.size();
    // reverse(v2.begin(), v2.end());
    // reverse(v2.begin(), v2.begin() + k);
    // reverse(v2.begin() + k, v2.end());
    // for (int ele : v2)
    // {
    //     cout << ele << " ";
    // }
    // int n = 1e5 + 10;
    // cout << n;

    // Q6: Given Q queries, check if the given number is present in the array or not.
    // note:- value of all the elements in the array is less than 10 to the power 5.
    int n;
    cout << "Enter number of element do you want to insert in the array :" << endl;
    cin >> n;
    vector<int> v3(n);
    for (int i = 0; i < n; i++)
    {

        cin >> v3[i];
    }
    const int N = 1e5 + 10; // 10^5+10
    // create a vector(array) of size N and every element of the array is 0.
    vector<int> freq(N, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v3[i]]++;
    }
    cout << "Enter a queries? : ";
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Enter query element? : ";
        int queryElement;
        cin >> queryElement;
        cout << freq[queryElement] << endl;
    }

    cout << endl;
    return 0;
}