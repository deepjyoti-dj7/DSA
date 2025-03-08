#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadane(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    for (size_t i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int maxCircularSubarraySum(vector<int>& nums) {
    int maxKadane = kadane(nums);
    int totalSum = 0, minSum = nums[0], currentMin = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
        if (i > 0) {
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);
        }
    }
    
    if (totalSum == minSum) return maxKadane;
    return max(maxKadane, totalSum - minSum);
}

int main() {
    vector<int> nums = {5, -3, 5};
    cout << "Maximum Circular Subarray Sum: " << maxCircularSubarraySum(nums) << endl;
    return 0;
}
