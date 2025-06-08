// 1. Brute Force (Recursive) - O(2^N) Time
function bruteForce(prices, i, holding) {
    if (i >= prices.length) return 0;

    if (holding) {
        return Math.max(prices[i] + bruteForce(prices, i + 1, false),
                        bruteForce(prices, i + 1, true));
    } else {
        return Math.max(-prices[i] + bruteForce(prices, i + 1, true),
                        bruteForce(prices, i + 1, false));
    }
}

function maxProfitBruteForce(prices) {
    return bruteForce(prices, 0, false);
}

// 2. Recursion + Memoization (O(N) Time, O(N) Space)
function memoizedDFS(prices, i, holding, memo) {
    if (i >= prices.length) return 0;
    if (memo[i][holding ? 1 : 0] !== -1) return memo[i][holding ? 1 : 0];

    if (holding) {
        return memo[i][1] = Math.max(prices[i] + memoizedDFS(prices, i + 1, false, memo),
                                     memoizedDFS(prices, i + 1, true, memo));
    } else {
        return memo[i][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, true, memo),
                                     memoizedDFS(prices, i + 1, false, memo));
    }
}

function maxProfitMemo(prices) {
    let n = prices.length;
    let memo = Array.from({ length: n }, () => Array(2).fill(-1));
    return memoizedDFS(prices, 0, false, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
function maxProfitDP(prices) {
    let n = prices.length;
    let dp = Array.from({ length: n + 1 }, () => Array(2).fill(0));

    for (let i = n - 1; i >= 0; i--) {
        dp[i][1] = Math.max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
    }
    return dp[0][0];
}

// 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
function maxProfitOptimizedDP(prices) {
    let aheadNotHolding = 0, aheadHolding = 0;

    for (let i = prices.length - 1; i >= 0; i--) {
        let tempNotHolding = Math.max(-prices[i] + aheadHolding, aheadNotHolding);
        let tempHolding = Math.max(prices[i] + aheadNotHolding, aheadHolding);
        aheadNotHolding = tempNotHolding;
        aheadHolding = tempHolding;
    }
    return aheadNotHolding;
}

// 5. Greedy Approach (O(N) Time, O(1) Space) - Best Solution
function maxProfitGreedy(prices) {
    let profit = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

// Main function to test different approaches
function main() {
    let prices = [7, 1, 5, 3, 6, 4]; // Example input

    console.log("Brute Force:", maxProfitBruteForce(prices));
    console.log("Memoization:", maxProfitMemo(prices));
    console.log("Bottom-Up DP:", maxProfitDP(prices));
    console.log("Optimized DP:", maxProfitOptimizedDP(prices));
    console.log("Greedy Approach:", maxProfitGreedy(prices));
}

// Execute main function
main();
