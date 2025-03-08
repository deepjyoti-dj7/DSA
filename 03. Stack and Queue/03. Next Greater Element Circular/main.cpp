#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            result[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElementCircular(nums);

    cout << "Next Greater Elements (Circular):\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
