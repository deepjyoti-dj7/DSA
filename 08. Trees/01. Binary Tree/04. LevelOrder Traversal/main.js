class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Level Order Traversal using BFS (Queue)
function levelOrderBFS(root) {
    let result = [];
    if (!root) return result;

    let queue = [root];

    while (queue.length > 0) {
        let levelSize = queue.length;
        let level = [];

        for (let i = 0; i < levelSize; i++) {
            let node = queue.shift();
            level.push(node.val);

            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        result.push(level);
    }
    return result;
}

// DFS Helper Function
function dfs(node, level, result) {
    if (!node) return;

    if (result.length === level)
        result.push([]);

    result[level].push(node.val);

    dfs(node.left, level + 1, result);
    dfs(node.right, level + 1, result);
}

// Level Order Traversal using DFS (Recursion)
function levelOrderDFS(root) {
    let result = [];
    dfs(root, 0, result);
    return result;
}

// Main function
function main() {
    // Sample Tree:
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7

    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);
    root.right.left = new TreeNode(6);
    root.right.right = new TreeNode(7);

    console.log("Level Order Traversal (BFS):", levelOrderBFS(root));
    console.log("Level Order Traversal (DFS):", levelOrderDFS(root));
}

// Run the main function
main();
