#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool helper(int A, int B, const vector<int> &C, long long limit) {
    long long usedPainters = 0;
    int painters = 1;
    for (int n : C) {
      long long board_time = 1LL * n * B;
      if (board_time > limit)
        return false;

      if (usedPainters + board_time > limit) {
        painters++;
        if (painters > A) {
          return false;
        }
        usedPainters = 0;
      }
      usedPainters += board_time;
    }
    return true;
  }

public:
  int paint(int A, int B, vector<int> &C) {

    long long l = 1LL * (*max_element(C.begin(), C.end())) * B;
    long long r = 1LL * accumulate(C.begin(), C.end(), 0LL) * B;
    long long ans = r;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      if (helper(A, B, C, mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    return ans % 10000003;
  }
};