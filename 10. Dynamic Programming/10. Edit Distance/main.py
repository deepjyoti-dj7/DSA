# 1. Brute Force (Recursion)
def edit_distance_brute(s1, s2, i, j):
    if i == 0:
        return j
    if j == 0:
        return i
    if s1[i - 1] == s2[j - 1]:
        return edit_distance_brute(s1, s2, i - 1, j - 1)
    return 1 + min(
        edit_distance_brute(s1, s2, i - 1, j),    # delete
        edit_distance_brute(s1, s2, i, j - 1),    # insert
        edit_distance_brute(s1, s2, i - 1, j - 1) # replace
    )

# 2. Memoization (Top-down DP)
def edit_distance_memo(s1, s2):
    from functools import lru_cache

    @lru_cache(None)
    def dp(i, j):
        if i == 0:
            return j
        if j == 0:
            return i
        if s1[i - 1] == s2[j - 1]:
            return dp(i - 1, j - 1)
        return 1 + min(dp(i - 1, j), dp(i, j - 1), dp(i - 1, j - 1))

    return dp(len(s1), len(s2))

# 3. Tabulation (Bottom-up DP)
def edit_distance_tab(s1, s2):
    n, m = len(s1), len(s2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = i
    for j in range(m + 1):
        dp[0][j] = j

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

    return dp[n][m]

# 4. Space Optimized DP
def edit_distance_space_opt(s1, s2):
    n, m = len(s1), len(s2)
    prev = list(range(m + 1))

    for i in range(1, n + 1):
        curr = [i] + [0] * m
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                curr[j] = prev[j - 1]
            else:
                curr[j] = 1 + min(prev[j], curr[j - 1], prev[j - 1])
        prev = curr

    return prev[m]

# Main function
def main():
    s1 = "horse"
    s2 = "ros"

    print("Brute Force:", edit_distance_brute(s1, s2, len(s1), len(s2)))
    print("Memoization:", edit_distance_memo(s1, s2))
    print("Tabulation:", edit_distance_tab(s1, s2))
    print("Space Optimized:", edit_distance_space_opt(s1, s2))

main()