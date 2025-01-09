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

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 0, 1};
    int n = arr.size();

    cout << "Length of LIS: " << LIS(arr, 0, -1) << endl;
    
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << "Length of LIS using Memoization: " << LIS_Memoization(arr, 0, -1, dp) << endl;

    return 0;
}