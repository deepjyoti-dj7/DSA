import java.util.Arrays;

public class LCS {

    // 1. Brute Force Recursive Approach
    public static int LCS_Recursive(String s1, String s2, int i, int j) {
        if (i < 0 || j < 0) 
            return 0;

        if (s1.charAt(i) == s2.charAt(j)) 
            return 1 + LCS_Recursive(s1, s2, i - 1, j - 1);
        else 
            return Math.max(LCS_Recursive(s1, s2, i - 1, j), LCS_Recursive(s1, s2, i, j - 1));
    }

    // 2. Memoization Approach
    public static int LCS_Memoization(String s1, String s2, int i, int j, int[][] dp) {
        if (i < 0 || j < 0) 
            return 0;
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        if (s1.charAt(i) == s2.charAt(j)) 
            return dp[i][j] = 1 + LCS_Memoization(s1, s2, i - 1, j - 1, dp);
        else 
            return dp[i][j] = Math.max(LCS_Memoization(s1, s2, i - 1, j, dp), LCS_Memoization(s1, s2, i, j - 1, dp));
        
    }

    // 3. Tabulation Approach
    public static int LCS_Tabulation(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int[][] dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    // 4. Space Optimized Tabulation Approach
    public static int LCS_TabulationSpaceOptimized(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) 
                    curr[j] = 1 + prev[j - 1];
                else 
                    curr[j] = Math.max(prev[j], curr[j - 1]);
            }
            prev = curr.clone();
        }
        return prev[m];
    }

    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "ace";

        // 1. Brute Force Recursive
        System.out.println("Length of LCS (Brute Force): " + LCS_Recursive(s1, s2, s1.length() - 1, s2.length() - 1));

        int[][] dp = new int[s1.length()][s2.length()];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        // 2. Memoization
        System.out.println("Length of LCS (Memoization): " + LCS_Memoization(s1, s2, s1.length() - 1, s2.length() - 1, dp));

        // 3. Tabulation
        System.out.println("Length of LCS (Tabulation): " + LCS_Tabulation(s1, s2));

        // 4. Space Optimized Tabulation
        System.out.println("Length of LCS (Tabulation Space Optimized): " + LCS_TabulationSpaceOptimized(s1, s2));
    }
}
