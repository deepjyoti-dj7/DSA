function isSafe(board, row, col, n) {
    for (let i = 0; i < row; i++) {
        if (board[i][col] === 'Q') return false;
    }
    for (let i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] === 'Q') return false;
    }
    for (let i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] === 'Q') return false;
    }
    return true;
}

function solveNQueens(row, n, board, solutions) {
    if (row === n) {
        solutions.push(board.map(r => r.join("")));
        return;
    }

    for (let col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, n, board, solutions);
            board[row][col] = '.';
        }
    }
}

function nQueens(n) {
    let solutions = [];
    let board = Array.from({ length: n }, () => Array(n).fill('.'));
    solveNQueens(0, n, board, solutions);
    return solutions;
}

function printSolutions(solutions) {
    for (let solution of solutions) {
        for (let row of solution) {
            console.log(row);
        }
        console.log();
    }
}

// Main function
function main() {
    let n = 8;
    let solutions = nQueens(n);
    console.log(`Solutions for ${n}-Queens:`);
    printSolutions(solutions);
}

main();
