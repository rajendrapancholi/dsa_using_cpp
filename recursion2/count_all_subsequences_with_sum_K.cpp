/* Count all subsequences with sum K
Given an array nums and an integer k. Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

Examples
Example 1:
Input :
 nums = [4, 9, 2, 5, 1] , k = 10
Output :
 2
Explanation :
 The possible subsets with sum k are [9, 1] , [4, 5, 1].

Example 2:
Input :
 nums = [4, 2, 10, 5, 1, 3] , k = 5
Output :
 3
Explanation :
 The possible subsets with sum k are [4, 1] , [2, 3] , [5].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> mp;
public:
  int cntSubSqWithSumK(int idx, int sum, int currSum, int cnt, vector<int>& nums){
    if(idx == nums.size()){
      if(currSum == sum){
        cnt++;
      }
      return cnt;
    };
    int ans = cntSubSqWithSumK(idx+1, sum, currSum  + nums[idx], cnt, nums) + cntSubSqWithSumK(idx+1, sum, currSum,  cnt, nums);
    
    return ans;
  }
};

int main() {
  vector<int> nums = {4, 2, 10, 5, 1, 3};
  int k = 5; //Output : 2

  Solution sl;
  cout<<sl.cntSubSqWithSumK(0, k, 0, 0, nums);
  return 0;
}
