#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> majorityElementBruteForce(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) count++;
        }
        if (count > n / 3 && find(result.begin(), result.end(), nums[i]) == result.end()) {
            result.push_back(nums[i]);
        }
    }
    return result;
}

// Sorting Approach
vector<int> majorityElementSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n;) {
        int count = upper_bound(nums.begin(), nums.end(), nums[i]) - lower_bound(nums.begin(), nums.end(), nums[i]);
        if (count > n / 3) result.push_back(nums[i]);
        i += count;
    }
    return result;
}

// HashMap Approach
vector<int> majorityElementHashMap(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    vector<int> result;
    for (auto [key, value] : freq) {
        if (value > nums.size() / 3) result.push_back(key);
    }
    return result;
}

// Boyer-Moore Voting Algorithm
vector<int> majorityElementBoyerMoore(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
        else if (count1 == 0) candidate1 = num, count1 = 1;
        else if (count2 == 0) candidate2 = num, count2 = 1;
        else count1--, count2--;
    }

    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    vector<int> result;
    int n = nums.size();
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);
    
    return result;
}

// Main Function
int main() {
    vector<int> nums = {3, 2, 3, 1, 1, 1, 2, 2};
    cout << "Brute Force: "; for (int num : majorityElementBruteForce(nums)) cout << num << " ";
    cout << "\nSorting: "; for (int num : majorityElementSorting(nums)) cout << num << " ";
    cout << "\nHashMap: "; for (int num : majorityElementHashMap(nums)) cout << num << " ";
    cout << "\nBoyer-Moore: "; for (int num : majorityElementBoyerMoore(nums)) cout << num << " ";
    return 0;
}
