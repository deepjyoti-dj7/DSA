def backtrack(nums, used, current, result):
    if len(current) == len(nums):
        result.append(list(current))
        return

    for i in range(len(nums)):
        if used[i]:
            continue
        if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
            continue

        used[i] = True
        current.append(nums[i])
        backtrack(nums, used, current, result)
        current.pop()
        used[i] = False

def permute_unique(nums):
    result = []
    nums.sort()
    backtrack(nums, [False] * len(nums), [], result)
    return result

# Main function
def main():
    nums = [1, 1, 2]
    print("Unique Permutations:")
    print(permute_unique(nums))

main()
