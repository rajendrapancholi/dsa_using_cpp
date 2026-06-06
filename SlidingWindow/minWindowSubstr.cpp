/* 76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minSubstr(string s, string t){
    string minStr = "";
    int n = s.length(), minlen = 1e9;
    for(int i = 0; i < n; i++){
      unordered_map<char, int> mp;
      for(auto ch: t) mp[ch]++;
      string tStr = "";
      for(int j = i; j < n; j++){
        tStr += s[j];
        if(mp.find(s[j]) != mp.end()){
          mp[s[j]]--;
          if(mp[s[j]] == 0) mp.erase(s[j]);
        }
        if(mp.empty()){
          if(tStr.length() < minlen){
            minlen = tStr.length();
            minStr = tStr;
            break;
          }
        }
      }
    }
    return minStr;
  }

  string minSubstrSW(string s, string t) {
    int m = s.length();
    int n = t.length();
    if (m < n) return "";
    vector<int> mapT(128, 0);
    for (char c : t) mapT[c]++;
    int left = 0, right = 0, minLen = 1e9, startIdx = -1, requiredCount = n;
    
    while (right < m) {
      if (mapT[s[right]] > 0) {
        requiredCount--;
      }
      mapT[s[right]]--;
      right++;
      while (requiredCount == 0) {
        int currentWindowLen = right - left;
        if (currentWindowLen < minLen) {
          minLen = currentWindowLen;
          startIdx = left;
        }
        mapT[s[left]]++;
        if (mapT[s[left]] > 0) {
          requiredCount++;
        }
        left++;
      }
    }
    return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
  }


};

int main(){
  string s = "ADOBECODEBANC", t = "ABC"; // Output: "BANC"
  Solution sl;
  cout<<sl.minSubstr(s, t)<<endl;
  cout<<sl.minSubstrSW(s, t)<<endl;
  return 0;
}