// Flood Fill Algorithm - Graphs
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    private:
        void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int initColor) {
            // color with new color
            ans[row][col] = newColor; 
            int n = image.size(); // rows
            int m = image[0].size(); // columns
            // there are exactly 4 neighbours
            for(int i = 0;i<4;i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor) {
                    dfs(nrow, ncol, ans, image, newColor, delRow, delCol, initColor);
                }
            }
        }

    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
            vector<vector<int>> ans = image;
            int initColor = image[sr][sc];
            // defines the directions.[top, bottom, left, right]
            int delRow[] = {-1, 1, 0, 0}; 
            int delCol[] = {0, 0, -1, 1};
            dfs(sr, sc, ans, image, newColor, delRow, delCol, initColor); 
            return ans;
        }
};


int main() {
    vector<vector<int>> image = {
        {1,1,1},
	    {1,1,0},
	    {1,0,1}};
    Solution sl;
    vector<vector<int>> ans = sl.floodFill(image, 1, 1, 2);
    for(auto x: ans){
        for(auto el: x) cout<<el<<' ';
        cout<<endl;
    }
    return 0;
}
/*
Time Complexity: O(NxM + NxMx4) ~ O(N x M)
For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.
Space Complexity: O(N x M) + O(N x M)
O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 

*/