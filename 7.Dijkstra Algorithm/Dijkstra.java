import java.util.*;

public class Dijkstra {
    public static List<Integer> dijkstraPriorityQueue(int n, int src, List<List<int[]>> adj) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        pq.offer(new int[]{0, src});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int dis = current[0], node = current[1];

            for (int[] neighbor : adj.get(node)) {
                int neigh = neighbor[0], edgeWt = neighbor[1];
                if (dis + edgeWt < dist[neigh]) {
                    dist[neigh] = dis + edgeWt;
                    pq.offer(new int[]{dist[neigh], neigh});
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int d : dist) 
            result.add(d);
        return result;
    }

    public static List<Integer> dijkstraSet(int n, int src, List<List<int[]>> adj) {
        TreeSet<int[]> set = new TreeSet<>(Comparator.comparingInt(a -> a[0]));
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        set.add(new int[]{0, src});

        while (!set.isEmpty()) {
            int[] current = set.pollFirst();
            int dis = current[0], node = current[1];

            for (int[] neighbor : adj.get(node)) {
                int neigh = neighbor[0], edgeWt = neighbor[1];
                if (dis + edgeWt < dist[neigh]) {
                    set.remove(new int[]{dist[neigh], neigh});

                    dist[neigh] = dis + edgeWt;
                    set.add(new int[]{dist[neigh], neigh});
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int d : dist) 
            result.add(d);
        return result;
    }

    public static void main(String[] args) {
        int n = 5; // Number of nodes
        int src = 0; // Source node
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) 
            adj.add(new ArrayList<>());

        // Graph representation
        adj.get(0).add(new int[]{1, 2});
        adj.get(0).add(new int[]{4, 1});
        adj.get(1).add(new int[]{2, 3});
        adj.get(2).add(new int[]{3, 6});
        adj.get(4).add(new int[]{2, 2});
        adj.get(4).add(new int[]{3, 4});

        // Priority Queue
        System.out.println("Distances (Priority Queue): " + dijkstraPriorityQueue(n, src, adj));

        // Set
        System.out.println("Distances (Set): " + dijkstraSet(n, src, adj));
    }
}
