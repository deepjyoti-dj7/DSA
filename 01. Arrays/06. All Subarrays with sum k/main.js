// 🔹 Brute Force (O(N²))
function subarraySumBrute(nums, k) {
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        let sum = 0;
        for (let j = i; j < nums.length; j++) {
            sum += nums[j];
            if (sum === k) count++;
        }
    }
    return count;
}

// 🔹 Optimized (O(N)) - Prefix Sum + HashMap
function subarraySumOptimized(nums, k) {
    let prefixSumCount = new Map();
    prefixSumCount.set(0, 1);

    let count = 0, prefixSum = 0;
    for (let num of nums) {
        prefixSum += num;
        if (prefixSumCount.has(prefixSum - k)) {
            count += prefixSumCount.get(prefixSum - k);
        }
        prefixSumCount.set(prefixSum, (prefixSumCount.get(prefixSum) || 0) + 1);
    }
    return count;
}

// Main function
function main() {
    let nums = [1, 2, 3, 4, 2, -1, 2];
    let k = 5;

    console.log("Brute Force:", subarraySumBrute(nums, k));
    console.log("Optimized:", subarraySumOptimized(nums, k));
}

main();
