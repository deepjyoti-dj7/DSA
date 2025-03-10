#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
        if (candidates[i] > target) break; // No need to proceed

        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, current, result);
        current.pop_back();  // Backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    backtrack(candidates, target, 0, current, result);
    return result;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    
    vector<vector<int>> result = combinationSum2(candidates, target);
    
    cout << "Combinations:\n";
    for (const auto& comb : result) {
        cout << "{ ";
        for (int num : comb) cout << num << " ";
        cout << "}\n";
    }
    return 0;
}
