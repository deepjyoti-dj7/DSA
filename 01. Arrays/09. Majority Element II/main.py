from collections import Counter

# Brute Force Approach - O(n²) Time, O(1) Space
def majority_element_brute_force(nums):
    result = []
    n = len(nums)
    for num in nums:
        if nums.count(num) > n // 3 and num not in result:
            result.append(num)
    return result

# Sorting Approach - O(n log n) Time, O(1) Space
def majority_element_sorting(nums):
    nums.sort()
    result, n = [], len(nums)
    i = 0
    while i < n:
        count, num = 0, nums[i]
        while i < n and nums[i] == num:
            count += 1
            i += 1
        if count > n // 3:
            result.append(num)
    return result

# HashMap Approach - O(n) Time, O(n) Space
def majority_element_hashmap(nums):
    count = Counter(nums)
    return [key for key in count if count[key] > len(nums) // 3]

# Boyer-Moore Voting Algorithm - O(n) Time, O(1) Space (Optimal Solution)
def majority_element_boyer_moore(nums):
    candidate1, candidate2, count1, count2 = 0, 1, 0, 0
    
    for num in nums:
        if num == candidate1:
            count1 += 1
        elif num == candidate2:
            count2 += 1
        elif count1 == 0:
            candidate1, count1 = num, 1
        elif count2 == 0:
            candidate2, count2 = num, 1
        else:
            count1 -= 1
            count2 -= 1

    count1, count2 = 0, 0
    for num in nums:
        if num == candidate1:
            count1 += 1
        elif num == candidate2:
            count2 += 1

    result, n = [], len(nums)
    if count1 > n // 3:
        result.append(candidate1)
    if count2 > n // 3:
        result.append(candidate2)
    return result

# Main Function
def main():
    nums = [3, 2, 3, 1, 1, 1, 2, 2]
    print("Brute Force:", majority_element_brute_force(nums))
    print("Sorting:", majority_element_sorting(nums))
    print("HashMap:", majority_element_hashmap(nums))
    print("Boyer-Moore:", majority_element_boyer_moore(nums))

main()
