class TreeNode {
    int val;
    TreeNode left, right;
    
    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class main {
    private static int maxSum;
    
    public static int dfs(TreeNode root) {
        if (root == null) return 0;
        
        int leftMax = Math.max(0, dfs(root.left));
        int rightMax = Math.max(0, dfs(root.right));
        
        maxSum = Math.max(maxSum, root.val + leftMax + rightMax);
        
        return root.val + Math.max(leftMax, rightMax);
    }
    
    public static int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        dfs(root);
        return maxSum;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(-10);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        System.out.println(maxPathSum(root)); // Output: 42
    }
}
