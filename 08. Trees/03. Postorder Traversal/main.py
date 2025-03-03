class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Postorder Traversal (Recursive)
def postorder_traversal_recursive(root, result):
    if not root:
        return
    postorder_traversal_recursive(root.left, result)
    postorder_traversal_recursive(root.right, result)
    result.append(root.val)

# Postorder Traversal (Iterative)
def postorder_traversal_iterative(root):
    if not root:
        return []
    
    result = []
    stack1, stack2 = [root], []

    while stack1:
        node = stack1.pop()
        stack2.append(node)
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)

    while stack2:
        result.append(stack2.pop().val)

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
    postorder_traversal_recursive(root, recursive_result)
    print("Recursive Postorder Traversal:", recursive_result)

    iterative_result = postorder_traversal_iterative(root)
    print("Iterative Postorder Traversal:", iterative_result)

# Run the main function
main()
