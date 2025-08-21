// Rotten Oranges : Min time to rot all oranges
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minRottenTime(vector<vector<int>>& grid) {
    queue<pair<int, int>> rotten;
    int totalOranges = 0;
    int rottenCount = 0;
    int minutes = 0;

    int n = grid.size(), m = grid[0].size(); // n=rows, m=columns

    // Store the rotten oranges and count total oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) totalOranges++; // Count all oranges
            if (grid[i][j] == 2) rotten.push({i, j}); // Store rotten oranges
        }
    }

    // Directions for up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!rotten.empty()) {
        int sz = rotten.size();
        rottenCount += sz;

        while (sz--) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check boundaries and if the orange is fresh
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Rot the fresh orange
                    rotten.push({newX, newY}); // Add to queue
                }
            }
        }

        if (!rotten.empty()) minutes++; // Increment time if there are still rotten oranges
    }

    return (totalOranges == rottenCount) ? minutes : -1; // Check if all oranges are rotten
}

int main() {
    // vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Minimum rotten time is: " << minRottenTime(grid) << endl;

    return 0;
}
