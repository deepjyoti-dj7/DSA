#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DFS Approach
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;  // Both null -> symmetric
    if (!t1 || !t2) return false; // One null -> not symmetric
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetricDFS(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// BFS Approach
bool isSymmetricBFS(TreeNode* root) {
    if (!root) return true;

    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({root->left, root->right});

    while (!q.empty()) {
        auto [t1, t2] = q.front();
        q.pop();

        if (!t1 && !t2) continue;
        if (!t1 || !t2 || t1->val != t2->val) return false;

        q.push({t1->left, t2->right});
        q.push({t1->right, t2->left});
    }
    return true;
}

// Main function
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << "DFS Approach: " << (isSymmetricDFS(root) ? "True" : "False") << endl;
    cout << "BFS Approach: " << (isSymmetricBFS(root) ? "True" : "False") << endl;

    return 0;
}
