class Process {
    constructor(pid, arrival, burst) {
        this.pid = pid;
        this.arrival = arrival;
        this.burst = burst;
    }
}

function sjfScheduling(processes) {
    processes.sort((a, b) => a.burst - b.burst);

    let n = processes.length;
    let waitingTime = new Array(n).fill(0);
    let turnaroundTime = new Array(n).fill(0);
    let totalWaiting = 0, totalTurnaround = 0;

    turnaroundTime[0] = processes[0].burst;

    for (let i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burst;
        turnaroundTime[i] = waitingTime[i] + processes[i].burst;
        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime[i];
    }

    console.log("PID\tArrival\tBurst\tWaiting\tTurnaround");
    for (let i = 0; i < n; i++) {
        console.log(`${processes[i].pid}\t${processes[i].arrival}\t${processes[i].burst}\t${waitingTime[i]}\t${turnaroundTime[i]}`);
    }

    console.log("Average Waiting Time:", (totalWaiting / n).toFixed(2));
    console.log("Average Turnaround Time:", (totalTurnaround / n).toFixed(2));
}

function main() {
    let processes = [
        new Process(1, 0, 6),
        new Process(2, 1, 8),
        new Process(3, 2, 7),
        new Process(4, 3, 3)
    ];

    console.log("SJF Scheduling Results:");
    sjfScheduling(processes);
}

main();
