// Breadth First Search (BFS): Level Order Traversal
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:
/*
Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list*/

    vector<int> bfsTravesal(int V, vector<int> adj[]){
        int vis[V]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }

};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> ans){
    for (auto x: ans){
        cout<<x<<" ";
    }
    
}

int main(){
/*  0
   / \
  1   4
 / \
2   3  */

    vector<int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    Solution sl;
    vector <int> ans = sl.bfsTravesal(5, adj);
    printAns(ans);

    return 0;
}
