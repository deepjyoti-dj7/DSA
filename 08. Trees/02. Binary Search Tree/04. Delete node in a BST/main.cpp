#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to find the minimum value node in a subtree
TreeNode* findMin(TreeNode* root) {
    while (root->left) root = root->left;
    return root;
}

// Recursive Delete
TreeNode* deleteRecursive(TreeNode* root, int key) {
    if (!root) return root;
    
    if (key < root->val) root->left = deleteRecursive(root->left, key);
    else if (key > root->val) root->right = deleteRecursive(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteRecursive(root->right, temp->val);
    }
    return root;
}

// Iterative Delete
TreeNode* deleteIterative(TreeNode* root, int key) {
    TreeNode* parent = NULL, *cur = root;
    
    while (cur && cur->val != key) {
        parent = cur;
        if (key < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    if (!cur) return root; // Key not found

    if (!cur->left || !cur->right) {
        TreeNode* newChild = (cur->left) ? cur->left : cur->right;
        if (!parent) return newChild;
        if (parent->left == cur) parent->left = newChild;
        else parent->right = newChild;
    } else {
        TreeNode* successor = findMin(cur->right);
        cur->val = successor->val;
        cur->right = deleteRecursive(cur->right, successor->val);
    }
    return root;
}

// Inorder Traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function
int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);

    root = deleteRecursive(root, 10);
    cout << "Inorder after Recursive Delete: ";
    inorder(root);
    cout << endl;

    root = deleteIterative(root, 6);
    cout << "Inorder after Iterative Delete: ";
    inorder(root);
    cout << endl;

    return 0;
}
