class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {

    // Find minimum node in a subtree
    private static TreeNode findMin(TreeNode root) {
        while (root.left != null) root = root.left;
        return root;
    }

    // Recursive Delete
    public static TreeNode deleteRecursive(TreeNode root, int key) {
        if (root == null) return null;

        if (key < root.val) root.left = deleteRecursive(root.left, key);
        else if (key > root.val) root.right = deleteRecursive(root.right, key);
        else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            
            TreeNode temp = findMin(root.right);
            root.val = temp.val;
            root.right = deleteRecursive(root.right, temp.val);
        }
        return root;
    }

    // Iterative Delete
    public static TreeNode deleteIterative(TreeNode root, int key) {
        TreeNode parent = null, cur = root;

        while (cur != null && cur.val != key) {
            parent = cur;
            if (key < cur.val) cur = cur.left;
            else cur = cur.right;
        }

        if (cur == null) return root; // Key not found

        if (cur.left == null || cur.right == null) {
            TreeNode newChild = (cur.left != null) ? cur.left : cur.right;
            if (parent == null) return newChild;
            if (parent.left == cur) parent.left = newChild;
            else parent.right = newChild;
        } else {
            TreeNode successor = findMin(cur.right);
            cur.val = successor.val;
            cur.right = deleteRecursive(cur.right, successor.val);
        }
        return root;
    }

    // Inorder Traversal
    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        root.left.right = new TreeNode(6);
        root.right.right = new TreeNode(14);

        root = deleteRecursive(root, 10);
        System.out.print("Inorder after Recursive Delete: ");
        inorder(root);
        System.out.println();

        root = deleteIterative(root, 6);
        System.out.print("Inorder after Iterative Delete: ");
        inorder(root);
        System.out.println();
    }
}
