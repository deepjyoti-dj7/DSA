#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrderBFS(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
        leftToRight = !leftToRight;
    }
    return result;
}

// DFS Helper Function
void dfs(TreeNode* node, int level, bool leftToRight, vector<vector<int>>& result) {
    if (!node) return;

    if (result.size() == level)
        result.push_back({});

    if (leftToRight)
        result[level].push_back(node->val);
    else
        result[level].insert(result[level].begin(), node->val);

    dfs(node->left, level + 1, !leftToRight, result);
    dfs(node->right, level + 1, !leftToRight, result);
}

// DFS Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrderDFS(TreeNode* root) {
    vector<vector<int>> result;
    dfs(root, 0, true, result);
    return result;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> resultBFS = zigzagLevelOrderBFS(root);
    cout << "Zigzag Level Order (BFS):\n";
    for (const auto& level : resultBFS) {
        for (int num : level) cout << num << " ";
        cout << endl;
    }

    vector<vector<int>> resultDFS = zigzagLevelOrderDFS(root);
    cout << "Zigzag Level Order (DFS):\n";
    for (const auto& level : resultDFS) {
        for (int num : level) cout << num << " ";
        cout << endl;
    }

    return 0;
}
