#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal (Recursive)
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    // Sample tree:   1
    //              /   \
    //             2     3
    //            / \   / \
    //           4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result;
    inorderTraversal(root, result);

    cout << "Inorder Traversal: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
