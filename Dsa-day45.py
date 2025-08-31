class Solution:
    def solveSudoku(self, board):
        self.solve(board)

    def solve(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for c in map(str, range(1, 10)):
                        if self.isValid(board, i, j, c):
                            board[i][j] = c
                            if self.solve(board):
                                return True
                            board[i][j] = '.'
                    return False
        return True

    def isValid(self, board, row, col, c):
        for i in range(9):
            if board[i][col] == c or board[row][i] == c or board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                return False
        return True
