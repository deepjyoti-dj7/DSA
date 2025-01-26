import java.util.*;

public class BFS {
    public static void bfs(int node, List<List<Integer>> adj, boolean[] vis) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        vis[node] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            System.out.print(cur + " ");

            for (int neigh : adj.get(cur)) {
                if (!vis[neigh]) {
                    q.add(neigh);
                    vis[neigh] = true;
                }
            }
        }
    }
    public static void main(String[] args) {
        int n = 6;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) 
            adj.add(new ArrayList<>());

        adj.get(0).addAll(Arrays.asList(1,2));
        adj.get(1).addAll(Arrays.asList(0, 3, 4));
        adj.get(2).addAll(Arrays.asList(0, 4));
        adj.get(3).addAll(Arrays.asList(1));
        adj.get(4).addAll(Arrays.asList(1, 2, 5));
        adj.get(5).addAll(Arrays.asList(4));

        boolean[] vis = new boolean[n];

        System.out.print("BFS starting from node 0: ");
        bfs(0, adj, vis);
    }
}