#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }

    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();

    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
      int current = matrix[row][col];

      if (current == target) {
        return true;
      }

      if (current > target) {
        col--;
      } else {
        row++;
      }
    }

    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  int target = 5;

  Solution obj;
  cout << (obj.searchMatrix(matrix, target) ? "true" : "false") << endl;

  return 0;
}