import java.util.Arrays;

public class main {

    // 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
    private static int bruteForce(int[] prices, int i, int transactionsLeft, boolean holding) {
        if (i >= prices.length || transactionsLeft == 0) return 0;

        if (holding) {
            return Math.max(prices[i] + bruteForce(prices, i + 1, transactionsLeft - 1, false),
                            bruteForce(prices, i + 1, transactionsLeft, true));
        } else {
            return Math.max(-prices[i] + bruteForce(prices, i + 1, transactionsLeft, true),
                            bruteForce(prices, i + 1, transactionsLeft, false));
        }
    }

    public static int maxProfitBruteForce(int k, int[] prices) {
        return bruteForce(prices, 0, k, false);
    }

    // 2. Recursion + Memoization (O(N * K) Time, O(N * K) Space)
    private static int memoizedDFS(int[] prices, int i, int transactionsLeft, boolean holding, int[][][] memo) {
        if (i >= prices.length || transactionsLeft == 0) return 0;
        if (memo[i][transactionsLeft][holding ? 1 : 0] != -1) return memo[i][transactionsLeft][holding ? 1 : 0];

        if (holding) {
            memo[i][transactionsLeft][1] = Math.max(prices[i] + memoizedDFS(prices, i + 1, transactionsLeft - 1, false, memo),
                                                    memoizedDFS(prices, i + 1, transactionsLeft, true, memo));
        } else {
            memo[i][transactionsLeft][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, transactionsLeft, true, memo),
                                                    memoizedDFS(prices, i + 1, transactionsLeft, false, memo));
        }

        return memo[i][transactionsLeft][holding ? 1 : 0];
    }

    public static int maxProfitMemo(int k, int[] prices) {
        int n = prices.length;
        int[][][] memo = new int[n][k + 1][2];
        for (int[][] row : memo) {
            for (int[] col : row) {
                Arrays.fill(col, -1);
            }
        }
        return memoizedDFS(prices, 0, k, false, memo);
    }

    // 3. Bottom-Up Dynamic Programming (O(N * K) Time, O(N * K) Space)
    public static int maxProfitDP(int k, int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;

        int[][] dp = new int[k + 1][n];

        for (int t = 1; t <= k; t++) {
            int maxDiff = -prices[0];
            for (int i = 1; i < n; i++) {
                dp[t][i] = Math.max(dp[t][i - 1], prices[i] + maxDiff);
                maxDiff = Math.max(maxDiff, dp[t - 1][i] - prices[i]);
            }
        }
        return dp[k][n - 1];
    }

    // 4. Optimized DP with O(N) Space (O(N * K) Time, O(K) Space)
    public static int maxProfitOptimizedDP(int k, int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;

        if (k >= n / 2) { // When k is large, reduce to infinite transactions problem (Greedy)
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];
        Arrays.fill(buy, Integer.MIN_VALUE);

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t] = Math.max(buy[t], sell[t - 1] - price);
                sell[t] = Math.max(sell[t], buy[t] + price);
            }
        }
        return sell[k];
    }

    // Main function to test different approaches
    public static void main(String[] args) {
        int[] prices = {3, 2, 6, 5, 0, 3}; // Example input
        int k = 2; // Maximum number of transactions

        System.out.println("Brute Force: " + maxProfitBruteForce(k, prices));
        System.out.println("Memoization: " + maxProfitMemo(k, prices));
        System.out.println("Bottom-Up DP: " + maxProfitDP(k, prices));
        System.out.println("Optimized DP: " + maxProfitOptimizedDP(k, prices));
    }
}
