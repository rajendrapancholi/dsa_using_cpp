#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int rows = (int)mat.size(), cols = (int)mat[0].size(), low = 0,
        high = rows - 1;

    while (low < high) {
      int mid = low + (high - low) / 2;

      int bestCol = 0;
      for (int col = 1; col < cols; col++) {
        if (mat[mid][col] > mat[mid][bestCol]) {
          bestCol = col;
        }
      }

      if (mat[mid][bestCol] > mat[mid + 1][bestCol]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    int bestCol = 0;
    for (int col = 1; col < cols; col++) {
      if (mat[low][col] > mat[low][bestCol]) {
        bestCol = col;
      }
    }

    return {low, bestCol};
  }
};

int main() {
  vector<vector<int>> mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};

  Solution obj;
  vector<int> answer = obj.findPeakGrid(mat);
  cout << answer[0] << " " << answer[1] << endl;

  return 0;
}