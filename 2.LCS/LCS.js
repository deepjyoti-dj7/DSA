// 1. Brute Force Recursive Approach
function LCS(s1, s2, i, j) {
  if (i < 0 || j < 0) {
    return 0;
  }

  if (s1[i] === s2[j]) {
    return 1 + LCS(s1, s2, i - 1, j - 1);
  } else {
    return Math.max(LCS(s1, s2, i - 1, j), LCS(s1, s2, i, j - 1));
  }
}

// 2. Memoization Approach
function LCSMemoization(s1, s2, i, j, dp) {
  if (i < 0 || j < 0) {
    return 0;
  }

  if (dp[i][j] !== -1) {
    return dp[i][j];
  }

  if (s1[i] === s2[j]) {
    dp[i][j] = 1 + LCSMemoization(s1, s2, i - 1, j - 1, dp);
  } else {
    dp[i][j] = Math.max(
      LCSMemoization(s1, s2, i - 1, j, dp),
      LCSMemoization(s1, s2, i, j - 1, dp)
    );
  }

  return dp[i][j];
}

// 3. Tabulation Approach
function LCSTabulation(s1, s2) {
  const n = s1.length;
  const m = s2.length;
  const dp = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

// 4. Space Optimized Tabulation Approach
function LCSTabulationSpaceOptimized(s1, s2) {
  const n = s1.length;
  const m = s2.length;
  let prev = Array(m + 1).fill(0);
  let cur = Array(m + 1).fill(0);

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        cur[j] = 1 + prev[j - 1];
      } else {
        cur[j] = Math.max(prev[j], cur[j - 1]);
      }
    }
    prev = [...cur];
  }

  return prev[m];
}

function printLCS(s1, s2) {
  const n = s1.length;
  const m = s2.length;
  const dp = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  let lcs = [];
  let i = n;
  let j = m;

  while (i > 0 && j > 0) {
    if (s1[i - 1] === s2[j - 1]) {
      lcs.push(s1[i - 1]);
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  return lcs.reverse().join("");
}

// Main Function
const s1 = "abcde";
const s2 = "ace";

// 1. Brute Force Recursive
console.log(
  "Length of LCS (Brute Force):",
  LCS(s1, s2, s1.length - 1, s2.length - 1)
);

// 2. Memoization
const dp = Array.from({ length: s1.length }, () => Array(s2.length).fill(-1));
console.log(
  "Length of LCS (Memoization):",
  LCSMemoization(s1, s2, s1.length - 1, s2.length - 1, dp)
);

// 3. Tabulation
console.log("Length of LCS (Tabulation):", LCSTabulation(s1, s2));

// 4. Space Optimized Tabulation
console.log(
  "Length of LCS (Tabulation Space Optimized):",
  LCSTabulationSpaceOptimized(s1, s2)
);

console.log("The LCS is:", printLCS(s1, s2));
