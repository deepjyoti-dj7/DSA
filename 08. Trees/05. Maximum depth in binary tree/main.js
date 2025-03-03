class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Recursive DFS approach
function maxDepthRecursive(root) {
    if (!root) return 0;
    return 1 + Math.max(maxDepthRecursive(root.left), maxDepthRecursive(root.right));
}

// Iterative BFS approach using Queue
function maxDepthIterative(root) {
    if (!root) return 0;

    let queue = [root];
    let depth = 0;

    while (queue.length > 0) {
        let size = queue.length;
        depth++;
        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
    }

    return depth;
}

// Main function
function main() {
    let root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);

    console.log("Recursive Max Depth:", maxDepthRecursive(root));
    console.log("Iterative Max Depth:", maxDepthIterative(root));
}

// Run the main function
main();
