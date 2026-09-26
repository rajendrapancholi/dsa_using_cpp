#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool helper(const vector<int> &bloomDay, int day, int m, int k) {
    int consecutive = 0, bouquets = 0;
    for (int bloom : bloomDay) {
      if (bloom <= day) {
        consecutive++;
        if (consecutive == k)
          bouquets++, consecutive = 0;
      } else
        consecutive = 0;
    }
    return bouquets >= m;
  }

public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    if ((long long)m * k > bloomDay.size())
      return -1;
    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = r;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (helper(bloomDay, mid, m, k))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};