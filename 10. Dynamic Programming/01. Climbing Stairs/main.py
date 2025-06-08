# 1. Brute Force
def climb_brute(n):
    if n <= 1:
        return 1
    return climb_brute(n - 1) + climb_brute(n - 2)

# 2. Memoization
def climb_memo(n, memo=None):
    if memo is None:
        memo = {}
    if n <= 1:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = climb_memo(n - 1, memo) + climb_memo(n - 2, memo)
    return memo[n]

# 3. Tabulation
def climb_tab(n):
    if n <= 1:
        return 1
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

# 4. Space Optimized
def climb_opt(n):
    if n <= 1:
        return 1
    a, b = 1, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

# Main function
def main():
    n = 5
    print("Brute:", climb_brute(n))
    print("Memo:", climb_memo(n))
    print("Tabulation:", climb_tab(n))
    print("Optimized:", climb_opt(n))

main()
