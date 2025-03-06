class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Recursive Insert
def insert_recursive(root, key):
    if not root:
        return TreeNode(key)
    if key < root.val:
        root.left = insert_recursive(root.left, key)
    else:
        root.right = insert_recursive(root.right, key)
    return root

# Iterative Insert
def insert_iterative(root, key):
    if not root:
        return TreeNode(key)

    cur, parent = root, None
    while cur:
        parent = cur
        if key < cur.val:
            cur = cur.left
        else:
            cur = cur.right

    if key < parent.val:
        parent.left = TreeNode(key)
    else:
        parent.right = TreeNode(key)

    return root

# Inorder Traversal (Helper function)
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)

# Main function
def main():
    root = TreeNode(8)
    root = insert_recursive(root, 3)
    root = insert_recursive(root, 10)
    root = insert_iterative(root, 6)
    root = insert_iterative(root, 14)

    print("Inorder Traversal:", end=" ")
    inorder(root)
    print()

if __name__ == "__main__":
    main()
