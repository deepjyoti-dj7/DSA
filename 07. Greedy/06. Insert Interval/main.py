def insert(intervals, newInterval):
    result = []
    i, n = 0, len(intervals)

    # Before the new interval
    while i < n and intervals[i][1] < newInterval[0]:
        result.append(intervals[i])
        i += 1

    # Merge overlapping intervals
    while i < n and intervals[i][0] <= newInterval[1]:
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i += 1
    result.append(newInterval)

    # After the new interval
    while i < n:
        result.append(intervals[i])
        i += 1

    return result

# Main function
def main():
    intervals = [[1, 3], [6, 9]]
    newInterval = [2, 5]

    result = insert(intervals, newInterval)
    print("Updated intervals:", result)

# Run main function
if __name__ == "__main__":
    main()
