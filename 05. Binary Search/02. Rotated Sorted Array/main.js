function search(nums, target) {
    let left = 0, right = nums.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (nums[mid] === target) return mid;

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
    }
    return -1;
}

// Main function
function main() {
    let nums = [4, 5, 6, 7, 0, 1, 2];
    let target = 0;
    console.log("Index of target:", search(nums, target));
}

// Run main function
main();
