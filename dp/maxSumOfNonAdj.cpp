/* Maximum sum of non-adjacent elements
Problem Statement: Given an array of N positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.
Note: A subsequence of an array is a list with elements of the array where some elements are deleted (or not deleted at all) and the elements should be in the same order in the subsequence as in the array.
Examples
Input: nums = [1, 2, 4]
Output: 5
Explanation: 
Subsequence {1,4} gives maximum sum.

Input:  [2, 1, 4, 9]
Output: 11
Explanation: 
Subsequence {2,9} gives maximum sum
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // 1. Memoization
  int solve(vector<int>& arr, int i, vector<int>& dp){
    if(i<0) return 0;
    if(i==0) return arr[0];
    if(dp[i]!=-1) return dp[i];
    int pick = arr[i] + solve(arr, i-2, dp);
    int notPick = solve(arr, i-1, dp);
    return dp[i] = max(pick, notPick);
  }

  int maxNosAdjSum(vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(arr, n-1, dp);
  }

  // 2. Tabulation
  int maxNosAdjSum2(vector<int>& arr){
    int n = arr.size();
    if(n==1) return arr[0];
    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i=2; i<n; i++){
      dp[i] = max(arr[i]+dp[i-2], dp[i-1]);
    }
    return dp[n-1];
  }

  // 3. Space Optimization
  int maxNosAdjSum3(vector<int>& arr){
    int n = arr.size();
    if(arr.empty()) return 0;
    vector<int> dp(n);
    int prev2 = 0;
    int prev = arr[0];
    for(int i=1; i<n; i++){
      int pick = arr[i]+prev2;
      int notPick = prev;
      int curr = max(pick, notPick);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
};

int main() {
  vector<int> arr = {2,1,4,9}; // 11
  vector<int> arr2 = {3,2,5,10,7}; // 15
  Solution sl;
  cout<<sl.maxNosAdjSum(arr)<<endl;
  cout<<sl.maxNosAdjSum2(arr)<<endl;
  cout<<sl.maxNosAdjSum3(arr2)<<endl;
  return 0;
}
