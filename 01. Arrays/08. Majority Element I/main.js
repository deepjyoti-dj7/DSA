// Brute Force
function majorityElementBruteForce(nums) {
    for (let num of nums) {
        let count = nums.filter(x => x === num).length;
        if (count > nums.length / 2) return num;
    }
    return -1;
}

// Sorting
function majorityElementSorting(nums) {
    nums.sort((a, b) => a - b);
    return nums[Math.floor(nums.length / 2)];
}

// HashMap
function majorityElementHashMap(nums) {
    let freq = {};
    for (let num of nums) freq[num] = (freq[num] || 0) + 1;
    for (let key in freq) {
        if (freq[key] > nums.length / 2) return parseInt(key);
    }
    return -1;
}

// Boyer-Moore Voting Algorithm (Optimal)
function majorityElementBoyerMoore(nums) {
    let candidate = 0, count = 0;
    for (let num of nums) {
        if (count === 0) candidate = num;
        count += (num === candidate) ? 1 : -1;
    }
    return candidate;
}

// Main Function
let nums = [3, 2, 3];
console.log("Brute Force:", majorityElementBruteForce(nums));
console.log("Sorting:", majorityElementSorting(nums));
console.log("HashMap:", majorityElementHashMap(nums));
console.log("Boyer-Moore:", majorityElementBoyerMoore(nums));
