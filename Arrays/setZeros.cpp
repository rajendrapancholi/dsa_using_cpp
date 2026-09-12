// Set to zeros

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> row(r, 0);
    vector<int> col(c, 0);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (matrix[i][j] == 0)

        {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (row[i] == 1 || col[j] == 1) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  // Output:
  // 1 0 1
  // 0 0 0
  // 1 0 1

  matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  // Output:
  // 0 0 0 0
  // 0 4 5 0
  // 0 3 1 0

  Solution sol;
  sol.setZeroes(matrix);

  for (auto it : matrix) {
    for (int e : it) {
      cout << e << " ";
    }
    cout << "\n";
  }

  return 0;
}