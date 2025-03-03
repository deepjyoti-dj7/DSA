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
    // Preorder Traversal (Recursive)
    public static void preorderTraversalRecursive(TreeNode root, List<Integer> result) {
        if (root == null) return;
        result.add(root.val);
        preorderTraversalRecursive(root.left, result);
        preorderTraversalRecursive(root.right, result);
    }

    // Preorder Traversal (Iterative)
    public static List<Integer> preorderTraversalIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            result.add(node.val);

            // Push right first so that left is processed first
            if (node.right != null) stack.push(node.right);
            if (node.left != null) stack.push(node.left);
        }
        return result;
    }

    public static void main(String[] args) {
        // Sample tree:   1
        //              /   \
        //             2     3
        //            / \   / \
        //           4   5 6   7

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        // Recursive Preorder Traversal
        List<Integer> recursiveResult = new ArrayList<>();
        preorderTraversalRecursive(root, recursiveResult);
        System.out.println("Recursive Preorder Traversal: " + recursiveResult);

        // Iterative Preorder Traversal
        List<Integer> iterativeResult = preorderTraversalIterative(root);
        System.out.println("Iterative Preorder Traversal: " + iterativeResult);
    }
}
