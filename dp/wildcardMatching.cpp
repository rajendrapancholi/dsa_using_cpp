/* Wildcard Matching

Problem Statement: We are given two strings ‘S1’ and ‘S2’. String S1 can have the following two special characters.

‘?’ can be matched to a single character of S2.
‘*’ can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
We need to check whether strings S1 and S2 match or not.

Examples
Input: S1 = "ab*cd", S2 = "abdefcd"
Output: true
Explanation: "ab" matches "ab", '*' matches "def", "cd" matches "cd". The strings match.

Input: S1 = "*a*b", S2 = "aaab"
Output: true
Explanation: First '*' matches "aa", 'a' matches 'a', second '*' matches empty string, 'b' matches 'b'. The strings match. 
*/

// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  bool helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    // BC-1:  if pattern exausted
    if(i < 0 && j < 0) return true;

    // BC-2: if text is esausted
    if(i < 0 && j >= 0) return false;

    // BC-3: if text is exausted but * remains
    if(j < 0 && i >= 0) {
      for(int ii = 0; ii <= i; ii++) {
        if(s1[ii]!= '*') return false;
      }
      return true;
    }
    
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j] || s1[i] == '?') {
      return dp[i][j] = helper(i-1, j-1, s1, s2, dp);
    }

    if(s1[i] == '*') {
      return dp[i][j] = helper(i-1, j, s1, s2, dp) || helper(i, j-1, s1, s2, dp);
    } 
    
    return dp[i][j] = false;
  }

public:
  bool wildcardMatching(string &s1, string &s2){
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return helper(n-1, m-1, s1, s2, dp);
  }
};

int main() {
  string S1 = "ab*cd", S2 = "abdefcd";

  Solution sl;

  cout<<sl.wildcardMatching(S1, S2)<<endl;

  return 0;
}
