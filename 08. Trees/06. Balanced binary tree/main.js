class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

// Helper function to check height and balance
function checkHeight(root) {
    if (!root) return 0;

    let leftHeight = checkHeight(root.left);
    if (leftHeight === -1) return -1;

    let rightHeight = checkHeight(root.right);
    if (rightHeight === -1) return -1;

    if (Math.abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + Math.max(leftHeight, rightHeight);
}

// Function to check if tree is balanced
function isBalanced(root) {
    return checkHeight(root) !== -1;
}

// Main function
function main() {
    let root = new TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);

    console.log(isBalanced(root)); // Output: true
}

// Run the main function
main();
