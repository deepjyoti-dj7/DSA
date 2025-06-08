// 1. Brute Force
function climbBrute(n) {
    if (n <= 1) return 1;
    return climbBrute(n - 1) + climbBrute(n - 2);
}

// 2. Memoization
function climbMemo(n, memo = {}) {
    if (n <= 1) return 1;
    if (memo[n] !== undefined) return memo[n];
    return memo[n] = climbMemo(n - 1, memo) + climbMemo(n - 2, memo);
}

// 3. Tabulation
function climbTab(n) {
    if (n <= 1) return 1;
    const dp = Array(n + 1).fill(0);
    dp[0] = dp[1] = 1;
    for (let i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 4. Optimized
function climbOpt(n) {
    if (n <= 1) return 1;
    let a = 1, b = 1;
    for (let i = 2; i <= n; i++) {
        [a, b] = [b, a + b];
    }
    return b;
}

// Main function
function main() {
    const n = 5;
    console.log("Brute:", climbBrute(n));
    console.log("Memo:", climbMemo(n));
    console.log("Tabulation:", climbTab(n));
    console.log("Optimized:", climbOpt(n));
}

main();
