class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Inorder Traversal (Recursive)
function inorderTraversalRecursive(root, result) {
    if (!root) return;
    inorderTraversalRecursive(root.left, result);
    result.push(root.val);
    inorderTraversalRecursive(root.right, result);
}

// Inorder Traversal (Iterative)
function inorderTraversalIterative(root) {
    let result = [];
    let stack = [];
    let current = root;

    while (current !== null || stack.length > 0) {
        while (current !== null) {
            stack.push(current);
            current = current.left;
        }
        current = stack.pop();
        result.push(current.val);
        current = current.right;
    }
    return result;
}

// Main function
function main() {
    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.left = new TreeNode(6);
    root.right.right = new TreeNode(7);

    let recursiveResult = [];
    inorderTraversalRecursive(root, recursiveResult);
    console.log("Recursive Inorder Traversal:", recursiveResult);

    let iterativeResult = inorderTraversalIterative(root);
    console.log("Iterative Inorder Traversal:", iterativeResult);
}

// Run the main function
main();
