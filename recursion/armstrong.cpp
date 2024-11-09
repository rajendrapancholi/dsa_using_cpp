/**********************
Program Name        : Check number is armstrong.
Author              : Rajendra Pancholi
Date of creation    : 09/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
#include <math.h>
using namespace std;

int arm(int n, int d)
{
    if (n == 0)
        return 0;
    return pow(n % 10, d) + arm(n / 10, d);
}
int main()
{
    int n = 8208;
    int d = log10(n) + 1;
    if (n == arm(n, d))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}