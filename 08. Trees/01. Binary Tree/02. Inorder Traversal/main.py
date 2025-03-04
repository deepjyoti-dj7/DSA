class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Inorder Traversal (Recursive)
def inorder_traversal_recursive(root, result):
    if not root:
        return
    inorder_traversal_recursive(root.left, result)
    result.append(root.val)
    inorder_traversal_recursive(root.right, result)

# Inorder Traversal (Iterative)
def inorder_traversal_iterative(root):
    result = []
    stack = []
    current = root

    while current or stack:
        while current:
            stack.append(current)
            current = current.left
        current = stack.pop()
        result.append(current.val)
        current = current.right

    return result

# Main function
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    recursive_result = []
    inorder_traversal_recursive(root, recursive_result)
    print("Recursive Inorder Traversal:", recursive_result)

    iterative_result = inorder_traversal_iterative(root)
    print("Iterative Inorder Traversal:", iterative_result)

# Run the main function
main()
