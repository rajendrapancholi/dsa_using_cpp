/* Longest Increasing Subsequence | Binary Search
Problem Statement: Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].

The task is to find the length of the longest subsequence in which every element is greater than the previous one.

Note: In this article, we will solve the problem of the longest-increasing subsequence using binary search.

Examples
Example 1:
Input:
 nums = [10, 9, 2, 5, 3, 7, 101, 18]  
Output:
 4  
Explanation:
 The longest increasing subsequence is [2, 3, 7, 101], and its length is 4.

Example 2:
Input:
 nums = [0, 1, 0, 3, 2, 3]  
Output:
 4  
Explanation:
 The longest increasing subsequence is [0, 1, 2, 3], and its length is 4.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int LIS(vector<int> &nums){
    int n = nums.size();
    if( n == 0) return 0;

    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i < n; i++){
      if(nums[i] > temp.back()) 
        temp.push_back(nums[i]);
      else {
        int idx = lower_bound(temp.begin(), temp.end(), temp.back()) - temp.begin();
        temp[idx] = nums[i];
      }
    }
    return temp.size();
  }
  int LIS_Tabulation(vector<int> &nums){
    int maxLen = 0, n = nums.size();
    
    vector<int> dp(n, 1);
    
    for(int i = 0; i < n; i++){
      for(int prevI = 0; prevI < i; prevI++){
        if(nums[i] < nums[prevI] && dp[i] < dp[prevI] + 1)
          dp[i] = dp[prevI] + 1;
      }
      if(maxLen < dp[i])
        maxLen = dp[i];
    }
    return maxLen;
  }
};

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  Solution sl;

  cout<<sl.LIS(nums)<<endl;
  cout<<sl.LIS_Tabulation(nums)<<endl;
  return 0;
}
