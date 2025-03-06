#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Search
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
}

// Iterative Search
TreeNode* searchBSTIterative(TreeNode* root, int val) {
    while (root && root->val != val) {
        root = val < root->val ? root->left : root->right;
    }
    return root;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int target = 2;
    TreeNode* result = searchBST(root, target);
    cout << (result ? "Found: " + to_string(result->val) : "Not Found") << endl;

    result = searchBSTIterative(root, target);
    cout << (result ? "Found (Iterative): " + to_string(result->val) : "Not Found") << endl;

    return 0;
}
