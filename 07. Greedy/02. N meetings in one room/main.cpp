#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 1;
    int lastEnd = meetings[0][1];

    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i][0] > lastEnd) {  
            count++; // Select the meeting
            lastEnd = meetings[i][1];
        }
    }
    return count; // Return max number of meetings
}


int main() {
    vector<vector<int>> meetings = {{1, 3}, {2, 5}, {3, 8}, {6, 9}, {8, 10}, {5, 7}};

    cout << "Maximum number of meetings: " << maxMeetings(meetings) << endl;

    return 0;
}
