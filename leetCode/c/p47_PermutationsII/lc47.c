/* Given an array nums of distinct integers, return all the possible permutations. 

You can return the answer in any order. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

bool checkIfComplete(int* nums, int numsSize) {
    
    for(int i=0; i < numsSize; i++) {
        if(nums[i] < 0) 
            return false;
    }    

    return true;
}

int factorial(int num) {
   
    int sol = 1;
 
    for(int i=1; i<=num; i++)
        sol *= i; 

    return sol;
}

bool checkIfUnique(int** mat, int* arr, int colSize) {

    int rowSize = factorial(colSize);
    int temp = 0;

    for(int j=0; j < rowSize; j++) {
        for(int i=0; i < colSize; i++) {
            if(mat[j][i] == arr[i]) {
                temp++; 
            }    
        }
        
        if(temp == 3)
            return false;
        else
            temp = 0;
    }

    return true;
}

void recurPermuteUnique(int* nums, int* ds, int** sol, int numsSize, int* freq, bool new) {
   
    static int j = 0;
    
    if(new)
        j = 0;
    
    if(checkIfComplete(ds, numsSize) && j < factorial(numsSize) && checkIfUnique(sol, ds, numsSize)) {
        
        for(int i=0; i<numsSize; i++)
            sol[j][i] = ds[i];

        j++;

        return;
    }

    for(int i=0; i<numsSize; i++) {
       
        int k = 0;
 
        if(freq[i] != 1) {

            while(ds[k] > 0) 
                k++;
    
            ds[k] = nums[i];        
            freq[i] = 1;
            recurPermuteUnique(nums, ds, sol, numsSize, freq, false);
            freq[i] = 0;
            ds[k] = -1;        
        }         
    } 
}

int** permuteUnique(int* nums, int numsSize, bool new) {

    int ds[numsSize];
    int freq[numsSize];

    for(int i=0; i < numsSize; i++) {
        ds[i] = -1;
        freq[i] = 0;
    }    

    int solSize = factorial(numsSize);

    int** sol = allocateMatrixInt(solSize, numsSize);

    for(int i=0; i<solSize; i++) {
        for(int j=0; j<numsSize; j++) {
            sol[i][j] = 0;
        }
    } 
    
    if(new) {
        recurPermuteUnique(nums, ds, sol, numsSize, freq, true);
        new = false;
    }
    else  
        recurPermuteUnique(nums, ds, sol, numsSize, freq, false);

    return sol;

}

int main(void) {

    // Test 1:

    int** sol1 = allocateMatrixInt(3, 3);

    printf("Test 1:\n");
    int nums1[3] = {1, 1, 2};
    int numsSize1 = sizeof(nums1) / sizeof(int); 
    printf("\nList 1: ");
    printArrayInt(nums1, numsSize1); 
    sol1 = permuteUnique(nums1, numsSize1, true);
    printf("Solution 1:\n");
    printMatrixInt(sol1, 3, 3);

    // Test 2:

    int** sol2 = allocateMatrixInt(6, 3);

    printf("Test 2:\n");
    int nums2[3] = {1, 2, 3};
    int numsSize2 = sizeof(nums2) / sizeof(int); 
    printf("\nList 2: ");
    printArrayInt(nums2, numsSize2); 
    sol2 = permuteUnique(nums2, numsSize2, true);
    printf("Solution 2:\n");
    printMatrixInt(sol2, 6, 3);

    return EXIT_SUCCESS; 
}
