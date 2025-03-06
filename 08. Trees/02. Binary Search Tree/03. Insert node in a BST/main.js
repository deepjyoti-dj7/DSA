class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Recursive Insert
function insertRecursive(root, key) {
    if (!root) return new TreeNode(key);
    if (key < root.val) root.left = insertRecursive(root.left, key);
    else root.right = insertRecursive(root.right, key);
    return root;
}

// Iterative Insert
function insertIterative(root, key) {
    if (!root) return new TreeNode(key);

    let cur = root, parent = null;
    while (cur) {
        parent = cur;
        if (key < cur.val) cur = cur.left;
        else cur = cur.right;
    }

    if (key < parent.val) parent.left = new TreeNode(key);
    else parent.right = new TreeNode(key);

    return root;
}

// Inorder Traversal (Helper function)
function inorder(root) {
    if (!root) return;
    inorder(root.left);
    process.stdout.write(root.val + " ");
    inorder(root.right);
}

// Main function
function main() {
    let root = new TreeNode(8);
    root = insertRecursive(root, 3);
    root = insertRecursive(root, 10);
    root = insertIterative(root, 6);
    root = insertIterative(root, 14);

    process.stdout.write("Inorder Traversal: ");
    inorder(root);
    console.log();
}

main();
