function LIS_Recursive(arr, ind, prev) {
  if (ind === arr.length) return 0;

  let notTake = LIS_Recursive(arr, ind + 1, prev);
  let take = 0;
  if (prev === -1 || arr[prev] < arr[ind]) {
    take = 1 + LIS_Recursive(arr, ind + 1, ind);
  }

  return Math.max(take, notTake);
}

function LIS_Memoization(arr, ind, prev, dp) {
  if (ind === arr.length) return 0;

  if (dp[ind][prev + 1] !== -1) return dp[ind][prev + 1];

  let notTake = LIS_Memoization(arr, ind + 1, prev, dp);
  let take = 0;
  if (prev === -1 || arr[prev] < arr[ind]) {
    take = 1 + LIS_Memoization(arr, ind + 1, ind, dp);
  }

  dp[ind][prev + 1] = Math.max(take, notTake);
  return dp[ind][prev + 1];
}

function LIS_Tabulation(arr) {
  const n = arr.length;
  const dp = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));

  for (let ind = n - 1; ind >= 0; ind--) {
    for (let prev = ind - 1; prev >= -1; prev--) {
      let notTake = dp[ind + 1][prev + 1];
      let take = 0;
      if (prev === -1 || arr[prev] < arr[ind]) {
        take = 1 + dp[ind + 1][ind + 1];
      }
      dp[ind][prev + 1] = Math.max(take, notTake);
    }
  }

  return dp[0][0];
}

function LIS_Tabulation_SpaceOptimized(arr) {
  const n = arr.length;
  let cur = new Array(n + 1).fill(0);
  let next = new Array(n + 1).fill(0);

  for (let ind = n - 1; ind >= 0; ind--) {
    for (let prev = ind - 1; prev >= -1; prev--) {
      let notTake = next[prev + 1];
      let take = 0;
      if (prev === -1 || arr[prev] < arr[ind]) {
        take = 1 + next[ind + 1];
      }
      cur[prev + 1] = Math.max(take, notTake);
    }
    next = [...cur];
  }

  return next[0];
}

// Example Usage
const arr = [1, 2, 3, 5, 6, 0, 1];
console.log("Length of LIS (Recursive):", LIS_Recursive(arr, 0, -1));

// Memoization
const n = arr.length;
const dp = Array.from({ length: n }, () => Array(n + 1).fill(-1));
console.log("Length of LIS (Memoization):", LIS_Memoization(arr, 0, -1, dp));

// Tabulation
console.log("Length of LIS (Tabulation):", LIS_Tabulation(arr));

// Tabulation with Space Optimization
console.log(
  "Length of LIS (Space Optimized):",
  LIS_Tabulation_SpaceOptimized(arr)
);
