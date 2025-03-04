#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check height and balance
int checkHeight(TreeNode* root) {
    if (!root) return 0;
    
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + max(leftHeight, rightHeight);
}

// Function to check if tree is balanced
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << (isBalanced(root) ? "true" : "false") << endl;

    return 0;
}
