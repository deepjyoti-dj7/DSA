# 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
def brute_force(prices, i, holding):
    if i >= len(prices):
        return 0

    if holding:
        return max(prices[i] + brute_force(prices, i + 2, False),  # Sell and cooldown
                   brute_force(prices, i + 1, True))  # Skip
    else:
        return max(-prices[i] + brute_force(prices, i + 1, True),  # Buy
                   brute_force(prices, i + 1, False))  # Skip

def max_profit_brute_force(prices):
    return brute_force(prices, 0, False)


# 2. Recursion + Memoization (O(N) Time, O(N) Space)
def memoized_dfs(prices, i, holding, memo):
    if i >= len(prices):
        return 0
    if memo[i][holding] != -1:
        return memo[i][holding]

    if holding:
        memo[i][1] = max(prices[i] + memoized_dfs(prices, i + 2, False, memo),  # Sell and cooldown
                         memoized_dfs(prices, i + 1, True, memo))  # Skip
    else:
        memo[i][0] = max(-prices[i] + memoized_dfs(prices, i + 1, True, memo),  # Buy
                         memoized_dfs(prices, i + 1, False, memo))  # Skip
    return memo[i][holding]

def max_profit_memo(prices):
    n = len(prices)
    memo = [[-1] * 2 for _ in range(n)]
    return memoized_dfs(prices, 0, False, memo)


# 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
def max_profit_dp(prices):
    n = len(prices)
    if n == 0:
        return 0

    dp = [[0] * 2 for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        dp[i][1] = max(prices[i] + (dp[i + 2][0] if i + 2 < n else 0), dp[i + 1][1])  # Holding
        dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0])  # Not holding

    return dp[0][0]


# 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
def max_profit_optimized_dp(prices):
    n = len(prices)
    if n == 0:
        return 0

    ahead_not_holding, ahead_holding, ahead_cooldown = 0, 0, 0

    for i in range(n - 1, -1, -1):
        temp_not_holding = max(-prices[i] + ahead_holding, ahead_not_holding)
        temp_holding = max(prices[i] + ahead_cooldown, ahead_holding)
        ahead_cooldown = ahead_not_holding
        ahead_not_holding = temp_not_holding
        ahead_holding = temp_holding

    return ahead_not_holding


# Main function to test different approaches
def main():
    prices = [1, 2, 3, 0, 2]  # Example input

    print("Brute Force:", max_profit_brute_force(prices))
    print("Memoization:", max_profit_memo(prices))
    print("Bottom-Up DP:", max_profit_dp(prices))
    print("Optimized DP:", max_profit_optimized_dp(prices))


main()
