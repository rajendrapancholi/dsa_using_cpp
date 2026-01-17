/* Disjoint Set, Union by Rank, Union by Size, Path Compression
*/

#include <iostream>
#include<vector>

using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findUltimateparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltimateparent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUltimateparent(u);
        int ulp_v = findUltimateparent(v);
        if(ulp_u==ulp_v) return; // if same component
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
        void unionBySize(int u, int v) {
        int ulp_u = findUltimateparent(u);
        int ulp_v = findUltimateparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltimateparent(3) == ds.findUltimateparent(7))
        cout << "Same\n";
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUltimateparent(3) == ds.findUltimateparent(7))
        cout << "Same\n";
    else cout << "Not same\n";

    DisjointSet ds1(7);
    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds1.findUltimateparent(3) == ds1.findUltimateparent(7))
        cout << "Same\n";
    else cout << "Not same\n";

    ds1.unionByRank(3, 7);

    if (ds1.findUltimateparent(3) == ds1.findUltimateparent(7))
        cout << "Same\n";
    else cout << "Not same\n";
    return 0;
}