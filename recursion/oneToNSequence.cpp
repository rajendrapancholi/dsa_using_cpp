/**********************
Program Name        : Find the increasing sequence from 1 to n without using any loop.
Author              : Rajendra Pancholi
Date of creation    : 08/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

void incSeq(int n, int i)
{
    cout << i << " ";
    if (i == n)
        return;
    incSeq(n, i + 1);
}
int main()
{
    int n = 13;
    incSeq(n, 1);
    return 0;
}