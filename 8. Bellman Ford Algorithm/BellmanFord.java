import java.util.*;

public class BellmanFord {
    public static List<Integer> bellmanFord(int n, int src, int[][] edges) {
        List<Integer> dist = new ArrayList<>(Collections.nCopies(n, Integer.MAX_VALUE));
        dist.set(src, 0);

        // Relax all edges (n-1) times
        for (int i = 0; i < n - 1; i++) {
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                if (dist.get(u) != Integer.MAX_VALUE && dist.get(u) + weight < dist.get(v)) {
                    dist.set(v, dist.get(u) + weight);
                }
            }
        }

        // Check for negative weight cycles
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist.get(u) != Integer.MAX_VALUE && dist.get(u) + weight < dist.get(v)) {
                System.out.println("Negative weight cycle detected!");
                return null;
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int n = 5; // Number of vertices
        int src = 0; // Source vertex
        int[][] edges = {
            {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
            {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
        };

        List<Integer> distances = bellmanFord(n, src, edges);

        if (distances != null) {
            System.out.println("Distances from source " + src + ": " + distances);
        }
    }
}
