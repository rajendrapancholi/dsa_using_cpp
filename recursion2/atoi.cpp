/* Recursive Implementation of atoi()
Implement the function myAtoi(s) which converts the given string s to a 32-bit signed integer (similar to the C/C++ atoi function).

Steps to Implement: 1. First, ignore any leading whitespace characters ' ' until the first non-whitespace character is found.
2. Check the next character to determine the sign. If it’s a '-', the number should be negative. If it’s a '+', the number should be positive. If neither is found, assume the number is positive.
3. Read the digits and convert them into a number. Stop reading once a non-digit character is encountered or the end of the string is reached. Leading zeros should be ignored during conversion.
4. The result should be clamped within the 32-bit signed integer range: [-2147483648, 2147483647]. If the computed number is outside this range, return -2147483648 if the number is less than -2147483648, or return 2147483647 if the number is greater than 2147483647.
5. Finally, return the computed number after applying all the above steps.

Examples
  Input: s = " -12345"  
  Output: -12345  
  Explanation: Ignore leading whitespaces.  
  The sign '-' is encountered, indicating the number is negative.  
  Digits 12345 are read and converted to -12345.

  Input: s = "4193 with words"  
  Output: 4193  
  Explanation: Read the digits 4193 and stop when encountering the first non-digit character (w).
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(string n, int i, int ans, int sign){
    if(i >= n.size()) return ans * sign;
    while(n[i] >= '0' && n[i] <= '9'){
      ans = ans * 10 + (n[i] - '0');
      i++;
    }
    return ans * sign;
  }

public:
  int atoi(string n){
    int ans = 0, i = 0, sign = 1;
    while(n[i] < '0' || n[i] > '9'){
      i++;
    }

    if(n[i-1] == '-'){
      sign = -1;
      // i++;
    }
    return helper(n, i, ans, sign);
    
  }
};

int main() {
  Solution sl;
  cout<<sl.atoi(" -12345")<<endl;
  return 0;
}
