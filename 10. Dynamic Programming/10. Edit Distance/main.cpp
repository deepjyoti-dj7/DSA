#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Brute Force (Recursion)
int editDistanceBrute(string s1, string s2, int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;

    if (s1[i - 1] == s2[j - 1])
        return editDistanceBrute(s1, s2, i - 1, j - 1);

    return 1 + min({
        editDistanceBrute(s1, s2, i - 1, j),   // delete
        editDistanceBrute(s1, s2, i, j - 1),   // insert
        editDistanceBrute(s1, s2, i - 1, j - 1)  // replace
    });
}

// 2. Memoization (Top-down DP with vector)
int editDistanceMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i == 0) return j;
    if (j == 0) return i;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = editDistanceMemo(s1, s2, i - 1, j - 1, dp);

    return dp[i][j] = 1 + min({
        editDistanceMemo(s1, s2, i - 1, j, dp),
        editDistanceMemo(s1, s2, i, j - 1, dp),
        editDistanceMemo(s1, s2, i - 1, j - 1, dp)
    });
}

// 3. Tabulation (Bottom-up DP)
int editDistanceTab(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
        }
    }

    return dp[n][m];
}

// 4. Space Optimized DP (Only 2 Rows)
int editDistanceSpaceOpt(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<int> prev(m+1), curr(m+1);

    for (int j = 0; j <= m; j++) prev[j] = j;

    for (int i = 1; i <= n; i++) {
        curr[0] = i;
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min({ prev[j], curr[j - 1], prev[j - 1] });
        }
        prev = curr;
    }

    return prev[m];
}

int main() {
    string s1 = "horse", s2 = "ros";

    cout << "Brute Force: " << editDistanceBrute(s1, s2, s1.length(), s2.length()) << endl;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    cout << "Memoization: " << editDistanceMemo(s1, s2, s1.length(), s2.length(), dp) << endl;

    cout << "Tabulation: " << editDistanceTab(s1, s2) << endl;

    cout << "Space Optimized: " << editDistanceSpaceOpt(s1, s2) << endl;

    return 0;
}
