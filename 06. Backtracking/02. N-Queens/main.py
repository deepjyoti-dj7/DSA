def is_safe(board, row, col, n):
    for i in range(row):
        if board[i][col] == 'Q':
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 'Q':
            return False
    return True

def solve_n_queens(row, n, board, solutions):
    if row == n:
        solutions.append(["".join(r) for r in board])
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 'Q'
            solve_n_queens(row + 1, n, board, solutions)
            board[row][col] = '.'

def n_queens(n):
    solutions = []
    board = [['.' for _ in range(n)] for _ in range(n)]
    solve_n_queens(0, n, board, solutions)
    return solutions

def print_solutions(solutions):
    for solution in solutions:
        for row in solution:
            print(row)
        print()

# Main function
def main():
    n = 8
    solutions = n_queens(n)
    print(f"Solutions for {n}-Queens:")
    print_solutions(solutions)

main()
