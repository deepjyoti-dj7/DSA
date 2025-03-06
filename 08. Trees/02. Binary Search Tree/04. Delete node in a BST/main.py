class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Find minimum node in a subtree
def find_min(root):
    while root.left:
        root = root.left
    return root

# Recursive Delete
def delete_recursive(root, key):
    if not root:
        return root
    
    if key < root.val:
        root.left = delete_recursive(root.left, key)
    elif key > root.val:
        root.right = delete_recursive(root.right, key)
    else:
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        
        temp = find_min(root.right)
        root.val = temp.val
        root.right = delete_recursive(root.right, temp.val)
    
    return root

# Inorder Traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)

# Main function
def main():
    root = TreeNode(8)
    root.left = TreeNode(3)
    root.right = TreeNode(10)
    root.left.right = TreeNode(6)
    root.right.right = TreeNode(14)

    root = delete_recursive(root, 10)
    print("Inorder after Recursive Delete:", end=" ")
    inorder(root)
    print()

if __name__ == "__main__":
    main()
