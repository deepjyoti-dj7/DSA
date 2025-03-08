def kadane(nums):
    max_sum = nums[0]
    current_sum = nums[0]

    for i in range(1, len(nums)):
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)

    return max_sum

def max_circular_subarray_sum(nums):
    max_kadane = kadane(nums)
    total_sum = sum(nums)
    min_sum = nums[0]
    current_min = nums[0]

    for i in range(1, len(nums)):
        current_min = min(nums[i], current_min + nums[i])
        min_sum = min(min_sum, current_min)

    return max_kadane if total_sum == min_sum else max(max_kadane, total_sum - min_sum)

def main():
    nums = [5, -3, 5]
    print("Maximum Circular Subarray Sum:", max_circular_subarray_sum(nums))

main()
