#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Insert
TreeNode* insertRecursive(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insertRecursive(root->left, key);
    else root->right = insertRecursive(root->right, key);
    return root;
}

// Iterative Insert
TreeNode* insertIterative(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    
    TreeNode* cur = root;
    TreeNode* parent = nullptr;
    
    while (cur) {
        parent = cur;
        if (key < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    if (key < parent->val) parent->left = new TreeNode(key);
    else parent->right = new TreeNode(key);
    
    return root;
}

// Inorder Traversal (Helper function)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function
int main() {
    TreeNode* root = new TreeNode(8);
    root = insertRecursive(root, 3);
    root = insertRecursive(root, 10);
    root = insertIterative(root, 6);
    root = insertIterative(root, 14);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
