/*Count Partitions with Given Difference
Given an array with N positive integers and an integer D, count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.
Examples
Input: arr = [1, 1, 2, 3], diff = 1
Output: 3
Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3]. 
Input:  arr = [1, 2, 3, 4], diff = 2
Output: 2
Explanation: The subsets are [1, 3] and [2, 4], [1, 2, 3] and [4]. 
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
private:
    int solve(vector<int> &list, int idx, int target, vector<vector<int>> &dp){
      if(target == 0) return 1;
      if(idx == 0) return (target == list[0])? 1 : 0;
      
      if(dp[idx][target] != -1) return dp[idx][target];

      int notPick = solve(list, idx-1, target, dp);
      int pick = false;
      if(list[idx] <= target){
        pick = solve(list, idx-1, target - list[idx], dp);
      }
      return dp[idx][target] = notPick + pick;
    }
public:
  int countPartWithDiff(vector<int> &list, int len, int diff){
    int sum = accumulate(list.begin(), list.end(), 0);
    vector<int> subsets;

    if((sum + diff) % 2 != 0 || sum < diff) return 0;

    vector<vector<int>> dp(len, vector<int>((sum+diff)/2 + 1, -1));
    
    return solve(list, len-1, (sum+diff)/2, dp);    
  }
};

int main() {
  int diff = 0;
  int len = 0;
  cin>>diff;
  cin>>len;
  vector<int> list(len);
  for(int i = 0; i < len; i++)
    cin>>list[i];
  
  Solution sl;
  cout<<"count: "<<sl.countPartWithDiff(list, len, diff)<<endl;
  return 0;
}
