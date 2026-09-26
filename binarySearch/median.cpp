#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double median(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return median(nums2, nums1);
    };

    int n = nums1.size();
    int m = nums2.size();

    // calculate total left for correct partition
    int totalLeft = (n + m + 1) / 2;
    int start = 0, end = n;

    while (start <= end) {
      int mid = start + (end - start) / 2;

      int requiredElementOfFirstArray = mid;
      int requiredElementOfSecondArray =
          totalLeft - requiredElementOfFirstArray;

      int l1, l2, r1, r2;

      if (requiredElementOfFirstArray == 0) {
        l1 = INT_MIN;
      } else {
        l1 = nums1[requiredElementOfFirstArray - 1];
      };

      if (requiredElementOfSecondArray == 0) {
        l2 = INT_MIN;
      } else {
        l2 = nums2[requiredElementOfSecondArray - 1];
      };

      if (requiredElementOfFirstArray == n) {
        r1 = INT_MAX;
      } else {
        r1 = nums1[requiredElementOfFirstArray];
      };

      if (requiredElementOfSecondArray == m) {
        r2 = INT_MAX;
      } else {
        r2 = nums2[requiredElementOfSecondArray];
      };

      if (l1 <= r2 && l2 <= r1) { // correct partition
        if ((n + m) % 2 != 0) {   // odd
          return max(l1, l2);
        } else { // even
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        };
      } else if (l1 > r2) {
        end = mid - 1;
      } else {
        start = mid + 1;
      };
    };

    return 0.0;
  }
};

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr1 = {2, 4, 6}, arr2 = {1, 3, 5}; // Output: 3.5

    Solution sl;
    auto result = sl.median(arr1, arr2);
    cout << result << "\n";
    
    return 0;
}