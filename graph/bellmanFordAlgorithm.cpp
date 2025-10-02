/* Bellman Ford Algorithm
Problem Statement: Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S.
Note: If the Graph contains a negative cycle then return an array consisting of only -1.
Example:
Input Format: 
V = 6, 
E = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], 
S = 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> bellman_ford(vector<vector<int>> &edges, int S, int V){
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        // TC = O(VxE)
        for(int i=0; i < V-1; i++){
            for(auto it: edges){
                int u = it[0]; // source
                int v = it[1]; // destination
                int wt = it[2]; // weight from src to dest
                if(dist[u]!=1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for(auto it: edges){
            int u = it[0]; // source
            int v = it[1]; // destination
            int wt = it[2]; // weight from src to dest
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};

int main(){
    int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};
    int S = 0;
    Solution sl;
    vector<int> ans = sl.bellman_ford(edges, S, V);
    for(auto d: ans){
        cout<<d<<' ';
    }
    cout<<endl;
    return 0;
}