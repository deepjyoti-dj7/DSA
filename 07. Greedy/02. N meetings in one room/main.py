def max_meetings(meetings):
    # Sort by end time (greedy approach)
    meetings.sort(key=lambda x: x[1])

    count = 1
    last_end = meetings[0][1]

    for i in range(1, len(meetings)):
        if meetings[i][0] > last_end:
            count += 1  # Select the meeting
            last_end = meetings[i][1]

    return count  # Return max number of meetings

# Main function
def main():
    meetings = [[1, 3], [2, 5], [3, 8], [6, 9], [8, 10], [5, 7]]
    print("Maximum number of meetings:", max_meetings(meetings))

# Run the main function
if __name__ == "__main__":
    main()
