// Course Schedule I and II | Pre-requisite Tasks | Topological

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
            if(topo.size()!=V) {
                topo.clear();
                return topo;
            }
            return topo;
        }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main(){
    // int N = 4, P = 3;
    // int arr[][2] = {{1,0},{2,1},{3,2}};
    
    // int N = 5, P = 4;
    // int arr[][2] = {{1,2},{4,3},{2,4},{4,1}};
    
    int N = 3, P = 2;
    int arr[][2] = {{1,0}, {0,1}};

    vector<int> adj[N];
    for(int i=0; i<P; i++){
       addEdge(adj, arr[i][0], arr[i][1]);
    }
    Solution sl;
    vector<int> ans = sl.kahnsAlgo(N, adj);
    if(!ans.empty()){
        cout<<"YES"<<endl;
        for(auto it: ans){
            cout<<it<<' ';
        }
    } else {
        cout<<"NO"<<endl;
    }
    cout<<endl;
    return 0;
}