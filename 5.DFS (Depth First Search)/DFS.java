import java.util.*;

public class DFS {

    public static void dfs(int node, List<List<Integer>> adj, boolean[] vis) {
        vis[node] = true;
        System.out.print(node + " ");

        for (int neigh : adj.get(node)) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    public static void main(String[] args) {
        int n = 6;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) 
            adj.add(new ArrayList<>());

        adj.get(0).addAll(Arrays.asList(1, 2));
        adj.get(1).addAll(Arrays.asList(0, 3, 4));
        adj.get(2).addAll(Arrays.asList(0, 4));
        adj.get(3).addAll(Arrays.asList(1));
        adj.get(4).addAll(Arrays.asList(1, 2, 5));
        adj.get(5).addAll(Arrays.asList(4));

        boolean[] vis = new boolean[n];

        System.out.print("DFS starting from node 0: ");
        dfs(0, adj, vis);
    }
}
