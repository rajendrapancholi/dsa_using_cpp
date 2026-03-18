/* Dynamic Programming: Frog Jump with k Distances

Problem Statement:
A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k. To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
Examples
Example 1:
Input: heights = [10, 5, 20, 0, 15], k = 2
Output: 15
Explanation:
0th step -> 2nd step, cost = abs(10 - 20) = 10
2nd step -> 4th step, cost = abs(20 - 15) = 5
Total cost = 10 + 5 = 15.

Example 2:
Input: heights = [15, 4, 1, 14, 15], k = 3
Output: 2
Explanation:
0th step -> 3rd step, cost = abs(15 - 14) = 1
3rd step -> 4th step, cost = abs(14 - 15) = 1
Total cost = 1 + 1 = 2.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int solve(int i, vector<int> &heights, int k, vector<int> &dp){
    // Base case
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i]; // return memoized value.
    int minStep = INT_MAX;
    for(int j=1; j<=k; j++){
      if(i-j>=0){
        int jumpCost = solve(i - j, heights, k, dp) + abs(heights[i] - heights[i - j]);
        minStep = min(minStep, jumpCost);
      }
    }
    return dp[i] = minStep;
  }

public:  
  int frogKJump(vector<int> &heights, int k){
    int n = heights.size();
    if(n<=1) return 0;
    vector<int> dp(n, -1);
    return solve(n-1, heights, k, dp);
  }

  int tabulation(vector<int> &heights, int k){
    int n = heights.size();
    if(n<=1) return 0;
    
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<n; i++){
      int mimSteps = INT_MAX;
      for(int j=1; j<=k; j++){
        if(i-j>=0){
          int jumpCost = dp[i-j] + abs(heights[i] - heights[i - j]);
          mimSteps = min(mimSteps, jumpCost);
        }
      }
      dp[i] = mimSteps;
    }

    return dp[n-1];
  }
};

int main() {
  vector<int> heights = {10, 5, 20, 0, 15}; // o/p: 15
  int k = 2; // jump step
  vector<int> heights2 = {15, 4, 1, 14, 15}; // o/p: 2
  k = 3;
  Solution sl;
  
  cout<<"Using Recursion (top-down)\n";
  cout<<sl.frogKJump(heights2, k)<<endl;
  cout<<"Using tabulation (bottom-up)\n";
  cout<<sl.tabulation(heights2, k)<<endl;

  return 0;
}
