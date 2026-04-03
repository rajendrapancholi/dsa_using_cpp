/* Partition Equal Subset Sum
Problem Description: Given an array arr of n integers, return true if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal else return false.
Examples
Input: nums = [2, 3, 3, 3, 4, 5]
Output: True
Explanation: Nums can be partitioned into two subsets of sum 10.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
bool subsetSum(int idx, vector<int>& nums, int target, vector<vector<int>>& dp){
  if(target == 0) return true;
  if(idx == 0) return nums[idx] == target;

  if(dp[idx][target] != -1) return dp[idx][target];

  bool notpick = subsetSum(idx-1, nums, target, dp);
  bool pick = false;
  if(nums[idx] <= target){
    pick = subsetSum(idx - 1, nums, target - nums[idx], dp);
  }

  return dp[idx][target] = notpick || pick;
}

public:
  bool partEqSubsetSum(int n, vector<int>& nums, int target){
    if(target % 2 != 0) return false;
    
    target /=2;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    return subsetSum(n-1, nums, target, dp);
  }
  
  // tabulation
  bool partEqSubsetSum2(int n, vector<int>& nums, int totalSum){
    if(totalSum % 2 != 0) return false;
    
    totalSum /=2;
    vector<vector<bool>> dp(n, vector<bool>(totalSum+1, false));

    for(int i = 0; i < n; i++){ // if(target == 0) return true;
      dp[i][0] = true;
    }

    if(nums[0] <= totalSum){ // if(idx == 0) return nums[idx] == target;
      dp[0][nums[0]] = true;
    }

    for(int idx = 1; idx < n; idx++){
      for(int target = 1; target <= totalSum; target++){
        bool notpick = dp[idx - 1][target]; // bool notpick = subsetSum(idx-1, nums, target, dp);
        bool pick = false;
        if(nums[idx] <= target){
          pick = dp[idx - 1][target - nums[idx]]; // pick = subsetSum(idx - 1, nums, target - nums[idx], dp);
        }
        dp[idx][target] = notpick || pick; // dp[idx][target] = notpick || pick;
      }
    }
    return dp[n-1][totalSum];
  }
};

int main() {
  int n = 0, target = 0;
  
  cin>>n;
  vector<int> nums(n);

  for(int i=0; i<n; i++){
    cin>>nums[i];
    target+=nums[i];
  }

  Solution sl;
  cout<<(sl.partEqSubsetSum(n, nums, target)?"True":"False")<<endl;
  cout<<(sl.partEqSubsetSum2(n, nums, target)?"True":"False")<<endl;
  return 0;
}

