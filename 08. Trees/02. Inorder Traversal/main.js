class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Inorder Traversal (Recursive)
function inorderTraversal(root, result) {
    if (!root) return;
    inorderTraversal(root.left, result);
    result.push(root.val);
    inorderTraversal(root.right, result);
}

// Main function
function main() {
    // Sample tree
    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.left = new TreeNode(6);
    root.right.right = new TreeNode(7);

    let result = [];
    inorderTraversal(root, result);
    console.log("Inorder Traversal:", result);
}

// Run the main function
main();
