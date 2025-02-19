def largestRectangleArea(heights):
    stack = []
    max_area = 0
    heights.append(0)  # Sentinel value

    for i in range(len(heights)):
        while stack and heights[i] < heights[stack[-1]]:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)

    return max_area

# Main function
def main():
    heights = [2, 1, 5, 6, 2, 3]
    print("Largest Rectangle Area:", largestRectangleArea(heights))

# Run main function
main()
