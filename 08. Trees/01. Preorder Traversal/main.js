class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Preorder Traversal (Recursive)
function preorderTraversalRecursive(root, result) {
    if (!root) return;
    result.push(root.val);
    preorderTraversalRecursive(root.left, result);
    preorderTraversalRecursive(root.right, result);
}

// Preorder Traversal (Iterative)
function preorderTraversalIterative(root) {
    let result = [];
    if (!root) return result;

    let stack = [root];

    while (stack.length > 0) {
        let node = stack.pop();
        result.push(node.val);

        // Push right first so left is processed first
        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
    }
    return result;
}

// Main function
function main() {
    // Sample tree:   1
    //              /   \
    //             2     3
    //            / \   / \
    //           4   5 6   7

    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.left = new TreeNode(6);
    root.right.right = new TreeNode(7);

    let recursiveResult = [];
    preorderTraversalRecursive(root, recursiveResult);
    console.log("Recursive Preorder Traversal:", recursiveResult);

    let iterativeResult = preorderTraversalIterative(root);
    console.log("Iterative Preorder Traversal:", iterativeResult);
}

// Run the main function
main();
