/**********************
Program Name        : Find the value p^q using recursion
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;
// Method 1: Time complexity is O(n)
int pow_rec(int p, int q)
{
    // Base case
    if (q == 0)
    {
        return 1;
    }
    return p * pow_rec(p, q - 1);
}

int main()
{
    int p;
    int q;
    cout << "Enter (num, pow): ";
    cin >> p >> q;
    int ans = pow_rec(p, q);
    cout << p << " raise to the power " << q << " is :" << ans << endl;
    // cout << ans << endl;
    return 0;
}
