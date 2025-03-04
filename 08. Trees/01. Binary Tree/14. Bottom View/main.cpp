#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS Approach for Bottom View
vector<int> bottomViewBFS(TreeNode* root) {
    if (!root) return {};

    map<int, int> bottomNodes;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        bottomNodes[hd] = node->val;  // Store last encountered node at this HD

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<int> result;
    for (auto& [_, val] : bottomNodes) {
        result.push_back(val);
    }
    return result;
}

// DFS Approach for Bottom View
void dfs(TreeNode* node, int hd, int depth, map<int, pair<int, int>>& bottomNodes) {
    if (!node) return;

    // If depth is greater, update bottom view
    if (!bottomNodes.count(hd) || depth >= bottomNodes[hd].second) {
        bottomNodes[hd] = {node->val, depth};
    }

    // Traverse left and right subtrees
    dfs(node->left, hd - 1, depth + 1, bottomNodes);
    dfs(node->right, hd + 1, depth + 1, bottomNodes);
}

vector<int> bottomViewDFS(TreeNode* root) {
    if (!root) return {};

    map<int, pair<int, int>> bottomNodes;
    dfs(root, 0, 0, bottomNodes);

    vector<int> result;
    for (auto& [_, val] : bottomNodes) {
        result.push_back(val.first);
    }
    return result;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    vector<int> resultBFS = bottomViewBFS(root);
    vector<int> resultDFS = bottomViewDFS(root);

    cout << "Bottom View (BFS): ";
    for (int val : resultBFS) cout << val << " ";
    cout << endl;

    cout << "Bottom View (DFS): ";
    for (int val : resultDFS) cout << val << " ";
    cout << endl;

    return 0;
}
