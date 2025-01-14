import java.util.*;

public class LongestCommonSubstring {

    public static int LCS_Iterative(String s1, String s2) {
        int res = 0;
        int n = s1.length(), m = s2.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curr = 0;
                while ((i + curr) < n && (j + curr) < m && s1.charAt(i + curr) == s2.charAt(j + curr)) 
                    curr++;
                res = Math.max(res, curr);
            }
        }
        return res;
    }

    public static int LCS_Solve(String s1, String s2, int n, int m) {
        if (n == 0 || m == 0 || s1.charAt(n - 1) != s2.charAt(m - 1))
            return 0;
        return 1 + LCS_Solve(s1, s2, n - 1, m - 1);
    }

    public static int LCS_Recursion(String s1, String s2) {
        int res = 0;
        for (int i = 1; i <= s1.length(); i++) 
            for (int j = 1; j <= s2.length(); j++) 
                res = Math.max(res, LCS_Solve(s1, s2, i, j));
        return res;
    }

    public static int LCS_Tabulation(String s1, String s2) {
        int res = 0;
        int m = s1.length(), n = s2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = Math.max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }

    public static int LCS_Tabulation_SpaceOptimized(String s1, String s2) {
        int res = 0;
        int n = s1.length(), m = s2.length();
        int[] prev = new int[m + 1];
        int[] cur = new int[m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    cur[j] = prev[j - 1] + 1;
                    res = Math.max(res, cur[j]);
                } else {
                    cur[j] = 0;
                }
            }
            prev = Arrays.copyOf(cur, cur.length);
        }
        return res;
    }

    public static String LCS_Tabulation_Print(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] dp = new int[m + 1][n + 1];
        int maxLen = 0, endIndex = -1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endIndex = i - 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        String lcs = "";
        if (maxLen > 0) 
            lcs = s1.substring(endIndex - maxLen + 1, endIndex + 1);

        System.out.println("Longest Common Substring: " + lcs + " || and length is: " + maxLen);

        return lcs;
    }

    public static String LCS_Tabulation_SpaceOptimized_Print(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[] prev = new int[m + 1];
        int[] cur = new int[m + 1];
        int maxLen = 0, endIndex = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    cur[j] = prev[j - 1] + 1;
                    if (cur[j] > maxLen) {
                        maxLen = cur[j];
                        endIndex = i - 1;
                    }
                } else {
                    cur[j] = 0;
                }
            }
            prev = Arrays.copyOf(cur, cur.length);
        }

        String lcs = "";
        if (maxLen > 0) 
            lcs = s1.substring(endIndex - maxLen + 1, endIndex + 1);

        System.out.println("Longest Common Substring: " + lcs + " || and length is: " + maxLen);

        return lcs;
    }

    public static void main(String[] args) {
        String s1 = "geeksforgeeks";
        String s2 = "practicewritegeekscourses";

        System.out.println("Longest Common Substring Iterative: " + LCS_Iterative(s1, s2));
        System.out.println("Longest Common Substring Recursion: " + LCS_Recursion(s1, s2));
        System.out.println("Longest Common Substring Tabulation: " + LCS_Tabulation(s1, s2));
        System.out.println("Longest Common Substring Tabulation_SpaceOptimized: " + LCS_Tabulation_SpaceOptimized(s1, s2));

        LCS_Tabulation_Print(s1, s2);
        LCS_Tabulation_SpaceOptimized_Print(s1, s2);
    }
}
