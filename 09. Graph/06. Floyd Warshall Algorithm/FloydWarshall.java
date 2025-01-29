import java.util.*;

public class FloydWarshall {
    public static void floydWarshall(int n, int[][] dist) {
        // Iterating through all intermediate nodes
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 4; // Number of vertices
        int[][] dist = {
            {0, 3, Integer.MAX_VALUE, 7},
            {8, 0, 2, Integer.MAX_VALUE},
            {5, Integer.MAX_VALUE, 0, 1},
            {2, Integer.MAX_VALUE, Integer.MAX_VALUE, 0}
        };

        floydWarshall(n, dist);

        System.out.println("Shortest distances between every pair of vertices:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == Integer.MAX_VALUE) 
                    System.out.print("INF ");
                else 
                    System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }
}
