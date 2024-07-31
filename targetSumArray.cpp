#include <iostream>
#include <vector>
using namespace std;

int secondLargestEle(int arr[], int size)
{
    int max = INT16_MIN;
    int secondMax = INT16_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > secondMax && arr[i] != max)
        {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

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
    int arr[] = {2, 3, 5, 7, 6, 1, 7};
    int ln = sizeof(arr) / sizeof(arr[0]);
    cout << secondLargestEle(arr, ln);

    cout << endl;
    return 0;
}