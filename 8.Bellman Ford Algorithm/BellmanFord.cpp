#include <bits/stdc++.h>
using namespace std;

vector<int> BellmanFord(int n, int src, vector<vector<int>> &edges) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges (n-1) times
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return {};
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of vertices
    int src = 0; // Source vertex
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    vector<int> distances = BellmanFord(n, src, edges);

    if (!distances.empty()) {
        cout << "Distances from source " << src << ": ";
        for (int i = 0; i < n; i++) {
            if (distances[i] == INT_MAX)
                cout << "INF ";
            else
                cout << distances[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
