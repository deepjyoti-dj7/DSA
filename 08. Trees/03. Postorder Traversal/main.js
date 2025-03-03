class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Postorder Traversal (Recursive)
function postorderTraversalRecursive(root, result) {
    if (!root) return;
    postorderTraversalRecursive(root.left, result);
    postorderTraversalRecursive(root.right, result);
    result.push(root.val);
}

// Postorder Traversal (Iterative)
function postorderTraversalIterative(root) {
    let result = [];
    if (!root) return result;

    let stack1 = [], stack2 = [];
    stack1.push(root);

    while (stack1.length > 0) {
        let node = stack1.pop();
        stack2.push(node);

        if (node.left) stack1.push(node.left);
        if (node.right) stack1.push(node.right);
    }

    while (stack2.length > 0) {
        result.push(stack2.pop().val);
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
    postorderTraversalRecursive(root, recursiveResult);
    console.log("Recursive Postorder Traversal:", recursiveResult);

    let iterativeResult = postorderTraversalIterative(root);
    console.log("Iterative Postorder Traversal:", iterativeResult);
}

// Run the main function
main();
