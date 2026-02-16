/* Climbing Stairs
Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the "Nth" stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.

Input: n = 2
Output: 2
Explanation: There are 2 unique ways to climb to the 2nd step:
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are 3 unique ways to climb to the 3rd step:
1. 1 step + 1 step + 1 step
2. 2 steps + 1 step
3. 1 step + 2 steps
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfWays(int n){

  //   if(n<=1) return 1;
  //   return numberOfWays(n-1) + numberOfWays(n-2);
  vector<int> dp(n + 1, -1);
  // Base cases
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
  }
};

int main() {
  Solution sl;
  cout<<sl.numberOfWays(3)<<endl;
  return 0;
}
