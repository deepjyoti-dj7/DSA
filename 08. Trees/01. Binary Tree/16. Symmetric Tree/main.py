from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# DFS Approach
def is_mirror_dfs(t1, t2):
    if not t1 and not t2:
        return True
    if not t1 or not t2:
        return False
    return (t1.val == t2.val and 
            is_mirror_dfs(t1.left, t2.right) and 
            is_mirror_dfs(t1.right, t2.left))

def is_symmetric_dfs(root):
    if not root:
        return True
    return is_mirror_dfs(root.left, root.right)

# BFS Approach
def is_symmetric_bfs(root):
    if not root:
        return True

    queue = deque([(root.left, root.right)])

    while queue:
        t1, t2 = queue.popleft()

        if not t1 and not t2:
            continue
        if not t1 or not t2 or t1.val != t2.val:
            return False

        queue.append((t1.left, t2.right))
        queue.append((t1.right, t2.left))

    return True

# Main function
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)

    print("DFS Approach:", is_symmetric_dfs(root))
    print("BFS Approach:", is_symmetric_bfs(root))

main()
