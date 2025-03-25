// 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
function bruteForce(prices, i, holding, fee) {
    if (i >= prices.length) return 0;

    if (holding) {
        return Math.max(prices[i] - fee + bruteForce(prices, i + 1, false, fee),
                        bruteForce(prices, i + 1, true, fee));
    } else {
        return Math.max(-prices[i] + bruteForce(prices, i + 1, true, fee),
                        bruteForce(prices, i + 1, false, fee));
    }
}

function maxProfitBruteForce(prices, fee) {
    return bruteForce(prices, 0, false, fee);
}

// 2. Recursion + Memoization (O(N) Time, O(N) Space)
function memoizedDFS(prices, i, holding, fee, memo) {
    if (i >= prices.length) 
        return 0;
    if (memo[i][holding ? 1 : 0] !== -1) 
        return memo[i][holding ? 1 : 0];

    if (holding) {
        return memo[i][1] = Math.max(prices[i] - fee + memoizedDFS(prices, i + 1, false, fee, memo),
                                     memoizedDFS(prices, i + 1, true, fee, memo));
    } else {
        return memo[i][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, true, fee, memo),
                                     memoizedDFS(prices, i + 1, false, fee, memo));
    }
}

function maxProfitMemo(prices, fee) {
    let n = prices.length;
    let memo = Array.from({ length: n }, () => Array(2).fill(-1));
    return memoizedDFS(prices, 0, false, fee, memo);
}

// 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
function maxProfitDP(prices, fee) {
    let n = prices.length;
    let dp = Array.from({ length: n + 1 }, () => Array(2).fill(0));

    for (let i = n - 1; i >= 0; i--) {
        dp[i][1] = Math.max(prices[i] - fee + dp[i + 1][0], dp[i + 1][1]); // Holding
        dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]); // Not holding
    }
    return dp[0][0];
}

// 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
function maxProfitOptimizedDP(prices, fee) {
    let aheadNotHolding = 0, aheadHolding = 0;

    for (let i = prices.length - 1; i >= 0; i--) {
        let tempNotHolding = Math.max(-prices[i] + aheadHolding, aheadNotHolding);
        let tempHolding = Math.max(prices[i] - fee + aheadNotHolding, aheadHolding);
        aheadNotHolding = tempNotHolding;
        aheadHolding = tempHolding;
    }
    return aheadNotHolding;
}

// 5. Greedy Approach (O(N) Time, O(1) Space) - Best Solution
function maxProfitGreedy(prices, fee) {
    let profit = 0;
    let minPrice = prices[0];

    for (let i = 1; i < prices.length; i++) {
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
function main() {
    let prices = [1, 3, 2, 8, 4, 9]; // Example input
    let fee = 2;

    console.log("Brute Force:", maxProfitBruteForce(prices, fee));
    console.log("Memoization:", maxProfitMemo(prices, fee));
    console.log("Bottom-Up DP:", maxProfitDP(prices, fee));
    console.log("Optimized DP:", maxProfitOptimizedDP(prices, fee));
    console.log("Greedy Approach:", maxProfitGreedy(prices, fee));
}

// Run the main function
main();
