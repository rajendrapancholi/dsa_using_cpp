// Topological Sort Algorithm using kahn's algorithm
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> kahnsAlgo(int V, vector<int> adj[]){
            int indegree[V] = {0};
            queue<int> q;
            vector<int> topo;

            // Calculate the indegree of each node
            for (int i=0; i<V; i++){
                for(auto it: adj[i]){
                    indegree[it]++;
                }
            }
            for(int i=0; i<V; i++){
                if(indegree[i]==0) q.push(i);
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                topo.push_back(node);
                for(auto it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }
            return topo;
        }
};


int main(){
    // vector<int> adj[] = { {}, {}, {3}, {1},{0,1},{0,2}};
    vector<int> adj[] = { {}, {0}, {0}, {0}};
    int V = sizeof(adj)/sizeof(adj[0]);
    Solution sl;
    vector<int> ans = sl.kahnsAlgo(V, adj);
    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;
    return 0;
}
