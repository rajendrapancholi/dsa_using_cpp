/* Shortest Common Supersequence
We are given two strings ‘S1’ and ‘S2’. We need to return their shortest common supersequence. A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.

Examples
Input : str1 = "mno", str2 = "nop"
Output :"mnop"
Explanation : The shortest common supersequence is "mnop". It contains "mno" as the first three characters and "nop" as the last three characters, thus including both strings as subsequences.

Input :str1 = "dynamic", str2 = "program"
Output : "dynprogramic"
Explanation :The shortest common supersequence is "dynprogramic". It includes all characters from both "dynamic" and "program", with minimal overlap. For example, "dynamic" appears as "dyn...amic" and "program" appears as "...program..." within "dynprogramic".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shortestCommSupersequence(string &text1, string &text2){
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        if (text1[i - 1] == text2[j - 1]){
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else{
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0){
      if (text1[i - 1] == text2[j - 1]){
        ans += text1[i - 1];
        i--;
        j--;
      } else if (dp[i - 1][j] > dp[i][j - 1]){
        ans += text1[i - 1];
        i--;
      } else{
        ans += text2[j - 1];
        j--;
      }
    }

    while (i > 0) {
      ans += text1[i - 1];
      i--;
    }

    while (j > 0) {
      ans += text2[j - 1];
      j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  string s1 = "dynamic", s2 = "program";
  Solution sol;
  cout <<sol.shortestCommSupersequence(s1, s2) << endl;
  return 0;
}
