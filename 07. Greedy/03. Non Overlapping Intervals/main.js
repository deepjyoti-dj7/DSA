function eraseOverlapIntervals(intervals) {
    if (intervals.length === 0) return 0;

    // Sort by end time (greedy approach)
    intervals.sort((a, b) => a[1] - b[1]);

    let count = 1; // We can always select at least one interval
    let lastEnd = intervals[0][1];

    for (let i = 1; i < intervals.length; i++) {
        if (intervals[i][0] >= lastEnd) {
            count++; // Select this interval
            lastEnd = intervals[i][1];
        }
    }

    // Total intervals - non-overlapping intervals gives the removed intervals
    return intervals.length - count;
}

// Main function
function main() {
    let intervals = [[1, 3], [2, 4], [3, 5], [5, 6], [7, 8]];
    console.log("Minimum intervals to remove:", eraseOverlapIntervals(intervals));
}

// Run the main function
main();
