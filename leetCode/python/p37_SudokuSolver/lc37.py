#!/usr/bin/python3

import numpy as np

class Solution:
    '''
        Write a program to solve a Sudoku puzzle by filling the empty cells.
    
        A sudoku solution must satisfy all of the following rules:

        Each of the digits 1-9 must occur exactly once in each row.
        Each of the digits 1-9 must occur exactly once in each column.
        Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
        The '.' character indicates empty cells.    
    '''    
    def print_board(self, board):
        
        print(np.matrix(board))

    def find_empty_location(self, board):

        for y in range(9):
            for x in range(9):
                if board[y][x] == '.':
                    return y, x

        return None, None    

    def is_num_possible(self, y, x, n, board):
        
        for i in range(9):
            if board[y][i] == str(n):
                return False

        for i in range(9):
            if board[i][x] == str(n):
                return False

        x0 = (x // 3) * 3
        y0 = (y // 3) * 3

        for i in range(3):
            for j in range(3):
                if board[y0+i][x0+j] == str(n):
                    return False         

        return True

    def solveSudoku(self, board):
        '''
            Do not return anything, modify board in-place instead.
        '''

        y, x = self.find_empty_location(board)
    
        if y is None:
            return True

        for guess in range(1, 10):
            if self.is_num_possible(y, x, guess, board):
                board[y][x] = str(guess)
                if self.solveSudoku(board):
                    return True
             
            board[y][x] = '.'

        return False

if __name__ == '__main__':

    s = Solution()
    
    # Test 
    
    board = [['5','3','.','.','7','.','.','.','.'],
             ['6','.','.','1','9','5','.','.','.'],
             ['.','9','8','.','.','.','.','6','.'],
             ['8','.','.','.','6','.','.','.','3'],
             ['4','.','.','8','.','3','.','.','1'],
             ['7','.','.','.','2','.','.','.','6'],
             ['.','6','.','.','.','.','2','8','.'],
             ['.','.','.','4','1','9','.','.','5'],
             ['.','.','.','.','8','.','.','7','9']]
    
    print("\nStarting board:")
    s.print_board(board)
    
    s.solveSudoku(board)
    
    print("Solved board:")
    s.print_board(board)
