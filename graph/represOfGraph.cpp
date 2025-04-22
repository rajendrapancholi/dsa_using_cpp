/**********************
Program Name        : Representation of Graph
Author              : Rajendra Pancholi
Date of creation    : 22/04/2025
Organization        : NIT Patna
***********************/

#include <iostream>
#include <vector>
using namespace std;

// Space needed to represent a graph using its adjacency matrix is n² locations. Space complexity = (n*n), It is a costly method as n² locations are consumed.
int main()
{
    // M1
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    // cout << "Number of vertices: " << n << endl;
    // cout << "Number of edges: " << m << endl;
    // int adjMatrix[n + 1][n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v; // u = starting vertex, v = ending vertex
    //     cin >> u >> v;
    //     adjMatrix[u][v] = 1;
    //     adjMatrix[v][u] = 1; // for undirected graph
    // }

    // M2
    // adjacency list for undirected graph
    // time complexity: O(2E)
    // vector<int> adj[n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    // M3
    // for r directed graphs.
    // Space complexity = O(E)
    // adjacency list for directed graph
    // time complexity: O(E)
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        // u —> v
        cin >> u >> v;
        adj[u].push_back(v);
    }
    return 0;
}