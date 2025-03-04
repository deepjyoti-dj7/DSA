class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// BFS Approach
function zigzagLevelOrderBFS(root) {
    if (!root) return [];
    
    let result = [], queue = [root], leftToRight = true;
    
    while (queue.length) {
        let size = queue.length, level = new Array(size).fill(0);
        
        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            let index = leftToRight ? i : size - 1 - i;
            level[index] = node.val;
            
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        
        result.push(level);
        leftToRight = !leftToRight;
    }
    return result;
}

// DFS Approach
function dfs(node, level, leftToRight, result) {
    if (!node) return;

    if (result.length === level)
        result.push([]);

    if (leftToRight)
        result[level].push(node.val);
    else
        result[level].unshift(node.val);

    dfs(node.left, level + 1, !leftToRight, result);
    dfs(node.right, level + 1, !leftToRight, result);
}

function zigzagLevelOrderDFS(root) {
    let result = [];
    dfs(root, 0, true, result);
    return result;
}

// Main function
function main() {
    let root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);

    console.log("Zigzag Level Order (BFS):", zigzagLevelOrderBFS(root));
    console.log("Zigzag Level Order (DFS):", zigzagLevelOrderDFS(root));
}

main();
