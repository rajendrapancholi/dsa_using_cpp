/* 3477-II, 3479-III

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void buildST(int node, int start, int end, vector<int> &st, vector<int> &b) {
    if (start == end) {
      st[node] = b[start];
      return;
    }
    int mid = start + (end - start) / 2;
    buildST(2 * node, start, mid, st, b);
    buildST(2 * node + 1, mid + 1, end, st, b);

    int l = st[2 * node];
    int r = st[2 * node + 1];
    st[node] = max(l, r);
  }

  int qeuryST(int node, int l, int r, vector<int> &st, int fruit) {
    if (st[node] < fruit) {
      return false;
    }

    if (l == r) {
      st[node] = -1;
      return true;
    }

    int mid = l + (r - l) / 2;
    bool placed = false;
    if (st[2 * node] >= fruit)
      placed = qeuryST(2 * node, l, mid, st, fruit);
    else
      placed = qeuryST(2 * node + 1, mid + 1, r, st, fruit);

    st[node] = max(st[2 * node], st[2 * node + 1]);

    return placed;
  }

public:
  int fruitAndBasketII(vector<int> &f,
                       vector<int> &b) { // TC = O(n^2); SC = O(1);
    int n = f.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      bool placed = false;
      for (int j = 0; j < n; j++) {
        if (f[i] <= b[j]) {
          placed = true;
          b[j] = -1;
          break;
        }
      }
      if (!placed)
        ans++;
    }
    return ans;
  }

  int fruitAndBasketIII(vector<int> &f, vector<int> &b) { // TC = O(nlog(n)); SC = O(4*n);
    int n = f.size();
    int ans = 0;
    vector<int> st(4 * n);
    buildST(1, 0, n - 1, st, b);

    for (int i = 0; i < n; i++) {
      bool p = qeuryST(1, 0, n - 1, st, f[i]);
      if (!p)
        ans++;
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> fruits = {4, 2, 5}, baskets = {3, 5, 4};
  Solution sl;
  auto result = sl.fruitAndBasketIII(fruits, baskets);
  cout << result << "\n";

  return 0;
}