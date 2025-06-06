#include <iostream>
#include <vector>
using namespace std;

// 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
int bruteForce(vector<int>& prices, int i, bool holding, int fee) {
    if (i >= prices.size()) return 0;

    if (holding) {
        return max(prices[i] - fee + bruteForce(prices, i + 1, false, fee), // Sell
                   bruteForce(prices, i + 1, true, fee)); // Skip
    } else {
        return max(-prices[i] + bruteForce(prices, i + 1, true, fee), // Buy
                   bruteForce(prices, i + 1, false, fee)); // Skip
    }
}

int maxProfitBruteForce(vector<int>& prices, int fee) {
    return bruteForce(prices, 0, false, fee);
}

// 2. Recursion + Memoization (O(N) Time, O(N) Space)
int memoizedDFS(vector<int>& prices, int i, bool holding, int fee, vector<vector<int>>& memo) {
    if (i >= prices.size()) return 0;
    if (memo[i][holding] != -1) return memo[i][holding];

    if (holding) {
        return memo[i][holding] = max(prices[i] - fee + memoizedDFS(prices, i + 1, false, fee, memo),
                                      memoizedDFS(prices, i + 1, true, fee, memo));
    } else {
        return memo[i][holding] = max(-prices[i] + memoizedDFS(prices, i + 1, true, fee, memo),
                                      memoizedDFS(prices, i + 1, false, fee, memo));
    }
}

int maxProfitMemo(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> memo(n, vector<int>(2, -1));
    return memoizedDFS(prices, 0, false, fee, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
int maxProfitDP(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][1] = max(prices[i] - fee + dp[i + 1][0], dp[i + 1][1]); // Holding
        dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]); // Not holding
    }
    return dp[0][0];
}

// 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
int maxProfitOptimizedDP(vector<int>& prices, int fee) {
    int aheadNotHolding = 0, aheadHolding = 0;

    for (int i = prices.size() - 1; i >= 0; i--) {
        int tempNotHolding = max(-prices[i] + aheadHolding, aheadNotHolding);
        int tempHolding = max(prices[i] - fee + aheadNotHolding, aheadHolding);
        aheadNotHolding = tempNotHolding;
        aheadHolding = tempHolding;
    }
    return aheadNotHolding;
}

// 5. Greedy Approach (O(N) Time, O(1) Space) - Best Solution
int maxProfitGreedy(vector<int>& prices, int fee) {
    int profit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i]; // Update minimum buying price
        }
        if (prices[i] > minPrice + fee) {
            profit += prices[i] - minPrice - fee; // Sell stock and add profit
            minPrice = prices[i] - fee; // Adjust minPrice for next transaction
        }
    }
    return profit;
}

// Main function to test different approaches
int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9}; // Example input
    int fee = 2;

    cout << "Brute Force: " << maxProfitBruteForce(prices, fee) << endl;
    cout << "Memoization: " << maxProfitMemo(prices, fee) << endl;
    cout << "Bottom-Up DP: " << maxProfitDP(prices, fee) << endl;
    cout << "Optimized DP: " << maxProfitOptimizedDP(prices, fee) << endl;
    cout << "Greedy Approach: " << maxProfitGreedy(prices, fee) << endl;

    return 0;
}
