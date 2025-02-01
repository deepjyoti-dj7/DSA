#include <bits/stdc++.h>
using namespace std;

// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<string> &board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Backtracking function to solve N-Queens
void solveNQueens(int row, int n, vector<string> &board, vector<vector<string>> &solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q'; // Place queen
            solveNQueens(row + 1, n, board, solutions); // Recur for next row
            board[row][col] = '.'; // Backtrack
        }
    }
}

// Function to return all N-Queens solutions
vector<vector<string>> nQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.')); // Initialize empty board
    solveNQueens(0, n, board, solutions);
    return solutions;
}

// Utility function to print the solutions
void printSolutions(const vector<vector<string>> &solutions) {
    for (const auto &solution : solutions) {
        for (const string &row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int n = 8; // Change N to test different board sizes
    vector<vector<string>> solutions = nQueens(n);

    cout << "Solutions for " << n << "-Queens:\n";
    printSolutions(solutions);

    return 0;
}
