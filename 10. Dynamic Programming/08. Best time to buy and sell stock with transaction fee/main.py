# 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
def brute_force(prices, i, holding, fee):
    if i >= len(prices):
        return 0

    if holding:
        return max(prices[i] - fee + brute_force(prices, i + 1, False, fee),
                   brute_force(prices, i + 1, True, fee))
    else:
        return max(-prices[i] + brute_force(prices, i + 1, True, fee),
                   brute_force(prices, i + 1, False, fee))

def max_profit_brute_force(prices, fee):
    return brute_force(prices, 0, False, fee)


# 2. Recursion + Memoization (O(N) Time, O(N) Space)
def memoized_dfs(i, holding, prices, fee):
    if i >= len(prices):
        return 0

    if holding:
        return max(prices[i] - fee + memoized_dfs(i + 1, False, prices, fee),
                   memoized_dfs(i + 1, True, prices, fee))
    else:
        return max(-prices[i] + memoized_dfs(i + 1, True, prices, fee),
                   memoized_dfs(i + 1, False, prices, fee))

def max_profit_memo(prices, fee):
    return memoized_dfs(0, False, tuple(prices), fee)


# 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
def max_profit_dp(prices, fee):
    n = len(prices)
    dp = [[0] * 2 for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        dp[i][1] = max(prices[i] - fee + dp[i + 1][0], dp[i + 1][1])  # Holding
        dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0])  # Not holding

    return dp[0][0]


# 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
def max_profit_optimized_dp(prices, fee):
    ahead_not_holding, ahead_holding = 0, 0

    for i in range(len(prices) - 1, -1, -1):
        temp_not_holding = max(-prices[i] + ahead_holding, ahead_not_holding)
        temp_holding = max(prices[i] - fee + ahead_not_holding, ahead_holding)
        ahead_not_holding, ahead_holding = temp_not_holding, temp_holding

    return ahead_not_holding


# 5. Greedy Approach (O(N) Time, O(1) Space) - Best Solution
def max_profit_greedy(prices, fee):
    profit = 0
    min_price = prices[0]

    for i in range(1, len(prices)):
        if prices[i] < min_price:
            min_price = prices[i]  # Update minimum buying price
        if prices[i] > min_price + fee:
            profit += prices[i] - min_price - fee  # Sell stock and add profit
            min_price = prices[i] - fee  # Adjust min_price for next transaction

    return profit


# Main function to test different approaches
def main():
    prices = [1, 3, 2, 8, 4, 9]  # Example input
    fee = 2

    print("Brute Force:", max_profit_brute_force(prices, fee))
    print("Memoization:", max_profit_memo(prices, fee))
    print("Bottom-Up DP:", max_profit_dp(prices, fee))
    print("Optimized DP:", max_profit_optimized_dp(prices, fee))
    print("Greedy Approach:", max_profit_greedy(prices, fee))


# Run the main function
main()
