/*
Prim's Algorithm - Minimum Spanning Tree:
Problem Statement: Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
(Sometimes it may be asked to find the MST as well, where in the MST the edge-informations will be stored in the form {u, v}(u = starting node, v = ending node).)

Example:
Input Format:
	V = 5, edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}
	Result: 16

Input Format:
	V = 5, edges = { {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}}
	Result: 5
*/

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution {
	public:
	int mstUsingPrims(int V, vector<vector<int>> adj[]){
		priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> vis(V, 0);
		pq.push({0, 0});
		int sum = 0;
		while(!pq.empty()){
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;
			if(vis[node]==1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for(auto it: adj[node]){
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};

int main(){
	int V = 5;
	vector<vector<int>> edges = { 
		{0, 1, 2},
		{0, 3, 6},
		{1, 2, 3},
		{1, 3, 8},
		{1, 4, 5},
		{4, 2, 7}}; // {u, v, wt}

	vector<vector<int>> adj[V];
	for (auto it : edges){
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}
    // Printing adjacency list
    for (int i = 0; i < V; i++) {
        cout << "adj[" << i << "]: ";
        for (auto vec : adj[i]) {
            cout << "[" << vec[0] << "," << vec[1] << "] ";
        }
        cout << endl;
    }
	
	Solution obj;
	int sum = obj.mstUsingPrims(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}