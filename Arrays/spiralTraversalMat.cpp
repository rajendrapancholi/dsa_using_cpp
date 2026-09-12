/* Spiral Traversal of Matrix
Given a Matrix, print the given matrix in spiral order.
Examples
Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14,
15, 16 } } Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Input: Matrix[][] = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } }
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralTraversalMat(vector<vector<int>> &mat) {
    int l = 0, r = mat[0].size() - 1, t = 0, b = mat.size() - 1;
    vector<int> ans;

    while (l <= r && t <= b) {
      for (int i = l; i <= r; i++) { // left to right
        ans.push_back(mat[t][i]);
      }
      t++;
      for (int i = t; i <= b; i++) { // top to bottom
        ans.push_back(mat[i][r]);
      }
      r--;

      if (t <= b) {
        for (int i = r; i >= l; i--) {
          ans.push_back(mat[b][i]);
        }
        b--;
      }

      if (l <= r) {
        for (int i = b; i >= t; i--) {
          ans.push_back(mat[i][l]);
        }
        l++;
      }
    }
    return ans;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> mat = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  // Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

  Solution sl;
  auto result = sl.spiralTraversalMat(mat);

  for (int it : result) {
    cout << it << " ";
  }

  return 0;
}