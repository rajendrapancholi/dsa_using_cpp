#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  vector<int> segMin, segMax, lazy;

  void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
      segMin[node] += lazy[node];
      segMax[node] += lazy[node];

      if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void updateRange(int node, int start, int end, int ql, int qr, int val) {
    propagate(node, start, end);
    // No overlap
    if (qr < start || end < ql) return;
    // Full overlap
    if (ql <= start && end <= qr) {
      lazy[node] += val;
      propagate(node, start, end);
      return;
    }
    // Partial overlap
    int mid = start + (end - start) / 2;
    updateRange(2 * node, start, mid, ql, qr, val);
    updateRange(2 * node + 1, mid + 1, end, ql, qr, val);

    segMax[node] = max(segMax[2 * node], segMax[2 * node + 1]);
    segMin[node] = min(segMin[2 * node], segMin[2 * node + 1]);
  }

  int findLeftMostZero(int node, int start, int end) {
    propagate(node, start, end);
    if (segMin[node] > 0 || segMax[node] < 0)
      return -1;

    if (start == end) {
      return start;
    }

    int mid = start + (end - start) / 2;
    int l = findLeftMostZero(2 * node, start, mid);
    if (l != -1) {
      return l;
    }
    return findLeftMostZero(2 * node + 1, mid + 1, end);
  }

public:
  int balancedEvenOddSubArr(vector<int> &arr) { // TC = O(n^2); SC = O(n);
    int n = arr.size(), mxL = 0;
    unordered_map<int, int> mp;
    vector<int> cumSum(n, 0);
    for (int r = 0; r < n; r++) {
      int val = arr[r] % 2 == 0 ? 1 : -1;
      int prev = -1;

      if (mp.count(arr[r])) {
        prev = mp[arr[r]];
      }

      if (prev != -1) {
        for (int l = 0; l <= prev; l++) {
          cumSum[l] -= val;
        }
      }

      for (int l = 0; l <= r; l++) {
        cumSum[l] += val;

        if (cumSum[l] == 0)
          mxL = max(mxL, r - l + 1);
      }

      // for(int l=0; l<=r; l++){
      //   if(cumSum[l] == 0){
      //     mxL = max(mxL, r-l+1);
      //     break;
      //   }
      // }
      mp[arr[r]] = r;
    }

    return mxL;
  }

  int balancedEvenOddSubArrII(vector<int> &arr) { // TC = O(nlog(n)); SC = O(4n+4n+4n);
    int n = arr.size(), mxL = 0;

    segMax.assign(4*n, 0);
    segMin.assign(4*n, 0);
    lazy.assign(4*n, 0);

    unordered_map<int, int> mp;

    for (int r = 0; r < n; r++) {
      int val = arr[r] % 2 == 0 ? 1 : -1;
      int prev = -1;

      if (mp.count(arr[r])) {
        prev = mp[arr[r]];
      }

      if (prev != -1){
        updateRange(1, 0, n-1, 0, prev, -val);
      }
      
      updateRange(1, 0, n-1, 0, r, val);
      
      int l = findLeftMostZero(1, 0, n-1);
      if (l != -1)
        mxL = max(mxL, r - l + 1);
      
      mp[arr[r]] = r;
    }

    return mxL;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr = {1, 2, 3, 2}; // 3-> {1,2}, {2,3}, {3,2}
  Solution sl;

  // auto result = sl.balancedEvenOddSubArr(arr);
  // cout << result << "\n";
  auto result = sl.balancedEvenOddSubArrII(arr);
  cout << result << "\n";

  return 0;
}