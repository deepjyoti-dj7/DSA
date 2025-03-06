class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class BSTSearch {
    // Recursive Search
    public static TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) return root;
        return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
    }

    // Iterative Search
    public static TreeNode searchBSTIterative(TreeNode root, int val) {
        while (root != null && root.val != val) {
            root = val < root.val ? root.left : root.right;
        }
        return root;
    }

    // Main Function
    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        int target = 2;
        TreeNode result = searchBST(root, target);
        System.out.println(result != null ? "Found: " + result.val : "Not Found");

        result = searchBSTIterative(root, target);
        System.out.println(result != null ? "Found (Iterative): " + result.val : "Not Found");
    }
}
