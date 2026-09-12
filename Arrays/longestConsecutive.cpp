/* Longest Consecutive Sequence in an Array
Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers. The integers
in this sequence can appear in any order. Examples Example 1: Input: nums =
[100, 4, 200, 1, 3, 2] Output:
 4
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4],
which has a length of 4. This sequence can be formed regardless of the initial
order of the elements in the array.

Example 2:
Input:
nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output:
9
Explanation:
 The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5,
6, 7, 8], which has a length of 9. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    unordered_set<int> st;
    for (int n : nums) {
      st.insert(n);
    }
    int longest = 0;
    for (int e : st) {
      if (st.find(e - 1) == st.end()) {
        int count = 1, x = e;
        while (st.find(x + 1) != st.end())
          count++, x++;
        longest = max(longest, count);
      }
    }
    return longest;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> nums = {100, 4, 200, 1, 3, 2}; // Output: 4
  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};     // Output: 9
  Solution sol;
  auto result = sol.longestConsecutive(nums);
  cout << result << endl;

  return 0;
}

