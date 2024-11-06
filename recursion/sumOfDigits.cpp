/**********************
Program Name        : Given an integer find out the sum of its digit using recursion.
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>

using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sum(n / 10);
}
int main()
{
    int n = 2231;
    int ans = sum(n);
    cout << "Sum of digits is: " << ans << endl;

    return 0;
}