import java.util.Arrays;
import java.util.Comparator;

class Process {
    int pid, arrival, burst;

    Process(int pid, int arrival, int burst) {
        this.pid = pid;
        this.arrival = arrival;
        this.burst = burst;
    }
}

public class main {
    public static void sjfScheduling(Process[] processes) {
        Arrays.sort(processes, Comparator.comparingInt(p -> p.burst));

        int n = processes.length;
        int[] waitingTime = new int[n], turnaroundTime = new int[n];
        int totalWaiting = 0, totalTurnaround = 0;

        turnaroundTime[0] = processes[0].burst;

        for (int i = 1; i < n; i++) {
            waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burst;
            turnaroundTime[i] = waitingTime[i] + processes[i].burst;
            totalWaiting += waitingTime[i];
            totalTurnaround += turnaroundTime[i];
        }

        System.out.println("PID\tArrival\tBurst\tWaiting\tTurnaround");
        for (int i = 0; i < n; i++) {
            System.out.println(processes[i].pid + "\t" + processes[i].arrival + "\t" +
                    processes[i].burst + "\t" + waitingTime[i] + "\t" + turnaroundTime[i]);
        }

        System.out.println("Average Waiting Time: " + (double) totalWaiting / n);
        System.out.println("Average Turnaround Time: " + (double) totalTurnaround / n);
    }

    public static void main(String[] args) {
        Process[] processes = {
                new Process(1, 0, 6),
                new Process(2, 1, 8),
                new Process(3, 2, 7),
                new Process(4, 3, 3)
        };

        System.out.println("SJF Scheduling Results:");
        sjfScheduling(processes);
    }
}
