class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Left View using BFS
def left_view_bfs(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        size = len(queue)
        result.append(queue[0].val)  # First node at this level

        for _ in range(size):
            node = queue.pop(0)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    return result

# Right View using BFS
def right_view_bfs(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        size = len(queue)
        result.append(queue[-1].val)  # Last node at this level

        for _ in range(size):
            node = queue.pop(0)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    return result

# Left View using DFS
def left_view_dfs(node, level, result):
    if not node:
        return

    if level == len(result):
        result.append(node.val)

    left_view_dfs(node.left, level + 1, result)
    left_view_dfs(node.right, level + 1, result)

def get_left_view_dfs(root):
    result = []
    left_view_dfs(root, 0, result)
    return result

# Right View using DFS
def right_view_dfs(node, level, result):
    if not node:
        return

    if level == len(result):
        result.append(node.val)

    right_view_dfs(node.right, level + 1, result)
    right_view_dfs(node.left, level + 1, result)

def get_right_view_dfs(root):
    result = []
    right_view_dfs(root, 0, result)
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

    print("Left View (BFS):", left_view_bfs(root))
    print("Right View (BFS):", right_view_bfs(root))
    print("Left View (DFS):", get_left_view_dfs(root))
    print("Right View (DFS):", get_right_view_dfs(root))

main()
