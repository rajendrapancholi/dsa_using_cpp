/* Making a Large Island - DSU
Problem Statement: Given an n x n binary matrix grid, it is allowed to change at most one 0 to 1. A group of connected 1s forms an island, where two 1s are connected if they share one of their sides.
Return the size of the largest island in the grid after applying this operation.
Example 1:
Input: grid = [[1,0], [0,1]] 
Output: 3 
Explanation:
 We change one of the 0s to 1, connecting the two existing 1s, which results in an island with a maximum area of 3.
Example 2:
Input: grid = [[1, 1], [1, 1]]  
Output: 4 
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DisjointSetUnion{
public:
    vector<int> rank, size, parent;
    DisjointSetUnion(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUltimateParent(int node){
        if(node == parent[node]) return parent[node];
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int x, int y){
        int ulPx = findUltimateParent(x);
        int ulPy = findUltimateParent(y);
        if(ulPx == ulPy) return;
        if(rank[ulPx] < rank[ulPy]){
            parent[ulPx] = ulPy;
        } else if(rank[ulPy] < rank[ulPx]){
            parent[ulPy] = ulPx;
        } else {
            parent[ulPy] = ulPx;
            rank[ulPy]++;
        }
    }
    void unionBySize(int x, int y){
        int ulPx = findUltimateParent(x);
        int ulPy = findUltimateParent(y);
        if(ulPx == ulPy) return;
        if(size[ulPx] < size[ulPy]){
            parent[ulPx] = ulPy;
            size[ulPy] += size[ulPx];
        } else{ 
            parent[ulPy] = ulPx;
            size[ulPx] += size[ulPy];
        }
    }
};


class Solution{
private:
    bool isValid(int newRow, int newCol, int n, int m){
        return newRow>=0 && newRow < n && newCol>=0 && newCol < m;
    }
    int dirRow[4] = {-1, 0, 1, 0};
    int dirCol[4] = {0, 1, 0, -1};

    void makeConnection(DisjointSetUnion& dsu, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 0) continue;
                for(int i=0; i<4; i++){
                    int adjRow = row + dirRow[i];
                    int adjCol = col + dirCol[i];
                    if(isValid(adjRow, adjCol, n, m) && grid[adjRow][adjCol]==1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjRow * m + adjCol;
                        dsu.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    }

public:
    int maxLargeIsland(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        DisjointSetUnion dsu(n*m);

        makeConnection(dsu, grid);
        
        // Traverse all the elements
        int mx=0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if(grid[row][col]==1) continue;
                set<int> components;
                for(int i=0; i<4; i++){
                    int adjRow = row + dirRow[i];
                    int adjCol = col + dirCol[i];
                    if(isValid(adjRow, adjCol, n, m)){
                        if(grid[adjRow][adjCol]==1){
                            int adjNodeNo = adjRow * m + adjCol;
                            components.insert(dsu.findUltimateParent(adjNodeNo));
                        }
                    }
                }
                int tSize = 0;
                for(auto it: components){
                    tSize += dsu.size[it];
                }
                mx = max<int>(mx, tSize + 1);
            }
        }
        for(int nodeNo=0; nodeNo<n*m; nodeNo++){
            mx = max<int>(mx, dsu.size[dsu.findUltimateParent(nodeNo)]);
        }
        return mx;
    }
};

int main(){
    // vector<vector<int>> grid = {{1,0}, {0, 1 }}; // Output: 3 
    vector<vector<int>> grid = {{1, 1}, {1, 1}}; // Output: 4 
    Solution sl;
    cout<<sl.maxLargeIsland(grid)<<endl;
    return 0;
}