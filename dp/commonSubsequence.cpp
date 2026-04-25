/* Print Longest Common Subsequence
Given two strings str1 and str2, print the longest common subsequence of the two strings.

A subsequence of a string is a list of characters of the string where zero or more characters are deleted and they should be in the same order in the subsequence as in the original string.

Pre-requisite: Longest Common Subsequence

Examples
Input: str1 = "abcd", str2="bdef"
Output: "bd"
Explanation: LCS of two strings is "bd".
Input: str1 = "apple" str2 = "waffle"
Output: "ale"
Explanation: LCS of two strings is "ale".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestCommonSubsequence(string &text1, string &text2){
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // int ans = 0;
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        if (text1[i - 1] == text2[j - 1]){
          dp[i][j] = 1 + dp[i - 1][j - 1];
          // ans = max(ans, dp[i][j]);
        }
        else{
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          // dp[i][j] = 0;
        }
      }
    }

    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0){
      if (text1[i - 1] == text2[j - 1]){
        lcs += text1[i - 1];
        i--;
        j--;
      } else if (dp[i - 1][j] > dp[i][j - 1]){
        i--;
      } else{
        j--;
      }
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;
  }
};

int main() {
  string s1 = "abcde";
  string s2 = "ace"; Solution sol;
  cout << "LCS: " << sol.longestCommonSubsequence(s1, s2) << endl;
  cout<<"LCS lenght: " << sol.longestCommonSubsequence(s1, s2).size()<<endl;
  return 0;
}
