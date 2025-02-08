function maxMeetings(meetings) {
    // Sort by end time (greedy approach)
    meetings.sort((a, b) => a[1] - b[1]);

    let count = 1;
    let lastEnd = meetings[0][1];

    for (let i = 1; i < meetings.length; i++) {
        if (meetings[i][0] > lastEnd) {
            count++; // Select the meeting
            lastEnd = meetings[i][1];
        }
    }
    return count; // Return max number of meetings
}

// Main function
function main() {
    let meetings = [[1, 3], [2, 5], [3, 8], [6, 9], [8, 10], [5, 7]];
    console.log("Maximum number of meetings:", maxMeetings(meetings));
}

// Run the main function
main();
