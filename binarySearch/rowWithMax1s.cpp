#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rowWithMax1s(vector<vector<int>> &mat) {
    int rows = (int)mat.size();
    int cols = (int)mat[0].size();

    int row = 0;

    int col = cols - 1;

    int answer = -1;

    while (row < rows && col >= 0) {
      if (mat[row][col] == 1) {
        answer = row;
        col--;
      } else {
        row++;
      }
    }

    return answer;
  }
};

int main() {
  vector<vector<int>> mat = {{0, 0, 1, 1}, {0, 1, 1, 1}, {0, 0, 0, 1}};

  Solution obj;
  cout << obj.rowWithMax1s(mat) << endl;

  return 0;
}