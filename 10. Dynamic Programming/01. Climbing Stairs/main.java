public class main {

    // Brute force
    public static int climbBrute(int n) {
        if (n <= 1) return 1;
        return climbBrute(n - 1) + climbBrute(n - 2);
    }

    // Memoization
    public static int climbMemo(int n, int[] memo) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];
        return memo[n] = climbMemo(n - 1, memo) + climbMemo(n - 2, memo);
    }

    // Tabulation
    public static int climbTab(int n) {
        if (n <= 1) return 1;
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    // Optimized
    public static int climbOpt(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }

    public static void main(String[] args) {
        int n = 5;

        int[] memo = new int[n + 1];
        for (int i = 0; i <= n; i++) 
            memo[i] = -1;

        System.out.println("Brute: " + climbBrute(n));
        System.out.println("Memo: " + climbMemo(n, memo));
        System.out.println("Tabulation: " + climbTab(n));
        System.out.println("Optimized: " + climbOpt(n));
    }
}
