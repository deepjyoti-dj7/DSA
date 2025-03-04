#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Left View using BFS (Level Order Traversal)
vector<int> leftViewBFS(TreeNode* root) {
    if (!root) return {};

    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        result.push_back(q.front()->val); // First node at this level

        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

// Right View using BFS (Level Order Traversal)
vector<int> rightViewBFS(TreeNode* root) {
    if (!root) return {};

    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        result.push_back(q.back()->val); // Last node at this level

        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

// Left View using DFS
void leftViewDFS(TreeNode* node, int level, vector<int>& result) {
    if (!node) return;

    if (level == result.size()) {
        result.push_back(node->val);
    }

    leftViewDFS(node->left, level + 1, result);
    leftViewDFS(node->right, level + 1, result);
}

vector<int> leftView(TreeNode* root) {
    vector<int> result;
    leftViewDFS(root, 0, result);
    return result;
}

// Right View using DFS
void rightViewDFS(TreeNode* node, int level, vector<int>& result) {
    if (!node) return;

    if (level == result.size()) {
        result.push_back(node->val);
    }

    rightViewDFS(node->right, level + 1, result);
    rightViewDFS(node->left, level + 1, result);
}

vector<int> rightView(TreeNode* root) {
    vector<int> result;
    rightViewDFS(root, 0, result);
    return result;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> left_result_BFS = leftViewBFS(root);
    vector<int> right_result_BFS = rightViewBFS(root);
    vector<int> left_result_DFS = leftView(root);
    vector<int> right_result_DFS = rightView(root);

    cout << "Left View (BFS): ";
    for (int val : left_result_BFS) cout << val << " ";
    cout << endl;

    cout << "Right View (BFS): ";
    for (int val : right_result_BFS) cout << val << " ";
    cout << endl;

    cout << "Left View (DFS): ";
    for (int val : left_result_DFS) cout << val << " ";
    cout << endl;

    cout << "Right View (DFS): ";
    for (int val : right_result_DFS) cout << val << " ";
    cout << endl;

    return 0;
}
