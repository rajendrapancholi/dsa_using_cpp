/* Most Stones Removed with Same Row or Column - DSU
Input: n=6  stones = [[0, 0],[ 0, 1], [1, 0],[1, 2],[2, 1],[2, 2]]
Output: 5
Explanation: One of the many ways to remove 5 stones is to remove the following stones: [0,0], [1,0], [0,1], [2,1], [1,2]
*/

#include <iostream>
#include <vector>
#include<unordered_set>

using namespace std;

// Implement disjoint set data structure
class DSU {
 public:
    vector<int> parent, size, rank;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUltParnt(int node){
        if(node == parent[node]) return parent[node];
        return parent[node] = findUltParnt(parent[node]);
    }
    void unionByRank(int x, int y){
        int ultPx = findUltParnt(x); // ultimate parent of x
        int ultPy = findUltParnt(y);
        if(ultPx == ultPy) return;
        if(rank[ultPx] < rank[ultPy]) parent[ultPx] = ultPy;
        else if(rank[ultPy] < rank[ultPx]) parent[ultPy] = ultPx;
        else {
            parent[ultPy] = ultPx;
            rank[ultPx]++;
        }
    }
    void unionBySize(int x, int y){
        int ultPx = findUltParnt(x);
        int ultPy = findUltParnt(y);
        if(ultPx == ultPy) return;
        if(size[ultPx]<size[ultPy]){
            parent[ultPx] = ultPy;
            size[ultPy]+=size[ultPx];
        } else {
            parent[ultPy] = ultPx;
            size[ultPx]+=size[ultPy];
        }
    }
};

class Solution{
public:
    int mostStoneRemove(vector<vector<int>>& stones){
        int maxRow = 0;
        int maxCol = 0;

        for(auto it: stones){
            maxRow = max(maxRow, it[0]); // count rows in a stone to be used as a none in DSU
            maxCol = max(maxCol, it[1]); // count cols in a stone 
        }
        DSU dsu(maxRow+maxCol+1); // nodes: rows + cols (+1 for prevent collision)

        unordered_set<int> nodeStones;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // Column node started after the row node ends
            dsu.unionByRank(nodeRow, nodeCol);
            nodeStones.insert(nodeRow);
            nodeStones.insert(nodeCol);
        }
        int cntCopm = 0; // connected components in the dsu
        for(auto it: nodeStones){
            if(dsu.findUltParnt(it)==it){ 
                cntCopm++;
                cout<<"it: "<<it<<endl;
            }                     
        }
        return stones.size() - cntCopm;
    }    
};

int main(){
    vector<vector<int>> stones = {{0, 0},{ 0, 1}, {1, 0},{1, 2},{2, 1},{2, 2}}; // expected o/p: 5
    vector<vector<int>> stones2 = {{0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}}; // expected o/p: 4
    Solution sl;
    cout<<sl.mostStoneRemove(stones2)<<endl;

    return 0;
}