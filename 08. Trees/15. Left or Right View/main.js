class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

// Left View using BFS
function leftViewBFS(root) {
    if (!root) return [];

    let result = [];
    let queue = [root];

    while (queue.length > 0) {
        let size = queue.length;
        result.push(queue[0].val); // First node in the level

        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
    }
    return result;
}

// Right View using BFS
function rightViewBFS(root) {
    if (!root) return [];

    let result = [];
    let queue = [root];

    while (queue.length > 0) {
        let size = queue.length;
        result.push(queue[size - 1].val); // Last node in the level

        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
    }
    return result;
}

// Left View using DFS
function leftViewDFS(node, level, result) {
    if (!node) return;

    if (level === result.length) {
        result.push(node.val);
    }

    leftViewDFS(node.left, level + 1, result);
    leftViewDFS(node.right, level + 1, result);
}

function getLeftView(root) {
    let result = [];
    leftViewDFS(root, 0, result);
    return result;
}

// Right View using DFS
function rightViewDFS(node, level, result) {
    if (!node) return;

    if (level === result.length) {
        result.push(node.val);
    }

    rightViewDFS(node.right, level + 1, result);
    rightViewDFS(node.left, level + 1, result);
}

function getRightView(root) {
    let result = [];
    rightViewDFS(root, 0, result);
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

    console.log("Left View (BFS):", leftViewBFS(root));
    console.log("Right View (BFS):", rightViewBFS(root));
    console.log("Left View (DFS):", getLeftView(root));
    console.log("Right View (DFS):", getRightView(root));
}

main();