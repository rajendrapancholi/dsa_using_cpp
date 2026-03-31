/* Minimum Path Sum In a Grid
Problem Statement: Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Examples
Input: grid = [[5,9,6],[11,5,2]]
Output: 21
Explanation: Minimum sum is achieved via path 5->9->5->2 i.e. 21.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dp){
    if(i < 0 || j < 0) return 1e9;
    if(i == 0 && j == 0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int up = minPathSum(grid, m, n, i-1, j, dp);
    int left = minPathSum(grid, m, n, i, j-1, dp);

    return dp[i][j] = grid[i][j] + min(up, left);
  }
};

int main() {
  vector<vector<int>> grid = {{5,9,6},{11,5,2}};
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n, -1));
  Solution sl;
  cout<<sl.minPathSum(grid, m, n, m-1, n-1, dp);
  return 0;
}
