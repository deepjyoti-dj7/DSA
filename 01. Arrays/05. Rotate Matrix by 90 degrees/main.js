function rotateMatrix(matrix) {
    let n = matrix.length;

    // Step 1: Transpose the matrix
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }

    // Step 2: Reverse each row
    for (let i = 0; i < n; i++) {
        matrix[i].reverse();
    }
}

// Main function
function main() {
    let matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];

    console.log("Original Matrix:");
    console.log(matrix.map(row => row.join(" ")).join("\n"));

    rotateMatrix(matrix);

    console.log("Rotated Matrix:");
    console.log(matrix.map(row => row.join(" ")).join("\n"));
}

main();
