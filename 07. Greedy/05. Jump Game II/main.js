function jump(nums) {
    let jumps = 0, farthest = 0, currentEnd = 0;

    for (let i = 0; i < nums.length - 1; i++) {
        farthest = Math.max(farthest, i + nums[i]); // Update farthest reachable index

        if (i === currentEnd) { // If we reach the end of the current jump
            jumps++;
            currentEnd = farthest; // Move to the farthest reachable index
        }
    }

    return jumps;
}

// Main function
function main() {
    console.log("Minimum jumps:", jump([2, 3, 1, 1, 4])); // Expected Output: 2
    console.log("Minimum jumps:", jump([1, 1, 1, 1])); // Expected Output: 3
}

// Run the main function
main();
