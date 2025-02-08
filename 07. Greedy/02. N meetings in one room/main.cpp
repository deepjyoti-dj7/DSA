#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start, end;
};

// Comparator function to sort meetings by end time
bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(vector<Meeting>& meetings) {
    sort(meetings.begin(), meetings.end(), compare); // Sort meetings by end time

    int count = 0, lastEndTime = -1;

    for (const auto& meeting : meetings) {
        if (meeting.start > lastEndTime) {
            count++;
            lastEndTime = meeting.end;
        }
    }

    return count;
}

int main() {
    vector<Meeting> meetings = {{1, 3}, {2, 5}, {3, 8}, {6, 9}, {8, 10}, {5, 7}};

    cout << "Maximum number of meetings: " << maxMeetings(meetings) << endl;

    return 0;
}
