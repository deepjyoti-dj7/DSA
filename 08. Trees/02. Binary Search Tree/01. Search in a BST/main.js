class TreeNode {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// Recursive Search
function searchBST(root, val) {
    if (!root || root.val === val) return root;
    return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
}

// Iterative Search
function searchBSTIterative(root, val) {
    while (root && root.val !== val) {
        root = val < root.val ? root.left : root.right;
    }
    return root;
}

// Main Function
function main() {
    let root = new TreeNode(4);
    root.left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root.right = new TreeNode(7);

    let target = 2;
    let result = searchBST(root, target);
    console.log(result ? `Found: ${result.val}` : "Not Found");

    result = searchBSTIterative(root, target);
    console.log(result ? `Found (Iterative): ${result.val}` : "Not Found");
}

main();
