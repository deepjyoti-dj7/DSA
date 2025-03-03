#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxSum;

int dfs(TreeNode* root) {
    if (!root) return 0;
    
    int leftMax = max(0, dfs(root->left));
    int rightMax = max(0, dfs(root->right));
    
    maxSum = max(maxSum, root->val + leftMax + rightMax);
    
    return root->val + max(leftMax, rightMax);
}

int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    dfs(root);
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl; // Output: 42

    return 0;
}
