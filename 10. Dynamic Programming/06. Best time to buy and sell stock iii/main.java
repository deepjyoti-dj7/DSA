import java.util.*;

public class main {

    // 1. Brute Force (Recursive) - Exponential Time Complexity O(2^N)
    public static int bruteForce(int[] prices, int i, int transactionsLeft, boolean holding) {
        if (i >= prices.length || transactionsLeft == 0) return 0;

        if (holding) {
            return Math.max(prices[i] + bruteForce(prices, i + 1, transactionsLeft - 1, false),
                            bruteForce(prices, i + 1, transactionsLeft, true));
        } else {
            return Math.max(-prices[i] + bruteForce(prices, i + 1, transactionsLeft, true),
                            bruteForce(prices, i + 1, transactionsLeft, false));
        }
    }

    public static int maxProfitBruteForce(int[] prices) {
        return bruteForce(prices, 0, 2, false);
    }

    // 2. Recursion + Memoization (O(N * 2) Time, O(N * 2) Space)
    public static int memoizedDFS(int[] prices, int i, int transactionsLeft, boolean holding, Integer[][][] memo) {
        if (i >= prices.length || transactionsLeft == 0) return 0;
        if (memo[i][transactionsLeft][holding ? 1 : 0] != null) return memo[i][transactionsLeft][holding ? 1 : 0];

        if (holding) {
            memo[i][transactionsLeft][1] = Math.max(
                prices[i] + memoizedDFS(prices, i + 1, transactionsLeft - 1, false, memo),
                memoizedDFS(prices, i + 1, transactionsLeft, true, memo)
            );
        } else {
            memo[i][transactionsLeft][0] = Math.max(
                -prices[i] + memoizedDFS(prices, i + 1, transactionsLeft, true, memo),
                memoizedDFS(prices, i + 1, transactionsLeft, false, memo)
            );
        }

        return memo[i][transactionsLeft][holding ? 1 : 0];
    }

    public static int maxProfitMemo(int[] prices) {
        int n = prices.length;
        Integer[][][] memo = new Integer[n][3][2];
        return memoizedDFS(prices, 0, 2, false, memo);
    }

    // 3. Bottom-Up Dynamic Programming (O(N * 2) Time, O(N * 2) Space)
    public static int maxProfitDP(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n + 1][3][2];

        for (int i = n - 1; i >= 0; i--) {
            for (int transactionsLeft = 1; transactionsLeft < 3; transactionsLeft++) {
                dp[i][transactionsLeft][1] = Math.max(prices[i] + dp[i + 1][transactionsLeft - 1][0], dp[i + 1][transactionsLeft][1]);
                dp[i][transactionsLeft][0] = Math.max(-prices[i] + dp[i + 1][transactionsLeft][1], dp[i + 1][transactionsLeft][0]);
            }
        }
        return dp[0][2][0];
    }

    // 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
    public static int maxProfitOptimizedDP(int[] prices) {
        int buy1 = Integer.MIN_VALUE, sell1 = 0;
        int buy2 = Integer.MIN_VALUE, sell2 = 0;

        for (int price : prices) {
            buy1 = Math.max(buy1, -price);     // First buy
            sell1 = Math.max(sell1, buy1 + price); // First sell
            buy2 = Math.max(buy2, sell1 - price); // Second buy
            sell2 = Math.max(sell2, buy2 + price); // Second sell
        }

        return sell2;
    }

    public static void main(String[] args) {
        int[] prices = {3, 3, 5, 0, 0, 3, 1, 4}; // Example input

        System.out.println("Brute Force: " + maxProfitBruteForce(prices));
        System.out.println("Memoization: " + maxProfitMemo(prices));
        System.out.println("Bottom-Up DP: " + maxProfitDP(prices));
        System.out.println("Optimized DP: " + maxProfitOptimizedDP(prices));
    }
}
