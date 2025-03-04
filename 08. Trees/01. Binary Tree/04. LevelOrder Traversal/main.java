import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    
    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class main {
    
    // Level Order Traversal using BFS (Queue)
    public static List<List<Integer>> levelOrderBFS(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                level.add(node.val);

                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            result.add(level);
        }
        return result;
    }

    // DFS Helper Function
    private static void dfs(TreeNode node, int level, List<List<Integer>> result) {
        if (node == null) return;

        if (result.size() == level)
            result.add(new ArrayList<>());

        result.get(level).add(node.val);

        dfs(node.left, level + 1, result);
        dfs(node.right, level + 1, result);
    }

    // Level Order Traversal using DFS (Recursion)
    public static List<List<Integer>> levelOrderDFS(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(root, 0, result);
        return result;
    }

    public static void main(String[] args) {
        // Sample Tree:
        //      1
        //     / \
        //    2   3
        //   / \ / \
        //  4  5 6  7

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        System.out.println("Level Order Traversal (BFS): " + levelOrderBFS(root));
        System.out.println("Level Order Traversal (DFS): " + levelOrderDFS(root));
    }
}
