class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.maxSum = float('-inf')

        def dfs(node):
            if not node:
                return 0
            
            leftMax = max(0, dfs(node.left))
            rightMax = max(0, dfs(node.right))

            self.maxSum = max(self.maxSum, node.val + leftMax + rightMax)
            
            return node.val + max(leftMax, rightMax)

        dfs(root)
        return self.maxSum

# Main function
def main():
    root = TreeNode(-10)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    sol = Solution()
    print(sol.maxPathSum(root))  # Output: 42

# Run the main function
main()
