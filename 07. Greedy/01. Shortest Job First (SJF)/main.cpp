#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
};

// Comparator function to sort by burst time (SJF)
bool compare(Process a, Process b) {
    return a.burst < b.burst;
}

void sjfScheduling(vector<Process>& processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end(), compare); // Sort by burst time

    vector<int> waitingTime(n, 0), turnaroundTime(n, 0);
    int totalWaiting = 0, totalTurnaround = 0;

    // First process has no waiting time
    turnaroundTime[0] = processes[0].burst;

    // Calculate Waiting Time and Turnaround Time
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burst;
        turnaroundTime[i] = waitingTime[i] + processes[i].burst;
        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime[i];
    }

    // Output results
    cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].arrival << "\t" 
             << processes[i].burst << "\t" << waitingTime[i] << "\t" 
             << turnaroundTime[i] << "\n";
    }

    cout << "Average Waiting Time: " << (float)totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaround / n << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 6}, {2, 1, 8}, {3, 2, 7}, {4, 3, 3}
    };

    cout << "SJF Scheduling Results:\n";
    sjfScheduling(processes);

    return 0;
}
