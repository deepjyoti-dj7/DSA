import java.util.*;

public class TopologicalSort {
    public static void dfs(int node, List<List<Integer>> adj, boolean[] vis, Stack<Integer> st) {
        vis[node] = true;
        for (int neigh : adj.get(node)) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, st);
            }
        }
        st.push(node);
    }

    public static List<Integer> topologicalSortDFS(int n, List<List<Integer>> adj) {
        boolean[] vis = new boolean[n];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        List<Integer> topo = new ArrayList<>();
        while (!st.isEmpty()) {
            topo.add(st.pop());
        }
        return topo;
    }

    public static List<Integer> topologicalSortBFS(int n, List<List<Integer>> adj) {
        int[] indegree = new int[n];
        for (int i = 0; i < n; i++) {
            for (int neigh : adj.get(i)) {
                indegree[neigh]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        List<Integer> topo = new ArrayList<>();
        while (!q.isEmpty()) {
            int cur = q.poll();
            topo.add(cur);

            for (int neigh : adj.get(cur)) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.add(neigh);
                }
            }
        }

        return topo;
    }

    public static void main(String[] args) {
        int n = 6;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        adj.get(5).add(2);
        adj.get(5).add(0);
        adj.get(4).add(0);
        adj.get(4).add(1);
        adj.get(2).add(3);
        adj.get(3).add(1);

        List<Integer> topo = topologicalSortDFS(n, adj);
        System.out.println("Topological Sort (DFS): " + topo);

        topo = topologicalSortBFS(n, adj);
        System.out.println("Topological Sort (BFS): " + topo);
    }
}
