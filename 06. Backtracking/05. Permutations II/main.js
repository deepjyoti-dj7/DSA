function backtrack(nums, used, current, result) {
    if (current.length === nums.length) {
        result.push([...current]);
        return;
    }

    for (let i = 0; i < nums.length; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] === nums[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        current.push(nums[i]);
        backtrack(nums, used, current, result);
        current.pop();
        used[i] = false;
    }
}

function permuteUnique(nums) {
    const result = [];
    nums.sort((a, b) => a - b);
    backtrack(nums, Array(nums.length).fill(false), [], result);
    return result;
}

// Main function
function main() {
    const nums = [1, 1, 2];
    console.log("Unique Permutations:");
    console.log(permuteUnique(nums));
}

main();
