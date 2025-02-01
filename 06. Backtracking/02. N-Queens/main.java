import java.util.*;

public class main {

    // Check if a queen can be placed safely
    private static boolean isSafe(List<String> board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (board.get(i).charAt(col) == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board.get(i).charAt(j) == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board.get(i).charAt(j) == 'Q') return false;
        }

        return true;
    }

    // Backtracking function to solve N-Queens
    private static void solveNQueens(int row, int n, List<String> board, List<List<String>> solutions) {
        if (row == n) {
            solutions.add(new ArrayList<>(board));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                char[] rowArray = board.get(row).toCharArray();
                rowArray[col] = 'Q';
                board.set(row, new String(rowArray));

                solveNQueens(row + 1, n, board, solutions);

                rowArray[col] = '.';
                board.set(row, new String(rowArray));
            }
        }
    }

    public static List<List<String>> nQueens(int n) {
        List<List<String>> solutions = new ArrayList<>();
        List<String> board = new ArrayList<>(Collections.nCopies(n, ".".repeat(n)));
        solveNQueens(0, n, board, solutions);
        return solutions;
    }

    public static void printSolutions(List<List<String>> solutions) {
        for (List<String> solution : solutions) {
            for (String row : solution) {
                System.out.println(row);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int n = 8;
        List<List<String>> solutions = nQueens(n);
        System.out.println("Solutions for " + n + "-Queens:");
        printSolutions(solutions);
    }
}
