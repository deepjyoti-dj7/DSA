#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: O(N^2) Time, O(1) Space
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target)
                return {nums[i], nums[j]}; // Return indices of the two numbers
        }
    }
    return {}; // No solution found
}

// Sorting + Two Pointers Approach: O(N log N) Time, O(1) Space
vector<int> twoSumTwoPointers(vector<int> nums, int target) {
    vector<pair<int, int>> indexedNums;
    for (int i = 0; i < nums.size(); i++)
        indexedNums.push_back({nums[i], i}); // Store value with original index

    sort(indexedNums.begin(), indexedNums.end()); // Sort based on values

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = indexedNums[left].first + indexedNums[right].first;
        if (sum == target)
            return {indexedNums[left].first, indexedNums[right].first}; // Return original indices
        else if (sum < target)
            left++;
        else
            right--;
    }
    return {}; // No solution found
}

// Hashing (Optimal) Approach: O(N) Time, O(N) Space
vector<int> twoSumHashing(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Stores {value, index}
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end())
            return {complement, nums[i]}; // Return indices of the two numbers
        numMap[nums[i]] = i; // Store index of the current number
    }
    return {}; // No solution found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Brute Force Approach
    vector<int> result1 = twoSumBruteForce(nums, target);
    if (!result1.empty())
        cout << "Brute Force: [" << result1[0] << ", " << result1[1] << "]\n";
    else
        cout << "No solution found using Brute Force\n";

    // Two Pointers Approach
    vector<int> result2 = twoSumTwoPointers(nums, target);
    if (!result2.empty())
        cout << "Two Pointers: [" << result2[0] << ", " << result2[1] << "]\n";
    else
        cout << "No solution found using Two Pointers\n";

    // Hashing Approach
    vector<int> result3 = twoSumHashing(nums, target);
    if (!result3.empty())
        cout << "Hashing: [" << result3[0] << ", " << result3[1] << "]\n";
    else
        cout << "No solution found using Hashing\n";

    return 0;
}
