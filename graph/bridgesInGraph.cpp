/* Bridges in Graph - Using Tarjan's Algorithm of time in and low time
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
  int timer = 1; //  track the time
  /**
   * @param node     The current vertex being visited.
   * @param parent   The vertex from which the DFS arrived (to prevent moving back to the parent).
   * @param visited  Array/Vector to keep track of visited nodes (prevents cycles).
   * @param adj      The Adjacency List representing the graph.
   * @param tin      Array storing the time at which each node was first discovered.
   * @param low      Array storing the lowest discovery time reachable from the node in the DFS tree.
   * @param timer    A reference to a counter that increments as we discover new nodes.
   * @param bridges  A list/vector to store the identified critical connections (edges).
   */
  void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridge){
    visited[node]=1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it: adj[node]) {
      if(it == parent) continue;
      if(visited[it]==0){
        dfs(it, node, visited, adj, tin, low, bridge);
        // Backtrackig
        low[node] = min(low[node], low[it]);
        if(low[it] > tin[node]){
          bridge.push_back({it, node});
        }
      } else {
        low[node] = min(low[node], tin[it]);
      }
    }
  }

public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections){
    // build a adjacency list
    vector<int> adj[n];
    for(auto it: connections) {
      int u = it[0], v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int tin[n]; // Discovery to time
    int low[n]; // Lowest reachable time
    vector<int> visited(n, 0);
    vector<vector<int>> bridges;
    // Run  the dfs to fetch critical connections or bridges.
    dfs(0, -1, visited, adj, tin, low, bridges);
    return bridges;
  }
};

int main() {
  int n = 13;
  vector<vector<int>> connections = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {3, 4}, 
    {4, 5}, 
    {5, 6}, {6, 7}, {7, 8}, {8, 5},
    {7, 9}, 
    {9, 10}, {10, 11}, {11, 9}     
  };
  // n = 6;
  vector<vector<int>> connections2 = {
    {0, 1}, {1, 2}, {2, 0},
    {2, 3},
    {3, 4}, {4, 5}, {5, 3} 
  };

  Solution sl;
  vector<vector<int>> bridges = sl.criticalConnections(n, connections);

  cout << "Critical Connections (Bridges): ";
  for (auto it : bridges) {
    cout << "[" << it[0] << ", " << it[1] << "] ";
  }
  cout << endl;
  return 0;
}