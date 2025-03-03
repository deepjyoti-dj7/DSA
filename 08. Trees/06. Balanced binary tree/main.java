class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class main {
    // Helper function to check height and balance
    private static int checkHeight(TreeNode root) {
        if (root == null) return 0;

        int leftHeight = checkHeight(root.left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(root.right);
        if (rightHeight == -1) return -1;

        if (Math.abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + Math.max(leftHeight, rightHeight);
    }

    // Function to check if tree is balanced
    public static boolean isBalanced(TreeNode root) {
        return checkHeight(root) != -1;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println(isBalanced(root));
    }
}
