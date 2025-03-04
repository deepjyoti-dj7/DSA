class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

function verticalTraversal(root) {
    let map = new Map();
    let queue = [[root, 0, 0]];
    
    while (queue.length) {
        let [node, col, row] = queue.shift();
        if (!map.has(col)) map.set(col, []);
        map.get(col).push([row, node.val]);

        if (node.left) queue.push([node.left, col - 1, row + 1]);
        if (node.right) queue.push([node.right, col + 1, row + 1]);
    }

    let sortedKeys = [...map.keys()].sort((a, b) => a - b);
    let result = [];

    for (let key of sortedKeys) {
        let values = map.get(key);
        values.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
        result.push(values.map(x => x[1]));
    }

    return result;
}

// Main function
function main() {
    let root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);

    console.log("Vertical Order Traversal:", verticalTraversal(root));
}

main();
