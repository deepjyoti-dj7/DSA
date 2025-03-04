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
    // Inorder Traversal (Recursive)
    public static void inorderTraversalRecursive(TreeNode root, List<Integer> result) {
        if (root == null) return;
        inorderTraversalRecursive(root.left, result);
        result.add(root.val);
        inorderTraversalRecursive(root.right, result);
    }

    // Inorder Traversal (Iterative)
    public static List<Integer> inorderTraversalIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
            current = stack.pop();
            result.add(current.val);
            current = current.right;
        }
        return result;
    }

    public static void main(String[] args) {
        // Sample tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        List<Integer> recursiveResult = new ArrayList<>();
        inorderTraversalRecursive(root, recursiveResult);
        System.out.println("Recursive Inorder Traversal: " + recursiveResult);

        List<Integer> iterativeResult = inorderTraversalIterative(root);
        System.out.println("Iterative Inorder Traversal: " + iterativeResult);
    }
}
