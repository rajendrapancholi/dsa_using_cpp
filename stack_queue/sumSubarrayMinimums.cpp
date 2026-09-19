/* Sum of Subarray Minimums
Given an array of integers arr of size n, calculate the sum of the minimum value
in each (contiguous) subarray of arr. Since the result may be large, return the
answer modulo 10⁹ +7.

Examples
Example 1:
Input:
 arr = [3, 1, 2, 5]
Output:
 18
Explanation:
 The minimum of subarrays: [3], [1], [2], [5], [3, 1], [1, 2], [2, 5], [3, 1,
2], [1, 2, 5], [3, 1, 2, 5] are 3, 1, 2, 5, 1, 1, 2, 1, 1, 1 respectively and
their sum is 18.

Example 2:
Input:
 arr = [2, 3, 1]
Output:
 10
Explanation:
 The minimum of subarrays: [2], [3], [1], [2,3], [3,1], [2,3,1] are 2, 3, 1, 2,
1, 1 respectively and their sum is 10. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> findNSE(vector<int> &arr) { // TC = O(n), SC = O(n);
    stack<int> st;
    vector<int> ans(arr.size());
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      ans[i] = st.empty() ? n : st.top();
      st.push(i);
    }
    return ans;
  }

  vector<int> findPSE(vector<int> &arr) { // TC = O(n), SC = O(n);
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] > arr[i])
        st.pop();
      ans[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    return ans;
  }

public:
  int sumSubarrayMinimumsM1(vector<int> &arr) { // TC = O(n^2), SC = O(1);
    int ans = 0, n = arr.size();
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int mn = arr[i];
      for (int j = i; j < n; j++) {
        mn = min(mn, arr[j]);
        ans = (ans + mn) % mod;
      }
    }
    return ans;
  }

  int sumSubarrayMinimumsM2(vector<int> &arr) { // TC = O(n + n + n) = O(n); SC = O(2n + 2n) = O(n);
    int ans = 0, n = arr.size();
    int mod = 1e9 + 7;
    vector<int> pse = findPSE(arr); // find pse indices
    vector<int> nse = findNSE(arr); // find nse indices
    for (int i = 0; i < n; i++) {
      int left = i - pse[i];
      int right = nse[i] - i;
      int freq = left * right;
      int val = freq * arr[i];
      ans += val;
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr = {3, 1, 2, 5}; // 18
  // arr = {2, 3, 1};                // 10
  Solution sl;
  auto result = sl.sumSubarrayMinimumsM1(arr);
  cout << result << "\n\n";

  result = sl.sumSubarrayMinimumsM2(arr);
  cout << result << "\n";

  return 0;
}