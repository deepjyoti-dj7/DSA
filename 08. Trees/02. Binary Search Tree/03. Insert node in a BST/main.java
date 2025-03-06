import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {

    // Recursive Insert
    public static TreeNode insertRecursive(TreeNode root, int key) {
        if (root == null) return new TreeNode(key);
        if (key < root.val) root.left = insertRecursive(root.left, key);
        else root.right = insertRecursive(root.right, key);
        return root;
    }

    // Iterative Insert
    public static TreeNode insertIterative(TreeNode root, int key) {
        if (root == null) return new TreeNode(key);

        TreeNode cur = root, parent = null;
        while (cur != null) {
            parent = cur;
            if (key < cur.val) cur = cur.left;
            else cur = cur.right;
        }

        if (key < parent.val) parent.left = new TreeNode(key);
        else parent.right = new TreeNode(key);

        return root;
    }

    // Inorder Traversal (Helper function)
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    // Main function
    public static void main(String[] args) {
        TreeNode root = new TreeNode(8);
        root = insertRecursive(root, 3);
        root = insertRecursive(root, 10);
        root = insertIterative(root, 6);
        root = insertIterative(root, 14);

        System.out.print("Inorder Traversal: ");
        inorder(root);
        System.out.println();
    }
}
