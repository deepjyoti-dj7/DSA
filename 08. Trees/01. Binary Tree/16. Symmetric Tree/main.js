class TreeNode {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// DFS Approach
function isMirrorDFS(t1, t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return t1.val === t2.val &&
           isMirrorDFS(t1.left, t2.right) &&
           isMirrorDFS(t1.right, t2.left);
}

function isSymmetricDFS(root) {
    if (!root) return true;
    return isMirrorDFS(root.left, root.right);
}

// BFS Approach
function isSymmetricBFS(root) {
    if (!root) return true;

    let queue = [[root.left, root.right]];

    while (queue.length > 0) {
        let [t1, t2] = queue.shift();

        if (!t1 && !t2) continue;
        if (!t1 || !t2 || t1.val !== t2.val) return false;

        queue.push([t1.left, t2.right]);
        queue.push([t1.right, t2.left]);
    }
    return true;
}

function main() 
{
    let root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(2);
    root.left.left = new TreeNode(3);
    root.left.right = new TreeNode(4);
    root.right.left = new TreeNode(4);
    root.right.right = new TreeNode(3);

    console.log("DFS Approach:", isSymmetricDFS(root));
    console.log("BFS Approach:", isSymmetricBFS(root));
}

main();