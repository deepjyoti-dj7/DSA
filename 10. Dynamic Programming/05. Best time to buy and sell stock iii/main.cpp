#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Brute Force (Recursive) - Exponential Time Complexity O(2^N)
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

int maxProfitBruteForce(vector<int>& prices) {
    return bruteForce(prices, 0, 2, false);
}

// 2. Recursion + Memoization (O(N * 2) Time, O(N * 2) Space)
int memoizedDFS(vector<int>& prices, int i, int transactionsLeft, bool holding, vector<vector<vector<int>>>& memo) {
    if (i >= prices.size() || transactionsLeft == 0) return 0;
    if (memo[i][transactionsLeft][holding] != -1) return memo[i][transactionsLeft][holding];

    if (holding) {
        return memo[i][transactionsLeft][holding] = max(
            prices[i] + memoizedDFS(prices, i + 1, transactionsLeft - 1, false, memo),
            memoizedDFS(prices, i + 1, transactionsLeft, true, memo)
        );
    } else {
        return memo[i][transactionsLeft][holding] = max(
            -prices[i] + memoizedDFS(prices, i + 1, transactionsLeft, true, memo),
            memoizedDFS(prices, i + 1, transactionsLeft, false, memo)
        );
    }
}

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(3, vector<int>(2, -1)));
    return memoizedDFS(prices, 0, 2, false, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N * 2) Time, O(N * 2) Space)
int maxProfitDP(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));

    for (int i = n - 1; i >= 0; i--) {
        for (int transactionsLeft = 1; transactionsLeft < 3; transactionsLeft++) {
            dp[i][transactionsLeft][1] = max(prices[i] + dp[i + 1][transactionsLeft - 1][0], dp[i + 1][transactionsLeft][1]);
            dp[i][transactionsLeft][0] = max(-prices[i] + dp[i + 1][transactionsLeft][1], dp[i + 1][transactionsLeft][0]);
        }
    }
    return dp[0][2][0];
}

// 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
int maxProfitOptimizedDP(vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int price : prices) {
        buy1 = max(buy1, -price);       // First buy
        sell1 = max(sell1, buy1 + price); // First sell
        buy2 = max(buy2, sell1 - price); // Second buy
        sell2 = max(sell2, buy2 + price); // Second sell
    }

    return sell2;
}

// Main function to test different approaches
int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4}; // Example input

    cout << "Brute Force: " << maxProfitBruteForce(prices) << endl;
    cout << "Memoization: " << maxProfitMemo(prices) << endl;
    cout << "Bottom-Up DP: " << maxProfitDP(prices) << endl;
    cout << "Optimized DP: " << maxProfitOptimizedDP(prices) << endl;

    return 0;
}
