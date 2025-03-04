import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {

    // Left View using BFS
    public static List<Integer> leftViewBFS(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            result.add(queue.peek().val); // First node in the level

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        return result;
    }

    // Right View using BFS
    public static List<Integer> rightViewBFS(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            result.add(queue.peek().val); // Last node in the level

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node.right != null) queue.add(node.right);
                if (node.left != null) queue.add(node.left);
            }
        }
        return result;
    }

    // Left View using DFS
    public static void leftViewDFS(TreeNode node, int level, List<Integer> result) {
        if (node == null) return;

        if (level == result.size()) {
            result.add(node.val);
        }

        leftViewDFS(node.left, level + 1, result);
        leftViewDFS(node.right, level + 1, result);
    }

    public static List<Integer> leftView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        leftViewDFS(root, 0, result);
        return result;
    }

    // Right View using DFS
    public static void rightViewDFS(TreeNode node, int level, List<Integer> result) {
        if (node == null) return;

        if (level == result.size()) {
            result.add(node.val);
        }

        rightViewDFS(node.right, level + 1, result);
        rightViewDFS(node.left, level + 1, result);
    }

    public static List<Integer> rightView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        rightViewDFS(root, 0, result);
        return result;
    }

    // Main function
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        // BFS Results
        System.out.println("Left View (BFS): " + leftViewBFS(root));
        System.out.println("Right View (BFS): " + rightViewBFS(root));

        // DFS Results
        System.out.println("Left View (DFS): " + leftView(root));
        System.out.println("Right View (DFS): " + rightView(root));
    }
}
