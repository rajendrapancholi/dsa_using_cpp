/* Maximum Rectangles
Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

Example 1:
Input: matrix = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1,
0]]

Output: 6

Explanation: The highlighted part depicts the rectangle with the largest area
i.e. 6.
 */

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
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

public:
  int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty())
      return 0;

    int maxRect = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> arr(n, 0);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          arr[j] += 1;
        } else {
          arr[j] = 0;
        }
      }
      maxRect = max(maxRect, largestRectangleArea(arr));
    }
    return maxRect;
  }
};