# 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
def brute_force(prices, i, transactions_left, holding):
    if i >= len(prices) or transactions_left == 0:
        return 0

    if holding:
        return max(prices[i] + brute_force(prices, i + 1, transactions_left - 1, False),
                   brute_force(prices, i + 1, transactions_left, True))
    else:
        return max(-prices[i] + brute_force(prices, i + 1, transactions_left, True),
                   brute_force(prices, i + 1, transactions_left, False))

def max_profit_brute_force(k, prices):
    return brute_force(prices, 0, k, False)


# 2. Recursion + Memoization (O(N * K) Time, O(N * K) Space)
def memoized_dfs(prices, i, transactions_left, holding, memo):
    if i >= len(prices) or transactions_left == 0:
        return 0
    if memo[i][transactions_left][holding] != -1:
        return memo[i][transactions_left][holding]

    if holding:
        memo[i][transactions_left][1] = max(prices[i] + memoized_dfs(prices, i + 1, transactions_left - 1, False, memo),
                                            memoized_dfs(prices, i + 1, transactions_left, True, memo))
    else:
        memo[i][transactions_left][0] = max(-prices[i] + memoized_dfs(prices, i + 1, transactions_left, True, memo),
                                            memoized_dfs(prices, i + 1, transactions_left, False, memo))

    return memo[i][transactions_left][holding]

def max_profit_memo(k, prices):
    n = len(prices)
    memo = [[[-1] * 2 for _ in range(k + 1)] for _ in range(n)]
    return memoized_dfs(prices, 0, k, False, memo)


# 3. Bottom-Up Dynamic Programming (O(N * K) Time, O(N * K) Space)
def max_profit_dp(k, prices):
    n = len(prices)
    if n == 0:
        return 0

    dp = [[0] * n for _ in range(k + 1)]

    for t in range(1, k + 1):
        max_diff = -prices[0]
        for i in range(1, n):
            dp[t][i] = max(dp[t][i - 1], prices[i] + max_diff)
            max_diff = max(max_diff, dp[t - 1][i] - prices[i])

    return dp[k][n - 1]


# 4. Optimized DP with O(N) Space (O(N * K) Time, O(K) Space)
def max_profit_optimized_dp(k, prices):
    n = len(prices)
    if n == 0:
        return 0

    # When k is large, reduce to infinite transactions problem (Greedy)
    if k >= n // 2:
        profit = sum(max(prices[i] - prices[i - 1], 0) for i in range(1, n))
        return profit

    buy = [-float('inf')] * (k + 1)
    sell = [0] * (k + 1)

    for price in prices:
        for t in range(1, k + 1):
            buy[t] = max(buy[t], sell[t - 1] - price)
            sell[t] = max(sell[t], buy[t] + price)

    return sell[k]


# Main function to test different approaches
def main():
    prices = [3, 2, 6, 5, 0, 3]  # Example input
    k = 2  # Maximum number of transactions

    print("Brute Force:", max_profit_brute_force(k, prices))
    print("Memoization:", max_profit_memo(k, prices))
    print("Bottom-Up DP:", max_profit_dp(k, prices))
    print("Optimized DP:", max_profit_optimized_dp(k, prices))

# Run the main function
main()
