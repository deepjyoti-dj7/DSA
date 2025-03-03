function canJump(nums) {
    let maxReach = 0;

    for (let i = 0; i < nums.length; i++) {
        if (i > maxReach) return false; // If we can't reach this index, return false
        maxReach = Math.max(maxReach, i + nums[i]); // Update farthest reach
        if (maxReach >= nums.length - 1) return true; // Early exit if we can reach the last index
    }

    return false;
}

// Main function
function main() {
    console.log(canJump([2, 3, 1, 1, 4])); // Expected Output: true
    console.log(canJump([3, 2, 1, 0, 4])); // Expected Output: false
}

// Run the main function
main();
