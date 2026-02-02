/* Number of Islands - II - Online Queries - DSU
Problem Statement: You are given an n, m which means the row and column of the 2D matrix, and an array of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.
Example 1:
Input Format: n = 4 m = 5 k = 4 A = {{1,1},{0,1},{3,3},{3,4}} 
Output: 1 1 2 2 
Explanation: The following illustration is the representation of the operation:
Example 2:
Input Format: n = 4 m = 5 k = 12 A = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4}, {3,2}, {2,2},{1,2}, {0,2}} 
Output: 1 1 2 1 1 2 2 2 3 3 1 1 
Explanation: If we follow the process like in example 1, we will get the above result.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion {
private:
    vector<int> rank, size, parent;
public:
    DisjointSetUnion(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUltimateParent(int node){
        if(node==parent[node]) return parent[node];
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int x, int y){
        int ultPx = findUltimateParent(x);
        int ultPy = findUltimateParent(y);
        if(ultPx == ultPy) return;
        if(size[ultPx] < size[ultPy]){
            parent[ultPx] = ultPy;
            size[ultPy] += size[ultPx];
        } else{
            parent[ultPy] = ultPx;
            size[ultPx] += size[ultPy];
        }

    }
    void unionByRank(int x, int y){
        int ultPx = findUltimateParent(x);
        int ultPy = findUltimateParent(y);
        if(ultPx == ultPy) return;
        if(rank[ultPx] < rank[ultPy]){
            parent[ultPx] = ultPy;
        } else if( rank[ultPy] < rank[ultPx]){
            parent[ultPy] = ultPx;
        } else {
            parent[ultPx] = ultPy;
            rank[ultPx]++;
        }
    }
};




class Solution {
private:
    bool isValid(int adjRow, int adjCol, int n, int m){
        return adjRow>=0 && adjRow < n && adjCol>=0 && adjCol<m;
    }
public:
    /**
     * @brief isalandQuery
     * 
     * @param list A vector of (x, y) coordinate pairs representing points.
     * @param n : The number of rows.
     * @param m : The number of columns.
     * @param k : the number of points.
     * 
     * @return vector<int>
     */
    vector<int> isalandQuery(vector<pair<int, int>> list, int n, int m, int k) {
        DisjointSetUnion dsu(n*m);
        vector<int> result;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i=0; i<size(list); i++){
            int x = list[i].first;
            int y = list[i].second;
            if(vis[x][y]==0){
                vis[x][y]=1;
                count++;
                int nodeNo = x*m + y;

                int drow[] = {-1, 0, +1, 0};
                int dcol[] = {0, +1, 0, -1};

                for(int j=0; j<4; j++){
                    int adjrow = x + drow[j];
                    int adjcol = y + dcol[j];
                    if(isValid(adjrow, adjcol, n, m) && vis[adjrow][adjcol]==1){
                        int adjNodeNo = adjrow*m + adjcol;
                        if(dsu.findUltimateParent(nodeNo)!=dsu.findUltimateParent(adjNodeNo)){
                            count--;
                            dsu.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
                result.push_back(count);
            } else{
                result.push_back(count);
            }
        }
        return result;
    }
};

int main(){
    vector<pair<int, int>> list = {{0,0}, {0,0}, {1,1}, {1,0}, {0,1}, {0,3}, {1,3}, {0,4}, {3,2},{2,2}, {1,2}, {0,2}};
    int n=4, m=5, k=list.size();
    Solution sl;
    for(auto it: sl.isalandQuery(list, n, m, k)){
         cout<<it<<" ";
    } cout<<endl;
    return 0;
}

