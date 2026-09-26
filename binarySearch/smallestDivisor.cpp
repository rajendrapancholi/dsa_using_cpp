#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long helper(const vector<int> &nums, int divisor) {
    long long sum = 0;
    for (int value : nums) {
      sum += (value + divisor - 1) / divisor;
      if (sum > LLONG_MAX)
        break;
    }
    return sum;
  }

public:
  int smallestDivisor(vector<int> &nums, int limit) {
    int l = 1;
    int r = *max_element(nums.begin(), nums.end());
    int ans = r;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      long long sum = helper(nums, mid);
      if (sum <= limit) ans = mid, r = mid - 1;
       else l = mid + 1;
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> nums = {8, 4, 2, 3};
  int limit = 4;
  Solution sl;
  auto result = sl.smallestDivisor(nums, limit);
  cout << result << "\n";

  return 0;
}