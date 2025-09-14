// Topological Sort Algorithm
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void dfs(int node, vector<int> adj[], stack<int> &st, vector<int> &vis){
            vis[node]=1;
            for(auto it: adj[node]){
                if(vis[it]==0){
                    dfs(it, adj, st, vis);
                }
            }
            st.push(node);
        }
    public:
        void topologySort(int V, vector<int> adj[], vector<int> &ans){ // TC = O(v+e)
            vector<int> vis(V, 0);
            stack<int> st;
            for(int i=0; i<V; i++){
                if(vis[i]==0){
                    dfs(i, adj, st, vis);
                }    
            }
            while(!st.empty()){ // reverse the stack
                ans.push_back(st.top());
                st.pop();
            }
        }
};

int main(){//             0  1   2   3     4   5
    vector<int> adj[] = { {},{},{3},{1},{0,2},{0,2}};
    Solution sl;
    vector<int> ans;
    int V = sizeof(adj)/sizeof(adj[0]);
    sl.topologySort(V, adj, ans);
    for(auto it: ans){
        cout<<it<<' ';
    }
    cout<<endl;
    return 0;
}



