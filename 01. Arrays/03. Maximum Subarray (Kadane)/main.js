function maxSubArray(nums) {
    let maxSum = nums[0], currSum = 0;
    for (let num of nums) {
        currSum = Math.max(num, currSum + num);
        maxSum = Math.max(maxSum, currSum);
    }
    return maxSum;
}

// Example usage
const nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
console.log("Maximum Subarray Sum:", maxSubArray(nums));
