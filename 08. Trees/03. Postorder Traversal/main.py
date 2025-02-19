class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Postorder Traversal (Recursive)
def postorder_traversal(root, result):
    if not root:
        return
    postorder_traversal(root.left, result)
    postorder_traversal(root.right, result)
    result.append(root.val)

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
    postorder_traversal(root, result)
    print("Postorder Traversal:", result)

# Run the main function
main()
