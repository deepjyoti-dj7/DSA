class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

function isSameTree(p, q) {
    if (!p && !q) return true;
    if (!p || !q || p.val !== q.val) return false;

    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}

// Main function
function main() {
    let p = new TreeNode(1);
    p.left = new TreeNode(2);
    p.right = new TreeNode(3);

    let q = new TreeNode(1);
    q.left = new TreeNode(2);
    q.right = new TreeNode(3);

    console.log(isSameTree(p, q)); // Output: true
}

// Run the main function
main();
