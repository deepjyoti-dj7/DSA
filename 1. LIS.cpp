#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> &arr, int ind, int prev) {
    if (ind == arr.size()) 
        return 0;

    int take = 0;
    int notTake = LIS(arr, ind + 1, prev);
    if (arr[prev] < arr[ind])
        take = 1 + LIS(arr, ind + 1, ind);

    return max(take, notTake);
}

int LIS_Memoization(vector<int> &arr, int ind, int prev, vector<vector<int>> &dp) {
    if (ind == arr.size()) 
        return 0;

    if (dp[ind][prev + 1] != -1) 
        return dp[ind][prev + 1];

    int take = 0;
    int notTake = LIS_Memoization(arr, ind + 1, prev, dp);
    if (arr[prev] < arr[ind])
        take = 1 + LIS_Memoization(arr, ind + 1, ind, dp);

    return dp[ind][prev + 1] = max(take, notTake);
}

int LIS_Tabulation(vector<int> &arr, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int take = 0;
            if (prev == -1 || arr[prev] < arr[ind])     
                take = 1 + dp[ind + 1][ind];
            dp[ind][prev + 1] = max(take, dp[ind + 1][prev + 1]);
        }
    }
    return dp[0][0];
}

int LIS_Tabulation_SpaceOptimized(vector<int> &arr, int n) {
    vector<int> cur(n + 1, 0), next(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int take = 0;
            if (prev == -1 || arr[prev] < arr[ind])     
                take = 1 + next[ind];
            cur[prev + 1] = max(take, next[prev + 1]);
        }
        next = cur;
    }
    return next[0];
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 0, 1};
    int n = arr.size();

    cout << "Length of LIS: " << LIS(arr, 0, -1) << endl;
    
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << "Length of LIS using Memoization: " << LIS_Memoization(arr, 0, -1, dp) << endl;

    cout << "Length of LIS using Tabulation: " << LIS_Tabulation(arr, n) << endl;

    cout << "Length of LIS using Tabulation and Space Optimization: " << LIS_Tabulation_SpaceOptimized(arr, n) << endl;

    return 0;
}