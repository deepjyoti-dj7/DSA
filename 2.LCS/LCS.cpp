#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force Recursive
int LCS(string s1, string s2, int i, int j) {
    if (i < 0 || j < 0)
        return 0;

    if (s1[i] == s2[j])
        return 1 + LCS(s1, s2, i - 1, j - 1);
    else
        return max(LCS(s1, s2, i - 1, j), LCS(s1, s2, i, j - 1));
}

// 2. Memoization
int LCS_Memoization(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return 1 + LCS_Memoization(s1, s2, i - 1, j - 1, dp);
    else
        return max(LCS_Memoization(s1, s2, i - 1, j, dp), LCS_Memoization(s1, s2, i, j - 1, dp));
}

// 3. Tabulation
int LCS_Tabulation(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1  ; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// 4. Space Optimized Tabulation
int LCS_Tabulation_SpaceOptimized(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<int> prev(n), cur(n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1  ; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

int main() {
    string s1 = "abcde", s2 = "ace";
    // 1. Brute Force Recursive
    cout << "Length of LCS (Brute Force): " << LCS(s1, s2, s1.size() - 1, s2.size() - 1) << endl;

    // 2. Memoization
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    cout << "Length of LCS (Memoization): " << LCS_Memoization(s1, s2, s1.size() - 1, s2.size() - 1, dp) << endl;

    // 3. Tabulation
    cout << "Length of LCS (Tabulation): " << LCS_Tabulation(s1, s2) << endl;

    // 4. Space Optimized Tabulation
    cout << "Length of LCS (Tabulation Space Optimized): " << LCS_Tabulation_SpaceOptimized(s1, s2) << endl;

    return 0;
}