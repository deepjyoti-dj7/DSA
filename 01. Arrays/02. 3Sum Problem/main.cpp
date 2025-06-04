#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: O(N^3) Time, O(1) Extra Space
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    set<vector<int>> uniqueTriplets;  // To avoid duplicates

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }

    // Copy unique triplets from set to result vector
    for (auto& triplet : uniqueTriplets) {
        result.push_back(triplet);
    }
    return result;
}

// Optimized Two Pointers Approach: O(N^2) Time, O(1) Extra Space
vector<vector<int>> threeSumOptimized(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort the array

    for (int i = 0; i < (int)nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

        int left = i + 1, right = (int)nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for left pointer
                while (left < right && nums[left] == nums[left + 1]) left++;
                // Skip duplicates for right pointer
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return result;
}

void printTriplets(const vector<vector<int>>& triplets) {
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Brute Force Approach results:\n";
    vector<vector<int>> bruteResult = threeSumBruteForce(nums);
    printTriplets(bruteResult);

    cout << "\nOptimized Two Pointers Approach results:\n";
    vector<vector<int>> optimizedResult = threeSumOptimized(nums);
    printTriplets(optimizedResult);

    return 0;
}
