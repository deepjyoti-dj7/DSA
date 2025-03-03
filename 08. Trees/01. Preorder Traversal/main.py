class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Preorder Traversal (Recursive)
def preorder_traversal_recursive(root, result):
    if not root:
        return
    result.append(root.val)
    preorder_traversal_recursive(root.left, result)
    preorder_traversal_recursive(root.right, result)

# Preorder Traversal (Iterative)
def preorder_traversal_iterative(root):
    if not root:
        return []
    
    stack, result = [root], []

    while stack:
        node = stack.pop()
        result.append(node.val)

        # Push right first so that left is processed first
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

    return result

# Main function
def main():
    # Sample tree:   1
    #              /   \
    #             2     3
    #            / \   / \
    #           4   5 6   7

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    recursive_result = []
    preorder_traversal_recursive(root, recursive_result)
    print("Recursive Preorder Traversal:", recursive_result)

    iterative_result = preorder_traversal_iterative(root)
    print("Iterative Preorder Traversal:", iterative_result)

# Run the main function
main()
