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

function LIS_Tabulation_SpaceOptimized1(arr) {
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

function LIS_Tabulation_SpaceOptimized2(arr) {
  const n = arr.length;
  let maxi = 1;
  let dp = new Array(n).fill(1);
  for (let i = 0; i < n; i++) {
    for (let prev = 0; prev < i; prev++) {
      if (arr[prev] < arr[i]) {
        dp[i] = Math.max(dp[i], 1 + dp[prev]);
      }
    }
    maxi = Math.max(maxi, dp[i]);
  }
  return maxi;
}

function LIS_Print(arr) {
  const n = arr.length;
  const dp = new Array(n).fill(1);
  const hash = new Array(n);
  let maxi = 1;
  let lastIndex = 0;

  for (let i = 0; i < n; i++) {
    hash[i] = i;
    for (let prev = 0; prev < i; prev++) {
      if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
        dp[i] = 1 + dp[prev];
        hash[i] = prev;
      }
    }
    if (dp[i] > maxi) {
      maxi = dp[i];
      lastIndex = i;
    }
  }

  const temp = [];
  temp.push(arr[lastIndex]);

  while (hash[lastIndex] !== lastIndex) {
    lastIndex = hash[lastIndex];
    temp.push(arr[lastIndex]);
  }

  temp.reverse();

  console.log("LIS elements:", temp.join(" "));
  console.log("Length of LIS is:", maxi);
}

function LIS_binary_search(arr) {
  const n = arr.length;
  const res = [];
  res.push(arr[0]);
  for (let i = 1; i < n; i++) {
    if (arr[i] > res[res.length - 1]) res.push(arr[i]);
    else {
      const ind = lowerBound(res, arr[i]);
      res[ind] = arr[i];
    }
  }
  return res.length;
}

function lowerBound(arr, key) {
  let left = 0;
  let right = arr.length - 1;
  while (left <= right) {
    const mid = Math.floor(left + (right - left) / 2);
    if (arr[mid] < key) left = mid + 1;
    else right = mid - 1;
  }
  return left;
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
  "Length of LIS (Space Optimized 1):",
  LIS_Tabulation_SpaceOptimized1(arr)
);

console.log(
  "Length of LIS (Space Optimized 2):",
  LIS_Tabulation_SpaceOptimized2(arr)
);

LIS_Print(arr);

console.log("Length of LIS:", LIS_binary_search(arr));
