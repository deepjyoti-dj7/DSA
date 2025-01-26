class DisjointSet {
    private int[] parent, rank, size;

    // Constructor: Initialize DSU with n elements
    public DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent initially
            size[i] = 1;  // Size of each set is initially 1
        }
    }

    // Find the representative (root) of the set containing x, with path compression
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union two sets containing x and y, using union by rank
    public void unionByRank(int x, int y) {
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
    public void unionBySize(int x, int y) {
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
    public boolean isConnected(int x, int y) {
        return find(x) == find(y);
    }
}

public class DSU {
    public static void main(String[] args) {
        int n = 7; // Number of elements
        DisjointSet ds = new DisjointSet(n);

        // Perform some union operations
        ds.unionByRank(1, 2);
        ds.unionByRank(2, 3);
        ds.unionBySize(4, 5);
        ds.unionBySize(6, 4);

        // Check connectivity
        System.out.println("Is 1 connected to 3? " + (ds.isConnected(1, 3) ? "Yes" : "No"));
        System.out.println("Is 1 connected to 5? " + (ds.isConnected(1, 5) ? "Yes" : "No"));

        // Find the root of a specific element
        System.out.println("Root of 2: " + ds.find(2));
        System.out.println("Root of 4: " + ds.find(4));
    }
}
