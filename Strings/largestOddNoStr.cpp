/* Largest Odd Number in a String.
Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
The number returned should not have leading zero's. But the given input string may have leading zero.

Examples
Example 1
Input:
 s = "5347"
Output:
 "5347"
Explanation:
 The odd numbers formed by the given string are → 5, 3, 53, 347, 5347. The largest odd number without leading zeroes is 5347.

Example 2
Input:
 s = "0214638"
Output:
 "21463"
Explanation:
 The odd numbers formed by the string are → 1, 3, 21, 63, 463, 1463, 21463. We can't use numbers starting with 0, so the largest valid odd number is 21463.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string largestOddN(string &s){
    string ans = "";
    int n = s.size();
    int zerosIdx = 0;
    for(auto c: s){
      if(c != '0') break;
      zerosIdx++;
    }
    if(zerosIdx == n-1) return "";
    for(int i = n - 1; i >= 0; i--)
      if((s[i] - '0')%2 == 1 && ans.size() < i - zerosIdx + 1)
        ans = s.substr(zerosIdx, i - zerosIdx+1);
  
    return ans;
  }

};

int main() {
  string s = "0000214638001"; // Output: "21463"
  Solution sl;
  cout<<sl.largestOddN(s)<<endl;
  return 0;
}
