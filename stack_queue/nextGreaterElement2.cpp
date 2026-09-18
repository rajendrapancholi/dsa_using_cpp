/* Next Greater Element - 2
Given a circular integer array arr, return the next greater element for every
element in arr. The next greater element for an element x is the first element
greater than x that we come across while traversing the array in a clockwise
manner. If it doesn't exist, return -1 for that element element.

Examples
Example 1:
Input:
 arr = [3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9]
Output:
 [10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10]
Explanation:
 For the first element in arr i.e, 3, the greater element which comes next to it
while traversing and is closest to it is 10. Hence,10 is present on index 0 in
the resultant array. Now for the second element i.e, 10, there is no greater
number and hence -1 is it’s next greater element (NGE). Similarly, we got the
NGEs for all other elements present in arr.

Example 2:
Input:
 arr = [5, 7, 1, 7, 6, 0]
Output:
 [7, -1, 7, -1, 7, 5]
Explanation:
 For the first element in arr i.e, 5, the greater element which comes next to it
while traversing and is closest to it is 7. Now for the second element i.e, 7,
there is no greater number and hence -1 is it’s next greater element (NGE).
Similarly, we got the NGEs for all other elements present in arr. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement2(vector<int> &arr) { // TC = O(2 * n), SC = O(2 * n);
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() <= arr[i % n]) {
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

  vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
  // Output: [10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10]

  Solution sl;
  auto result = sl.nextGreaterElement2(arr);

  for (auto r : result) {
    cout << r << " ";
  }

  return 0;
}