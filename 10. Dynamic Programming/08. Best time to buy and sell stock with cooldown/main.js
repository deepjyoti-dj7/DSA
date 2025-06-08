// 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
function bruteForce(prices, i, holding) {
    if (i >= prices.length) return 0;

    if (holding) {
        return Math.max(prices[i] + bruteForce(prices, i + 2, false),  // Sell and cooldown
                        bruteForce(prices, i + 1, true));  // Skip
    } else {
        return Math.max(-prices[i] + bruteForce(prices, i + 1, true),  // Buy
                        bruteForce(prices, i + 1, false));  // Skip
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
        memo[i][1] = Math.max(prices[i] + memoizedDFS(prices, i + 2, false, memo),  // Sell and cooldown
                              memoizedDFS(prices, i + 1, true, memo));  // Skip
    } else {
        memo[i][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, true, memo),  // Buy
                              memoizedDFS(prices, i + 1, false, memo));  // Skip
    }
    return memo[i][holding ? 1 : 0];
}

function maxProfitMemo(prices) {
    let n = prices.length;
    let memo = Array.from({ length: n }, () => [-1, -1]);
    return memoizedDFS(prices, 0, false, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
function maxProfitDP(prices) {
    let n = prices.length;
    if (n === 0) return 0;

    let dp = Array.from({ length: n + 1 }, () => [0, 0]);

    for (let i = n - 1; i >= 0; i--) {
        dp[i][1] = Math.max(prices[i] + (i + 2 < n ? dp[i + 2][0] : 0), dp[i + 1][1]);  // Holding
        dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);  // Not holding
    }
    return dp[0][0];
}

// 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
function maxProfitOptimizedDP(prices) {
    let n = prices.length;
    if (n === 0) return 0;

    let aheadNotHolding = 0, aheadHolding = 0, aheadCooldown = 0;

    for (let i = n - 1; i >= 0; i--) {
        let tempNotHolding = Math.max(-prices[i] + aheadHolding, aheadNotHolding);
        let tempHolding = Math.max(prices[i] + aheadCooldown, aheadHolding);
        aheadCooldown = aheadNotHolding;
        aheadNotHolding = tempNotHolding;
        aheadHolding = tempHolding;
    }
    return aheadNotHolding;
}

// Main function to test different approaches
function main() {
    let prices = [1, 2, 3, 0, 2];  // Example input

    console.log("Brute Force:", maxProfitBruteForce(prices));
    console.log("Memoization:", maxProfitMemo(prices));
    console.log("Bottom-Up DP:", maxProfitDP(prices));
    console.log("Optimized DP:", maxProfitOptimizedDP(prices));
}

main();
