// Cycle Detection in Directed Graph (BFS)

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool kahnsAlgo(int V, vector<int> adj[]){
            int indegree[V] = {0};
            queue<int> q;
            int cnt = 0;

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
                cnt++;
                for(auto it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }
            if(cnt==V) return false;
            return true;
        }
};


int main(){
    vector<int> adj[] = { {}, {}, {3}, {1,5},{0,1},{0,2}};
    // vector<int> adj[] = { {}, {0}, {0}, {0}};
    int V = sizeof(adj)/sizeof(adj[0]);
    Solution sl;
    bool ans = sl.kahnsAlgo(V, adj);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}
