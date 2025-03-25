#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
int bruteForce(vector<int>& prices, int i, int transactionsLeft, bool holding) {
    if (i >= prices.size() || transactionsLeft == 0) return 0;

    if (holding) {
        return max(prices[i] + bruteForce(prices, i + 1, transactionsLeft - 1, false),
                   bruteForce(prices, i + 1, transactionsLeft, true));
    } else {
        return max(-prices[i] + bruteForce(prices, i + 1, transactionsLeft, true),
                   bruteForce(prices, i + 1, transactionsLeft, false));
    }
}

int maxProfitBruteForce(int k, vector<int>& prices) {
    return bruteForce(prices, 0, k, false);
}

// 2. Recursion + Memoization (O(N * K) Time, O(N * K) Space)
int memoizedDFS(vector<int>& prices, int i, int transactionsLeft, bool holding, vector<vector<vector<int>>>& memo) {
    if (i >= prices.size() || transactionsLeft == 0) return 0;
    if (memo[i][transactionsLeft][holding] != -1) return memo[i][transactionsLeft][holding];

    if (holding) {
        memo[i][transactionsLeft][1] = max(prices[i] + memoizedDFS(prices, i + 1, transactionsLeft - 1, false, memo),
                                           memoizedDFS(prices, i + 1, transactionsLeft, true, memo));
    } else {
        memo[i][transactionsLeft][0] = max(-prices[i] + memoizedDFS(prices, i + 1, transactionsLeft, true, memo),
                                           memoizedDFS(prices, i + 1, transactionsLeft, false, memo));
    }

    return memo[i][transactionsLeft][holding];
}

int maxProfitMemo(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return memoizedDFS(prices, 0, k, false, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N * K) Time, O(N * K) Space)
int maxProfitDP(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int t = 1; t <= k; t++) {
        int maxDiff = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[t][i] = max(dp[t][i - 1], prices[i] + maxDiff);
            maxDiff = max(maxDiff, dp[t - 1][i] - prices[i]);
        }
    }
    return dp[k][n - 1];
}

// 4. Optimized DP with O(N) Space (O(N * K) Time, O(K) Space)
int maxProfitOptimizedDP(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    if (k >= n / 2) { // When k is large, reduce to infinite transactions problem (Greedy)
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }

    vector<int> buy(k + 1, INT_MIN);
    vector<int> sell(k + 1, 0);

    for (int price : prices) {
        for (int t = 1; t <= k; t++) {
            buy[t] = max(buy[t], sell[t - 1] - price);
            sell[t] = max(sell[t], buy[t] + price);
        }
    }
    return sell[k];
}

// Main function to test different approaches
int main() {
    vector<int> prices = {3, 2, 6, 5, 0, 3}; // Example input
    int k = 2; // Maximum number of transactions

    cout << "Brute Force: " << maxProfitBruteForce(k, prices) << endl;
    cout << "Memoization: " << maxProfitMemo(k, prices) << endl;
    cout << "Bottom-Up DP: " << maxProfitDP(k, prices) << endl;
    cout << "Optimized DP: " << maxProfitOptimizedDP(k, prices) << endl;

    return 0;
}
