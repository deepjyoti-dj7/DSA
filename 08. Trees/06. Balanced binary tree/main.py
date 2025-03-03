class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

# Helper function to check height and balance
def checkHeight(root):
    if not root:
        return 0

    leftHeight = checkHeight(root.left)
    if leftHeight == -1:
        return -1

    rightHeight = checkHeight(root.right)
    if rightHeight == -1:
        return -1

    if abs(leftHeight - rightHeight) > 1:
        return -1

    return 1 + max(leftHeight, rightHeight)

# Function to check if tree is balanced
def isBalanced(root):
    return checkHeight(root) != -1

# Main function
def main():
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    print(isBalanced(root))  # Output: True

# Run the main function
main()
