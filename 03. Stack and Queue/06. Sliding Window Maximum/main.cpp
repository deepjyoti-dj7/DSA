#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

// Brute Force Approach - O(N*K)
vector<int> bruteForceSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxVal = nums[i];
        for (int j = i; j < i + k; j++) {
            maxVal = max(maxVal, nums[j]);
        }
        result.push_back(maxVal);
    }
    return result;
}

// Max Heap (Priority Queue) Approach - O(N log K)
vector<int> heapSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});

        if (i >= k - 1) {
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            result.push_back(pq.top().first);
        }
    }
    return result;
}

// Optimized Deque Approach - O(N)
vector<int> dequeSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

// Main function
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    cout << "Brute Force Output: ";
    for (int num : bruteForceSlidingWindow(nums, k)) cout << num << " ";
    cout << endl;
    
    cout << "Heap Output: ";
    for (int num : heapSlidingWindow(nums, k)) cout << num << " ";
    cout << endl;
    
    cout << "Deque Output: ";
    for (int num : dequeSlidingWindow(nums, k)) cout << num << " ";
    cout << endl;
    
    return 0;
}
