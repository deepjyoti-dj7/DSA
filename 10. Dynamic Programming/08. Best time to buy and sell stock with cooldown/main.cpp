#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
int bruteForce(vector<int>& prices, int i, bool holding) {
    if (i >= prices.size()) return 0;

    if (holding) {
        return max(prices[i] + bruteForce(prices, i + 2, false), // Sell and cooldown
                   bruteForce(prices, i + 1, true));  // Skip
    } else {
        return max(-prices[i] + bruteForce(prices, i + 1, true), // Buy
                   bruteForce(prices, i + 1, false)); // Skip
    }
}

int maxProfitBruteForce(vector<int>& prices) {
    return bruteForce(prices, 0, false);
}

// 2. Recursion + Memoization (O(N) Time, O(N) Space)
int memoizedDFS(vector<int>& prices, int i, bool holding, vector<vector<int>>& memo) {
    if (i >= prices.size()) return 0;
    if (memo[i][holding] != -1) return memo[i][holding];

    if (holding) {
        return memo[i][holding] = max(prices[i] + memoizedDFS(prices, i + 2, false, memo), // Sell and cooldown
                                      memoizedDFS(prices, i + 1, true, memo)); // Skip
    } else {
        return memo[i][holding] = max(-prices[i] + memoizedDFS(prices, i + 1, true, memo), // Buy
                                      memoizedDFS(prices, i + 1, false, memo)); // Skip
    }
}

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> memo(n, vector<int>(2, -1));
    return memoizedDFS(prices, 0, false, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
int maxProfitDP(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][1] = max(prices[i] + ((i + 2 < n) ? dp[i + 2][0] : 0), dp[i + 1][1]); // Holding
        dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]); // Not holding
    }
    return dp[0][0];
}

// 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
int maxProfitOptimizedDP(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    int aheadNotHolding = 0, aheadHolding = 0, aheadCooldown = 0;

    for (int i = n - 1; i >= 0; i--) {
        int tempNotHolding = max(-prices[i] + aheadHolding, aheadNotHolding);
        int tempHolding = max(prices[i] + aheadCooldown, aheadHolding);
        aheadCooldown = aheadNotHolding;
        aheadNotHolding = tempNotHolding;
        aheadHolding = tempHolding;
    }
    return aheadNotHolding;
}

// 5. Greedy Approach - Not Applicable for Cooldown (Cooldown breaks transaction chaining)

// Main function to test different approaches
int main() {
    vector<int> prices = {1, 2, 3, 0, 2}; // Example input

    cout << "Brute Force: " << maxProfitBruteForce(prices) << endl;
    cout << "Memoization: " << maxProfitMemo(prices) << endl;
    cout << "Bottom-Up DP: " << maxProfitDP(prices) << endl;
    cout << "Optimized DP: " << maxProfitOptimizedDP(prices) << endl;

    return 0;
}
