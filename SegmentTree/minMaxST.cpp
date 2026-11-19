#include <bits/stdc++.h>
using namespace std;

struct Node {
  int mn = INT_MAX;
  int mx = INT_MIN;
};

class Solution {
private:
  vector<Node> st;
  vector<int> lazy;
  int n;

  void push(int node, int start, int end) {
    if (lazy[node] != 0) {
      st[node].mn += lazy[node];
      st[node].mx += lazy[node];
      if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void buildST(int node, int start, int end, vector<int> &arr) {
    if (start == end) {
      st[node].mn = arr[start];
      st[node].mx = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    buildST(2 * node, start, mid, arr);
    buildST(2 * node + 1, mid + 1, end, arr);

    st[node].mn = min(st[2 * node].mn, st[2 * node + 1].mn);
    st[node].mx = max(st[2 * node].mx, st[2 * node + 1].mx);
  }

  void updateST(int node, int start, int end, int ql, int qr, int val) {
    push(node, start, end);

    // No overlap
    if (qr < start || end < ql)
      return;

    // Full overlap
    if (ql <= start && end <= qr) {
      lazy[node] += val;
      push(node, start, end);
      return;
    }

    // Partial overlap
    int mid = start + (end - start) / 2;
    updateST(2 * node, start, mid, ql, qr, val);
    updateST(2 * node + 1, mid + 1, end, ql, qr, val);

    st[node].mn = min(st[2 * node].mn, st[2 * node + 1].mn);
    st[node].mx = max(st[2 * node].mx, st[2 * node + 1].mx);
  }

  Node queryST(int node, int start, int end, int ql, int qr) {
    push(node, start, end);

    // No overlap
    if (qr < start || end < ql) {
      return {INT_MAX, INT_MIN};
    }

    // Full overlap
    if (ql <= start && end <= qr) {
      return st[node];
    }

    // Partial overlap
    int mid = start + (end - start) / 2;
    Node leftRes = queryST(2 * node, start, mid, ql, qr);
    Node rightRes = queryST(2 * node + 1, mid + 1, end, ql, qr);

    Node ans;
    ans.mn = min(leftRes.mn, rightRes.mn);
    ans.mx = max(leftRes.mx, rightRes.mx);
    return ans;
  }

public:
  // TC: Build O(N), SC: O(4N)
  Solution(vector<int> &arr)
      : n(arr.size()), st(4 * arr.size()), lazy(4 * arr.size(), 0) {
    buildST(1, 0, n - 1, arr);
  }

  // TC: O(log N)
  void rangeUpdate(int l, int r, int val) { updateST(1, 0, n - 1, l, r, val); }

  // TC: O(log N)
  Node minMaxST(int l, int r) { return queryST(1, 0, n - 1, l, r); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr = {2, 1, 5, 4, 6, 8, 5, 3};
  Solution sl(arr);

  Node res1 = sl.minMaxST(2, 4);
  cout << "Before Update\nMin: " << res1.mn << ", Max: " << res1.mx
       << "\n"; // 4, 6

  sl.rangeUpdate(1, 3, 10);

  Node res2 = sl.minMaxST(2, 4);
  cout << "After Update\nMin: " << res2.mn << ", Max: " << res2.mx
       << "\n"; // 6, 15

  return 0;
}
