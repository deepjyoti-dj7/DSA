function previousGreaterElementCircular(nums) {
    let n = nums.length;
    let result = new Array(n).fill(-1);
    let stack = [];

    // Traverse twice in reverse order to simulate circular array
    for (let i = 2 * n - 1; i >= 0; i--) {
        while (stack.length > 0 && stack[stack.length - 1] <= nums[i % n]) {
            stack.pop();
        }
        if (i < n) {
            if (stack.length > 0) {
                result[i] = stack[stack.length - 1];
            }
            stack.push(nums[i]);
        }
    }

    return result;
}

// Main function
(function main() {
    let nums = [4, 5, 2, 10, 8];
    let result = previousGreaterElementCircular(nums);

    console.log("Previous Greater Elements (Circular):");
    console.log(result);
})();
