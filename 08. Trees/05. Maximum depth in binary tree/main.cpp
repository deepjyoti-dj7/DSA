#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive DFS approach
int maxDepthRecursive(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepthRecursive(root->left), maxDepthRecursive(root->right));
}

// Iterative BFS approach using Queue
int maxDepthIterative(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return depth;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Recursive Max Depth: " << maxDepthRecursive(root) << endl;
    cout << "Iterative Max Depth: " << maxDepthIterative(root) << endl;

    return 0;
}
