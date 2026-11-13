/* 2179. Count Good Triplets in an Array
You are given two 0-indexed arrays nums1 and nums2 of length n, both of which
are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing
order by position both in nums1 and nums2. In other words, if we consider pos1v
as the index of the value v in nums1 and pos2v as the index of the value v in
nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1,
such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation:
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1),
(2,0,3), (2,1,3), and (0,1,3). Out of those triplets, only the triplet (0,1,3)
satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet. Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).

Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
private:
  void updateST(int idx, int node, int start, int end, vector<ll> &st) {
    if (start == end) {
      st[node] = 1;
      return;
    }
    int mid = start + (end - start) / 2;

    if (idx <= mid)
      updateST(idx, 2 * node, start, mid, st);
    else
      updateST(idx, 2 * node + 1, mid + 1, end, st);

    st[node] = st[2 * node] + st[2 * node + 1];
  }

  ll queryST(int qs, int qe, int node, int start, int end, vector<ll> &st) {
    // not overlap
    if (qs > end || qe < start) {
      return 0;
    }
    // full overlap
    if (qs <= start && qe >= end) {
      return st[node];
    }
    // partial overlap
    int mid = start + (end - start) / 2;
    ll l = queryST(qs, qe, 2 * node, start, mid, st);
    ll r = queryST(qs, qe, 2 * node + 1, mid + 1, end, st);

    return l + r;
  }

public:
  long long goodTriplets(vector<int> &n1, vector<int> &n2) {
    int n = n1.size();
    unordered_map<int, int> mp2;
    for (int i = 0; i < n; i++) {
      mp2[n2[i]] = i;
    }
    vector<ll> st(4 * n, 0);
    ll ans = 0;

    updateST(mp2[n1[0]], 1, 0, n - 1, st);

    for (int i = 1; i < n; i++) {
      int idx = mp2[n1[i]]; // index in n2

      ll l_common_cnt = queryST(0, idx - 1, 1, 0, n - 1, st);
      ll l_not_common_cnt = i - l_common_cnt;
      ll after_idx_cnt = n - 1 - idx;
      ll r_common_cnt = after_idx_cnt - l_not_common_cnt;

      ans += l_common_cnt * r_common_cnt;

      updateST(idx, 1, 0, n - 1, st);
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // vector<int> nums1 = {2,0,1,3}, nums2 = {0,1,2,3}; // Output: 1
  vector<int> nums1 = {4, 0, 1, 3, 2}, nums2 = {4, 1, 0, 2, 3}; // Output: 4
  Solution sl;
  auto result = sl.goodTriplets(nums1, nums2);
  cout << result << "\n";

  return 0;
}