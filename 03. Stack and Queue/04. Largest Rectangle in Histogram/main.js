function largestRectangleArea(heights) {
    let stack = [];
    let maxArea = 0;
    heights.push(0); // Sentinel value

    for (let i = 0; i < heights.length; i++) {
        while (stack.length && heights[i] < heights[stack[stack.length - 1]]) {
            let height = heights[stack.pop()];
            let width = stack.length ? i - stack[stack.length - 1] - 1 : i;
            maxArea = Math.max(maxArea, height * width);
        }
        stack.push(i);
    }

    return maxArea;
}

// Main function
function main() {
    let heights = [2, 1, 5, 6, 2, 3];
    console.log("Largest Rectangle Area:", largestRectangleArea(heights));
}

// Run main function
main();
