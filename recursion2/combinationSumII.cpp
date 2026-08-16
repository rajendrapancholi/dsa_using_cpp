/* Combination Sum II - Find all unique combinations
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Examples
Example 1:
Input: candidates =  [10,1,2,7,6,1,5], target = 8
Output: 
[
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
]
Explanation: These are the unique combinations whose sum is equal to target.
 
Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]
Explanation: These are the unique combinations whose sum is equal to target.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  void helper(int start, int target, vector<int> temp, vector<int> &nums, vector<vector<int>> &ans){
    if(target == 0){
      ans.push_back(temp);
    }
    for(int i = start; i < nums.size(); i++){
      if(i > start && nums[i] == nums[i-1]) continue;
      temp.push_back(nums[i]);
      helper(i + 1, target - nums[i], temp, nums, ans);
      temp.pop_back();
    }
  }
public:
  vector<vector<int>> combSum(int target, vector<int> &nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    helper(0, target, {}, nums, ans);
    return ans;
  }
};

int main() {
  vector<int> nums = {10,1,2,7,6,1,5};
  int target = 8;
  /*Output: 
    [ [1,1,6],
      [1,2,5],
      [1,7],
      [2,6] ] 
  */
  Solution sl;
  for(auto it: sl.combSum(target, nums)) {
    for(auto e: it) {
      cout<<e<<" ";
    }
    cout<<endl;
  }
  return 0;
}
