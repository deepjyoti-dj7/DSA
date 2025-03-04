#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Collects left boundary nodes (excluding leaves)
void leftBoundary(TreeNode* root, vector<int>& result) {
    TreeNode* cur = root->left;
    while (cur) {
        if (cur->left || cur->right) result.push_back(cur->val);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

// Collects all leaf nodes
void leafNodes(TreeNode* root, vector<int>& result) {
    if (!root) return;
    if (!root->left && !root->right) {
        result.push_back(root->val);
        return;
    }
    leafNodes(root->left, result);
    leafNodes(root->right, result);
}

// Collects right boundary nodes in reverse order (excluding leaves)
void rightBoundary(TreeNode* root, vector<int>& result) {
    stack<int> st;
    TreeNode* cur = root->right;
    while (cur) {
        if (cur->left || cur->right) st.push(cur->val);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
}

// Main function to get boundary traversal
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    result.push_back(root->val);  // Root node

    leftBoundary(root, result);
    leafNodes(root, result);
    rightBoundary(root, result);

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    vector<int> result = boundaryTraversal(root);
    
    cout << "Boundary Traversal: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
