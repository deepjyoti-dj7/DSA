#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Ceil
int findCeilIterative(TreeNode* root, int key) {
    int ceil = -1;
    while (root) {
        if (root->val == key) return root->val;
        if (root->val > key) {
            ceil = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}

// Recursive Ceil
int findCeilRecursive(TreeNode* root, int key) {
    if (!root) return -1;
    if (root->val == key) return root->val;
    if (root->val < key) return findCeilRecursive(root->right, key);
    int ceil = findCeilRecursive(root->left, key);
    return (ceil >= key) ? ceil : root->val;
}

// Iterative Floor
int findFloorIterative(TreeNode* root, int key) {
    int floor = -1;
    while (root) {
        if (root->val == key) return root->val;
        if (root->val < key) {
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}

// Recursive Floor
int findFloorRecursive(TreeNode* root, int key) {
    if (!root) return -1;
    if (root->val == key) return root->val;
    if (root->val > key) return findFloorRecursive(root->left, key);
    int floor = findFloorRecursive(root->right, key);
    return (floor <= key && floor != -1) ? floor : root->val;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int key = 5;
    cout << "Ceil (Iterative): " << findCeilIterative(root, key) << endl;
    cout << "Ceil (Recursive): " << findCeilRecursive(root, key) << endl;
    cout << "Floor (Iterative): " << findFloorIterative(root, key) << endl;
    cout << "Floor (Recursive): " << findFloorRecursive(root, key) << endl;

    return 0;
}
