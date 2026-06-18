/* Jump Game 2
You are given a 0-indexed array nums of length n representing your maximum jump capability from each index.

You start at index 0. Each element nums[i] represents the maximum number of steps you can jump forward from index i.
Your goal is to reach the last index of the array (nums[n - 1]) using the minimum number of jumps
Return the minimum number of jumps required to reach the last index.
You can assume that it is always possible to reach the last index.

Examples
Input: nums = [2, 3, 1, 1, 4]
Output: 2
Explanation: Jump from index 0 → 1 → 4.

Input:
 nums = [2, 3, 0, 1, 4]
Output: 2
Explanation: Jump from index 0 → 1 → 4.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int helper(vector<int> &nums, int i){
    if(i >= nums.size() - 1) return 0;
    if(nums[i] == 0) return 1e9;
    int mj = 1e9;
    for(int idx = 1; idx <= nums[i]; idx++){
      int step = helper(nums, i + idx);
      if(step != 1e9){
        mj = min(mj, 1 + step);
      }
    }
    return mj;
  }
public:
  int minJump2Target(vector<int> &nums){
    // int n = nums.size();
    // return helper(nums, 0);
    
    int mxi = 0;
    int mj = 1e9;
    for(int i = 0; i < nums.size(); i++){
      if(i > mxi) return 0;
      mxi = max(mxi, i + nums[i]);
      if(i + nums[i] == nums.size() - 1){
        mj = min(mj, i + 1);
      }
      if (mxi >= nums.size() - 1) return mj; 
    }

    return mj;
  }
};

int main() {
  vector<int> nums = {2, 3, 1, 1,   4};
  // vector<int> nums = {2, 3, 0, 1, 4};
  Solution sl;
  cout<<sl.minJump2Target(nums)<<endl;
  return 0;
}
