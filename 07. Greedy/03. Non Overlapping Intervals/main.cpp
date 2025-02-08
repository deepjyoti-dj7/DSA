#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort by end time (greedy approach)
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 1; // We can always select at least one interval
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= lastEnd) {  
            count++; // Select this interval
            lastEnd = intervals[i][1];
        }
    }

    // Total intervals - non-overlapping intervals gives the removed intervals
    return intervals.size() - count;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {5, 6}, {7, 8}};
    cout << "Minimum intervals to remove: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
