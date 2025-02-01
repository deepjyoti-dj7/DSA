# Brute Force - O(N^2)
def two_sum_brute_force(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [nums[i], nums[j]]
    return [-1, -1]

# Sorting + Two Pointers - O(N log N)
def two_sum_sorting(nums, target):
    sorted_nums = sorted(nums)
    left, right = 0, len(nums) - 1

    while left < right:
        sum_val = sorted_nums[left] + sorted_nums[right]
        if sum_val == target:
            return [sorted_nums[left], sorted_nums[right]]
        elif sum_val < target:
            left += 1
        else:
            right -= 1
    return [-1, -1]

# Hashing (Optimal) - O(N)
def two_sum_hashing(nums, target):
    num_set = set()
    for num in nums:
        complement = target - num
        if complement in num_set:
            return [complement, num]
        num_set.add(num)
    return [-1, -1]


def main():
    nums = [2, 7, 11, 15]
    target = 9

    print("Brute Force:", two_sum_brute_force(nums, target))
    print("Hashing:", two_sum_hashing(nums, target))
    print("Sorting + Two Pointers:", two_sum_sorting(nums, target))

main()