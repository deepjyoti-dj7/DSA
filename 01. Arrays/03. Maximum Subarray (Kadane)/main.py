def maxSubArray(nums):
    max_sum = nums[0]
    curr_sum = 0
    for num in nums:
        curr_sum = max(num, curr_sum + num)
        max_sum = max(max_sum, curr_sum)
    return max_sum

# Example usage
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print("Maximum Subarray Sum:", maxSubArray(nums))
