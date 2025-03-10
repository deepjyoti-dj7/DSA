#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue; // Skip used numbers
        
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    
    backtrack(nums, used, current, result);
    return result;
}

// Utility function to print permutations
void printPermutations(const vector<vector<int>>& permutations) {
    cout << "[\n";
    for (const auto& perm : permutations) {
        cout << "  [";
        for (size_t i = 0; i < perm.size(); i++) {
            cout << perm[i] << (i < perm.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Permutations:\n";
    printPermutations(permute(nums));
    return 0;
}
