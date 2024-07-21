#include <iostream>
using namespace std;

int main()
{
    // type 1: array initialization and declaration.
    int arr[] = {11, 12, 13, 14, 15};

    // type 2:
    int arr2[5];
    arr2[0] = 21;
    arr2[1] = 22;
    arr2[2] = 23;
    arr2[3] = 24;
    arr2[4] = 25;

    arr2[4] = 222;
    // Access the elements of an array.
    int ln = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < ln; i++)
    {
        // cout << arr[i] << " ";
        cout << arr2[i] << " ";
    }
    cout << endl;
    // Display elements using for each loop.
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    int sum = 0;
    // Sum of all the elements of the array.
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    cout << endl
         << "Sum of all elements is: " << sum << endl;

    // Maximum value out of the array.
    int max = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < max)
        {
            max = arr[i];
        }
    }
    cout << "Maximum value of the array is :" << max << endl;

    // Taking input in an array
    // int arr3[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Enter an element " << i + 1 << ": ";
    //     cin >> arr3[i];
    // }
    // cout << endl
    //      << "All elements are :";
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr3[i] << " ";
    // }
    // cout << endl;

    return 0;
}