// Brute Force - O(N^2)
function twoSumBruteForce(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [nums[i], nums[j]];
            }
        }
    }
    return [-1, -1];
}

// Sorting + Two Pointers - O(N log N)
function twoSumSorting(nums, target) {
    let sortedNums = [...nums].sort((a, b) => a - b);
    let left = 0, right = nums.length - 1;

    while (left < right) {
        let sum = sortedNums[left] + sortedNums[right];
        if (sum === target) {
            return [sortedNums[left], sortedNums[right]];
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return [-1, -1];
}

// Hashing (Optimal) - O(N)
function twoSumHashing(nums, target) {
    let map = new Map();
    for (let num of nums) {
        let complement = target - num;
        if (map.has(complement)) {
            return [complement, num];
        }
        map.set(num, true);
    }
    return [-1, -1];
}


function main() {
    // Test case
    let nums = [2, 7, 11, 15];
    let target = 9;
    
    console.log("Brute Force:", twoSumBruteForce(nums, target));
    console.log("Sorting + Two Pointers:", twoSumSorting(nums, target));
    console.log("Hashing:", twoSumHashing(nums, target));
}

main();