import java.util.Arrays;

public class main {

    // 1. Brute Force (Recursive) - Exponential Time Complexity (O(2^N))
    public static int bruteForce(int[] prices, int i, boolean holding) {
        if (i >= prices.length) return 0;

        if (holding) {
            return Math.max(prices[i] + bruteForce(prices, i + 2, false),  // Sell and cooldown
                            bruteForce(prices, i + 1, true));  // Skip
        } else {
            return Math.max(-prices[i] + bruteForce(prices, i + 1, true),  // Buy
                            bruteForce(prices, i + 1, false)); // Skip
        }
    }

    public static int maxProfitBruteForce(int[] prices) {
        return bruteForce(prices, 0, false);
    }

    // 2. Recursion + Memoization (O(N) Time, O(N) Space)
    public static int memoizedDFS(int[] prices, int i, boolean holding, int[][] memo) {
        if (i >= prices.length) return 0;
        if (memo[i][holding ? 1 : 0] != -1) return memo[i][holding ? 1 : 0];

        if (holding) {
            memo[i][1] = Math.max(prices[i] + memoizedDFS(prices, i + 2, false, memo),  // Sell and cooldown
                                  memoizedDFS(prices, i + 1, true, memo));  // Skip
        } else {
            memo[i][0] = Math.max(-prices[i] + memoizedDFS(prices, i + 1, true, memo),  // Buy
                                  memoizedDFS(prices, i + 1, false, memo));  // Skip
        }
        return memo[i][holding ? 1 : 0];
    }

    public static int maxProfitMemo(int[] prices) {
        int n = prices.length;
        int[][] memo = new int[n][2];
        for (int[] row : memo) Arrays.fill(row, -1);
        return memoizedDFS(prices, 0, false, memo);
    }

    // 3. Bottom-Up Dynamic Programming (O(N) Time, O(N) Space)
    public static int maxProfitDP(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;

        int[][] dp = new int[n + 1][2];

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = Math.max(prices[i] + ((i + 2 < n) ? dp[i + 2][0] : 0), dp[i + 1][1]);  // Holding
            dp[i][0] = Math.max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);  // Not holding
        }
        return dp[0][0];
    }

    // 4. Optimized DP with O(1) Space (O(N) Time, O(1) Space)
    public static int maxProfitOptimizedDP(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;

        int aheadNotHolding = 0, aheadHolding = 0, aheadCooldown = 0;

        for (int i = n - 1; i >= 0; i--) {
            int tempNotHolding = Math.max(-prices[i] + aheadHolding, aheadNotHolding);
            int tempHolding = Math.max(prices[i] + aheadCooldown, aheadHolding);
            aheadCooldown = aheadNotHolding;
            aheadNotHolding = tempNotHolding;
            aheadHolding = tempHolding;
        }
        return aheadNotHolding;
    }

    // Main function to test different approaches
    public static void main(String[] args) {
        int[] prices = {1, 2, 3, 0, 2};  // Example input

        System.out.println("Brute Force: " + maxProfitBruteForce(prices));
        System.out.println("Memoization: " + maxProfitMemo(prices));
        System.out.println("Bottom-Up DP: " + maxProfitDP(prices));
        System.out.println("Optimized DP: " + maxProfitOptimizedDP(prices));
    }
}
