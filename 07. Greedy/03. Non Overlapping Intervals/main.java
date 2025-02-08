import java.util.*;

public class main {
    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;

        // Sort by end time (greedy approach)
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));

        int count = 1; // We can always select at least one interval
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= lastEnd) {  
                count++; // Select this interval
                lastEnd = intervals[i][1];
            }
        }

        // Total intervals - non-overlapping intervals gives the removed intervals
        return intervals.length - count;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 3}, {2, 4}, {3, 5}, {5, 6}, {7, 8}};
        System.out.println("Minimum intervals to remove: " + eraseOverlapIntervals(intervals));
    }
}
