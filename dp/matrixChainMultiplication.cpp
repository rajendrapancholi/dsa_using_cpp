/* Matrix Chain Multiplication
Problem Statement: Given a chain of matrices A1,..., An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices .

Examples
Input :  [40, 20, 30, 10, 30]
Output :  26000 
Explanation :  Best parenthesization is ( (A1 x (A2 x A3)) x A4 ).

Input :  [10, 20, 30, 40, 30] 
Output :  30000 
Explanation :  Optimal parenthesization minimizes cost.
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
  int helper(int i, int j, vector<int> &mat, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int minCost = 1e9;

    for(int k = i; k < j; k++)    {
      int cost = mat[i-1] * mat[k] * mat[j] + helper(i, k, mat, dp) + helper(k + 1, j, mat, dp);

      if(minCost > cost) minCost = cost;
    }

    return dp[i][j] = minCost;
  }
public:
  int matrixChainMulti(vector<int> &mat){
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(1, n - 1, mat, dp);
  }

  int mcmTabulation(vector<int> &mat){
  int n = mat.size();
  vector<vector<int>> dp(n, vector<int>(n, 0)); 
  for(int i = n - 1; i >= 1; i--){
    for(int j = i + 1; j < n; j++){   
      int minCost = 1e9;
      for(int k = i; k < j; k++){
        int cost = mat[i - 1] * mat[k] * mat[j] + dp[i][k] + dp[k + 1][j];
        if(cost < minCost) {
          minCost = cost;
        }
      }
      dp[i][j] = minCost;
    }
  }
  return dp[1][n - 1];
}
};

int main() {
  vector<int> mat = {40, 20, 30, 10, 30};
  Solution sl;
  cout<<sl.matrixChainMulti(mat)<<endl;
  cout<<sl.mcmTabulation(mat)<<endl;
  return 0;
}
