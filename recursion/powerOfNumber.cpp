/**********************
Program Name        : Find the value p^q using recursion
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/
#include <iostream>
using namespace std;
// Method 1: Time complexity is O(q)
/* int pow_rec(int p, int q)
{
    // Base case
    if (q == 0)
    {
        return 1;
    }
    return p * pow_rec(p, q - 1);
} */

// Method 2: Time complexity is O(log(q))
int pow_rec(int p, int q)
{
    // Base case of the recursion
    if (q == 0)
        return 1;
    if (q % 2 == 0)
    {
        // If q is even
        int res = pow_rec(p, q / 2);
        return res * res;
    }
    else
    {
        // If q is odd
        int res = pow_rec(p, (q - 1) / 2);
        return p * res * res;
    }
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
