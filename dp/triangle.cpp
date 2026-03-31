#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int solve(vector<vector<int>> &triangle, int m, int i, int j, vector<vector<int>> &dp){
  
    if (i == m - 1) {
      return triangle[i][j];
    }

    if(dp[i][j] != -1) return dp[i][j];

    int bottom = solve(triangle, m, i+1, j, dp);
    int bottomR = solve(triangle, m, i+1, j+1, dp);
    
    return dp[i][j] = triangle[i][j] + min(bottom, bottomR);	
  }

  int minimumPathSum(vector<vector<int>> &triangle)
  {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(triangle, n, 0, 0, dp);
  }
};

int main()
{
  Solution obj;
  vector<vector<int>> triangle{
      {1},
      {2, 3},
      {3, 6, 7},
      {8, 9, 6, 10}};
  cout << obj.minimumPathSum(triangle);
  return 0;
}
