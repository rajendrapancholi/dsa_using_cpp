/* Number of Operations to Make Network Connected.
Problem Statement: You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.
*/

#include <iostream>
#include <vector>
#include<unordered_set>

using namespace std;

class DSU {
public: 
    vector<int> rank, parent;
    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n+1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findUP (int node){ // Find ultimate parent
        if( parent[node] != node) parent[node] = findUP(parent[node]);
        return parent[node];
    }
    void unionByRank(int x, int y){
        int px = findUP(x);
        int py = findUP(y);
        if(px==py) return;
        if(rank[px] < rank[py]){
            parent[px] = py;
        } else if(rank[py]<rank[px]){
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution{
public:
    int makeConnected(int n, vector<vector<int>>& connections){
        if(connections.size() < n-1) return -1; // If edges are less than n - 1, we can't connect

        DSU dsu(n);
        for(auto& it: connections){
            dsu.unionByRank(it[0], it[1]);
        }
        unordered_set<int> component;
        for(int i=0; i<n; i++){
            component.insert(dsu.findUP(i));
        }
        return component.size()-1;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,4}}; // -1
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;
    
    n = 8;
    vector<vector<int>> connections1 = {{0,1}, {0,2}, {0,3}, {1,2}, {2,3}, {4,5}, {5,6}, {7,8}}; // 1
     
    Solution sol1;
    cout << sol1.makeConnected(n, connections1) << endl;
    return 0;
}