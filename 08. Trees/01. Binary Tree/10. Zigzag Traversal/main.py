from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# BFS Approach
def zigzagLevelOrderBFS(root):
    if not root:
        return []

    result = []
    queue = deque([root])
    left_to_right = True

    while queue:
        level_size = len(queue)
        level = [0] * level_size

        for i in range(level_size):
            node = queue.popleft()
            index = i if left_to_right else level_size - 1 - i
            level[index] = node.val

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level)
        left_to_right = not left_to_right

    return result

# DFS Approach
def dfs(node, level, left_to_right, result):
    if not node:
        return

    if len(result) == level:
        result.append([])

    if left_to_right:
        result[level].append(node.val)
    else:
        result[level].insert(0, node.val)

    dfs(node.left, level + 1, not left_to_right, result)
    dfs(node.right, level + 1, not left_to_right, result)

def zigzagLevelOrderDFS(root):
    result = []
    dfs(root, 0, True, result)
    return result

# Main function
def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print("Zigzag Level Order (BFS):", zigzagLevelOrderBFS(root))
    print("Zigzag Level Order (DFS):", zigzagLevelOrderDFS(root))

main()
