import java.util.*;

public class main {
    // 1. Brute Force (Recursive) - O(2^N)
    public static int bruteForce(int[] prices, int i, boolean holding) {
        if (i >= prices.length) return 0;

        if (holding) {
            return Math.max(prices[i] + bruteForce(prices, i + 1, false),
                            bruteForce(prices, i + 1, true));
        } else {
            return Math.max(-prices[i] + bruteForce(prices, i + 1, true),
                            bruteForce(prices, i + 1, false));
        }
    }

    public static int maxProfitBruteForce(int[] prices) {
        return bruteForce(prices, 0, false);
    }

    // 2. Memoization - O(N) Time, O(N) Space
    public static int memoizedDFS(int[] prices, int i, boolean holding, int[][] memo) {
        if (i >= prices.length) return 0;
        if (memo[i][holding ? 1 : 0] != -1) return memo[i][holding ? 1 : 0];

        if (holding) {
            return memo[i][1] = Math.max(prices[i] + memoizedDFS(prices, i + 1, false, memo),
                                         memoizedDFS(prices, i + 1, true, memo));
        } else {
            return memo[i][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, true, memo),
                                         memoizedDFS(prices, i + 1, false, memo));
        }
    }

    public static int maxProfitMemo(int[] prices) {
        int n = prices.length;
        int[][] memo = new int[n][2];
        for (int[] row : memo) Arrays.fill(row, -1);
        return memoizedDFS(prices, 0, false, memo);
    }

    // 3. Bottom-Up DP - O(N) Time, O(N) Space
    public static int maxProfitDP(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n + 1][2];

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = Math.max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }
        return dp[0][0];
    }

    // 4. Optimized DP - O(N) Time, O(1) Space
    public static int maxProfitOptimizedDP(int[] prices) {
        int aheadNotHolding = 0, aheadHolding = 0;

        for (int i = prices.length - 1; i >= 0; i--) {
            int tempNotHolding = Math.max(-prices[i] + aheadHolding, aheadNotHolding);
            int tempHolding = Math.max(prices[i] + aheadNotHolding, aheadHolding);
            aheadNotHolding = tempNotHolding;
            aheadHolding = tempHolding;
        }
        return aheadNotHolding;
    }

    // 5. Greedy Approach - O(N) Time, O(1) Space
    public static int maxProfitGreedy(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 4}; // Example input

        System.out.println("Brute Force: " + maxProfitBruteForce(prices));
        System.out.println("Memoization: " + maxProfitMemo(prices));
        System.out.println("Bottom-Up DP: " + maxProfitDP(prices));
        System.out.println("Optimized DP: " + maxProfitOptimizedDP(prices));
        System.out.println("Greedy Approach: " + maxProfitGreedy(prices));
    }
}
