#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS Approach for Top View
vector<int> topViewBFS(TreeNode* root) {
    if (!root) return {};

    map<int, int> topNodes;  // {horizontal distance : node value}
    queue<pair<TreeNode*, int>> q; // {node, horizontal distance}
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // If no node is placed at this HD, place the first encountered node
        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = node->val;
        }

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<int> result;
    for (auto& x : topNodes) {
        result.push_back(x.second);
    }
    return result;
}

// DFS Approach for Top View
void dfs(TreeNode* node, int hd, int depth, map<int, pair<int, int>>& topNodes) {
    if (!node) return;

    // If this HD is not visited or we found a shallower node, update it
    if (topNodes.find(hd) == topNodes.end() || depth < topNodes[hd].second) {
        topNodes[hd] = {node->val, depth};
    }

    // Recur for left and right subtrees
    dfs(node->left, hd - 1, depth + 1, topNodes);
    dfs(node->right, hd + 1, depth + 1, topNodes);
}

vector<int> topViewDFS(TreeNode* root) {
    if (!root) return {};

    map<int, pair<int, int>> topNodes; // {horizontal distance : {value, depth}}
    dfs(root, 0, 0, topNodes);

    vector<int> result;
    for (auto& x : topNodes) {
        result.push_back(x.second.first);
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

    // BFS Solution
    vector<int> resultBFS = topViewBFS(root);
    cout << "Top View (BFS): ";
    for (int val : resultBFS) cout << val << " ";
    cout << endl;

    // DFS Solution
    vector<int> resultDFS = topViewDFS(root);
    cout << "Top View (DFS): ";
    for (int val : resultDFS) cout << val << " ";
    cout << endl;

    return 0;
}
