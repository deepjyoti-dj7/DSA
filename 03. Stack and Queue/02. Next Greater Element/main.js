function nextGreaterElement(nums) {
    let stack = [];
    let result = new Array(nums.length).fill(-1);

    for (let i = 0; i < nums.length; i++) {
        while (stack.length > 0 && nums[stack[stack.length - 1]] < nums[i]) {
            result[stack.pop()] = nums[i];
        }
        stack.push(i);
    }

    return result;
}

// Main function
function main() {
    let nums = [4, 5, 2, 10, 8];
    let result = nextGreaterElement(nums);

    console.log("Next Greater Elements:");
    console.log(result);
}

// Run the main function
main();
