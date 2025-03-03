from collections import deque

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Level Order Traversal using BFS (Queue)
def level_order_bfs(root):
    result = []
    if not root:
        return result

    queue = deque([root])

    while queue:
        level_size = len(queue)
        level = []

        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level)

    return result

# DFS Helper Function
def dfs(node, level, result):
    if not node:
        return

    if len(result) == level:
        result.append([])

    result[level].append(node.val)

    dfs(node.left, level + 1, result)
    dfs(node.right, level + 1, result)

# Level Order Traversal using DFS (Recursion)
def level_order_dfs(root):
    result = []
    dfs(root, 0, result)
    return result

# Main function
def main():
    # Sample Tree:
    #      1
    #     / \
    #    2   3
    #   / \ / \
    #  4  5 6  7

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    print("Level Order Traversal (BFS):", level_order_bfs(root))
    print("Level Order Traversal (DFS):", level_order_dfs(root))

# Run the main function
main()
