#include <iostream>
#include <vector>
using namespace std;

// 1. Brute force
int climbBrute(int n) {
    if (n <= 1) return 1;
    return climbBrute(n - 1) + climbBrute(n - 2);
}

// 2. Memoization
int climbMemo(int n, vector<int>& memo) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = climbMemo(n - 1, memo) + climbMemo(n - 2, memo);
}

// 3. Tabulation
int climbTab(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// 4. Space optimized
int climbOpt(int n) {
    if (n <= 1) return 1;
    int a = 1, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    int n = 5;
    vector<int> memo(n + 1, -1);

    cout << "Brute: " << climbBrute(n) << endl;
    cout << "Memo: " << climbMemo(n, memo) << endl;
    cout << "Tabulation: " << climbTab(n) << endl;
    cout << "Optimized: " << climbOpt(n) << endl;

    return 0;
}
