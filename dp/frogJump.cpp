/* Frog Jump
Problem Statement: Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1..

Examples
Example 1:
Input: heights = [2, 1, 3, 5, 4]
Output: 2
Explanation: One possible route can be,
0th step -> 2nd Step = abs(2 - 3) = 1
2nd step -> 4th step = abs(3 - 4) = 1
Total = 1 + 1 = 2.

Example 2:
Input: heights = [7, 5, 1, 2, 6]
Output: 9
Explanation: One possible route can be,
0th step -> 1st Step = abs(7 - 5) = 2
1st step -> 3rd step = abs(5 - 2) = 3
3rd step -> 4th step = abs(2 - 6) = 4
Total = 2 + 3 + 4 = 9.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(int i, vector<int>& heights, vector<int>& dp) {
    if (i == 0) return 0; 
    if (dp[i] != -1) return dp[i];
    int jumpOne = solve(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    int jumpTwo = INT_MAX;
    if (i > 1) {
      jumpTwo = solve(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
    }

    return dp[i] = min(jumpOne, jumpTwo);
  }

  // step 1
  int frogJump(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
  }

  // Step 2
  int tabulation(vector<int> &heights, int n){
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<n; i++){
      int jumpOne = dp[i-1] + abs(heights[i] - heights[i-1]);
      int jumpTwo = INT_MAX;
      if(i>1){
        jumpTwo = dp[i-2] + abs(heights[i]-heights[i-2]);
      }
      dp[i] = min(jumpOne, jumpTwo); 
    }
    return dp[n-1];
  }
  // step 3
  int spaceOptimization(vector<int> &heights, int n){
    int prev1 = 0;
    int prev2 = 0;  
    int curr = INT_MAX;
    for(int i=1; i<n; i++){
      int jumpOne = prev1 + abs(heights[i] - heights[i-1]);
      int jumpTwo = INT_MAX;
      if(i>1){
        jumpTwo = prev2 + abs(heights[i]-heights[i-2]);
      }
      curr = min(jumpOne, jumpTwo);
      prev2 = prev1;
      prev1 = curr;
    }
    return curr;
  }
};

int main() {
  vector<int> heights = {7, 5, 1, 2, 6};
  Solution sl;

  cout<<"Using Recursion (top-down):\n";
  cout<<sl.frogJump(heights)<<endl;
  cout<<"Using tabulation (bottom-up):\n";
  cout<<sl.tabulation(heights, 5)<<endl;
  cout<<"Space optimization:\n";
  cout<<sl.spaceOptimization(heights, 5)<<endl;
  return 0;
}
