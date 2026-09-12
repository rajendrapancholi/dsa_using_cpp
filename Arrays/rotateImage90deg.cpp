/* Rotate Image by 90 degree
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise. The
rotation must be done in place, meaning the input 2D matrix must be modified
directly..

Examples
Input : matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

Examples
Input : matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]
Output : matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]] */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> rotateImage90deg(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> rotated(m,
                                vector<int>(n)); // brute force tc n^2, sc n^2
    // for(int i = 0; i < m; i++){
    //   for(int j = 0; j < n; j++){
    //     rotated[i][j] = mat[m - j - 1][i];
    //   }
    // }
    // return rotated;

    for (int i = 0; i < m; i++) // tc O(n^2), sc = O(1);
      for (int j = i + 1; j < n; j++)
        swap(mat[i][j], mat[j][i]);

    for (int i = 0; i < m; i++)
      reverse(mat[i].begin(), mat[i].end());

    return rotated;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}}; // Output [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

  // vector<vector<int>> matrix = {{0, 1, 1, 2}, {2, 0, 3, 1}, {4, 5, 0, 5}, {5,
  // 6, 7, 0}}; // Output [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1,
  // 2]]

  Solution sl;
  auto result = sl.rotateImage90deg(matrix);

  for (auto it : matrix) {
    for (int e : it) {
      cout << e << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  cout << "\n";
  for (auto it : result) {
    for (int e : it) {
      cout << e << " ";
    }
    cout << "\n";
  }

  return 0;
}