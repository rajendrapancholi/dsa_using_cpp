#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        bool dfs(int node, int col, vector<int> &color, vector<int> adj[]){
            color[node] = col;
            for(auto it: adj[node]){
                if(color[it] == -1) {
                    if(dfs(it, !col, color, adj) == false) return false; 
                }
                else if(color[it] == col) {
                    return false; 
                }
            }
            return true;
        }
    public:
        bool isBipertite(int V, vector<int> adj[]){
            vector<int> color(V, -1);
            for(int i=1; i<V; i++){
                if(color[i]==-1){
                    if(dfs(i, 0, color, adj)==false) return false;
                }
            }
            return true;
        }

};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector<int> adj[9];
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 5, 6);
    
    vector<int> adj2[11];
    addEdge(adj2, 1,2);
    addEdge(adj2, 2,3);
    addEdge(adj2, 3,4);
    addEdge(adj2, 4,5);
    addEdge(adj2, 5,6);
    addEdge(adj2, 6,7);
    addEdge(adj2, 7,8);
    addEdge(adj2, 8,3);
    addEdge(adj2, 6,9);
    addEdge(adj2, 9,10);

    int i=0;
    for(auto it: adj2){
        cout<<i<<": ";
        for(auto x: it) cout<<x<<' ';
        i++;
        cout<<endl;
    }
    Solution sl;
    int V = sizeof(adj2)/sizeof(adj2[0]);
    bool ans = sl.isBipertite(V, adj2);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

