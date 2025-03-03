#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Level Order Traversal using BFS (Queue)
vector<vector<int>> levelOrderBFS(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
    }
    return result;
}

// Helper function for DFS Level Order Traversal
void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
    if (!node) return;

    // If we reach a new level, create a new vector
    if (result.size() == level)
        result.push_back({});

    // Add the current node to its respective level
    result[level].push_back(node->val);

    // Recursive calls for left and right children
    dfs(node->left, level + 1, result);
    dfs(node->right, level + 1, result);
}

// Level Order Traversal using DFS (Recursion)
vector<vector<int>> levelOrderDFS(TreeNode* root) {
    vector<vector<int>> result;
    dfs(root, 0, result);
    return result;
}

// Main function
int main() {
    // Sample tree:
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // BFS Approach
    vector<vector<int>> resultBFS = levelOrderBFS(root);
    cout << "Level Order Traversal (BFS):\n";
    for (const auto& level : resultBFS) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // DFS Approach
    vector<vector<int>> resultDFS = levelOrderDFS(root);
    cout << "Level Order Traversal (DFS):\n";
    for (const auto& level : resultDFS) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
