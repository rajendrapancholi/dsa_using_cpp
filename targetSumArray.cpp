#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 2, 4, 5, 3, 6};
    int ln = sizeof(arr1) / sizeof(arr1[0]);
    int x;
    int count = 0;
    cout << "Enter x: ";
    cin >> x;

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

    return 0;
}