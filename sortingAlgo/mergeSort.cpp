/**********************
Program Name        : Merge sort
Author              : Rajendra Pancholi
Date of creation    : 13/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

// M1: using vector
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i < temp.size(); i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{

    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    // vector<int> arr = {12, 11, 13, 5, 6, 7};
    vector<int> arr = {38, 27, 43, 10};
    int n = arr.size();
    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// M2: using array
// void merge(int *arr, int mid, int low, int high)
// {
//     int ln = mid - low + 1;
//     int rn = high - mid;

//     int left = low, right = mid + 1;

//     int lArr[ln], rArr[rn];

//     for (int i = 0; i < ln; i++)
//     {
//         lArr[i] = arr[left + i];
//     }
//     for (int j = 0; j < rn; j++)
//     {
//         rArr[j] = arr[right + j];
//     }

//     int i = 0, j = 0, k = left;
//     while (i < ln && j <= rn)
//     {

//         if (lArr[i] <= rArr[j])
//         {
//             arr[k] = lArr[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = rArr[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < ln)
//     {
//         arr[k] = lArr[i];
//         i++;
//         k++;
//     }
//     while (j < rn)
//     {
//         arr[k] = rArr[j];
//         j++;
//         k++;
//     }
// }
// void mergeSort(int *arr, int low, int high)
// {
//     if (low >= high)
//     {
//         return;
//     }
//     int mid = low + (high - low) / 2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     merge(arr, mid, low, high);
// }

// int main()
// {

//     // int arr[] = {12, 11, 13, 5, 6, 7};
//     int arr[] = {10, 11, 3, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     mergeSort(arr, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }