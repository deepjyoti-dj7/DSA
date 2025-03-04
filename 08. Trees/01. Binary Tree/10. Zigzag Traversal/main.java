import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

public class main {
    // BFS Approach
    public static List<List<Integer>> zigzagLevelOrderBFS(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean leftToRight = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>(Collections.nCopies(size, 0));

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                int index = leftToRight ? i : (size - 1 - i);
                level.set(index, node.val);

                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }

            result.add(level);
            leftToRight = !leftToRight;
        }
        return result;
    }

    // DFS Approach
    public static void dfs(TreeNode node, int level, boolean leftToRight, List<List<Integer>> result) {
        if (node == null) return;

        if (result.size() == level)
            result.add(new ArrayList<>());

        if (leftToRight)
            result.get(level).add(node.val);
        else
            result.get(level).add(0, node.val);

        dfs(node.left, level + 1, !leftToRight, result);
        dfs(node.right, level + 1, !leftToRight, result);
    }

    public static List<List<Integer>> zigzagLevelOrderDFS(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(root, 0, true, result);
        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println("Zigzag Level Order (BFS): " + zigzagLevelOrderBFS(root));
        System.out.println("Zigzag Level Order (DFS): " + zigzagLevelOrderDFS(root));
    }
}
