/* Length of the longest subarray with zero Sum
Given an array containing both positive and negative integers, we have to find
the length of the longest subarray with the sum of all elements equal to zero.

Examples
Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result:
 5
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result:
 8
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthLongestSubarrayO(vector<int> &nums) {
    unordered_map<int, int> sumIndexMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
      sum += nums[i];
      if (sum == 0)
        maxLen = i + 1;
      else if (sumIndexMap.find(sum) != sumIndexMap.end())
        maxLen = max(maxLen, i - sumIndexMap[sum]);
      else
        sumIndexMap[sum] = i;
    }
    return maxLen;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> nums = {9, -3, 3, -1, 6, -5}; // Result: 5
  Solution sl;
  auto result = sl.lengthLongestSubarrayO(nums);

  cout << result << "\n";

  return 0;
}