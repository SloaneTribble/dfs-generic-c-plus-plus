#include <iostream>
#include <vector>
using namespace std;

// Generic DFS function for a graph represented by an adjacency list
void dfs(int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << "Visiting node " << node << endl; // Perform any desired operation on the node

    // Traverse all adjacent nodes (neighbors) of the current node
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited); // Recursively visit unvisited neighbors
        }
    }
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    // Initialize adjacency list with n nodes
    vector<vector<int>> adjList(n);
    
    // Read edges and build the adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Assuming 0-based indexing for nodes; if 1-based, adjust accordingly
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph; remove this line for directed
    }

    // Initialize visited array to keep track of visited nodes
    vector<bool> visited(n, false);

    // Perform DFS from every node to handle disconnected graphs
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "Starting new DFS traversal from node " << i << endl;
            dfs(i, adjList, visited);
        }
    }

    return 0;
}
