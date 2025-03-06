class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; left = right = null; }
}

public class main {
    // Iterative Ceil
    public static int findCeilIterative(TreeNode root, int key) {
        int ceil = -1;
        while (root != null) {
            if (root.val == key) return root.val;
            if (root.val > key) {
                ceil = root.val;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return ceil;
    }

    // Recursive Ceil
    public static int findCeilRecursive(TreeNode root, int key) {
        if (root == null) return -1;
        if (root.val == key) return root.val;
        if (root.val < key) return findCeilRecursive(root.right, key);
        int ceil = findCeilRecursive(root.left, key);
        return (ceil >= key) ? ceil : root.val;
    }

    // Iterative Floor
    public static int findFloorIterative(TreeNode root, int key) {
        int floor = -1;
        while (root != null) {
            if (root.val == key) return root.val;
            if (root.val < key) {
                floor = root.val;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return floor;
    }

    // Recursive Floor
    public static int findFloorRecursive(TreeNode root, int key) {
        if (root == null) return -1;
        if (root.val == key) return root.val;
        if (root.val > key) return findFloorRecursive(root.left, key);
        int floor = findFloorRecursive(root.right, key);
        return (floor <= key && floor != -1) ? floor : root.val;
    }

    // Main function
    public static void main(String[] args) {
        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(4);
        root.right = new TreeNode(12);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(6);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(14);

        int key = 5;
        System.out.println("Ceil (Iterative): " + findCeilIterative(root, key));
        System.out.println("Ceil (Recursive): " + findCeilRecursive(root, key));
        System.out.println("Floor (Iterative): " + findFloorIterative(root, key));
        System.out.println("Floor (Recursive): " + findFloorRecursive(root, key));
    }
}
