/**********************
Program Name        : Given two sorted arrays, Write a program to merge them in a sorted manner.
Author              : Rajendra Pancholi
Date of creation    : 14/12/2024
Organization        : NIT Patna
***********************/
/***********************
 Input: arr1[]={5, 8, 10}, arr2[]={2, 7, 8}
 Output: arr3[]={2, 5, 7, 8, 10}
***********************/
#include <iostream>
using namespace std;

void sortArr(int *arr1, int *arr2, int ln1, int ln2, int *arr3)
{
    int k = 0, i = 0, j = 0;

    while (i < ln1 && j < ln2 && k < (ln1 + ln2))
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < ln1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < ln2)
    {
        arr3[k] = arr1[j];
        j++;
        k++;
    }
}

int main()
{
    int arr1[] = {5, 8, 10}, arr2[] = {2, 7, 8};
    int ln1 = sizeof(arr1) / sizeof(arr1[0]);
    int ln2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[ln1 + ln2];
    sortArr(arr1, arr2, ln1, ln2, arr3);
    for (int i = 0; i < ln1 + ln2; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}