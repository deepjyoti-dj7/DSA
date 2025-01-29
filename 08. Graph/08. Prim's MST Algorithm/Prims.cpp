#include <bits/stdc++.h>
using namespace std;

// A structure to represent a weighted edge in the graph
typedef pair<int, int> pii; // {weight, vertex}

// Prim's Algorithm to find the Minimum Spanning Tree
void primsAlgorithm(int n, vector<vector<pii>> &adj) {
    vector<int> key(n, INT_MAX);  // To store the minimum weight edge for each vertex
    vector<bool> inMST(n, false); // To keep track of vertices included in MST
    vector<int> parent(n, -1);    // To store the MST structure

    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap: {key, vertex}
    key[0] = 0;  // Start from vertex 0 (arbitrary)
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // If the vertex is already in MST, skip it
        inMST[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;   // Adjacent vertex
            int weight = edge.second; // Weight of the edge

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;  // Update the minimum weight edge for vertex v
                pq.push({key[v], v});
                parent[v] = u;    // Store the MST edge
            }
        }
    }

    // Printing the MST edges and total weight
    int totalWeight = 0;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (weight: " << key[i] << ")\n";
        totalWeight += key[i];
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<pii>> adj(n);

    // Adding edges to the adjacency list
    // Example graph
    adj[0].push_back({1, 2}); adj[1].push_back({0, 2});
    adj[0].push_back({3, 6}); adj[3].push_back({0, 6});
    adj[1].push_back({2, 3}); adj[2].push_back({1, 3});
    adj[1].push_back({3, 8}); adj[3].push_back({1, 8});
    adj[1].push_back({4, 5}); adj[4].push_back({1, 5});
    adj[2].push_back({4, 7}); adj[4].push_back({2, 7});

    // Run Prim's algorithm
    primsAlgorithm(n, adj);

    return 0;
}
