def max_meetings(meetings):
    meetings.sort(key=lambda x: x[1])  # Sort by end time

    count, last_end_time = 0, -1

    for start, end in meetings:
        if start > last_end_time:
            count += 1
            last_end_time = end

    return count

def main():
    meetings = [
        (1, 3), (2, 5), (3, 8), (6, 9), (8, 10), (5, 7)
    ]

    print("Maximum number of meetings:", max_meetings(meetings))

main()
