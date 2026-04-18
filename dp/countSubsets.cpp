/* Count total subsets of given target
Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K.
Examples
Input: arr = [1, 2, 2, 3], K = 3
Output: 3
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int solve(vector<int> &list, int k, int i, vector<vector<int>> &dp){
    // find the subset
    if(k == 0) return 1;
    if(i == 0) return (list[0] == k) ? 1 : 0;
    if(i < 0) return 0; 
    
    if(dp[i][k]!=-1) return dp[i][k];

    int notPick = solve(list, k, i-1, dp);
    int pick = 0;
    if(list[i] <= k )
      pick = solve(list, k-list[i], i-1, dp);
  

    return dp[i][k] = pick + notPick;
  }
public:
  int countSubsets(vector<int> &list, int k, int len){
    vector<vector<int>> dp(len, vector<int>(k+1, -1));
    return solve(list, k, len-1, dp);
  }
};

int main() {
  Solution sl;
  int k = 3;
  cin>>k; // target
  int len=0; // length of the list
  cin>>len;
  vector<int> list(len);
  for(int i=0; i<len; i++){
    cin>>list[i];
  }
  cout<<sl.countSubsets(list, k, len)<<endl;

  return 0;
}
