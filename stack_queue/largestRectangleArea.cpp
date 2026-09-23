#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
public:
  int largestRectangleArea(vector<int> &h) {
    int n = h.size();
    stack<int> st;
    int maxA = 0;

    for (int i = 0; i <= n; i++) {
      int curr = (i == n) ? 0 : h[i];
      while (!st.empty() && h[st.top()] >= curr) {
        int height = h[st.top()];
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;

        maxA = max(maxA, height * width);
      }
      if (i < n) {
        st.push(i);
      }
    }
    return maxA;
  }
};