import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

// Custom Pair class
class Pair<U, V> {
    private final U key;
    private final V value;
    
    public Pair(U key, V value) {
        this.key = key;
        this.value = value;
    }

    public U getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

public class main {

    // BFS Approach for Top View
    public static List<Integer> topViewBFS(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Map<Integer, Integer> topNodes = new TreeMap<>();
        Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        queue.add(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.poll();
            TreeNode node = pair.getKey();
            int hd = pair.getValue();

            if (!topNodes.containsKey(hd)) {
                topNodes.put(hd, node.val);
            }

            if (node.left != null) queue.add(new Pair<>(node.left, hd - 1));
            if (node.right != null) queue.add(new Pair<>(node.right, hd + 1));
        }

        for (int val : topNodes.values()) result.add(val);
        return result;
    }

    // DFS Approach for Top View
    public static void dfs(TreeNode node, int hd, int depth, Map<Integer, Pair<Integer, Integer>> topNodes) {
        if (node == null) return;

        if (!topNodes.containsKey(hd) || depth < topNodes.get(hd).getValue()) {
            topNodes.put(hd, new Pair<>(node.val, depth));
        }

        dfs(node.left, hd - 1, depth + 1, topNodes);
        dfs(node.right, hd + 1, depth + 1, topNodes);
    }

    public static List<Integer> topViewDFS(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Map<Integer, Pair<Integer, Integer>> topNodes = new TreeMap<>();
        dfs(root, 0, 0, topNodes);

        for (Pair<Integer, Integer> pair : topNodes.values()) result.add(pair.getKey());
        return result;
    }

    // Main Function
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.left.right.right = new TreeNode(5);
        root.left.right.right.right = new TreeNode(6);

        System.out.println("Top View (BFS): " + topViewBFS(root));
        System.out.println("Top View (DFS): " + topViewDFS(root));
    }
}
