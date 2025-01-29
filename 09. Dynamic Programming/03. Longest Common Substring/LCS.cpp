#include <bits/stdc++.h>
using namespace std;

int LCS_Iterative(string & s1, string& s2) {
    int res = 0;
    int n = s1.length(), m = s2.length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int curr = 0;
            while ((i + curr) < n && (j + curr) < m && s1[i + curr] == s2[j + curr]) 
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int LCS_Solve(const string& s1, const string& s2, int n, int m) {
    if (n == 0 || m == 0 || s1[n - 1] != s2[m - 1])
        return 0;
    return 1 + LCS_Solve(s1, s2, n - 1, m - 1);
}

int LCS_Recursion(const string& s1, const string& s2) {
    int res = 0;
    for (int i = 1; i <= s1.size(); i++) 
        for (int j = 1; j <= s2.size(); j++) 
            res = max(res, LCS_Solve(s1, s2, i, j));
    return res;
}

int LCS_Tabulation(const string& s1, const string& s2) {
    int res = 0;
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
            else 
                dp[i][j] = 0;
        }
    }
    return res;
}

int LCS_Tabulation_SpaceOptimized(const string& s1, const string& s2) {
    int res = 0;
    int n = s1.length(), m = s2.length();
    vector<int> prev(n + 1, 0), cur(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = prev[j - 1] + 1;
                res = max(res, cur[j]);
            }
            else 
                cur[j] = 0;
        }
        prev = cur;
    }
    return res;
}

string LCS_Tabulation_Print(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0, endIndex = -1; 

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1; 
                }
            } 
            else 
                dp[i][j] = 0; 
        }
    }

    string lcs = "";
    if (maxLen > 0) 
        lcs = s1.substr(endIndex - maxLen + 1, maxLen);

    cout << "Longest Common Substring: " << lcs << " || and length is: " << maxLen << endl;

    return lcs;
}

string LCS_Tabulation_SpaceOptimized_Print(const string& s1, const string& s2) {
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int maxLen = 0, endIndex = -1; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = prev[j - 1] + 1;
                if (cur[j] > maxLen) {
                    maxLen = cur[j];
                    endIndex = i - 1; 
                }
            } 
            else 
                cur[j] = 0; 
        }
        prev = cur;
    }

    string lcs = "";
    if (maxLen > 0) 
        lcs = s1.substr(endIndex - maxLen + 1, maxLen);

    cout << "Longest Common Substring: " << lcs << " || and length is: " << maxLen << endl;

    return lcs;
}


int main() {
    string s1 = "geeksforgeeks";
    string s2 = "practicewritegeekscourses";
    
    cout << "Longest Common Substring Iterative: " << LCS_Iterative(s1, s2) << endl;
    cout << "Longest Common Substring Recursion: " << LCS_Recursion(s1, s2) << endl;
    cout << "Longest Common Substring Tabulation: " << LCS_Tabulation(s1, s2) << endl;
    cout << "Longest Common Substring Tabulation_SpaceOptimized: " << LCS_Tabulation_SpaceOptimized(s1, s2) << endl;

    LCS_Tabulation_Print(s1, s2);
    LCS_Tabulation_SpaceOptimized_Print(s1, s2);

    return 0;
}