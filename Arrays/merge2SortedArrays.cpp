/* Merge two Sorted Arrays Without Extra Space
Given two sorted integer arrays nums1 and nums2, merge both the arrays into a
single array sorted in non-decreasing order. The final sorted array should be
stored inside the array nums1 and it should be done in-place. Array nums1 has a
length of m + n, where the first m elements denote the elements of nums1 and
rest are 0s whereas nums2 has a length of n.

Examples
Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8]
Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4,
5] are from nums1 and [-3, 1, 8] are from nums2 Input : nums1 = [0, 2, 7, 8, 0,
0, 0], nums2 = [-7, -3, -1] Output :  [-7, -3, -1, 0, 2, 7, 8] Explanation : The
merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and
[-7, -3, -1] are from nums2 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merge2SortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int i = nums1.size() - nums2.size() - 1, j = nums2.size() - 1,
        k = nums1.size() - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }
    while (k >= 0 && j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0},
              nums2 = {-3, 1, 8}; // Output : [-5, -3, -2, 1, 4, 5, 8]

  Solution sl;
  sl.merge2SortedArrays(nums1, nums2);

  for (auto r : nums1) {
    cout << r << " ";
  }

  return 0;
}
