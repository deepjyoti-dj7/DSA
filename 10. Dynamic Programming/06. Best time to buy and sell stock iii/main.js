function maxProfitBruteForce(prices) {
    function bruteForce(i, transactionsLeft, holding) {
        if (i >= prices.length || transactionsLeft === 0) return 0;

        if (holding) {
            return Math.max(prices[i] + bruteForce(i + 1, transactionsLeft - 1, false),
                            bruteForce(i + 1, transactionsLeft, true));
        } else {
            return Math.max(-prices[i] + bruteForce(i + 1, transactionsLeft, true),
                            bruteForce(i + 1, transactionsLeft, false));
        }
    }
    return bruteForce(0, 2, false);
}

function maxProfitMemo(prices) {
    let n = prices.length;
    let memo = Array.from({ length: n }, () => Array.from({ length: 3 }, () => Array(2).fill(-1)));

    function memoizedDFS(i, transactionsLeft, holding) {
        if (i >= prices.length || transactionsLeft === 0) return 0;
        if (memo[i][transactionsLeft][holding] !== -1) return memo[i][transactionsLeft][holding];

        if (holding) {
            memo[i][transactionsLeft][1] = Math.max(
                prices[i] + memoizedDFS(i + 1, transactionsLeft - 1, false),
                memoizedDFS(i + 1, transactionsLeft, true)
            );
        } else {
            memo[i][transactionsLeft][0] = Math.max(
                -prices[i] + memoizedDFS(i + 1, transactionsLeft, true),
                memoizedDFS(i + 1, transactionsLeft, false)
            );
        }

        return memo[i][transactionsLeft][holding];
    }

    return memoizedDFS(0, 2, false);
}

function maxProfitDP(prices) {
    let n = prices.length;
    let dp = Array.from({ length: n + 1 }, () => Array.from({ length: 3 }, () => Array(2).fill(0)));

    for (let i = n - 1; i >= 0; i--) {
        for (let transactionsLeft = 1; transactionsLeft < 3; transactionsLeft++) {
            dp[i][transactionsLeft][1] = Math.max(prices[i] + dp[i + 1][transactionsLeft - 1][0], dp[i + 1][transactionsLeft][1]);
            dp[i][transactionsLeft][0] = Math.max(-prices[i] + dp[i + 1][transactionsLeft][1], dp[i + 1][transactionsLeft][0]);
        }
    }
    return dp[0][2][0];
}

function maxProfitOptimizedDP(prices) {
    let buy1 = -Infinity, sell1 = 0;
    let buy2 = -Infinity, sell2 = 0;

    for (let price of prices) {
        buy1 = Math.max(buy1, -price);
        sell1 = Math.max(sell1, buy1 + price);
        buy2 = Math.max(buy2, sell1 - price);
        sell2 = Math.max(sell2, buy2 + price);
    }

    return sell2;
}

// Example usage
function main() {
    let prices = [3, 3, 5, 0, 0, 3, 1, 4];
    console.log("Brute Force:", maxProfitBruteForce(prices));
    console.log("Memoization:", maxProfitMemo(prices));
    console.log("Bottom-Up DP:", maxProfitDP(prices));
    console.log("Optimized DP:", maxProfitOptimizedDP(prices));
}

main();