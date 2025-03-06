function previousGreaterElement(nums) {
    let stack = [];
    let result = new Array(nums.length).fill(-1);

    for (let i = 0; i < nums.length; i++) {
        while (stack.length > 0 && stack[stack.length - 1] <= nums[i]) {
            stack.pop();
        }
        if (stack.length > 0) {
            result[i] = stack[stack.length - 1];
        }
        stack.push(nums[i]);
    }
    
    return result;
}

// Test
const nums = [4, 5, 2, 10, 8];
console.log("Previous Greater Elements:");
console.log(previousGreaterElement(nums).join(" "));
