// Surrounded Regions | Replace O’s with X’s

#include<iostream>
#include<vector>

using namespace std;
class Solution{
    private:
        void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
            vis[row][col]=1;
            int n = grid.size(); // Numbers of rows
            int m = grid[0].size(); // Numbers of columns
            // define directions [top, right, bottom, left]
            int dirRow[4] = {-1, 0, +1, 0};
            int dirCol1[4] = {0, +1, 0, -1};

            for(int i=0; i<4; i++){
                int nRow = row + dirRow[i];
                int nCol = col + dirCol1[i];
                if(nRow>=0&&nRow<n && nCol>=0&&nCol<m && vis[nRow][nCol]==0 && grid[nRow][nCol]=='o'){
                    dfs(nRow, nCol, grid, vis);
                }
            }
        }
    public:
        vector<vector<char>> replaceWithX(vector<vector<char>>& grid){
            int n = grid.size(); // rows
            int m = grid[0].size(); // columns
            vector<vector<int>> vis(n, vector(m, 0));
            for(int i=0; i<m; i++){
                // top row
                if(grid[0][i]=='o' && vis[0][i]==0)
                    dfs(0, i, grid, vis);
                // bottom row
                if(grid[n-1][i]=='o' && vis[n-1][i]==0)
                    dfs(n-1, i, grid, vis);
            }
            for(int i=0; i<n; i++){
                // right col
                if(grid[i][m-1]=='o' && vis[i][m-1]==0)
                    dfs(i, m-1, grid, vis);
                // left col
                if(grid[i][0]=='o' && vis[i][0]==0)
                    dfs(i, 0, grid, vis);
            }
            // Replace with X
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(vis[i][j]==0)
                        grid[i][j] = 'x';
                }
            }
            return grid;
        }

};




int main(){
    vector<vector<char>> grid1 = {
        {'x', 'x', 'x', 'x'},
        {'x', 'o', 'x', 'x'},
        {'x', 'o', 'o', 'x'},
        {'x', 'o', 'x', 'x'},
        {'x', 'x', 'o', 'o'}
    }; 
    vector<vector<char>> grid2 = {
        {'x', 'x', 'x', 'x'},
        {'x', 'x', 'x', 'x'},
        {'x', 'o', 'o', 'x'},
        {'x', 'o', 'o', 'x'},
        {'x', 'x', 'x', 'x'}
    };

    Solution sl;
    vector<vector<char>> ans = sl.replaceWithX(grid2);
    for(auto x: ans){
        for(auto el: x)
            cout<<el<<' ';
        cout<<endl;
    }
        
    return 0;
}