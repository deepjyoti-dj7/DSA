#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank, size;

public:
    // Constructor: Initialize DSU with n elements
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Rank is initialized to 0
        size.resize(n, 1); // Size of each set is initially 1
        for (int i = 0; i < n; i++) 
            parent[i] = i; // Each element is its own parent initially
    }

    // Find the representative (root) of the set containing x, with path compression
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // Union two sets containing x and y, using union by rank
    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) 
                parent[rootY] = rootX; // Attach smaller tree under larger tree
            else if (rank[rootX] < rank[rootY]) 
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX; // If ranks are equal, attach under one and increment rank
                rank[rootX]++;
            }
        }
    }

    // Union two sets containing x and y, using union by size
    void unionBySize(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

    // Helper function to check if two elements are in the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};


// Edge structure
struct Edge {
    int u, v, weight;

    Edge(int _u, int _v, int _weight) {
        u = _u;
        v = _v;
        weight = _weight;
    }

    // Comparator for sorting edges by weight
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

void kruskalMST(int n, vector<Edge> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Create a Disjoint Set
    DisjointSet ds(n);

    vector<Edge> mst; // To store MST edges
    int totalWeight = 0;

    for (const auto &edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // Check if the current edge forms a cycle
        if (ds.find(u) != ds.find(v)) {
            ds.unionByRank(u, v);
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    // Output the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto &edge : mst) {
        cout << edge.u << " - " << edge.v << " (weight: " << edge.weight << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int n = 5; // Number of vertices
    vector<Edge> edges;

    // Adding edges to the graph
    edges.emplace_back(0, 1, 2);
    edges.emplace_back(0, 3, 6);
    edges.emplace_back(1, 2, 3);
    edges.emplace_back(1, 3, 8);
    edges.emplace_back(1, 4, 5);
    edges.emplace_back(2, 4, 7);

    // Call Kruskal's Algorithm
    kruskalMST(n, edges);

    return 0;
}
