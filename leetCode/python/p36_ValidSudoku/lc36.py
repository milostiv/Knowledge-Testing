#!/usr/bin/python3

import numpy as np

class Solution:
    '''
        Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

            - Each row must contain the digits 1-9 without repetition.
            - Each column must contain the digits 1-9 without repetition.
            - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
        Note:

            A Sudoku board (partially filled) could be valid but is not necessarily solvable.
            Only the filled cells need to be validated according to the mentioned rules.
    '''
    def print_board(self, board):
    
        print(np.matrix(board))

    def is_num_possible(self, y, x, board):

        num_of_inst = 0
        x0 = (x // 3) * 3
        y0 = (y // 3) * 3
        
        for i in range(9):
            if board[y][i] == board[y][x]:
                num_of_inst += 1

        if num_of_inst > 1:
            return False

        num_of_inst = 0

        for i in range(9):
            if board[i][x] == board[y][x]:
                num_of_inst += 1

        if num_of_inst > 1:
            return False

        num_of_inst = 0

        for i in range(3):
            for j in range(3):
                if board[y0+i][x0+j] == board[y][x]:
                    num_of_inst += 1

        if num_of_inst > 1:
            return False

        return True
    
    def isValidSudoku(self, board) -> bool:
        
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.' and self.is_num_possible(i, j, board) == False:
                    return False

        return True

if __name__ == '__main__':

    s = Solution()
    
    # Test 1:
    
    board1 = [['5','3','.','.','7','.','.','.','.'],
              ['6','.','.','1','9','5','.','.','.'],
              ['.','9','8','.','.','.','.','6','.'],
              ['8','.','.','.','6','.','.','.','3'],
              ['4','.','.','8','.','3','.','.','1'],
              ['7','.','.','.','2','.','.','.','6'],
              ['.','6','.','.','.','.','2','8','.'],
              ['.','.','.','4','1','9','.','.','5'],
              ['.','.','.','.','8','.','.','7','9']]

    print('Test 1:\n')
    s.print_board(board1)

    if s.isValidSudoku(board1):
        print('\nGiven board is valid!')
    else:
        print('\nGiven board is NOT valid!')

    # Test 2:

    board2 = [['8','3','.','.','7','.','.','.','.'],
              ['6','.','.','1','9','5','.','.','.'],
              ['.','9','8','.','.','.','.','6','.'],
              ['8','.','.','.','6','.','.','.','3'],
              ['4','.','.','8','.','3','.','.','1'],
              ['7','.','.','.','2','.','.','.','6'],
              ['.','6','.','.','.','.','2','8','.'],
              ['.','.','.','4','1','9','.','.','5'],
              ['.','.','.','.','8','.','.','7','9']]

    print('\nTest 2:\n')
    s.print_board(board2)

    if s.isValidSudoku(board2):
        print('\nGiven board is valid!')
    else:
        print('\nGiven board is NOT valid!')
