#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long helper(vector<int> &piles, int rate) {
    long long sum = 0;
    for (int p : piles)
      sum += (p + 1LL * rate - 1) / rate;
    return sum;
  }

public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    int ans = r;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (helper(piles, mid) <= h) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    return ans;
  }
};