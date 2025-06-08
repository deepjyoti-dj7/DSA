import java.util.Arrays;

public class main {

    // 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
    public static int bruteForce(int[] prices, int i, boolean holding, int fee) {
        if (i >= prices.length) return 0;

        if (holding) {
            return Math.max(prices[i] - fee + bruteForce(prices, i + 1, false, fee),
                            bruteForce(prices, i + 1, true, fee));
        } else {
            return Math.max(-prices[i] + bruteForce(prices, i + 1, true, fee),
                            bruteForce(prices, i + 1, false, fee));
        }
    }

    public static int maxProfitBruteForce(int[] prices, int fee) {
        return bruteForce(prices, 0, false, fee);
    }

    // 2. Recursion + Memoization (O(N) Time, O(N) Space)
    public static int memoizedDFS(int[] prices, int i, boolean holding, int fee, int[][] memo) {
        if (i >= prices.length) return 0;
        if (memo[i][holding ? 1 : 0] != -1) return memo[i][holding ? 1 : 0];

        if (holding) {
            return memo[i][1] = Math.max(prices[i] - fee + memoizedDFS(prices, i + 1, false, fee, memo),
                                         memoizedDFS(prices, i + 1, true, fee, memo));
        } else {
            return memo[i][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, true, fee, memo),
                                         memoizedDFS(prices, i + 1, false, fee, memo));
        }
    }

    public static int maxProfitMemo(int[] prices, int fee) {
        int n = prices.length;
        int[][] memo = new int[n][2];
        for (int[] row : memo) Arrays.fill(row, -1);
        return memoizedDFS(prices, 0, false, fee, memo);
    }

    // 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
    public static int maxProfitDP(int[] prices, int fee) {
        int n = prices.length;
        int[][] dp = new int[n + 1][2];

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = Math.max(prices[i] - fee + dp[i + 1][0], dp[i + 1][1]); // Holding
            dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]); // Not holding
        }
        return dp[0][0];
    }

    // 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
    public static int maxProfitOptimizedDP(int[] prices, int fee) {
        int aheadNotHolding = 0, aheadHolding = 0;

        for (int i = prices.length - 1; i >= 0; i--) {
            int tempNotHolding = Math.max(-prices[i] + aheadHolding, aheadNotHolding);
            int tempHolding = Math.max(prices[i] - fee + aheadNotHolding, aheadHolding);
            aheadNotHolding = tempNotHolding;
            aheadHolding = tempHolding;
        }
        return aheadNotHolding;
    }

    // 5. Greedy Approach (O(N) Time, O(1) Space) - Best Solution
    public static int maxProfitGreedy(int[] prices, int fee) {
        int profit = 0;
        int minPrice = prices[0];

        for (int i = 1; i < prices.length; i++) {
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
    public static void main(String[] args) {
        int[] prices = {1, 3, 2, 8, 4, 9}; // Example input
        int fee = 2;

        System.out.println("Brute Force: " + maxProfitBruteForce(prices, fee));
        System.out.println("Memoization: " + maxProfitMemo(prices, fee));
        System.out.println("Bottom-Up DP: " + maxProfitDP(prices, fee));
        System.out.println("Optimized DP: " + maxProfitOptimizedDP(prices, fee));
        System.out.println("Greedy Approach: " + maxProfitGreedy(prices, fee));
    }
}
