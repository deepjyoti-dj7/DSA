import java.util.*;

public class main {

    // 1. Brute Force (Recursion)
    public static int editDistanceBrute(String s1, String s2, int i, int j) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (s1.charAt(i - 1) == s2.charAt(j - 1))
            return editDistanceBrute(s1, s2, i - 1, j - 1);

        return 1 + Math.min(
            editDistanceBrute(s1, s2, i - 1, j),       // delete
            Math.min(
                editDistanceBrute(s1, s2, i, j - 1),   // insert
                editDistanceBrute(s1, s2, i - 1, j - 1) // replace
            )
        );
    }

    // 2. Memoization (Top-down DP)
    public static int editDistanceMemo(String s1, String s2, int i, int j, int[][] dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1.charAt(i - 1) == s2.charAt(j - 1))
            return dp[i][j] = editDistanceMemo(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = 1 + Math.min(
            editDistanceMemo(s1, s2, i - 1, j, dp), 
            Math.min(
                editDistanceMemo(s1, s2, i, j - 1, dp),
                editDistanceMemo(s1, s2, i - 1, j - 1, dp)
            )
        );
    }

    // 3. Tabulation (Bottom-up DP)
    public static int editDistanceTab(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + Math.min(
                        dp[i - 1][j], 
                        Math.min(dp[i][j - 1], dp[i - 1][j - 1])
                    );
            }
        }

        return dp[n][m];
    }

    // 4. Space Optimized DP (2 rows)
    public static int editDistanceSpaceOpt(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + Math.min(
                        prev[j],
                        Math.min(curr[j - 1], prev[j - 1])
                    );
            }
            prev = curr.clone();
        }

        return prev[m];
    }

    public static void main(String[] args) {
        String s1 = "horse", s2 = "ros";

        System.out.println("Brute Force: " + editDistanceBrute(s1, s2, s1.length(), s2.length()));

        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int[] row : dp) Arrays.fill(row, -1);
        System.out.println("Memoization: " + editDistanceMemo(s1, s2, s1.length(), s2.length(), dp));

        System.out.println("Tabulation: " + editDistanceTab(s1, s2));

        System.out.println("Space Optimized: " + editDistanceSpaceOpt(s1, s2));
    }
}
