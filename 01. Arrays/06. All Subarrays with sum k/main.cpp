#include <bits/stdc++.h>
using namespace std;

// 🔹 Brute Force (O(N²)) 
int subarraySumBrute(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k) count++;
        }
    }
    return count;
}

// 🔹 Optimized (O(N)) - Prefix Sum + HashMap
int subarraySumOptimized(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;

    int count = 0, prefixSum = 0;
    for (int num : nums) {
        prefixSum += num;
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];
        }
        prefixSumCount[prefixSum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 2, -1, 2};
    int k = 5;

    cout << "Brute Force: " << subarraySumBrute(nums, k) << endl;
    cout << "Optimized: " << subarraySumOptimized(nums, k) << endl;

    return 0;
}
