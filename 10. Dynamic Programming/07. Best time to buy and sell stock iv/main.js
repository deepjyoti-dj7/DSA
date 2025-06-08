// 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
function bruteForce(prices, i, transactionsLeft, holding) {
    if (i >= prices.length || transactionsLeft === 0) 
        return 0;

    if (holding) {
        return Math.max(prices[i] + bruteForce(prices, i + 1, transactionsLeft - 1, false),
                        bruteForce(prices, i + 1, transactionsLeft, true));
    } else {
        return Math.max(-prices[i] + bruteForce(prices, i + 1, transactionsLeft, true),
                        bruteForce(prices, i + 1, transactionsLeft, false));
    }
}

function maxProfitBruteForce(k, prices) {
    return bruteForce(prices, 0, k, false);
}

// 2. Recursion + Memoization (O(N * K) Time, O(N * K) Space)
function memoizedDFS(prices, i, transactionsLeft, holding, memo) {
    if (i >= prices.length || transactionsLeft === 0) 
        return 0;
    if (memo[i][transactionsLeft][holding ? 1 : 0] !== -1) 
        return memo[i][transactionsLeft][holding ? 1 : 0];

    if (holding) {
        memo[i][transactionsLeft][1] = Math.max(prices[i] + memoizedDFS(prices, i + 1, transactionsLeft - 1, false, memo),
                                                memoizedDFS(prices, i + 1, transactionsLeft, true, memo));
    } else {
        memo[i][transactionsLeft][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, transactionsLeft, true, memo),
                                                memoizedDFS(prices, i + 1, transactionsLeft, false, memo));
    }

    return memo[i][transactionsLeft][holding ? 1 : 0];
}

function maxProfitMemo(k, prices) {
    let n = prices.length;
    let memo = Array.from({ length: n }, () => Array.from({ length: k + 1 }, () => Array(2).fill(-1)));
    return memoizedDFS(prices, 0, k, false, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N * K) Time, O(N * K) Space)
function maxProfitDP(k, prices) {
    let n = prices.length;
    if (n === 0) return 0;

    let dp = Array.from({ length: k + 1 }, () => Array(n).fill(0));

    for (let t = 1; t <= k; t++) {
        let maxDiff = -prices[0];
        for (let i = 1; i < n; i++) {
            dp[t][i] = Math.max(dp[t][i - 1], prices[i] + maxDiff);
            maxDiff = Math.max(maxDiff, dp[t - 1][i] - prices[i]);
        }
    }
    return dp[k][n - 1];
}

// 4. Optimized DP with O(N) Space (O(N * K) Time, O(K) Space)
function maxProfitOptimizedDP(k, prices) {
    let n = prices.length;
    if (n === 0) return 0;

    if (k >= n / 2) { // When k is large, reduce to infinite transactions problem (Greedy)
        let profit = 0;
        for (let i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }

    let buy = Array(k + 1).fill(-Infinity);
    let sell = Array(k + 1).fill(0);

    for (let price of prices) {
        for (let t = 1; t <= k; t++) {
            buy[t] = Math.max(buy[t], sell[t - 1] - price);
            sell[t] = Math.max(sell[t], buy[t] + price);
        }
    }
    return sell[k];
}

// Main function to test different approaches
function main() {
    let prices = [3, 2, 6, 5, 0, 3]; // Example input
    let k = 2; // Maximum number of transactions

    console.log("Brute Force:", maxProfitBruteForce(k, prices));
    console.log("Memoization:", maxProfitMemo(k, prices));
    console.log("Bottom-Up DP:", maxProfitDP(k, prices));
    console.log("Optimized DP:", maxProfitOptimizedDP(k, prices));
}

// Run the main function
main();
