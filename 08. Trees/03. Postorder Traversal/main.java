import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    
    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class PostorderTraversal {
    // Postorder Traversal (Recursive)
    public static void postorderTraversal(TreeNode root, List<Integer> result) {
        if (root == null) return;
        postorderTraversal(root.left, result);
        postorderTraversal(root.right, result);
        result.add(root.val);
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

        List<Integer> result = new ArrayList<>();
        postorderTraversal(root, result);

        System.out.println("Postorder Traversal: " + result);
    }
}
