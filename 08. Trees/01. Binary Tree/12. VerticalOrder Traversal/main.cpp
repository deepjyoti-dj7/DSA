#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int, int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto [node, pos] = q.front();
        q.pop();
        int col = pos.first, row = pos.second;

        nodes[col].push_back({row, node->val});

        if (node->left) q.push({node->left, {col - 1, row + 1}});
        if (node->right) q.push({node->right, {col + 1, row + 1}});
    }

    vector<vector<int>> result;
    for (auto& [col, values] : nodes) {
        sort(values.begin(), values.end());
        vector<int> colVals;
        for (auto& [row, val] : values) colVals.push_back(val);
        result.push_back(colVals);
    }
    return result;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (const auto& col : result) {
        for (int num : col) cout << num << " ";
        cout << endl;
    }
    return 0;
}
