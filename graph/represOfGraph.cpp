/**********************
Program Name        : Representation of Graph
Author              : Rajendra Pancholi
Date of creation    : 22/04/2025
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

// Space needed to represent a graph using its adjacency matrix is n² locations. Space complexity = (n*n), It is a costly method as n² locations are consumed.
int main()
{
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    cout << "Number of vertices: " << n << endl;
    cout << "Number of edges: " << m << endl;
    int adjMatrix[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v; // u = starting vertex, v = ending vertex
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }

    return 0;
}