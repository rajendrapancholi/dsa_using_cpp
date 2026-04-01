/* Ninja and his friends
Problem Statement:  We are given an ‘MxN’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, n-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙). When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once. They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect.
Examples
Example 1:
Input: ‘R’ = 3, ‘C’ = 4
‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21
Example 2:
Input: ‘R’ = 2, ‘C’ = 3
‘GRID’ = [[4, 1, 2], [7, 3, 5]]
Output: 18
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxNoOfChoco(vector<vector<int>> grid, vector<vector<vector<int>>>& dp, int m, int n, int i, int j1, int j2){
    
    if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;
    
    if(i == m-1) return (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e9;

    int currentVal = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

    // Explore all 9 combinations of moves
    for (int alice = -1; alice <= 1; alice++) {
        for (int bob = -1; bob <= 1; bob++) {
            int res = maxNoOfChoco(grid, dp, m, n, i + 1, j1 + alice, j2 + bob);
            maxi = max(maxi, currentVal + res);
        }
    }

    return dp[i][j1][j2] = maxi;
  }
};

int main() {
  vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}}; // 21
  vector<vector<int>> grid2 = {{4, 1, 2}, {7, 3, 5}}; // 18
  int m = grid2.size();
  int n = grid2[0].size();
  vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
  
  Solution sl;

  cout<<sl.maxNoOfChoco(grid2, dp, m, n, 0, 0, n-1)<<endl;
  return 0;
}
