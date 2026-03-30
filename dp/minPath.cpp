/* Minimum path sum
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

private:
public:
  int minPathSum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i == m - 1 && j == n - 1) 
            dp[i][j] = grid[i][j];
        else {
          int down = (i + 1 < m) ? dp[i + 1][j] : 1e9; 
          int right = (j + 1 < n) ? dp[i][j + 1] : 1e9;
          dp[i][j] = grid[i][j] + min(down, right);
        }
      }
    }
    return dp[0][0];
  }
};

int main(){
  vector<vector<int>> grid =  {{1,3,1},{1,5,1},{4,2,1}};
  Solution sl;

  cout<<sl.minPathSum(grid)<<endl;

  return 0;
}
