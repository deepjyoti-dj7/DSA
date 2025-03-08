def jump(nums):
    jumps, farthest, currentEnd = 0, 0, 0

    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])  # Update farthest reachable index

        if i == currentEnd:  # If we reach the end of the current jump
            jumps += 1
            currentEnd = farthest  # Move to the farthest reachable index

    return jumps

# Main function
def main():
    print("Minimum jumps:", jump([2, 3, 1, 1, 4]))  # Expected Output: 2
    print("Minimum jumps:", jump([1, 1, 1, 1]))  # Expected Output: 3

# Run the main function
main()
