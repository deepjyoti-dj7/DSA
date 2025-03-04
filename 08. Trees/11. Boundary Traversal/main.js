class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Collects left boundary nodes (excluding leaves)
function leftBoundary(root, result) {
    let cur = root.left;
    while (cur) {
        if (cur.left || cur.right) result.push(cur.val);
        cur = cur.left ? cur.left : cur.right;
    }
}

// Collects all leaf nodes
function leafNodes(root, result) {
    if (!root) return;
    if (!root.left && !root.right) {
        result.push(root.val);
        return;
    }
    leafNodes(root.left, result);
    leafNodes(root.right, result);
}

// Collects right boundary nodes in reverse order (excluding leaves)
function rightBoundary(root, result) {
    let stack = [];
    let cur = root.right;
    while (cur) {
        if (cur.left || cur.right) stack.push(cur.val);
        cur = cur.right ? cur.right : cur.left;
    }
    while (stack.length > 0) {
        result.push(stack.pop());
    }
}

// Main function to get boundary traversal
function boundaryTraversal(root) {
    if (!root) return [];

    let result = [root.val];

    leftBoundary(root, result);
    leafNodes(root, result);
    rightBoundary(root, result);

    return result;
}

// Example Usage
function main() {
    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.right = new TreeNode(6);
    root.left.right.left = new TreeNode(7);
    root.left.right.right = new TreeNode(8);

    console.log("Boundary Traversal:", boundaryTraversal(root));
}

// Run the main function
main();
