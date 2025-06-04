# Brute Force O(N^3)
def three_sum_brute_force(nums):
    unique_triplets = set()
    n = len(nums)

    for i in range(n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                if nums[i] + nums[j] + nums[k] == 0:
                    triplet = tuple(sorted((nums[i], nums[j], nums[k])))
                    unique_triplets.add(triplet)

    return [list(triplet) for triplet in unique_triplets]

# Optimized Two Pointers O(N^2)
def three_sum_optimized(nums):
    nums.sort()
    result = []

    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        left, right = i+1, len(nums) - 1
        while left < right:
            s = nums[i] + nums[left] + nums[right]
            if s == 0:
                result.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left+1]:
                    left += 1
                while left < right and nums[right] == nums[right-1]:
                    right -= 1
                left += 1
                right -= 1
            elif s < 0:
                left += 1
            else:
                right -= 1
    return result

def print_triplets(triplets):
    for t in triplets:
        print(t)

# Main function
def main():
    nums = [-1, 0, 1, 2, -1, -4]

    print("Brute Force Approach results:")
    brute = three_sum_brute_force(nums)
    print_triplets(brute)

    print("\nOptimized Two Pointers Approach results:")
    optimized = three_sum_optimized(nums)
    print_triplets(optimized)

# Run the main function
main()
