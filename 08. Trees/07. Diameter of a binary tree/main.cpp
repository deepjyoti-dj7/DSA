#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int diameter = 0;

int depth(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    diameter = max(diameter, leftDepth + rightDepth);

    return 1 + max(leftDepth, rightDepth);
}

int diameterOfBinaryTree(TreeNode* root) {
    depth(root);
    return diameter;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root) << endl;  // Output: 3

    return 0;
}
