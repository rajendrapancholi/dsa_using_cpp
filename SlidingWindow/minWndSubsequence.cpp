/* Minimum Window Subsequence
Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.
If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1
Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of s2 in the window must occur in order.

Example 2
Input: s1 = "jmeqsiwvaovvnbstl", s2 = "u"
Output: ""

Constraints
1 <= s1.length <= 2 * 104
1 <= s2.length <= 100
s1 and s2 consist of lowercase English letters.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string minWndSubsequence(string &s1, string &s2){
    string ans = "";
    int m = s1.size(), n = s2.size();
    if(m < n) return ans;
    int minlen = 1e9;
    for(int i = 0; i < m; i++){
      string tStr = "";
      int reqlen = s2.size();
      for(int j = i; j < m; j++){
        tStr += s1[j];
        if(s1[j] == s2[n - reqlen]){
          reqlen--;
        }

        if(reqlen == 0){
          if(minlen > j - i + 1){
            minlen = j - i + 1;
            ans = tStr;
          }
          break;
        }
      }
    }
    return ans;
  }
  
  string minWndSubsequenceSW(string &s1, string &s2){
    string ans = "";
    int m = s1.size(), n = s2.size();
    if(m < n) return ans;
    int minlen = 1e9, s2_idx = 0, left = 0;

    for(int right = 0; right < m; right++){
      if(s1[right] == s2[s2_idx]) s2_idx++;
      if(s2_idx == n){
        left = right;
        int back_idx = n - 1;
        while(left >= 0 && back_idx >= 0){
          if(s1[left] == s2[back_idx]){
            back_idx--;
          }
          left--;
        }
        left++;
        int currentLen = right - left + 1;
        if(currentLen < minlen){
          minlen = currentLen;
          ans = s1.substr(left, currentLen);
        }
        s2_idx = 0;
        right = left; 
      }
    }
    return ans;
  }
};

int main(){
  string s1 = "abcdebdde", s2 = "bde"; // Output: "bcde"
  // string s1 = "jmeqsiwvaovvnbstl", s2 = "u"; // Output: ""
  Solution sl;

  cout<<sl.minWndSubsequence(s1, s2)<<endl;
  cout<<sl.minWndSubsequenceSW(s1, s2)<<endl;
  return 0;
}