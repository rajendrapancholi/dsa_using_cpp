/* Palindrome Partitioning
Problem Description: Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s.

Examples
Input: s = "bababcbadcede"
Output: 4
Explanation: If we do 4 partitions in the following way, each substring of the partition will be a palindrome.
bab | abcba | d | c | ede.
Input: s = "aab"
Output: 1 
Explanation: If we do 1 partition in the following way, each substring of the partition will be a palindrome.
aa | b.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool isPalindrome(int i, int j, const string &s) {
    while (i < j) {
      if (s[i] != s[j]) return false;
      i++, j--;
    }
    return true;
  }


  int helper(int i, int j, string &s, vector<int> &dp){
    if (i == j) return 0;
    if(dp[i] != -1) return dp[i];

    int minCuts = 1e9;
    
    for (int k = i; k < j; k++) {
      if (isPalindrome(i, k, s)) {
        int cost = 1 + helper(k + 1, j, s, dp);
        minCuts = min(minCuts, cost);
      }
    }
    return dp[i] = minCuts;
  }
public:
  int minPalindromPartition(string &s){
    int i = 0, n = s.size();
    if (n == 0) return 0;
    vector<int> dp(n, -1);
    return helper(i, n, s, dp) - 1;
  }
  
  int minPalindromPartitionTab(string &s){
    int n = s.size();
    if (n == 0) return 0;
    vector<int> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; i--){
      int minCuts = 1e9;
      for (int k = i; k < n; k++) {
        if (isPalindrome(i, k, s)) {
          int cost = 1 + dp[k + 1];
          minCuts = min(minCuts, cost);
        }
      }
      dp[i] = minCuts;
    }
    return dp[0] - 1;
  }
};

int main() {
  string s = "bababcbadcede";
  // string s = "aab";
  Solution sl;
  cout<<sl.minPalindromPartition(s)<<endl;
  cout<<sl.minPalindromPartitionTab(s)<<endl;
  return 0;
}
