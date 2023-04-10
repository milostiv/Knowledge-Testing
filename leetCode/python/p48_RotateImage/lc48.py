#!/usr/bin/python3

import numpy as np

class Solution:
    ''' 
        You are given an n x n 2D matrix representing an image, 
        rotate the image by 90 degrees (clockwise).

        You have to rotate the image in-place, 
        which means you have to modify the input 2D matrix directly. 
        DO NOT allocate another 2D matrix and do the rotation.
    '''
    def print_matrix(self, matrix):
    
        print(np.matrix(matrix))

    def transpose_matrix(self, matrix):
    
        for i in range(1, len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    def reverse_rows_matrix(self, matrix):
        
        for i in range(len(matrix)):
            for j in range(len(matrix) // 2):
                matrix[i][j], matrix[i][len(matrix) - 1 - j] = \
                    matrix[i][len(matrix) - 1 - j], matrix[i][j] 
    
    def rotate(self, matrix) -> None:
        '''
            Do not return anything, modify matrix in-place instead.
        '''
        self.transpose_matrix(matrix)
        self.reverse_rows_matrix(matrix) 

if __name__ == '__main__':

    s = Solution()

    # Test 1:

    print('Test 1:\n')

    print('Matrix 1:\n')

    matrix1 = [[1,2,3],
               [4,5,6],
               [7,8,9]]
    
    s.print_matrix(matrix1)

    print('\nRotated Matrix 1:\n')

    s.rotate(matrix1)

    s.print_matrix(matrix1)

    # Test 2:
    
    print('\nTest 2:\n')
    
    print('Matrix 2:\n')

    matrix2 = [[5,1,9,11],
               [2,4,8,10],
               [13,3,6,7],
               [15,14,12,16]]

    s.print_matrix(matrix2)

    print('\nRotated Matrix 2:\n')

    s.rotate(matrix2)

    s.print_matrix(matrix2)
