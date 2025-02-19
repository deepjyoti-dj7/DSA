class Process:
    def __init__(self, pid, arrival, burst):
        self.pid = pid
        self.arrival = arrival
        self.burst = burst

def sjf_scheduling(processes):
    processes.sort(key=lambda p: p.burst)

    n = len(processes)
    waiting_time = [0] * n
    turnaround_time = [0] * n
    total_waiting, total_turnaround = 0, 0

    turnaround_time[0] = processes[0].burst

    for i in range(1, n):
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst
        turnaround_time[i] = waiting_time[i] + processes[i].burst
        total_waiting += waiting_time[i]
        total_turnaround += turnaround_time[i]

    print("PID\tArrival\tBurst\tWaiting\tTurnaround")
    for i in range(n):
        print(f"{processes[i].pid}\t{processes[i].arrival}\t{processes[i].burst}\t{waiting_time[i]}\t{turnaround_time[i]}")

    print(f"Average Waiting Time: {total_waiting / n:.2f}")
    print(f"Average Turnaround Time: {total_turnaround / n:.2f}")

def main():
    processes = [
        Process(1, 0, 6),
        Process(2, 1, 8),
        Process(3, 2, 7),
        Process(4, 3, 3)
    ]

    print("SJF Scheduling Results:")
    sjf_scheduling(processes)

main()
