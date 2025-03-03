function insert(intervals, newInterval) {
    let result = [];
    let i = 0, n = intervals.length;

    // Before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push(newInterval);

    // After the new interval
    while (i < n) {
        result.push(intervals[i]);
        i++;
    }

    return result;
}

// Main function
function main() {
    let intervals = [[1, 3], [6, 9]];
    let newInterval = [2, 5];

    let result = insert(intervals, newInterval);
    console.log("Updated intervals:", result);
}

// Run main function
main();
