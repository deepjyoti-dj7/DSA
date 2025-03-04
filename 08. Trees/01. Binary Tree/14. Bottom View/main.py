from collections import deque

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# BFS Approach for Bottom View
def bottom_view_bfs(root):
    if not root:
        return []

    bottom_nodes = {}
    queue = deque([(root, 0)])

    while queue:
        node, hd = queue.popleft()
        bottom_nodes[hd] = node.val  # Store last encountered node at this HD

        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))

    return [bottom_nodes[key] for key in sorted(bottom_nodes.keys())]

# DFS Approach for Bottom View
def dfs(node, hd, depth, bottom_nodes):
    if not node:
        return

    if hd not in bottom_nodes or depth >= bottom_nodes[hd][1]:
        bottom_nodes[hd] = (node.val, depth)

    dfs(node.left, hd - 1, depth + 1, bottom_nodes)
    dfs(node.right, hd + 1, depth + 1, bottom_nodes)

def bottom_view_dfs(root):
    if not root:
        return []

    bottom_nodes = {}
    dfs(root, 0, 0, bottom_nodes)

    return [bottom_nodes[key][0] for key in sorted(bottom_nodes.keys())]

# Main function
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(4)
    root.left.right.right = TreeNode(5)
    root.left.right.right.right = TreeNode(6)

    print("Bottom View (BFS):", bottom_view_bfs(root))
    print("Bottom View (DFS):", bottom_view_dfs(root))

if __name__ == "__main__":
    main()