class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Recursive Search
def search_bst(root, val):
    if not root or root.val == val:
        return root
    return search_bst(root.left, val) if val < root.val else search_bst(root.right, val)

# Iterative Search
def search_bst_iterative(root, val):
    while root and root.val != val:
        root = root.left if val < root.val else root.right
    return root

# Main function
def main():
    root = TreeNode(4)
    root.left = TreeNode(2, TreeNode(1), TreeNode(3))
    root.right = TreeNode(7)

    target = 2
    result = search_bst(root, target)
    print(f"Found: {result.val}" if result else "Not Found")

    result = search_bst_iterative(root, target)
    print(f"Found (Iterative): {result.val}" if result else "Not Found")

if __name__ == "__main__":
    main()
