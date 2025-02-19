class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Inorder Traversal (Recursive)
def inorder_traversal(root, result):
    if not root:
        return
    inorder_traversal(root.left, result)
    result.append(root.val)
    inorder_traversal(root.right, result)

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
    inorder_traversal(root, result)
    print("Inorder Traversal:", result)

# Run the main function
main()
