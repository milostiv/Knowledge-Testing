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

void findEmptyLocation(char** board, int* y, int*x) {
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(board[i][j] == '.') {
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

bool isNumberPossible(char** board, int y, int x, char n) {

    int x0 = (x / 3) * 3;
    int y0 = (y / 3) * 3;

    for(int i=0; i<9; i++) {
        if(board[y][i] == n)
            return false;
    }
    
    for(int i=0; i<9; i++) {
        if(board[i][x] == board[y][x])
            return false;
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[y0+i][x0+j] == board[y][x])
                return false;
        }
    }

    return true;
}

bool solveSudoku(char** board) {
    
    int y, x;
    char guess_chr;

    findEmptyLocation(board, &y, &x);

    if(y < 0) 
        return true;        

    for(int guess = 1; guess < 10; guess++) {
        
        itoa(guess, &guess_chr);
 
        //if(isNumberPossible(board, y, x)) {
        //
        //}
    }
}

int main(void) {
    
    // Test:
 
    char* board[9] = {"53..7....",
                      "6..195...",
                      ".98....6.",
                      "8...6...3",
                      "4..8.3..1",
                      "7...2...6",
                      ".6....28.",
                      "...419..5",
                      "....8..79"};

    printMatrixChar(board, 9, 9);

    solveSudoku(board);
        
    return EXIT_SUCCESS;
}
