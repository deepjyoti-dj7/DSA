#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, farthest = 0, currentEnd = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]); // Update the farthest index we can reach

        if (i == currentEnd) { // If we reach the end of the current jump
            jumps++;
            currentEnd = farthest; // Move to the farthest reachable index
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4}; // Expected Output: 2
    cout << "Minimum jumps: " << jump(nums) << endl;

    nums = {1, 1, 1, 1}; // Expected Output: 3
    cout << "Minimum jumps: " << jump(nums) << endl;

    return 0;
}
