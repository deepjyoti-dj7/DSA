#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreaterElement(vector<int>& nums) {
    stack<int> st;
    vector<int> result(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = previousGreaterElement(nums);

    cout << "Previous Greater Elements:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
