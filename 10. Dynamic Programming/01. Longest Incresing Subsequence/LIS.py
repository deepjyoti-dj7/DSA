import bisect

def LIS(arr, ind, prev):
    if ind == len(arr):
        return 0
    
    not_take = LIS(arr, ind + 1, prev)
    take = 0
    if prev == -1 or arr[prev] < arr[ind]:
        take = 1 + LIS(arr, ind + 1, ind)
    
    return max(take, not_take)


def LIS_memoization(arr, ind, prev, dp):
    if ind == len(arr):
        return 0
    
    if dp[ind][prev + 1] != -1:
        return dp[ind][prev + 1]
    
    not_take = LIS_memoization(arr, ind + 1, prev, dp)
    take = 0
    if prev == -1 or arr[prev] < arr[ind]:
        take = 1 + LIS_memoization(arr, ind + 1, ind, dp)
    
    dp[ind][prev + 1] = max(take, not_take)
    return dp[ind][prev + 1]


def LIS_tabulation(arr, n):
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    
    for ind in range(n - 1, -1, -1):
        for prev in range(ind - 1, -2, -1):
            take = 0
            if prev == -1 or arr[prev] < arr[ind]:
                take = 1 + dp[ind + 1][ind]
            dp[ind][prev + 1] = max(take, dp[ind + 1][prev + 1])
    
    return dp[0][0]


def LIS_tabulation_space_optimized_1(arr, n):
    cur = [0] * (n + 1)
    next_ = [0] * (n + 1)
    
    for ind in range(n - 1, -1, -1):
        for prev in range(ind - 1, -2, -1):
            take = 0
            if prev == -1 or arr[prev] < arr[ind]:
                take = 1 + next_[ind]
            cur[prev + 1] = max(take, next_[prev + 1])
        next_ = cur[:]
    
    return next_[0]


def LIS_tabulation_space_optimized_2(arr, n):
    dp = [1] * n
    maxi = 1
    
    for i in range(n):
        for prev in range(i):
            if arr[prev] < arr[i]:
                dp[i] = max(dp[i], 1 + dp[prev])
        maxi = max(maxi, dp[i])
    
    return maxi


def LIS_print(arr, n):
    dp = [1] * n
    hash_ = list(range(n))
    maxi = 1
    last_index = 0
    
    for i in range(n):
        for prev in range(i):
            if arr[prev] < arr[i] and 1 + dp[prev] > dp[i]:
                dp[i] = 1 + dp[prev]
                hash_[i] = prev
        if dp[i] > maxi:
            maxi = dp[i]
            last_index = i
    
    temp = []
    while True:
        temp.append(arr[last_index])
        if hash_[last_index] == last_index:
            break
        last_index = hash_[last_index]
    
    temp.reverse()
    print("LIS is:", temp)
    print("Length of LIS is:", maxi)
    return maxi


def LIS_binary_search(arr, n):
    res = []
    for num in arr:
        pos = bisect.bisect_left(res, num)
        if pos == len(res):
            res.append(num)
        else:
            res[pos] = num
    return len(res)



def main():
    arr = [1, 2, 3, 5, 6, 0, 1]
    n = len(arr)

    print("Length of LIS using Recursion:", LIS(arr, 0, -1))
    
    dp = [[-1] * (n + 1) for _ in range(n)]
    print("Length of LIS using Memoization:", LIS_memoization(arr, 0, -1, dp))

    print("Length of LIS using Tabulation:", LIS_tabulation(arr, n))

    print("Length of LIS using Tabulation and Space Optimization 1:", LIS_tabulation_space_optimized_1(arr, n))

    print("Length of LIS using Tabulation and Space Optimization 2:", LIS_tabulation_space_optimized_2(arr, n))

    LIS_print(arr, n)

    print("Length of LIS using Binary Search:", LIS_binary_search(arr, n))

main()