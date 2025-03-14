#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

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
    return -1; // Target not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Index of target: " << search(nums, target) << endl;
    return 0;
}
