#!/usr/bin/python3
import sys

def is_safe(board, row, col, N):
    # Check this row on left side
    for i in range(col):
        if board[row][i]:
            return False
    
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    
    # Check lower diagonal on left side
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j]:
            return False
    
    return True

def solve_nqueens_util(board, col, N, result):
    if col >= N:
        result.append([[row, col] for row in range(N) if board[row][col]])
        return True
    
    res = False
    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1
            res = solve_nqueens_util(board, col + 1, N, result) or res
            board[i][col] = 0  # Backtrack if placing queen at board[i][col] doesn't lead to a solution
    
    return res

def solve_nqueens(N):
    if not isinstance(N, int):
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
    
    board = [[0] * N for _ in range(N)]
    result = []
    if not solve_nqueens_util(board, 0, N, result):
        print("No solution exists")
        return
    
    for sol in result:
        print(sol)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    
    try:
        N = int(sys.argv[1])
        solve_nqueens(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
