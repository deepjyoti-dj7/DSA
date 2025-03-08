#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreaterElementCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    // Traverse the array twice in reverse order to handle circular behavior
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if (i < n) {
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(nums[i]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = previousGreaterElementCircular(nums);

    cout << "Previous Greater Elements (Circular):\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
