#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= n; i++) {
        current.push_back(i);
        backtrack(i + 1, n, k, current, result);
        current.pop_back();  // Backtrack
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, n, k, current, result);
    return result;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> result = combine(n, k);

    cout << "Combinations:\n";
    for (const auto& comb : result) {
        cout << "{ ";
        for (int num : comb) cout << num << " ";
        cout << "}\n";
    }
    return 0;
}
