#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int celebrity(vector<vector<int>> &M) {
    int n = M.size();
    if (n == 0)
      return -1;

    int candidate = 0;

    // Find a possible celebrity
    for (int i = 1; i < n; ++i) {
      if (M[candidate][i] == 1) {
        candidate = i;
      }
    }

    // Verify the candidate
    for (int i = 0; i < n; ++i) {
      if (i == candidate)
        continue;

      // Candidate must not know anyone,
      // and everyone must know the candidate.
      if (M[candidate][i] == 1 || M[i][candidate] == 0) {
        return -1;
      }
    }

    return candidate;
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int>> M = {
      {0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}};
  Solution sl;
  auto result = sl.celebrity(M);
  cout << result << "\n";

  return 0;
}