#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Postorder Traversal (Recursive)
void postorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->val);
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
    postorderTraversal(root, result);

    cout << "Postorder Traversal: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
