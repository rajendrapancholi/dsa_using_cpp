#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long powerLimited(long long base, int exp, long long limit) {
    long long result = 1;

    while (exp > 0) {
      if (exp & 1) {
        if (result > limit / base) {
          return limit + 1;
        }
        result *= base;
      }

      exp >>= 1;

      if (exp > 0 && base > limit / base) {
        base = limit + 1;
      } else {
        base *= base;
      }
    }

    return result;
  }

public:
  int NthRoot(int N, int M) {
    if (M == 0)
      return 0;
    if (M == 1)
      return 1;

    long long left = 1;
    long long right = M;

    while (left <= right) {
      long long mid = left + (right - left) / 2;
      long long value = powerLimited(mid, N, M);

      if (value == M) {
        return static_cast<int>(mid);
      } else if (value < M) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};
