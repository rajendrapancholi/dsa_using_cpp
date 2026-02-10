/* Strongly connected components - Kosarajus Algorithm
*/
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

class Solution {
private:
    void dfs(int node, stack<int> &st, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){ // vis[it]==0
                dfs(it, st, adj, vis);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> adjT[], vector<int> &vis){
        vis[node] = 1;
        for(auto it: adjT[node]){
            if(!vis[it]){ // vis[it]==0
                dfs2(it, adjT, vis);
            }
        }
    }
public:
    int kosarajusAlgo(vector<int> adj[], int V){
        vector<int> vis(V, 0);
        stack<int> st;
        // Step 1: Sort all the edges according to its finising time.
        for(int i=0; i<V; i++){
            if(!vis[i])
                dfs(i, st, adj, vis);
        }
        // Step 2: Reverse the edges or reverse the graph.
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i]=0;
            for(auto it: adj[i]){
                // i->it to it->i
                adjT[it].push_back(i);
            }
        }

        // Step 3: Do a DFS on the stack
        int scc = 0;
        cout<<"Stack is "<<endl;
        while (!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                cout<<node<<" ";
                dfs2(node, adjT, vis);
            }
        }
        return scc;
    }
}; 


int main() {
    vector<vector<int>> grid = {
        {0,1,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,0,0},
    };
    int V = grid.size();
    vector<int> adj[V];
    for(int i = 0; i<V; i++){
        for(int j=0; j<V; j++){
            if(grid[i][j]==1)
                adj[i].push_back(j);
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout<<i<<": ";
        for (auto it: adj[i])
        {
            cout<<it<<' ';
        } cout<<endl;
        
    }
    
    Solution sl;
    int ans = sl.kosarajusAlgo(adj, V);
    cout<<"\nSCC : "<<ans<<endl;
    return 0;
}
