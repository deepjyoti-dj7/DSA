class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Iterative Ceil
def find_ceil_iterative(root, key):
    ceil = -1
    while root:
        if root.val == key:
            return root.val
        if root.val > key:
            ceil = root.val
            root = root.left
        else:
            root = root.right
    return ceil

# Recursive Ceil
def find_ceil_recursive(root, key):
    if not root:
        return -1
    if root.val == key:
        return root.val
    if root.val < key:
        return find_ceil_recursive(root.right, key)
    
    ceil = find_ceil_recursive(root.left, key)
    return ceil if ceil >= key else root.val

# Iterative Floor
def find_floor_iterative(root, key):
    floor = -1
    while root:
        if root.val == key:
            return root.val
        if root.val < key:
            floor = root.val
            root = root.right
        else:
            root = root.left
    return floor

# Recursive Floor
def find_floor_recursive(root, key):
    if not root:
        return -1
    if root.val == key:
        return root.val
    if root.val > key:
        return find_floor_recursive(root.left, key)
    
    floor = find_floor_recursive(root.right, key)
    return floor if floor <= key and floor != -1 else root.val

# Main function
def main():
    root = TreeNode(8)
    root.left = TreeNode(4)
    root.right = TreeNode(12)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(6)
    root.right.left = TreeNode(10)
    root.right.right = TreeNode(14)

    key = 5
    print("Ceil (Iterative):", find_ceil_iterative(root, key))
    print("Ceil (Recursive):", find_ceil_recursive(root, key))
    print("Floor (Iterative):", find_floor_iterative(root, key))
    print("Floor (Recursive):", find_floor_recursive(root, key))

# Run the main function
if __name__ == "__main__":
    main()
