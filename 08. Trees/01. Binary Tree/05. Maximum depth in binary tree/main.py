class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Recursive DFS approach
def maxDepthRecursive(root):
    if not root:
        return 0
    return 1 + max(maxDepthRecursive(root.left), maxDepthRecursive(root.right))

# Iterative BFS approach using Queue
from collections import deque
def maxDepthIterative(root):
    if not root:
        return 0
    
    queue = deque([root])
    depth = 0

    while queue:
        size = len(queue)
        depth += 1
        for _ in range(size):
            node = queue.popleft()
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    
    return depth

# Main function
def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print("Recursive Max Depth:", maxDepthRecursive(root))
    print("Iterative Max Depth:", maxDepthIterative(root))

# Run the main function
main()
