/* 4 Sum | Find Quads that add up to a target value
Given an array of N integers, your task is to find unique quads that add up to
give a target value. In short, you need to return an array of all the unique
quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a
given target.

Note: a, b, c and d are also distinct and lies between 0 to n-1 (both
inclusive). Examples Example 1: Input Format:arr[] = [1,0,-1,0,-2,2], target = 0
Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation:We have to find unique quadruplets from the array such that the sum
of those elements is equal to the target sum given that is 0. The result
obtained is such that the sum of the quadruplets yields 0.

Example 2:
Input Format: arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9
Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
Explanation: The sum of all the quadruplets is equal to the target i.e. 9. */

#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
  // TC = O(n^3 + nlogn) = O(n^3)
  // SC = O(n) = O(1): : O(no. of quadruplets), as This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).

  vector<vector<int>> fourSum(vector<int> &nums, int target) { 
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int l = j + 1, r = n - 1;
        while (l < r) {
          long long sum = (long long)nums[i] + nums[l] + nums[r];
          if (sum == target) {
            res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
            while (l < r && nums[l] == nums[l - 1])
              l++;
            while (l < r && nums[r] == nums[r + 1])
              r--;
          } else if (sum < target) {
            l++;
          } else
            r--;
        }
      }
    }
    return res;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> nums = {4,3,3,4,4,2,1,2,1,1}; // [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
  int target = 9;
  Solution sl;
  auto result = sl.fourSum(nums, target);

  for (auto r : result) {
    cout << "[ ";
    for (auto e : r) {
      cout << e << " ";
    }
    cout << "]\n";
  }

  return 0;
}