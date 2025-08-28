/* Number of Enclaves
Problem Statement: You are given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves.
Input-1: 
    0 0 0 0
    1 0 1 0
    0 1 1 0
    0 0 0 0
Output: 3

Input-2:
    0 0 1 1
    0 1 1 0
    0 1 1 0
    0 0 0 1
    0 1 1 0
Output: 0
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void dfs(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& vis){
            vis[row][col]=1;
            int n = grid.size(); // Numbers of rows
            int m = grid[0].size(); // Numbers of columns
            // define directions [top, right, bottom, left]
            int dirRow[4] = {-1, 0, +1, 0};
            int dirCol1[4] = {0, +1, 0, -1};

            for(int i=0; i<4; i++){
                int nRow = row + dirRow[i];
                int nCol = col + dirCol1[i];
                if(nRow>=0&&nRow<n && nCol>=0&&nCol<m && vis[nRow][nCol]==0 && grid[nRow][nCol]==1){
                    dfs(nRow, nCol, grid, vis);
                }
            }
        }
    public:
        int maxNumberEnclaves(vector<vector<int>>& grid){
            int n = grid.size(); // Number of rows
            int m = grid[0].size(); // Number of columns
            vector<vector<int>> vis(n, vector<int>(m, 0));
            queue<pair<int, int>> q;

            for(int i=0; i<m; i++){
                if(grid[0][i]==1 && vis[0][i]==0) // top row
                    dfs(0, i, grid, vis);
                if(grid[n-1][i]==1 && vis[n-1][i]==0) // bottom row
                    dfs(n-1, i, grid, vis);
            }
            for(int i=0; i<n; i++){
                if(grid[i][m-1]==1 && vis[i][m-1]==0) // right col
                    dfs(i, m-1, grid, vis);
                if(grid[i][0]==1 && vis[i][0]==0) // left col
                    dfs(i, 0, grid, vis);
            }
            int cnt = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==1 && vis[i][j]==0)
                        cnt++;
                }
            }
            return cnt;
        }
};


int main(){
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    }; // Output: 3
    vector<vector<int>> grid1 = {
        {0, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    }; // Output: 4
    vector<vector<int>> grid2 = {
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    }; // Output: 0
    Solution sl;
    int ans = sl.maxNumberEnclaves(grid);
    cout<<ans<<endl;
    return 0;
}