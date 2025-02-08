def erase_overlap_intervals(intervals):
    if not intervals:
        return 0

    # Sort by end time (greedy approach)
    intervals.sort(key=lambda x: x[1])

    count = 1  # We can always select at least one interval
    last_end = intervals[0][1]

    for i in range(1, len(intervals)):
        if intervals[i][0] >= last_end:
            count += 1  # Select this interval
            last_end = intervals[i][1]

    # Total intervals - non-overlapping intervals gives the removed intervals
    return len(intervals) - count

# Main function
def main():
    intervals = [[1, 3], [2, 4], [3, 5], [5, 6], [7, 8]]
    print("Minimum intervals to remove:", erase_overlap_intervals(intervals))

# Run the main function
if __name__ == "__main__":
    main()
