# 1. Brute Force (Recursive) - O(2^N) Time (Not practical for large inputs)
def brute_force(prices, i, transactions_left, holding):
    if i >= len(prices) or transactions_left == 0:
        return 0

    if holding:
        return max(prices[i] + brute_force(prices, i + 1, transactions_left - 1, False),
                   brute_force(prices, i + 1, transactions_left, True))
    else:
        return max(-prices[i] + brute_force(prices, i + 1, transactions_left, True),
                   brute_force(prices, i + 1, transactions_left, False))

def max_profit_brute_force(prices):
    return brute_force(prices, 0, 2, False)

# 2. Recursion + Memoization (O(N * 2) Time, O(N * 2) Space)
def memoized_dfs(prices, i, transactions_left, holding, memo):
    if i >= len(prices) or transactions_left == 0:
        return 0
    if memo[i][transactions_left][holding] != -1:
        return memo[i][transactions_left][holding]

    if holding:
        memo[i][transactions_left][holding] = max(
            prices[i] + memoized_dfs(prices, i + 1, transactions_left - 1, False, memo),
            memoized_dfs(prices, i + 1, transactions_left, True, memo)
        )
    else:
        memo[i][transactions_left][holding] = max(
            -prices[i] + memoized_dfs(prices, i + 1, transactions_left, True, memo),
            memoized_dfs(prices, i + 1, transactions_left, False, memo)
        )

    return memo[i][transactions_left][holding]

def max_profit_memo(prices):
    n = len(prices)
    memo = [[[-1] * 2 for _ in range(3)] for _ in range(n)]
    return memoized_dfs(prices, 0, 2, False, memo)

# 3. Bottom-Up Dynamic Programming (O(N * 2) Time, O(N * 2) Space)
def max_profit_dp(prices):
    n = len(prices)
    dp = [[[0] * 2 for _ in range(3)] for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        for transactions_left in range(1, 3):  # At most 2 transactions
            dp[i][transactions_left][1] = max(prices[i] + dp[i + 1][transactions_left - 1][0],
                                              dp[i + 1][transactions_left][1])
            dp[i][transactions_left][0] = max(-prices[i] + dp[i + 1][transactions_left][1],
                                              dp[i + 1][transactions_left][0])

    return dp[0][2][0]

# 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
def max_profit_optimized(prices):
    buy1, sell1 = float('-inf'), 0
    buy2, sell2 = float('-inf'), 0

    for price in prices:
        buy1 = max(buy1, -price)  # First buy
        sell1 = max(sell1, buy1 + price)  # First sell
        buy2 = max(buy2, sell1 - price)  # Second buy
        sell2 = max(sell2, buy2 + price)  # Second sell

    return sell2

# Main function to test different approaches
def main():
    prices = [3, 3, 5, 0, 0, 3, 1, 4]  # Example input

    print("Brute Force:", max_profit_brute_force(prices))
    print("Memoization:", max_profit_memo(prices))
    print("Bottom-Up DP:", max_profit_dp(prices))
    print("Optimized DP:", max_profit_optimized(prices))

# Execute main function
main()
