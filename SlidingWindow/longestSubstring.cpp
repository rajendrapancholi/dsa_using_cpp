/* Length of Longest Substring without any Repeating Character
Given a string, S. Find the length of the longest substring without repeating characters.
Examples
Example 1:
Input:
 S = "abcddabac"  
Output:
 4  
Explanation:
 The longest substring with distinct characters is "abcd", which has a length of 4.

Example 2:
Input:
 S = "aaabbbccc"  
Output:
 2  
Explanation:
 The longest substrings with distinct characters are "ab" and "bc", both having a length of 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestNonRepeatingSubstring(string& s) {
    int n = s.size();
    int HashLen = 256;
    int hash[HashLen];
    for (int i = 0; i < HashLen; ++i) {
      hash[i] = -1;
    }
    int l = 0, r = 0, maxLen = 0;
    while (r < n) {
      if (hash[s[r]] != -1) {
        l = max(hash[s[r]] + 1, l);
      }
      int len = r - l + 1;
      maxLen = max(len, maxLen);
      hash[s[r]] = r;
      r++;
    }
    return maxLen;
  }
};

int main() {
  string s = "aaabbbccc"; 
  
  Solution sol;
  int result = sol.longestNonRepeatingSubstring(s);
  cout << result << endl;
  return 0;
}
