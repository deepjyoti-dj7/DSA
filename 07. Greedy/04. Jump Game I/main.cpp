#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false; // If we can't reach this index, return false
        maxReach = max(maxReach, i + nums[i]); // Update the farthest reachable index
        if (maxReach >= nums.size() - 1) return true; // Early exit if we can reach the last index
    }

    return false;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4}; // Expected Output: true
    cout << (canJump(nums) ? "true" : "false") << endl;

    nums = {3, 2, 1, 0, 4}; // Expected Output: false
    cout << (canJump(nums) ? "true" : "false") << endl;

    return 0;
}
