#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> st;
    vector<int> result(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
