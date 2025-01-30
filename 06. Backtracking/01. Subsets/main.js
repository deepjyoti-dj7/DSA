function generateSubsets(index, nums, current, result) {
    if (index === nums.length) {
        result.push([...current]);
        return;
    }

    // Exclude the current element
    generateSubsets(index + 1, nums, current, result);

    // Include the current element
    current.push(nums[index]);
    generateSubsets(index + 1, nums, current, result);
    current.pop(); // Backtrack
}

function subsets(nums) {
    let result = [];
    generateSubsets(0, nums, [], result);
    return result;
}


function main() {
    let nums = [1, 2, 3];
    console.log("Subsets using Backtracking:");
    console.log(subsets(nums));    
}

main();