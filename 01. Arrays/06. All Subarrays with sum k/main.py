# 🔹 Brute Force (O(N²))
def subarray_sum_brute(nums, k):
    count = 0
    for i in range(len(nums)):
        sum_ = 0
        for j in range(i, len(nums)):
            sum_ += nums[j]
            if sum_ == k:
                count += 1
    return count

# 🔹 Optimized (O(N)) - Prefix Sum + HashMap
def subarray_sum_optimized(nums, k):
    prefix_sum_count = {0: 1}
    count = prefix_sum = 0

    for num in nums:
        prefix_sum += num
        if prefix_sum - k in prefix_sum_count:
            count += prefix_sum_count[prefix_sum - k]
        prefix_sum_count[prefix_sum] = prefix_sum_count.get(prefix_sum, 0) + 1

    return count

# Main function
def main():
    nums = [1, 2, 3, 4, 2, -1, 2]
    k = 5

    print("Brute Force:", subarray_sum_brute(nums, k))
    print("Optimized:", subarray_sum_optimized(nums, k))

main()