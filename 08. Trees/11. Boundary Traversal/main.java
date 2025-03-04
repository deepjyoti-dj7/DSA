import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {
    // Collects left boundary nodes
    private static void leftBoundary(TreeNode root, List<Integer> result) {
        TreeNode cur = root.left;
        while (cur != null) {
            if (cur.left != null || cur.right != null) result.add(cur.val);
            cur = (cur.left != null) ? cur.left : cur.right;
        }
    }

    // Collects all leaf nodes
    private static void leafNodes(TreeNode root, List<Integer> result) {
        if (root == null) return;
        if (root.left == null && root.right == null) result.add(root.val);
        leafNodes(root.left, result);
        leafNodes(root.right, result);
    }

    // Collects right boundary nodes in reverse order
    private static void rightBoundary(TreeNode root, List<Integer> result) {
        Stack<Integer> stack = new Stack<>();
        TreeNode cur = root.right;
        while (cur != null) {
            if (cur.left != null || cur.right != null) stack.push(cur.val);
            cur = (cur.right != null) ? cur.right : cur.left;
        }
        while (!stack.isEmpty()) result.add(stack.pop());
    }

    public static List<Integer> boundaryTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        result.add(root.val);
        leftBoundary(root, result);
        leafNodes(root, result);
        rightBoundary(root, result);

        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.right = new TreeNode(6);
        root.left.right.left = new TreeNode(7);
        root.left.right.right = new TreeNode(8);

        System.out.println("Boundary Traversal: " + boundaryTraversal(root));
    }
}
