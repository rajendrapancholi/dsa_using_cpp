/* Maximum Product Subarray in an Array
Given an array that contains both negative and positive
integers, find the maximum product subarray.

Examples
Input: Nums = [1,2,3,4,5,0]
Output: 120
Explanation:
In the given array, 1×2×3×4×5 gives maximum product value.
Input: Nums = [1,2,-3,0,-4,-5]
Output: 20
Explanation:
In the given array, (-4)×(-5) gives maximum product value. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProductSubarrayM1(vector<int> &nums) { // TC = O(n^2), SC = O(1);
    int maxProduct = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int product = nums[i];
      for (int j = i + 1; j < n; j++) {
        product *= nums[j];
        maxProduct = max(maxProduct, product);
      }
    }

    return maxProduct;
  }
  int maxProductSubarrayM2(vector<int> &arr) { // TC = O(n), SC = O(1);
    int n = arr.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (pre == 0)
        pre = 1;
      if (suff == 0)
        suff = 1;
      pre *= arr[i];
      suff *= arr[n - i - 1];

      ans = max(ans, max(pre, suff));
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> nums = {1, 2, 3, 4, 5, 0}; // Output: 120
  // nums = {1,2,-3,0,-4,-5}; // Output: 20
  Solution sl;
  auto result = sl.maxProductSubarrayM1(nums);
  cout << result << "\n";
  result = sl.maxProductSubarrayM2(nums);
  cout << result << "\n";

  return 0;
}