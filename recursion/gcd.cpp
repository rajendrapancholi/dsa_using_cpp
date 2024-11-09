/**********************
Program Name        : Find Greatest common divisor.
Author              : Rajendra Pancholi
Date of creation    : 09/11/2024
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int a = 4, b = 8;
    int ans = gcd(a, b);
    cout << "gcd is : " << ans << endl;
    return 0;
}
