#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Preorder Traversal (Recursive)
void preorderTraversalRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderTraversalRecursive(root->left, result);
    preorderTraversalRecursive(root->right, result);
}

// Preorder Traversal (Iterative)
vector<int> preorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);

        // Push right first so that left is processed first
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}

int main() {
    // Sample tree:   1
    //              /   \
    //             2     3
    //            / \   / \
    //           4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Recursive Preorder Traversal
    vector<int> recursiveResult;
    preorderTraversalRecursive(root, recursiveResult);
    cout << "Recursive Preorder Traversal: ";
    for (int val : recursiveResult) cout << val << " ";
    cout << endl;

    // Iterative Preorder Traversal
    vector<int> iterativeResult = preorderTraversalIterative(root);
    cout << "Iterative Preorder Traversal: ";
    for (int val : iterativeResult) cout << val << " ";
    cout << endl;

    return 0;
}
