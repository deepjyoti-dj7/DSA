def canJump(nums):
    maxReach = 0

    for i in range(len(nums)):
        if i > maxReach:
            return False  # If we can't reach this index, return False
        maxReach = max(maxReach, i + nums[i])  # Update farthest reach
        if maxReach >= len(nums) - 1:
            return True  # Early exit if we can reach the last index

    return False

# Main function
def main():
    print(canJump([2, 3, 1, 1, 4]))  # Expected Output: True
    print(canJump([3, 2, 1, 0, 4]))  # Expected Output: False

# Run the main function
if __name__ == "__main__":
    main()
