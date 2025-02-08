import java.util.*;

class Meeting {
    int start, end;

    public Meeting(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

class MeetingComparator implements Comparator<Meeting> {
    public int compare(Meeting a, Meeting b) {
        return a.end - b.end; // Sort by end time
    }
}

public class main {
    public static int maxMeetings(List<Meeting> meetings) {
        Collections.sort(meetings, new MeetingComparator()); // Sort by end time

        int count = 0, lastEndTime = -1;

        for (Meeting meeting : meetings) {
            if (meeting.start > lastEndTime) {
                count++;
                lastEndTime = meeting.end;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        List<Meeting> meetings = Arrays.asList(
            new Meeting(1, 3), new Meeting(2, 5), new Meeting(3, 8),
            new Meeting(6, 9), new Meeting(8, 10), new Meeting(5, 7)
        );

        System.out.println("Maximum number of meetings: " + maxMeetings(meetings));
    }
}
