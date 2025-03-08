function kadane(nums) {
    let maxSum = nums[0], currentSum = nums[0];
    for (let i = 1; i < nums.length; i++) {
        currentSum = Math.max(nums[i], currentSum + nums[i]);
        maxSum = Math.max(maxSum, currentSum);
    }
    return maxSum;
}

function maxCircularSubarraySum(nums) {
    let maxKadane = kadane(nums);
    let totalSum = 0, minSum = nums[0], currentMin = nums[0];

    for (let i = 0; i < nums.length; i++) {
        totalSum += nums[i];
        if (i > 0) {
            currentMin = Math.min(nums[i], currentMin + nums[i]);
            minSum = Math.min(minSum, currentMin);
        }
    }

    return totalSum === minSum ? maxKadane : Math.max(maxKadane, totalSum - minSum);
}

function main() {
    const nums = [5, -3, 5];
    console.log("Maximum Circular Subarray Sum:", maxCircularSubarraySum(nums));
}

main();
