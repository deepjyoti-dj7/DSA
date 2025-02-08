function maxMeetings(meetings) {
    meetings.sort((a, b) => a[1] - b[1]); // Sort by end time

    let count = 0, lastEndTime = -1;

    for (let [start, end] of meetings) {
        if (start > lastEndTime) {
            count++;
            lastEndTime = end;
        }
    }

    return count;
}

function main() {
    let meetings = [
        [1, 3], [2, 5], [3, 8], [6, 9], [8, 10], [5, 7]
    ];

    console.log("Maximum number of meetings:", maxMeetings(meetings));
}

main();
