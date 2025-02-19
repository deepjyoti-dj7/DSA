function longestOnes(nums, k) {
    let left = 0, maxLength = 0, zeroCount = 0;

    for (let right = 0; right < nums.length; right++) {
        if (nums[right] === 0) zeroCount++;

        while (zeroCount > k) {
            if (nums[left] === 0) zeroCount--;
            left++;
        }

        maxLength = Math.max(maxLength, right - left + 1);
    }

    return maxLength;
}

// Main function
function main() {
    let nums = [1, 1, 0, 0, 1, 1, 1, 0, 1, 1];
    let k = 2;

    console.log("Maximum consecutive ones (with at most " + k + " flips):", longestOnes(nums, k));
}

// Run main function
main();
