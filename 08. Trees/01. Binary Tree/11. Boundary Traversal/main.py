class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def left_boundary(root, result):
    cur = root.left
    while cur:
        if cur.left or cur.right:
            result.append(cur.val)
        cur = cur.left if cur.left else cur.right

def leaf_nodes(root, result):
    if not root:
        return
    if not root.left and not root.right:
        result.append(root.val)
        return
    leaf_nodes(root.left, result)
    leaf_nodes(root.right, result)

def right_boundary(root, result):
    stack = []
    cur = root.right
    while cur:
        if cur.left or cur.right:
            stack.append(cur.val)
        cur = cur.right if cur.right else cur.left
    result.extend(reversed(stack))

def boundary_traversal(root):
    if not root:
        return []
    
    result = [root.val]
    left_boundary(root, result)
    leaf_nodes(root, result)
    right_boundary(root, result)

    return result

# Main function
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(6)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(8)

    print("Boundary Traversal:", boundary_traversal(root))


if __name__ == "__main__":
    main()
