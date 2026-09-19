/* Next Smallest Element Using Stack
Given an integer array A, return the next smallest element for every element in
A. The next smallest element for an element x is the first element smallest than
x that we come across while traversing the array in a clockwise manner. If it
doesn't exist, return -1 for this element.

Examples
Input: arr = [1, 3, 2, 4]
Output: [-1, 2, -1, -1]

Input: arr = {4, 8, 5, 2, 25};
Output: [2 5 2 -1 -1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextSmallerElement1(vector<int> &arr) { // TC = O(n), SC = O(n);
    vector<int> ans(arr.size(), -1);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
      while (!st.empty() && st.top() >= arr[i]) {
        st.pop();
      }
      if (st.empty()) {
        ans[i] = -1;
      } else {
        ans[i] = st.top();
      }
      st.push(arr[i]);
    }
    return ans;
  }

  vector<int> nextSmallerElement2(vector<int> &arr) { // TC = O(2 * n), SC = O(2 * n);
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() >= arr[i % n]) {
        st.pop();
      }
      if (i < n) {
        if (!st.empty()) {
          ans[i] = st.top();
        }
      }
      st.push(arr[i % n]);
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr = {1, 3, 2, 4}; // Output: [-1 2 -1 -1]
  arr = {4, 8, 5, 2, 25}; // Output: [2 5 2 -1 -1]
  // arr = {10, 9, 8, 7}; // Output: [9 8 7 -1]
  Solution sl;
  
  auto result = sl.nextSmallerElement1(arr);
  for (auto r : result) {
    cout << r << " ";
  }
  cout<<"\n\n";
  result = sl.nextSmallerElement2(arr);
  for (auto r : result) {
    cout << r << " ";
  }

  return 0;
}
