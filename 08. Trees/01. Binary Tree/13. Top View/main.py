class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# BFS Approach for Top View
def topViewBFS(root):
    if not root:
        return []

    top_nodes = {}
    queue = [(root, 0)]

    while queue:
        node, hd = queue.pop(0)

        if hd not in top_nodes:
            top_nodes[hd] = node.val

        if node.left:
            queue.append((node.left, hd - 1))
        if node.right:
            queue.append((node.right, hd + 1))

    return [top_nodes[hd] for hd in sorted(top_nodes.keys())]

# DFS Approach for Top View
def dfs(node, hd, depth, top_nodes):
    if not node:
        return

    if hd not in top_nodes or depth < top_nodes[hd][1]:
        top_nodes[hd] = (node.val, depth)

    dfs(node.left, hd - 1, depth + 1, top_nodes)
    dfs(node.right, hd + 1, depth + 1, top_nodes)

def topViewDFS(root):
    if not root:
        return []

    top_nodes = {}
    dfs(root, 0, 0, top_nodes)

    return [top_nodes[hd][0] for hd in sorted(top_nodes.keys())]

# Main function
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(4)
    root.left.right.right = TreeNode(5)
    root.left.right.right.right = TreeNode(6)

    print("Top View (BFS):", topViewBFS(root))
    print("Top View (DFS):", topViewDFS(root))

    
main()
