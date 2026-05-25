/* Minimum cost to cut the stick
Problem Description: We are given a stick of length N and a cuts array of size C. The stick has markings as shown, and the cuts array depicts the marking at which the stick needs to be cut (shown in red).

Note: It is necessary to make cuts at all the red markings.

Whenever we make a cut, we incur a cost. This cost is equal to the length of the stick on which we are making the cut.

We need to find the minimum cost incurred to cut the stick at all the cut points.

Examples
Input: n = 7, cuts = [1, 3, 4, 5]
Output: 16
Explanation: Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16

Input: n = 7, cuts = [1, 3, 6]
Output: 14
Explanation: The optimal order for cutting the stick is [3, 1, 6].
The cost will be => 7 + 3 + 4 => 14.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j) return 0; // base case
    if(dp[i][j] != -1) return dp[i][j];
    int minCost = 1e9;
    
    for(int k = i; k <= j; k++){
      int cost = cuts[j + 1] - cuts[i - 1] + helper(i, k - 1, cuts, dp) + helper(k + 1, j, cuts, dp);
      minCost = min(minCost, cost);
    }
    
    return dp[i][j] = minCost;
  }

public:
  int minCostCutStick(int n, vector<int> &cuts){
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return helper(1, c, cuts, dp);
  }

  int minCostCutSickTab(int n, vector<int> &cuts){
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for(int i = c; i >= 1; i-- ){
      for(int j = 1; j <= c; j++){
        if(i > j)
          continue;
        int minCost = 1e9;
        for(int k = i; k <= j; k++){
          int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
          minCost = min(minCost, cost);
        }
        dp[i][j] = minCost; 
      }
    }
    return dp[1][c];
  }
};

int main() {
  vector<int> cuts = {1, 3, 6}; 
  int n = 7;

  Solution sl;
  // cout<<sl.minCostCutStick(n, cuts)<<endl;
  cout<<sl.minCostCutSickTab(n, cuts)<<endl;
  return 0;
}
