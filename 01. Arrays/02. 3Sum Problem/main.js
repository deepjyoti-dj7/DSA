// Brute Force O(N^3)
function threeSumBruteForce(nums) {
    const uniqueTriplets = new Set();
    const n = nums.length;

    for (let i = 0; i < n - 2; i++) {
        for (let j = i + 1; j < n - 1; j++) {
            for (let k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] === 0) {
                    let triplet = [nums[i], nums[j], nums[k]].sort((a, b) => a - b);
                    uniqueTriplets.add(triplet.toString());
                }
            }
        }
    }

    return Array.from(uniqueTriplets).map(str => str.split(',').map(Number));
}

// Optimized Two Pointers O(N^2)
function threeSumOptimized(nums) {
    nums.sort((a, b) => a - b);
    const result = [];

    for (let i = 0; i < nums.length - 2; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;

        let left = i + 1;
        let right = nums.length - 1;

        while (left < right) {
            const sum = nums[i] + nums[left] + nums[right];
            if (sum === 0) {
                result.push([nums[i], nums[left], nums[right]]);
                while (left < right && nums[left] === nums[left + 1]) left++;
                while (left < right && nums[right] === nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

function printTriplets(triplets) {
    triplets.forEach(t => console.log(t));
}

// Main function
function main() {
    const nums = [-1, 0, 1, 2, -1, -4];

    console.log("Brute Force Approach results:");
    const brute = threeSumBruteForce(nums);
    printTriplets(brute);

    console.log("\nOptimized Two Pointers Approach results:");
    const optimized = threeSumOptimized(nums);
    printTriplets(optimized);
}

// Run the main function
main();
