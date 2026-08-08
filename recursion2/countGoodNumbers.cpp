/* Count Good numbers
A digit string is considered good if the digits at even indices (0-based) are even digits (0, 2, 4, 6, 8) and the digits at odd indices are prime digits (2, 3, 5, 7).

Given an integer n, return the total number of good digit strings of length n. As the result may be large, return it modulo 109 + 7.

A digit string is a string consisting only of the digits '0' through '9'. It may contain leading zeros.

Examples
Example 1:
Input:
 n = 1
Output:
 5
Explanation:
 Only one index (0) → must be even.
Valid strings: "0", "2", "4", "6", "8"

Example 2:
Input:
 n = 2
Output:
 20
Explanation:
 Index 0: 5 options (even digits)
Index 1: 4 options (prime digits)
Total: 5 * 4 = 20
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  long long MOD = 1e9 + 7;
  long long power(long long base, long long exp) {
    long long res = 1;
    base = base % MOD;
    while (exp > 0) {
      if (exp % 2 == 1) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp /= 2;
    }
    return res;
  }

public:
  int countGoodNumbers(long long n) {
    long long evenPositions = (n + 1) / 2; 
    long long oddPositions = n / 2;
    long long evenChoices = power(5, evenPositions);
    long long oddChoices = power(4, oddPositions);
    return (evenChoices * oddChoices) % MOD;
  }
};

int main() {
  Solution sl;
  long long n = 3; 
  cout << sl.countGoodNumbers(n) << endl; // Output: 100
  return 0;
}
