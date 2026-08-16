/* Check if there exists a subsequence with sum K
Given an array nums and an integer k. Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

Examples
Example 1:
Input :
 nums = [1, 2, 3, 4, 5] , k = 8
Output :
 Yes
Explanation :
 The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Example 2:
Input :
 nums = [4, 3, 9, 2] , k = 10
Output :
 No
Explanation :
 No subsequence can sum up to 10.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool helper(int i, int target, int currSum, vector<int>& nums){
    if(currSum == target) return true;
    if(i == nums.size() || currSum > target ){
      return false;
    }
    return helper(i+1, target, currSum + nums[i], nums) || helper(i+1, target, currSum, nums);
  }
public:
  bool isExists(int k, vector<int>& nums){
    return helper(0, k, 0, nums);
  }
};
 
 int main() {
  vector<int> nums = {4, 3, 9, 2};
  int k = 10;
  // Output : Yes
  // Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.
  Solution sl;
  cout<<(sl.isExists(k, nums) ? "Yes" : "No")<<endl;
  return 0;
 }
 