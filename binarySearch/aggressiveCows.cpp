#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool canAssignStalls(const vector<int> &nums, int k, int limit) {
    int cows = 1, lastPosition = nums[0];
    ;
    for (int n : nums) {
      if (n - lastPosition >= limit) {
        cows++;
        if (cows >= k)
          return true;
        lastPosition = n;
      }
    }
    return false;
  }

public:
  int aggressiveCows(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.back() - nums.front();
    int ans = r;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (canAssignStalls(nums, k, mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    return ans;
  }
};