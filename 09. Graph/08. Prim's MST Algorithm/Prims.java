import java.util.*;

class Prims {
    static class Edge {
        int vertex, weight;

        Edge(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
    }

    static void primsAlgorithm(int n, List<List<Edge>> adj) {
        int[] key = new int[n];
        int[] parent = new int[n];
        boolean[] inMST = new boolean[n];
        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);

        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.weight - b.weight);
        key[0] = 0;
        pq.add(new Edge(0, 0));

        while (!pq.isEmpty()) {
            int u = pq.poll().vertex;
            inMST[u] = true;

            for (Edge edge : adj.get(u)) {
                int v = edge.vertex;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.add(new Edge(v, weight));
                    parent[v] = u;
                }
            }
        }

        // Output MST edges and total weight
        int totalWeight = 0;
        System.out.println("Edges in the Minimum Spanning Tree:");
        for (int i = 1; i < n; i++) {
            System.out.println(parent[i] + " - " + i + " (weight: " + key[i] + ")");
            totalWeight += key[i];
        }
        System.out.println("Total weight of MST: " + totalWeight);
    }

    public static void main(String[] args) {
        int n = 5;
        List<List<Edge>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Adding edges
        adj.get(0).add(new Edge(1, 2)); adj.get(1).add(new Edge(0, 2));
        adj.get(0).add(new Edge(3, 6)); adj.get(3).add(new Edge(0, 6));
        adj.get(1).add(new Edge(2, 3)); adj.get(2).add(new Edge(1, 3));
        adj.get(1).add(new Edge(3, 8)); adj.get(3).add(new Edge(1, 8));
        adj.get(1).add(new Edge(4, 5)); adj.get(4).add(new Edge(1, 5));
        adj.get(2).add(new Edge(4, 7)); adj.get(4).add(new Edge(2, 7));

        primsAlgorithm(n, adj);
    }
}
