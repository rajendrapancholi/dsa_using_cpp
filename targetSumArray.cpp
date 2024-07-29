#include <iostream>
#include <vector>
using namespace std;

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
    int arr2[] = {1, 2, 3, 2, 3, 4, 1, 5};
    int ln2 = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < ln2; i++)
    {
        for (int j = i + 1; j < ln2; j++)
        {
            if (arr2[i] == arr2[j])
            {
                arr2[i] = arr2[j] = -1;
            }
        }
    }
    for (int i = 0; i < ln2; i++)
    {
        if (arr2[i] > 0)
        {
            cout << arr2[i] << " ";
        }
    }
    cout << endl;

    return 0;
}