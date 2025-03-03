class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

function maxPathSum(root) {
    let maxSum = -Infinity;
    
    function dfs(node) {
        if (!node) return 0;
        
        let leftMax = Math.max(0, dfs(node.left));
        let rightMax = Math.max(0, dfs(node.right));
        
        maxSum = Math.max(maxSum, node.val + leftMax + rightMax);
        
        return node.val + Math.max(leftMax, rightMax);
    }
    
    dfs(root);
    return maxSum;
}

// Main function
function main() {
    let root = new TreeNode(-10);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.right.left = new TreeNode(15);
    root.right.right = new TreeNode(7);

    console.log(maxPathSum(root)); // Output: 42
}

// Run the main function
main();
