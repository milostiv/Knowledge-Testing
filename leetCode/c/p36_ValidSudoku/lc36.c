/* Determine if a 9 x 9 Sudoku board is valid. 

Only the filled cells need to be validated according to the following rules:

    - Each row must contain the digits 1-9 without repetition.
    - Each column must contain the digits 1-9 without repetition.
    - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

bool isNumberPossible(char** board, int y, int x) {

    int numOfInst = 0;
    int x0 = (x / 3) * 3;
    int y0 = (y / 3) * 3;

    for(int i=0; i<9; i++) {
        if(board[y][i] == board[y][x])
            numOfInst++; 
    }
    
    if(numOfInst > 1)
        return false;

    numOfInst = 0; 

    for(int i=0; i<9; i++) {
        if(board[i][x] == board[y][x])
            numOfInst++; 
    }
    
    if(numOfInst > 1)
        return false;
 
    numOfInst = 0;  

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[y0+i][x0+j] == board[y][x])
                numOfInst++;
        }
    }

    if(numOfInst > 1)
        return false;

    return true;
}

bool isValidSudoku(char** board) {

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(board[i][j] != '.' && isNumberPossible(board, i, j) == false) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {

    // Test 1:
    printf("Test 1:\n\n");

    char* board1[9] = {"53..7....",
                       "6..195...",
                       ".98....6.",
                       "8...6...3",
                       "4..8.3..1",
                       "7...2...6",
                       ".6....28.",
                       "...419..5",
                       "....8..79"};

    printMatrixChar(board1, 9, 9);
    
    if(isValidSudoku(board1))
        printf("\nGiven board is valid!\n");
    else
        printf("\nGiven board is NOT valid!\n");

    // Test 2:
    printf("\nTest 2:\n\n");

    char* board2[9] = {"83..7....",
                       "6..195...",
                       ".98....6.",
                       "8...6...3",
                       "4..8.3..1",
                       "7...2...6",
                       ".6....28.",
                       "...419..5",
                       "....8..79"};

    printMatrixChar(board2, 9, 9);
    
    if(isValidSudoku(board2))
        printf("\nGiven board is valid!\n");
    else
        printf("\nGiven board is NOT valid!\n");

    return EXIT_SUCCESS; 
}
