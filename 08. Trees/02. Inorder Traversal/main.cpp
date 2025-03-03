#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal (Recursive)
void inorderTraversalRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversalRecursive(root->left, result);
    result.push_back(root->val);
    inorderTraversalRecursive(root->right, result);
}

// Inorder Traversal (Iterative)
vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current || !st.empty()) {
        while (current) {  // Reach the leftmost node
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        result.push_back(current->val);
        current = current->right; // Move to right subtree
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

    vector<int> recursiveResult;
    inorderTraversalRecursive(root, recursiveResult);
    cout << "Recursive Inorder Traversal: ";
    for (int val : recursiveResult) cout << val << " ";
    cout << endl;

    vector<int> iterativeResult = inorderTraversalIterative(root);
    cout << "Iterative Inorder Traversal: ";
    for (int val : iterativeResult) cout << val << " ";
    cout << endl;

    return 0;
}
