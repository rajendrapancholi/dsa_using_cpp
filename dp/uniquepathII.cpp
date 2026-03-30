/* Program name
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r >= m || c >= n || grid[r][c] == 1) {
            return 0;
        }
        
        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        return helper(grid, r, c + 1, m, n) + helper(grid, r + 1, c, m, n);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return helper(obstacleGrid, 0, 0, m, n);
    }
};

int main() {

    Solution sl;
    return 0;
}
