/* Number of Longest Increasing Subsequences
Problem Description: Given an integer array nums, find the number of Longest Increasing Subsequences (LIS) in the array.

The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order.

Prerequisite:Longest increasing subsequence, Printing Longest Increasing subsequence

Examples
Input: nums = [1, 3, 5, 4, 7]
Output: 2
Explanation: There are two LIS of length 4: [1, 3, 4, 7] and [1, 3, 5, 7].

Input: nums = [2, 2, 2, 2, 2]
Output: 5 
Explanation: All elements are the same, so every single element can form an LIS of length 1. There are 5 such subsequences.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int numberOfLIS(vector<int> &nums){
    int n = nums.size(), ans = 0, maxLen = 0;
    vector<int> dp(n, 1), ct(n, 1);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
        if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
          dp[i] = dp[j] + 1;
          ct[i] = ct[j]; // reset
        } else if(nums[j] < nums[i] && dp[i] == dp[j] + 1){
          ct[i] = ct[i] + ct[j];
        }
      }
      if(maxLen < dp[i]) maxLen = dp[i];
    }
    
    for(int i = 0; i < n; i++){
      if(dp[i] == maxLen){
        ans += ct[i];
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 4, 7};
  Solution sl;
  cout<<sl.numberOfLIS(nums)<<endl;
  return 0;
}
