#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int helper(const vector<int> &weights, int capacity) {
    int total_days = 1, currW = 0;
    for (int w : weights) {
      if (currW + w > capacity) {
        total_days++;
        currW = 0;
      }
      currW += w;
    }
    return total_days;
  }

public:
  int shipWithinDays(vector<int> &weights, int days) {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    int ans = r;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (helper(weights, mid) <= days) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    return ans;
  }
};