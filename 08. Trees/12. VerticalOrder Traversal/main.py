from collections import defaultdict, deque

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def verticalTraversal(root):
    nodes = defaultdict(list)
    queue = deque([(root, 0, 0)])

    while queue:
        node, col, row = queue.popleft()
        nodes[col].append((row, node.val))

        if node.left:
            queue.append((node.left, col - 1, row + 1))
        if node.right:
            queue.append((node.right, col + 1, row + 1))

    result = []
    for col in sorted(nodes.keys()):
        nodes[col].sort()
        result.append([val for _, val in nodes[col]])

    return result

# Main function
def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print("Vertical Order Traversal:", verticalTraversal(root))

main()
