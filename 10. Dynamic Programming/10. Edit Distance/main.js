// 1. Brute Force (Recursion)
function editDistanceBrute(s1, s2, i, j) {
    if (i === 0) return j;
    if (j === 0) return i;

    if (s1[i - 1] === s2[j - 1])
        return editDistanceBrute(s1, s2, i - 1, j - 1);

    return 1 + Math.min(
        editDistanceBrute(s1, s2, i - 1, j),    // delete
        editDistanceBrute(s1, s2, i, j - 1),    // insert
        editDistanceBrute(s1, s2, i - 1, j - 1) // replace
    );
}

// 2. Memoization (Top-down DP)
function editDistanceMemo(s1, s2) {
    const n = s1.length, m = s2.length;
    const dp = Array.from({ length: n + 1 }, () => Array(m + 1).fill(-1));

    function helper(i, j) {
        if (i === 0) return j;
        if (j === 0) return i;
        if (dp[i][j] !== -1) return dp[i][j];

        if (s1[i - 1] === s2[j - 1])
            return dp[i][j] = helper(i - 1, j - 1);

        return dp[i][j] = 1 + Math.min(
            helper(i - 1, j),
            helper(i, j - 1),
            helper(i - 1, j - 1)
        );
    }

    return helper(n, m);
}

// 3. Tabulation (Bottom-up DP)
function editDistanceTab(s1, s2) {
    const n = s1.length, m = s2.length;
    const dp = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));

    for (let i = 0; i <= n; i++) dp[i][0] = i;
    for (let j = 0; j <= m; j++) dp[0][j] = j;

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + Math.min(
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                );
            }
        }
    }

    return dp[n][m];
}

// 4. Space Optimized DP (2 rows)
function editDistanceSpaceOpt(s1, s2) {
    const n = s1.length, m = s2.length;
    let prev = Array(m + 1).fill(0);
    let curr = Array(m + 1).fill(0);

    for (let j = 0; j <= m; j++) prev[j] = j;

    for (let i = 1; i <= n; i++) {
        curr[0] = i;
        for (let j = 1; j <= m; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = 1 + Math.min(
                    prev[j],
                    curr[j - 1],
                    prev[j - 1]
                );
            }
        }
        prev = [...curr];
    }

    return prev[m];
}

// Main function to test all
function main() {
    const s1 = "horse", s2 = "ros";

    console.log("Brute Force:", editDistanceBrute(s1, s2, s1.length, s2.length));
    console.log("Memoization:", editDistanceMemo(s1, s2));
    console.log("Tabulation:", editDistanceTab(s1, s2));
    console.log("Space Optimized:", editDistanceSpaceOpt(s1, s2));
};

main();
