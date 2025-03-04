class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

// BFS Approach for Top View
function topViewBFS(root) {
    if (!root) return [];

    let topNodes = new Map();
    let queue = [{ node: root, hd: 0 }];
    
    while (queue.length > 0) {
        let { node, hd } = queue.shift();

        if (!topNodes.has(hd)) {
            topNodes.set(hd, node.val);
        }

        if (node.left) queue.push({ node: node.left, hd: hd - 1 });
        if (node.right) queue.push({ node: node.right, hd: hd + 1 });
    }

    return [...topNodes.entries()].sort((a, b) => a[0] - b[0]).map(entry => entry[1]);
}

// DFS Approach for Top View
function dfs(node, hd, depth, topNodes) {
    if (!node) return;

    if (!topNodes.has(hd) || depth < topNodes.get(hd)[1]) {
        topNodes.set(hd, [node.val, depth]);
    }

    dfs(node.left, hd - 1, depth + 1, topNodes);
    dfs(node.right, hd + 1, depth + 1, topNodes);
}

function topViewDFS(root) {
    if (!root) return [];

    let topNodes = new Map();
    dfs(root, 0, 0, topNodes);

    return [...topNodes.entries()].sort((a, b) => a[0] - b[0]).map(entry => entry[1][0]);
}

// Main function
function main() {
    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.right = new TreeNode(4);
    root.left.right.right = new TreeNode(5);
    root.left.right.right.right = new TreeNode(6);

    console.log("Top View (BFS):", topViewBFS(root));
    console.log("Top View (DFS):", topViewDFS(root));
}


main();
