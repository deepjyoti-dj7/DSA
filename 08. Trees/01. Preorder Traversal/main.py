class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Preorder Traversal (Recursive)
def preorder_traversal(root, result):
    if not root:
        return
    result.append(root.val)
    preorder_traversal(root.left, result)
    preorder_traversal(root.right, result)

# Main function
def main():
    # Sample tree
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    result = []
    preorder_traversal(root, result)
    print("Preorder Traversal:", result)

# Run the main function
if __name__ == "__main__":
    main()
