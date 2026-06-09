/* Recursive Implementation of atoi()
Implement the function myAtoi(s) which converts the given string s to a 32-bit signed integer (similar to the C/C++ atoi function).

Steps to Implement: 1. First, ignore any leading whitespace characters ' ' until the first non-whitespace character is found.
2. Check the next character to determine the sign. If it’s a '-', the number should be negative. If it’s a '+', the number should be positive. If neither is found, assume the number is positive.
3. Read the digits and convert them into a number. Stop reading once a non-digit character is encountered or the end of the string is reached. Leading zeros should be ignored during conversion.
4. The result should be clamped within the 32-bit signed integer range: [-2147483648, 2147483647]. If the computed number is outside this range, return -2147483648 if the number is less than -2147483648, or return 2147483647 if the number is greater than 2147483647.
5. Finally, return the computed number after applying all the above steps.

Examples
Example 1:
Input:
 s = " -12345"  
Output:
 -12345  
Explanation:
  
Ignore leading whitespaces.  
The sign '-' is encountered, indicating the number is negative.  
Digits 12345 are read and converted to -12345.

Example 2:
Input:
 s = "4193 with words"  
Output:
 4193  
Explanation:
  
Read the digits 4193 and stop when encountering the first non-digit character (w).
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  const int INT_MIN_VAL = -2147483648;
  const int INT_MAX_VAL = 2147483647;
private:

  int helper(string &s, int i, int sign, int num){
    if(i >= s.size() || !isdigit(s[i])) return (int)(sign * num);

    num = num * 10 + (s[i] - '0');
    
    if (sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
    if (sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

    return helper(s, i + 1, sign, num);
  }
public:
  int myAtoi(string &s){
    int i = 0, num = 0;
    while(i < s.size() && s[i] == ' ') i++;  // skip leading char
    int sign = 1;
    if(i < s.size() && (s[i] == '+' || s[i] == '-')){
      sign = (s[i] == '+') ? +1 : -1;
      i++;
    }

    return helper(s, i, sign, num);
  }
};

int main() {
  string s = " -12345"; // Output: -12345  
  Solution sl;
  cout<<sl.myAtoi(s)<<endl;
  return 0;
}
