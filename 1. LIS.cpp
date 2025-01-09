#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> &arr, int ind, int prev) {
    if (ind == arr.size()) 
        return 0;

    int take = 0;
    int notTake = LIS(arr, ind + 1, prev);
    if (prev < arr[ind])
        take = 1 + LIS(arr, ind + 1, arr[ind]);

    return max(take, notTake);
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 0, 1};
    int n = arr.size();

    cout << "Length of LIS: " << LIS(arr, 0, INT_MIN) << endl;

    return 0;
}