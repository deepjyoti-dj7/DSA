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

    public U getKey() { return key; }
    public V getValue() { return value; }
}

public class main {

    // BFS Approach for Bottom View
    public static List<Integer> bottomViewBFS(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Map<Integer, Integer> bottomNodes = new TreeMap<>();
        Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        queue.add(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.poll();
            TreeNode node = pair.getKey();
            int hd = pair.getValue();

            bottomNodes.put(hd, node.val);  // Store last encountered node at this HD

            if (node.left != null) queue.add(new Pair<>(node.left, hd - 1));
            if (node.right != null) queue.add(new Pair<>(node.right, hd + 1));
        }

        for (int val : bottomNodes.values()) result.add(val);
        return result;
    }

    // DFS Approach for Bottom View
    public static void dfs(TreeNode node, int hd, int depth, Map<Integer, Pair<Integer, Integer>> bottomNodes) {
        if (node == null) return;

        if (!bottomNodes.containsKey(hd) || depth >= bottomNodes.get(hd).getValue()) {
            bottomNodes.put(hd, new Pair<>(node.val, depth));
        }

        dfs(node.left, hd - 1, depth + 1, bottomNodes);
        dfs(node.right, hd + 1, depth + 1, bottomNodes);
    }

    public static List<Integer> bottomViewDFS(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Map<Integer, Pair<Integer, Integer>> bottomNodes = new TreeMap<>();
        dfs(root, 0, 0, bottomNodes);

        for (Pair<Integer, Integer> pair : bottomNodes.values()) result.add(pair.getKey());
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

        System.out.println("Bottom View (BFS): " + bottomViewBFS(root));
        System.out.println("Bottom View (DFS): " + bottomViewDFS(root));
    }
}
