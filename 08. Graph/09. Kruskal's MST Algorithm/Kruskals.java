import java.util.*;

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


class Edge {
    int u, v, weight;

    public Edge(int u, int v, int weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }

    // Comparator to sort edges by weight
    public static final Comparator<Edge> COMPARE_BY_WEIGHT = new Comparator<Edge>() {
        public int compare(Edge e1, Edge e2) {
            return Integer.compare(e1.weight, e2.weight);
        }
    };
}

public class Kruskals {
    public static void kruskalMST(int n, List<Edge> edges) {
        // Sort edges by weight
        Collections.sort(edges, Edge.COMPARE_BY_WEIGHT);

        DisjointSet ds = new DisjointSet(n);

        List<Edge> mst = new ArrayList<>();
        int totalWeight = 0;

        for (Edge edge : edges) {
            int u = edge.u;
            int v = edge.v;

            // If they are in different sets, include this edge in MST
            if (ds.find(u) != ds.find(v)) {
                ds.unionByRank(u, v);
                mst.add(edge);
                totalWeight += edge.weight;
            }
        }

        // Output the MST
        System.out.println("Edges in the Minimum Spanning Tree:");
        for (Edge edge : mst) {
            System.out.println(edge.u + " - " + edge.v + " (weight: " + edge.weight + ")");
        }
        System.out.println("Total weight of MST: " + totalWeight);
    }

    public static void main(String[] args) {
        int n = 5; // Number of vertices
        List<Edge> edges = new ArrayList<>();

        // Adding edges
        edges.add(new Edge(0, 1, 2));
        edges.add(new Edge(0, 3, 6));
        edges.add(new Edge(1, 2, 3));
        edges.add(new Edge(1, 3, 8));
        edges.add(new Edge(1, 4, 5));
        edges.add(new Edge(2, 4, 7));

        // Call Kruskal's Algorithm
        kruskalMST(n, edges);
    }
}
