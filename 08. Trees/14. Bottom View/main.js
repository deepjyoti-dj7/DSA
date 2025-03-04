class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// BFS Approach for Bottom View
function bottomViewBFS(root) {
    if (!root) return [];

    let bottomNodes = new Map();
    let queue = [[root, 0]];

    while (queue.length > 0) {
        let [node, hd] = queue.shift();
        bottomNodes.set(hd, node.val);  // Store last encountered node at this HD

        if (node.left) queue.push([node.left, hd - 1]);
        if (node.right) queue.push([node.right, hd + 1]);
    }

    return [...new Map([...bottomNodes.entries()].sort())].map(([_, val]) => val);
}

// DFS Approach for Bottom View
function dfs(node, hd, depth, bottomNodes) {
    if (!node) return;

    if (!bottomNodes.has(hd) || depth >= bottomNodes.get(hd)[1]) {
        bottomNodes.set(hd, [node.val, depth]);
    }

    dfs(node.left, hd - 1, depth + 1, bottomNodes);
    dfs(node.right, hd + 1, depth + 1, bottomNodes);
}

function bottomViewDFS(root) {
    if (!root) return [];

    let bottomNodes = new Map();
    dfs(root, 0, 0, bottomNodes);

    return [...new Map([...bottomNodes.entries()].sort())].map(([_, val]) => val[0]);
}

function main() {
    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left.right = new TreeNode(4);
    root.left.right.right = new TreeNode(5);
    root.left.right.right.right = new TreeNode(6);

    console.log("Bottom View (BFS):", bottomViewBFS(root));
    console.log("Bottom View (DFS):", bottomViewDFS(root));
}

main();
