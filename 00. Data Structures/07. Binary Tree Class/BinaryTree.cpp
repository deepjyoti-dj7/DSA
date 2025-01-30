#include <iostream>
#include <queue>
#include <stack>
#include <string>

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    void inOrder(TreeNode<T>* node) {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void preOrder(TreeNode<T>* node) {
        if (node) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(TreeNode<T>* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }

    void deleteTree(TreeNode<T>* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        deleteTree(root);
    }

    bool empty() {
        return root == nullptr;
    }

    void insert(T value) {
        if (empty()) {
            root = new TreeNode<T>(value);
        } else {
            std::queue<TreeNode<T>*> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode<T>* current = q.front();
                q.pop();

                if (!current->left) {
                    current->left = new TreeNode<T>(value);
                    return;
                } else {
                    q.push(current->left);
                }

                if (!current->right) {
                    current->right = new TreeNode<T>(value);
                    return;
                } else {
                    q.push(current->right);
                }
            }
        }
    }

    bool search(T value) {
        if (empty()) return false;

        std::queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode<T>* current = q.front();
            q.pop();

            if (current->data == value) return true;

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        return false;
    }

    void inOrderTraversal() {
        std::cout << "In-Order Traversal: ";
        inOrder(root);
        std::cout << std::endl;
    }

    void preOrderTraversal() {
        std::cout << "Pre-Order Traversal: ";
        preOrder(root);
        std::cout << std::endl;
    }

    void postOrderTraversal() {
        std::cout << "Post-Order Traversal: ";
        postOrder(root);
        std::cout << std::endl;
    }

    void levelOrderTraversal() {
        std::cout << "Level-Order Traversal: ";
        if (empty()) {
            std::cout << "Tree is empty!" << std::endl;
            return;
        }

        std::queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode<T>* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    std::cout << "Tree Traversals:" << std::endl;

    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    tree.levelOrderTraversal();

    std::cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 100: " << (tree.search(100) ? "Found" : "Not Found") << std::endl;

    return 0;
}
