#include <bits/stdc++.h>
using namespace std;

void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // Base case: If we've processed all elements, add current subset to result
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Exclude the current element and move to the next
    generateSubsets(index + 1, nums, current, result);

    current.push_back(nums[index]);  // Include the current element
    generateSubsets(index + 1, nums, current, result);
    current.pop_back(); // Backtrack: Remove the last added element before returning
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(0, nums, current, result);
    return result;
}

// Utility function to print subsets
void printSubsets(const vector<vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << (i < subset.size() - 1 ? "," : "");
        }
        cout << "} ";
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    cout << "Subsets using Backtracking:\n";
    printSubsets(subsets(nums));

    return 0;
}
