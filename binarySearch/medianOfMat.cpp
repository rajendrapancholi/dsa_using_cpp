#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int median(vector<vector<int>> &mat) {
    int rows = (int)mat.size();
    int cols = (int)mat[0].size();

    int low = mat[0][0];
    int high = mat[0][cols - 1];

    for (int i = 1; i < rows; i++) {
      low = min(low, mat[i][0]);

      high = max(high, mat[i][cols - 1]);
    }

    int required = (rows * cols) / 2;

    while (low < high) {
      int mid = low + (high - low) / 2;
      int count = 0;

      for (int i = 0; i < rows; i++) {
        count += (int)(upper_bound(mat[i].begin(), mat[i].end(), mid) -
                       mat[i].begin());
      }

      if (count <= required) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};

int main() {
  vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

  Solution obj;
  cout << obj.median(mat) << endl;

  return 0;
}