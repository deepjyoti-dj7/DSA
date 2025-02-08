import java.util.*;

public class main {
    public static int maxMeetings(int[][] meetings) {
        // Sort by end time (greedy approach)
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[1]));

        int count = 1;
        int lastEnd = meetings[0][1];

        for (int i = 1; i < meetings.length; i++) {
            if (meetings[i][0] > lastEnd) {  
                count++; // Select the meeting
                lastEnd = meetings[i][1];
            }
        }
        return count; // Return max number of meetings
    }

    public static void main(String[] args) {
        int[][] meetings = {{1, 3}, {2, 5}, {3, 8}, {6, 9}, {8, 10}, {5, 7}};

        System.out.println("Maximum number of meetings: " + maxMeetings(meetings));
    }
}
