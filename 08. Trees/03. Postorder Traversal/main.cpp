#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Postorder Traversal (Recursive)
void postorderTraversalRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorderTraversalRecursive(root->left, result);
    postorderTraversalRecursive(root->right, result);
    result.push_back(root->val);
}

// Postorder Traversal (Iterative)
vector<int> postorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> stack1, stack2;
    stack1.push(root);
    
    while (!stack1.empty()) {
        TreeNode* node = stack1.top();
        stack1.pop();
        stack2.push(node);
        
        if (node->left) stack1.push(node->left);
        if (node->right) stack1.push(node->right);
    }
    
    while (!stack2.empty()) {
        result.push_back(stack2.top()->val);
        stack2.pop();
    }
    
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> recursiveResult;
    postorderTraversalRecursive(root, recursiveResult);
    cout << "Recursive Postorder Traversal: ";
    for (int val : recursiveResult) cout << val << " ";
    cout << endl;

    vector<int> iterativeResult = postorderTraversalIterative(root);
    cout << "Iterative Postorder Traversal: ";
    for (int val : iterativeResult) cout << val << " ";
    cout << endl;

    return 0;
}
