#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool placable(vector<int> &arr, double mid, int k) {
    int n = arr.size();
    int out = 0;
    for (int i = 0; i < n - 1; i++) {
      int temp = (arr[i + 1] - arr[i]) / mid;
      if ((arr[i + 1] - arr[i]) == temp * mid) {
        out = out + temp - 1;
      } else {
        out = out + temp;
      }
      if (out > k) {
        return false;
      }
    }
    return true;
  }

  double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    if (n < 2) {
      return 0;
    }

    int maxi = -1;
    for (int i = 0; i < n - 1; i++) {
      maxi = max(maxi, arr[i + 1] - arr[i]);
    }
    double low = 0, high = maxi, mid;
    while (high - low > 1e-6) { // 1e-6 = 10^(-6) = 0.000001
      mid = (double)low + (double)(high - low) / 2;
      auto temp = placable(arr, mid, k);
      if (temp) {
        high = mid;
      } else {
        low = mid;
      }
    }
    return high;
  }
};