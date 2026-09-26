#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool helper(vector<int> &nums, int limit, int k) {
    int currPages = 0, students = 1;
    for (int n : nums) {
      if (currPages + n > limit)
        students++, currPages = 0;
      currPages += n;
    }
    return students <= k;
  }

public:
  int splitArray(vector<int> &nums, int k) {
    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);
    int ans = r;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (helper(nums, mid, k))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};