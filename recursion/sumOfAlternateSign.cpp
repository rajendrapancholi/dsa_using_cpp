/**********************
Program Name        : Given a number n. Find the sum of natural numbers till n but with alternate
Author              : Rajendra Pancholi
Date of creation    : 08/11/2024
Organization        : NIT Patna
***********************/
/*
input: n = 5;
output: 3
1 - 2 + 3 - 4 + 5 = 3
*/

#include <iostream>
using namespace std;
int sumOfAltSign(int n, int i)
{
    // Base case: if the index reaches the end
    if (i == n)
        return (i % 2 == 0) ? -i : i; // if i is even: i = -i
    return ((i % 2 == 0) ? -i : i) + sumOfAltSign(n, i + 1);
}
int main()
{
    int n = 8;
    int ans = sumOfAltSign(n, 1);
    cout << ans << endl;

    return 0;
}