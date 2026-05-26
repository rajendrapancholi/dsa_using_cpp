/* Burst Balloons
Problem Statement: You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array. You are asked to burst all the balloons.
If you burst the ith balloon, you will get arr[i - 1] * arr[i] * arr[i + 1] coins. If i - 1 or i + 1 goes out of the array's bounds, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Examples

Example 1:
Input: N = 4, array[] = {3, 1, 5, 8}
Output: 167
Explanation: First, we will burst the second balloon with the value 1. Coins = 3*1*5 = 15. Second, we will burst the balloon with the value 5. Coins = 3*5*8 = 120. Third, we will burst the balloon with the value 3. Coins = 1*3*8 = 24. Fourth, we will burst the balloon with the value 8. Coins = 1*8*1 = 8. So, the total number of coins we can collect is 167. This is the maximum number of coins we can collect.

Example 2:
Input: N = 2, array[] = {1, 5}
Output: 10
Explanation:
First, we will burst the second balloon with the value 1. Coins = 1*1*5 = 5. Second, we will burst the balloon with the value 5. Coins = 1*5*1 = 5. So, the total number of coins we can collect is 10. This is the maximum number of coins we can collect.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int maxCost = 0;
    for(int k = i; k <= j; k++){
      int cost = cost = arr[i - 1] * arr[k] * arr[j + 1];
      maxCost = max(maxCost, cost + helper(i, k - 1, arr, dp) + helper(k + 1, j, arr, dp));
    }
    return dp[i][j] = maxCost;
  }

public:
  int maxBurstBalloons(int n, vector<int> &arr){
    vector<int> tempArr;
    tempArr.push_back(1);
  
    for (int val : arr) {
      tempArr.push_back(val);
    }
    tempArr.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    return helper(1, n, tempArr, dp);
  }

  int maxBurstBalloonsTab(int n, vector<int> &arr){
    vector<int> tempArr;
    tempArr.push_back(1);
  
    for (int val : arr)
      tempArr.push_back(val);
    
    tempArr.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for(int i = n; i >= 1; i--){
      for(int j = i; j <= n; j++){
        if(i > j) continue;
        int maxCost = 0;
        for(int k = i; k <= j; k++){
          int cost = cost = tempArr[i - 1] * tempArr[k] * tempArr[j + 1];
          maxCost = max(maxCost, cost + dp[i][k - 1] + dp[k + 1][j]);
        }
        dp[i][j] = maxCost;
      }
    }

    return dp[1][n];
  }
};

int main() {
  vector<int> arr = {3, 1, 5, 8};
  int n = 4;

  Solution sl;
  cout<<sl.maxBurstBalloons(n, arr)<<endl;
  cout<<sl.maxBurstBalloonsTab(n, arr)<<endl;
  return 0;
}
