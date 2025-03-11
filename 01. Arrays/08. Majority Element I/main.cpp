#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
int majorityElementBruteForce(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) count++;
        }
        if (count > n / 2) return nums[i];
    }
    return -1;
}

// Approach 2: Sorting
int majorityElementSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// Approach 3: HashMap
int majorityElementHashMap(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    for (auto [key, value] : freq) {
        if (value > nums.size() / 2) return key;
    }
    return -1;
}

// Approach 4: Boyer-Moore Voting Algorithm (Optimal)
int majorityElementBoyerMoore(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

// Main Function
int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Brute Force: " << majorityElementBruteForce(nums) << endl;
    cout << "Sorting: " << majorityElementSorting(nums) << endl;
    cout << "HashMap: " << majorityElementHashMap(nums) << endl;
    cout << "Boyer-Moore: " << majorityElementBoyerMoore(nums) << endl;
    return 0;
}
