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

function maximalRectangle(matrix) {
    if (!matrix.length) return 0;
    let cols = matrix[0].length;
    let heights = Array(cols).fill(0);
    let maxArea = 0;

    for (let row of matrix) {
        for (let j = 0; j < cols; j++) {
            heights[j] = row[j] === '1' ? heights[j] + 1 : 0;
        }
        maxArea = Math.max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

// Main function
function main() {
    let matrix = [
        ['1', '0', '1', '0', '0'],
        ['1', '0', '1', '1', '1'],
        ['1', '1', '1', '1', '1'],
        ['1', '0', '0', '1', '0']
    ];

    console.log("Maximal Rectangle Area:", maximalRectangle(matrix));
}

// Run main function
main();
