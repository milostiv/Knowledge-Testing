#!/usr/bin/python3

import numpy as np

class Solution:
    '''
        Given a 2D integer array matrix, return the transpose of matrix.

        The transpose of a matrix is the matrix flipped over its main diagonal, 
        switching the matrix's row and column indices.
    '''
    def print_matrix(self, matrix):
    
        print(np.matrix(matrix))
    
    def transpose(self, matrix):

        sol = [[0 for _ in range(len(matrix))] for _ in range(len(matrix[0]))]

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                sol[j][i] = matrix[i][j]

        return sol

if __name__ == '__main__':

    s = Solution()

    # Test 1:
   
    print('Test 1:\n') 
    print('Matrix 1:\n')

    matrix1 = [[1,2,3],
               [4,5,6],
               [7,8,9]]

    s.print_matrix(matrix1)

    print('\nTransposed matrix 1:\n')

    sol1 = s.transpose(matrix1)

    s.print_matrix(sol1)

    # Test 2:

    print('\nTest 2:\n') 
    print('Matrix 2:\n')

    matrix2 = [[1,2,3],
               [4,5,6]] 

    s.print_matrix(matrix2)

    print('\nTransposed matrix 2:\n')

    sol2 = s.transpose(matrix2)

    s.print_matrix(sol2)
