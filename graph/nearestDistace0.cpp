// Distance of Nearest Cell having 0
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //vis[] for storing the visited nodes
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //dist for storing distances.
        vector<vector<int>> dist(n, vector<int>(m, 0));
        //q: for storing the temp nodes by using BFS
        // ((rowIdx, colIdx), step)
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } else {
                    vis[i][j]=0;
                }
            }
        }
        // Define direcrions
        int delRow[4]={-1, 0, +1, 0};
        int delCol[4]={0, +1, 0, -1};
        // by using BFS Traversal
        while(!q.empty()){
            //row
            int row = q.front().first.first;
            //col
            int col = q.front().first.second;
            // step
            int step = q.front().second;
            q.pop();
            dist[row][col] = step;
            for(int i=0; i<4; i++){
                int nRow = row+delRow[i];
                int nCol = col+delCol[i];
                if(nRow>=0 && nRow < n && nCol>=0 && nCol<m && vis[nRow][nCol]==0){
                    vis[nRow][nCol]=1;
                    q.push({{nRow, nCol}, step+1});
                }
            }

        }
        return dist;
    }
};


int main(){
    vector<vector<int>> grid{
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    Solution sl;
    vector<vector<int>> ans = sl.updateMatrix(grid);
    for(auto x: ans){
        for(auto el: x){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    
	
}