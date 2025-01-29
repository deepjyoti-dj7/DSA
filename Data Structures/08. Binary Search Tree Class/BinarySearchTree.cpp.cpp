#include <iostream>
using namespace std;

template <typename T>
class BST {
private:
    // Node structure
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; // Root of the BST

    // Helper functions for recursive operations
    Node* insert(Node* node, T value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node* remove(Node* node, T value) {
        if (!node) return nullptr;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node to be deleted
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: find the in-order successor (smallest in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    bool search(Node* node, T value) {
        if (!node) return false;
        if (value == node->data) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    // Public API functions
    void insert(T value) {
        root = insert(root, value);
    }

    void remove(T value) {
        root = remove(root, value);
    }

    bool search(T value) {
        return search(root, value);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(7);
    bst.insert(15);
    bst.insert(30);

    cout << "In-order traversal: ";
    bst.inOrder();

    cout << "Pre-order traversal: ";
    bst.preOrder();

    cout << "Post-order traversal: ";
    bst.postOrder();

    cout << "Searching for 15: " << (bst.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    cout << "Removing 20..." << endl;
    bst.remove(20);
    cout << "In-order traversal after removal: ";
    bst.inOrder();

    return 0;
}
