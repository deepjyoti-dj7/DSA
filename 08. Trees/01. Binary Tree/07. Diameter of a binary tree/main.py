class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.diameter = 0

    def depth(self, root):
        if not root:
            return 0
        
        left_depth = self.depth(root.left)
        right_depth = self.depth(root.right)
        
        self.diameter = max(self.diameter, left_depth + right_depth)
        
        return 1 + max(left_depth, right_depth)

    def diameterOfBinaryTree(self, root):
        self.diameter = 0
        self.depth(root)
        return self.diameter

# Main function
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    sol = Solution()
    print(sol.diameterOfBinaryTree(root))  # Output: 3

# Run the main function
main()
