function nextGreaterElementCircular(nums) {
    let n = nums.length;
    let result = new Array(n).fill(-1);
    let stack = [];

    for (let i = 0; i < 2 * n; i++) {
        while (stack.length > 0 && nums[stack[stack.length - 1]] < nums[i % n]) {
            result[stack.pop()] = nums[i % n];
        }
        if (i < n) stack.push(i);
    }

    return result;
}

// Main function
(function main() {
    let nums = [4, 5, 2, 10, 8];
    let result = nextGreaterElementCircular(nums);

    console.log("Next Greater Elements (Circular):");
    console.log(result);
})();
