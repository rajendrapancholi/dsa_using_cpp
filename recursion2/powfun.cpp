/* Implement Pow(x,n) | X raised to the power N
Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.

Examples
Example 1:
Input:
 x = 2.0000, n = 10  
Output:
 1024.0000  
Explanation:
 The answer is calculated as 2^10, which equals 1024.

Example 2:
Input:
 x = 2.0000, n = -2  
Output:
 0.2500  
Explanation:
 The answer is calculated as 2^(-2), which is equal to 1/4 = 0.25.
Brute Force
Algorithm
Initialize the result variable, ans, to 1. This serves as the base case where any number raised to the power of 0 is 1.
Check if the exponent n is less than 0:
If true, invert x by setting x = 1/x and make n positive by setting n = -n. This transformation allows handling of negative exponents.
Use a loop to iterate from 0 to n (converted to an integer). In each iteration, multiply ans by x. This effectively computes x raised to the power of n.
Return the result stored in ans, which now contains the value of x^n.
Image 1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  double helper(double x, long long n) { 
    if (n == 0) return 1.0;
    if (n == 1) return x;
    if (n % 2 == 0)
      return helper(x * x, n / 2);
    return x * helper(x * x, (n - 1) / 2); 
  }
public:
  double powFun(double x, int n) {
    long long num = n; 
    if (num < 0) {
      num = -num;
      x = 1.0 / x;
    }
    return helper(x, num);
  }
};

int main() {
  Solution sl;
  cout<<sl.powFun(2, -2)<<endl;
  return 0;
}
