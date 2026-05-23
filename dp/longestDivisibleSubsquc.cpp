/* Longest Divisible Subset
Problem Statement: Given an array nums of positive integers, the task is to find the largest subset such that every pair (a, b) of elements in the subset satisfies a % b == 0 or b % a == 0.

Return the subset in any order. If there are multiple solutions, return any one of them.

Note: As there can be multiple correct answers, the compiler returns 1 if the answer is valid, else 0.

Examples
Example 1:
Input:
 nums = [3, 5, 10, 20]  
Output:
 [5, 10, 20]
Explanation:
 The subset [5, 10, 20] satisfies the divisibility condition:  
- 10 % 5 == 0
- 20 % 10 == 0

Example 2:
Input:
 nums = [16, 8, 2, 4, 32]
Output:
 [2, 4, 8, 16, 32]
Explanation:
 The entire array forms a divisible subset since:
- 32 % 16 == 0
- 16 % 8 == 0 
- 8 % 4 == 0
- 4 % 2 == 0

APPROACH
--------
- Sort: Order the array ascending.
- Initialize: Set dp lengths to 1. Point parent pointers to themselves.
- Update: For each element, find previous divisors. If they extend the chain length, update dp and parent.
- Track: Record the maximum subset length and its ending index.
- Backtrack: Follow parent pointers from the ending index to reconstruct the subset.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1), parent(n), temp;
    
    int maxLen = 0, lastIdx = 0;

    for(int i = 0; i < n; i++){
      parent[i] = i;
      for(int prevI = 0; prevI < i; prevI++){
        if(nums[i] % nums[prevI] == 0 && dp[i] < dp[prevI] + 1){
          dp[i] = dp[prevI] + 1;
          parent[i] = prevI;
        }
      }
      if(dp[i] > maxLen){
        lastIdx = i;
        maxLen = dp[i];
      }
    }
    // Backtracking
    int i = lastIdx;
    while(parent[i] != i) {
      temp.push_back(nums[i]);
      i = parent[i]; 
    }
    temp.push_back(nums[i]);

    return temp;
  }  
};

int main() {
  vector<int> nums = {3,4,16,8};
  Solution sol;
  vector<int> ans = sol.largestDivisibleSubset(nums);
  for(int x : ans) cout << x << " ";
  
  return 0;
}
