function backtrack(nums, used, current, result) {
    if (current.length === nums.length) {
        result.push([...current]);
        return;
    }
    
    for (let i = 0; i < nums.length; i++) {
        if (used[i]) continue;
        
        used[i] = true;
        current.push(nums[i]);
        backtrack(nums, used, current, result);
        current.pop();
        used[i] = false;
    }
}

function permute(nums) {
    const result = [];
    backtrack(nums, Array(nums.length).fill(false), [], result);
    return result;
}

function main() {
    const nums = [1, 2, 3];
    console.log("Permutations:", permute(nums));
}

// Run the main function
main();
