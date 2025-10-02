/* Number of Ways to Arrive at Destination
Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output:
4
Explanation: 
The four ways to get there in 7 minutes (which is the shortest calculated time) are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        while (!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if (dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

int main(){
    int n = 7;
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    Solution obj;
    int ans = obj.countPaths(n, edges);
    cout << ans;
    cout << endl;
    return 0;
}