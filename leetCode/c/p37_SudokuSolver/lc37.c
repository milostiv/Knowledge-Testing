/* Write a program to solve a Sudoku puzzle by filling the empty cells.
    
A sudoku solution must satisfy all of the following rules:

    - Each of the digits 1-9 must occur exactly once in each row.
    - Each of the digits 1-9 must occur exactly once in each column.
    - Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
     
The '.' character indicates empty cells. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../../mylib/mylib.h"

void printSudoku(int board[9][9]) {
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}

void findEmptyLocation(int board[9][9], int* y, int*x) {
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(board[i][j] == 0) {
                *y = i;
                *x = j; 
                return;
            }
        }
    }
    
    // If there are no empty location return negative values for x and y
    *y = -1;
    *x = -1;
}

bool isNumberPossible(int board[9][9], int y, int x, int n) {

    int x0 = (x / 3) * 3;
    int y0 = (y / 3) * 3;

    for(int i=0; i<9; i++) {
        if(board[y][i] == n)
            return false;
    }
    
    for(int i=0; i<9; i++) {
        if(board[i][x] == n) 
            return false;
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[y0+i][x0+j] == n)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int board[9][9]) {
    
    int y, x;

    findEmptyLocation(board, &y, &x);

    if(y < 0) 
        return true;        
    
    for(int guess=1; guess < 10; guess++) {
    
        if(isNumberPossible(board, y, x, guess)) {
            board[y][x] = guess;
            if(solveSudoku(board))
                return true;
        }

        board[y][x] = 0;
    }

    return false;
}

int main(void) {
    
    // Test:

    printf("Given sudoku:\n");

    int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}}; 

    printSudoku(board);

    solveSudoku(board);

    printf("\nSolved sudoku:\n");

    printSudoku(board);
        
    return EXIT_SUCCESS;
}
