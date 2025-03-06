class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Find minimum node in a subtree
function findMin(root) {
    while (root.left) root = root.left;
    return root;
}

// Recursive Delete
function deleteRecursive(root, key) {
    if (!root) return root;

    if (key < root.val) root.left = deleteRecursive(root.left, key);
    else if (key > root.val) root.right = deleteRecursive(root.right, key);
    else {
        if (!root.left) return root.right;
        if (!root.right) return root.left;

        let temp = findMin(root.right);
        root.val = temp.val;
        root.right = deleteRecursive(root.right, temp.val);
    }
    return root;
}

// Inorder Traversal
function inorder(root) {
    if (!root) return;
    inorder(root.left);
    process.stdout.write(root.val + " ");
    inorder(root.right);
}

// Main function
function main() {
    let root = new TreeNode(8);
    root.left = new TreeNode(3);
    root.right = new TreeNode(10);
    root.left.right = new TreeNode(6);
    root.right.right = new TreeNode(14);

    root = deleteRecursive(root, 10);
    process.stdout.write("Inorder after Recursive Delete: ");
    inorder(root);
    console.log();
}

main();
