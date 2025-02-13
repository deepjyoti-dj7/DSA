class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Postorder Traversal (Recursive)
function postorderTraversal(root, result) {
    if (!root) return;
    postorderTraversal(root.left, result);
    postorderTraversal(root.right, result);
    result.push(root.val);
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
    postorderTraversal(root, result);
    console.log("Postorder Traversal:", result);
}

// Run the main function
main();
