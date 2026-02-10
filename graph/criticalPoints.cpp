/* Finding critical point or articulation points.
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
  int timer = 0; // Track the time
private:
  void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it: adj[node]){
      if(it==parent) continue;

      if(vis[it]==0){
        dfs(it, node, adj, vis, tin, low, mark);
        // backtrack
        low[node] = min(low[node], low[it]);
        if(low[it]>=tin[node] && parent!=-1){
          mark[node]=1;
        }
        child++;
      } else {
        low[node] = min(low[node], tin[it]);
      }
    }
    if(child>1 && parent==-1){
      mark[node]=1;
    }
  }
public:
  vector<int> articulationPoint(vector<pair<int, int>> &connections, int edge){
    vector<int> artPts;
    vector<int> adj[edge];
    // 1. Make list
    for(int i=0; i<edge; i++){
      int u = connections[i].first;
      int v = connections[i].second;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    // 2. Track connection
    vector<int> vis(edge, 0);
    vector<int> tin(edge, 0); // Time of insertion during dfs.
    vector<int> low(edge, 0); // min tin .
    vector<int> mark(edge, 0); 
  
    // 3. Run DFS
    for(int i=0; i<edge; i++){
      if(!vis[i]) dfs(0, -1, adj, vis, tin, low, mark);
    }

    for(int i=0; i<edge; i++){
      if(mark[i]==1){
        artPts.push_back(i);
      }
    }
    if(artPts.size()==0) return {-1};
    return artPts;
  }
};

int main() {
  int edge = 8;
  vector<pair<int, int>> connections = {
    {0,1}, {0,2}, {0,3}, {2,3}, {2,4}, {2,5}, {4,6}, {5,6}
  };

  Solution sl;
  cout<<"Articulation points are:\n";
  for(auto it: sl.articulationPoint(connections, edge)){
    cout<<it<<" ";
  } cout<<endl;
  return 0;
}
