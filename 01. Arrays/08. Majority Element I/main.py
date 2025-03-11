from collections import Counter

# Brute Force
def majority_element_brute_force(nums):
    for num in nums:
        if nums.count(num) > len(nums) // 2:
            return num
    return -1

# Sorting
def majority_element_sorting(nums):
    nums.sort()
    return nums[len(nums) // 2]

# HashMap
def majority_element_hashmap(nums):
    count = Counter(nums)
    return max(count.keys(), key=lambda k: count[k])

# Boyer-Moore Voting Algorithm (Optimal)
def majority_element_boyer_moore(nums):
    candidate, count = 0, 0
    for num in nums:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate

# Main Function
nums = [3, 2, 3]
print("Brute Force:", majority_element_brute_force(nums))
print("Sorting:", majority_element_sorting(nums))
print("HashMap:", majority_element_hashmap(nums))
print("Boyer-Moore:", majority_element_boyer_moore(nums))
