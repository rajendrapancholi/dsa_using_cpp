/* Sum of Beauty of all substring
The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character (excluding characters that do not appear) in that string.

Given a string s, return the sum of beauty values of all possible substrings of s.

Examples
Example 1:
Input: s = "xyx"
Output: 1
Explanation:
 The substrings with non-zero beauty are:
"xyx" → frequencies: x:2, y:1 → beauty = 2 - 1 = 1
"xy" → x:1, y:1 → beauty = 0
"yx" → y:1, x:1 → beauty = 0
"x" or "y" → beauty = 0
Total sum = 1 (from "xyx") = 1

Example 2:
Input: s = "aabcbaa"
Output: 17
Explanation:
 Various substrings such as "aabc", "bcba", etc., have non-zero beauty values. Summing all gives 17.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int sumOfBeautyStr(string s){
    int ans = 0, n = s.size();
    for(int i = 0; i < n; i++){
      int hash[26] = {0};
      for(int j = i; j < n; j++){
        hash[s[j] - 'a']++;
        int mn = INT_MAX, mx = INT_MIN;
        for (int k = 0; k < 26; k++) {
          if (hash[k] > 0) {
            mn = min(mn, hash[k]);
            mx = max(mx, hash[k]);
          }
        }
        ans += (mx - mn);
      }
    }
    return ans;
  }
};

int main() {
  string s = "aba"; // Output: 1

  Solution sl;
  cout<<sl.sumOfBeautyStr(s)<<endl;
  return 0;
}
