// JavaScript implementation of Longest Common Substring

function LCS_Iterative(s1, s2) {
  let res = 0;
  let n = s1.length,
    m = s2.length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      let curr = 0;
      while (i + curr < n && j + curr < m && s1[i + curr] === s2[j + curr])
        curr++;
      res = Math.max(res, curr);
    }
  }
  return res;
}

function LCS_Solve(s1, s2, n, m) {
  if (n === 0 || m === 0 || s1[n - 1] !== s2[m - 1]) return 0;
  return 1 + LCS_Solve(s1, s2, n - 1, m - 1);
}

function LCS_Recursion(s1, s2) {
  let res = 0;
  for (let i = 1; i <= s1.length; i++)
    for (let j = 1; j <= s2.length; j++)
      res = Math.max(res, LCS_Solve(s1, s2, i, j));
  return res;
}

function LCS_Tabulation(s1, s2) {
  let res = 0;
  let m = s1.length,
    n = s2.length;
  let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        res = Math.max(res, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return res;
}

function LCS_Tabulation_SpaceOptimized(s1, s2) {
  let res = 0;
  let n = s1.length,
    m = s2.length;
  let prev = Array(m + 1).fill(0);
  let cur = Array(m + 1).fill(0);

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        cur[j] = prev[j - 1] + 1;
        res = Math.max(res, cur[j]);
      } else {
        cur[j] = 0;
      }
    }
    prev = [...cur];
  }
  return res;
}

function LCS_Tabulation_Print(s1, s2) {
  let m = s1.length,
    n = s2.length;
  let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
  let maxLen = 0,
    endIndex = -1;

  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (s1[i - 1] === s2[j - 1]) {
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

  let lcs = "";
  if (maxLen > 0) lcs = s1.substring(endIndex - maxLen + 1, endIndex + 1);

  console.log(
    "Longest Common Substring: " + lcs + " || and length is: " + maxLen
  );

  return lcs;
}

function LCS_Tabulation_SpaceOptimized_Print(s1, s2) {
  let n = s1.length,
    m = s2.length;
  let prev = Array(m + 1).fill(0);
  let cur = Array(m + 1).fill(0);
  let maxLen = 0,
    endIndex = -1;

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        cur[j] = prev[j - 1] + 1;
        if (cur[j] > maxLen) {
          maxLen = cur[j];
          endIndex = i - 1;
        }
      } else {
        cur[j] = 0;
      }
    }
    prev = [...cur];
  }

  let lcs = "";
  if (maxLen > 0) lcs = s1.substring(endIndex - maxLen + 1, endIndex + 1);

  console.log(
    "Longest Common Substring: " + lcs + " || and length is: " + maxLen
  );

  return lcs;
}

// Main function to test the implementation
(function main() {
  let s1 = "geeksforgeeks";
  let s2 = "practicewritegeekscourses";

  console.log("Longest Common Substring Iterative: " + LCS_Iterative(s1, s2));
  console.log("Longest Common Substring Recursion: " + LCS_Recursion(s1, s2));
  console.log("Longest Common Substring Tabulation: " + LCS_Tabulation(s1, s2));
  console.log(
    "Longest Common Substring Tabulation_SpaceOptimized: " +
      LCS_Tabulation_SpaceOptimized(s1, s2)
  );

  LCS_Tabulation_Print(s1, s2);
  LCS_Tabulation_SpaceOptimized_Print(s1, s2);
})();
