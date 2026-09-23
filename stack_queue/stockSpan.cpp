/* Stock span problem
Given an array arr of size n, where each element arr[i] represents the stock
price on day i. Calculate the span of stock prices for each day.

The span Si for a specific day i is defined as the maximum number of consecutive
previous days (including the current day) for which the stock price was less
than or equal to the price on day i.

Example 1:
Input: n = 7, arr = [120, 100, 60, 80, 90, 110, 115]

Output: [1, 1, 1, 2, 3, 5, 6]

Explanation:

Traversing the given input span:

120 is greater than or equal to 120 and there are no more elements behind it so
the span is 1,

100 is greater than or equal to 100 and smaller than 120 so the span is 1,

60 is greater than or equal to 60 and smaller than 100 so the span is 1,

80 is greater than or equal to 60, 80 and smaller than 100 so the span is 2,

90 is greater than or equal to 60, 80, 90 and smaller than 100 so the span is 3,

110 is greater than or equal to 60, 80, 90, 100, 110 and smaller than 120 so the
span is 5,

115 is greater than or equal to all previous elements and smaller than 120 so
the span is 6.

Hence the output will be 1 1 1 2 3 5 6. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> stockSpan(vector<int> arr, int n) {
    vector<int> res(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
      int span = 1;
      while (!st.empty() && st.top().first <= arr[i]) {
        span += st.top().second;
        st.pop();
      }
      st.push(make_pair(arr[i], span));
      res[i] = span;
    }
    return res;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
  Solution sl;
  auto result = sl.stockSpan(arr, arr.size());
  for (auto r : result) {
    cout << r << " ";
  }

  return 0;
}