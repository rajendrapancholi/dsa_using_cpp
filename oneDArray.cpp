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

    return 0;
}