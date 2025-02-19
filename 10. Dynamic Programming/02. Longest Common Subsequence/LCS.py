def LCS_recursive(s1, s2, i, j):
    if i < 0 or j < 0:
        return 0
    
    if s1[i] == s2[j]:
        return 1 + LCS_recursive(s1, s2, i - 1, j - 1)
    else:
        return max(LCS_recursive(s1, s2, i - 1, j), LCS_recursive(s1, s2, i, j - 1))


def LCS_memoization(s1, s2, i, j, dp):
    if i < 0 or j < 0:
        return 0
    
    if dp[i][j] != -1:
        return dp[i][j]
    
    if s1[i] == s2[j]:
        dp[i][j] = 1 + LCS_memoization(s1, s2, i - 1, j - 1, dp)
    else:
        dp[i][j] = max(LCS_memoization(s1, s2, i - 1, j, dp), LCS_memoization(s1, s2, i, j - 1, dp))
    
    return dp[i][j]


def LCS_tabulation(s1, s2):
    n, m = len(s1), len(s2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    return dp[n][m]


def LCS_tabulation_space_optimized(s1, s2):
    n, m = len(s1), len(s2)
    prev = [0] * (m + 1)
    cur = [0] * (m + 1)
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                cur[j] = 1 + prev[j - 1]
            else:
                cur[j] = max(prev[j], cur[j - 1])
        prev = cur[:]
    
    return prev[m]


def LCS_print(s1, s2):
    n, m = len(s1), len(s2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    lcs = []
    i, j = n, m
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            lcs.append(s1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    lcs.reverse()
    return ''.join(lcs)


def main():
    s1 = "abcde"
    s2 = "ace"
    
    # Brute Force Recursive
    print("Length of LCS (Brute Force):", LCS_recursive(s1, s2, len(s1) - 1, len(s2) - 1))
    
    # Memoization
    dp = [[-1 for _ in range(len(s2))] for _ in range(len(s1))]
    print("Length of LCS (Memoization):", LCS_memoization(s1, s2, len(s1) - 1, len(s2) - 1, dp))
    
    # Tabulation
    print("Length of LCS (Tabulation):", LCS_tabulation(s1, s2))
    
    # Space Optimized Tabulation
    print("Length of LCS (Tabulation Space Optimized):", LCS_tabulation_space_optimized(s1, s2))
    
    # LCS Printing
    print("The LCS is:", LCS_print(s1, s2))

main()