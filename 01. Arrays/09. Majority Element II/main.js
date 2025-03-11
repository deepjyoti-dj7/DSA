// Brute Force Approach - O(n²) Time, O(1) Space
function majorityElementBruteForce(nums) {
    let result = [];
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        let count = nums.filter(x => x === nums[i]).length;
        if (count > Math.floor(n / 3) && !result.includes(nums[i])) result.push(nums[i]);
    }
    return result;
}

// Sorting Approach - O(n log n) Time, O(1) Space
function majorityElementSorting(nums) {
    nums.sort((a, b) => a - b);
    let result = [], n = nums.length;
    for (let i = 0; i < n;) {
        let count = 0, num = nums[i];
        while (i < n && nums[i] === num) { count++; i++; }
        if (count > Math.floor(n / 3)) result.push(num);
    }
    return result;
}

// HashMap Approach - O(n) Time, O(n) Space
function majorityElementHashMap(nums) {
    let freq = {};
    for (let num of nums) freq[num] = (freq[num] || 0) + 1;
    return Object.keys(freq).filter(key => freq[key] > Math.floor(nums.length / 3)).map(Number);
}

// Boyer-Moore Voting Algorithm - O(n) Time, O(1) Space
function majorityElementBoyerMoore(nums) {
    let candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    for (let num of nums) {
        if (num === candidate1) count1++;
        else if (num === candidate2) count2++;
        else if (count1 === 0) { candidate1 = num; count1 = 1; }
        else if (count2 === 0) { candidate2 = num; count2 = 1; }
        else { count1--; count2--; }
    }
    count1 = count2 = 0;
    for (let num of nums) {
        if (num === candidate1) count1++;
        else if (num === candidate2) count2++;
    }
    let result = [];
    let n = nums.length;
    if (count1 > Math.floor(n / 3)) result.push(candidate1);
    if (count2 > Math.floor(n / 3)) result.push(candidate2);
    return result;
}

// Main Function
function main() {
    let nums = [3, 2, 3, 1, 1, 1, 2, 2];
    console.log("Brute Force:", majorityElementBruteForce(nums));
    console.log("Sorting:", majorityElementSorting(nums));
    console.log("HashMap:", majorityElementHashMap(nums));
    console.log("Boyer-Moore:", majorityElementBoyerMoore(nums));
}

main();
