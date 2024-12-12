/**********************
Program Name        : Sort string in lexicographical order.
Author              : Rajendra Pancholi
Date of creation    : 12/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <string.h>
using namespace std;
void sortString(string *str, int n)
{
    for (int i = 0; i < n; i++)
    {

        int minIdx = i;
        for (int j = i; j < n; j++)
        {
            if (str[minIdx] > str[j])
            {
                minIdx = j;
            }
        }
        if (i != minIdx)
        {
            swap(str[i], str[minIdx]);
        }
    }
}
int main()
{
    string str[] = {"papaya", "lime", "watermelon", "apple", "mango", "kivi"};
    int ans = str[0] < str[1];
    int n = sizeof(str) / sizeof(str[0]);
    cout << "\nBefore Sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
    }
    sortString(str, n);
    cout << "\nAfter Sorting\n";
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
    }

    // int cmp = strcmp("abr", "a");
    // cout << ans << endl;
    // cout << cmp << endl;

    return 0;
}