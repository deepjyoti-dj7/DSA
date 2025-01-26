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
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find the representative (root) of the set containing x, with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union two sets containing x and y, using union by rank
    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach smaller tree under larger tree
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
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

int main() {
    int n = 7; // Number of elements
    DisjointSet ds(n);

    // Perform some union operations
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 4);

    // Check connectivity
    cout << "Is 1 connected to 3? " << (ds.isConnected(1, 3) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 5? " << (ds.isConnected(1, 5) ? "Yes" : "No") << endl;

    // Find the root of a specific element
    cout << "Root of 2: " << ds.find(2) << endl;
    cout << "Root of 4: " << ds.find(4) << endl;

    return 0;
}
