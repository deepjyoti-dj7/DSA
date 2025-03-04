import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {

    // DFS Approach
    public static boolean isMirrorDFS(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.val == t2.val) && 
               isMirrorDFS(t1.left, t2.right) &&
               isMirrorDFS(t1.right, t2.left);
    }

    public static boolean isSymmetricDFS(TreeNode root) {
        if (root == null) return true;
        return isMirrorDFS(root.left, root.right);
    }

    // BFS Approach
    public static boolean isSymmetricBFS(TreeNode root) {
        if (root == null) return true;
        
        Queue<TreeNode[]> queue = new LinkedList<>();
        queue.add(new TreeNode[]{root.left, root.right});

        while (!queue.isEmpty()) {
            TreeNode[] pair = queue.poll();
            TreeNode t1 = pair[0], t2 = pair[1];

            if (t1 == null && t2 == null) continue;
            if (t1 == null || t2 == null || t1.val != t2.val) return false;

            queue.add(new TreeNode[]{t1.left, t2.right});
            queue.add(new TreeNode[]{t1.right, t2.left});
        }
        return true;
    }

    // Main Function
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);

        System.out.println("DFS Approach: " + isSymmetricDFS(root));
        System.out.println("BFS Approach: " + isSymmetricBFS(root));
    }
}
