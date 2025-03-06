class TreeNode {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// Iterative Ceil
function findCeilIterative(root, key) {
    let ceil = -1;
    while (root) {
        if (root.val === key) return root.val;
        if (root.val > key) {
            ceil = root.val;
            root = root.left;
        } else {
            root = root.right;
        }
    }
    return ceil;
}

// Recursive Ceil
function findCeilRecursive(root, key) {
    if (!root) return -1;
    if (root.val === key) return root.val;
    if (root.val < key) return findCeilRecursive(root.right, key);
    let ceil = findCeilRecursive(root.left, key);
    return ceil >= key ? ceil : root.val;
}

// Iterative Floor
function findFloorIterative(root, key) {
    let floor = -1;
    while (root) {
        if (root.val === key) return root.val;
        if (root.val < key) {
            floor = root.val;
            root = root.right;
        } else {
            root = root.left;
        }
    }
    return floor;
}

// Recursive Floor
function findFloorRecursive(root, key) {
    if (!root) return -1;
    if (root.val === key) return root.val;
    if (root.val > key) return findFloorRecursive(root.left, key);
    let floor = findFloorRecursive(root.right, key);
    return floor <= key && floor !== -1 ? floor : root.val;
}

// Main function
function main() {
    let root = new TreeNode(8, 
        new TreeNode(4, new TreeNode(2), new TreeNode(6)), 
        new TreeNode(12, new TreeNode(10), new TreeNode(14))
    );

    let key = 5;
    console.log(`Ceil (Iterative): ${findCeilIterative(root, key)}`);
    console.log(`Ceil (Recursive): ${findCeilRecursive(root, key)}`);
    console.log(`Floor (Iterative): ${findFloorIterative(root, key)}`);
    console.log(`Floor (Recursive): ${findFloorRecursive(root, key)}`);
}

main();
