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
    // Postorder Traversal (Recursive)
    public static void postorderTraversalRecursive(TreeNode root, List<Integer> result) {
        if (root == null) return;
        postorderTraversalRecursive(root.left, result);
        postorderTraversalRecursive(root.right, result);
        result.add(root.val);
    }

    // Postorder Traversal (Iterative)
    public static List<Integer> postorderTraversalIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root);

        while (!stack1.isEmpty()) {
            TreeNode node = stack1.pop();
            stack2.push(node);

            if (node.left != null) stack1.push(node.left);
            if (node.right != null) stack1.push(node.right);
        }

        while (!stack2.isEmpty()) {
            result.add(stack2.pop().val);
        }

        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        List<Integer> recursiveResult = new ArrayList<>();
        postorderTraversalRecursive(root, recursiveResult);
        System.out.println("Recursive Postorder Traversal: " + recursiveResult);

        List<Integer> iterativeResult = postorderTraversalIterative(root);
        System.out.println("Iterative Postorder Traversal: " + iterativeResult);
    }
}
