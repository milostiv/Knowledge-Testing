/* Given an array nums of distinct integers, return all the possible permutations. 

You can return the answer in any order. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

bool checkIfComplete(int* nums, int numsSize) {
    
    for(int i=0; i < numsSize; i++) {
        if(nums[i] < 0) 
            return false;
    }    

    return true;
}

void recurPermute(int* nums, int* ds, int** sol, int numsSize, int* freq, bool new) {
   
    static int j = 0;
    
    if(new)
        j = 0;
 
    if(checkIfComplete(ds, numsSize) && j < factorialInt(numsSize)) {
        
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
            recurPermute(nums, ds, sol, numsSize, freq, false);
            freq[i] = 0;
            ds[k] = -1;        
        }         
    } 
}

int** permute(int* nums, int numsSize, bool new) {

    int ds[numsSize];
    int freq[numsSize];

    for(int i=0; i < numsSize; i++) {
        ds[i] = -1;
        freq[i] = 0;
    }    

    int solSize = factorialInt(numsSize);

    int** sol = allocateMatrixInt(solSize, numsSize);

    for(int i=0; i<solSize; i++) {
        for(int j=0; j<numsSize; j++) {
            sol[i][j] = 0;
        }
    } 
    
    if(new) {
        recurPermute(nums, ds, sol, numsSize, freq, true);
        new = false;
    }
    else  
        recurPermute(nums, ds, sol, numsSize, freq, false);

    return sol;

}

int main(void) {

    // Test 1:

    int** sol1 = allocateMatrixInt(6, 3);

    printf("Test 1:\n");
    int nums1[3] = {1, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(int); 
    printf("\nList 1: ");
    printArrayInt(nums1, numsSize1); 
    sol1 = permute(nums1, numsSize1, true);
    printf("Solution 1:\n");
    printMatrixInt(sol1, 6, 3);

    // Test 2:

    int** sol2 = allocateMatrixInt(2, 2);

    printf("\nTest 2:\n");
    int nums2[2] = {0, 1};
    int numsSize2 = sizeof(nums2) / sizeof(int);
    printf("\nList 2: ");
    printArrayInt(nums2, numsSize2);
    sol2 = permute(nums2, numsSize2, true);
    printf("Solution 2:\n");
    printMatrixInt(sol2, 2, 2);

    // Test 3:

    int** sol3 = allocateMatrixInt(1, 1);

    printf("\nTest 3:\n");
    int nums3[1] = {1};
    int numsSize3 = sizeof(nums3) / sizeof(int);
    printf("\nList 3: ");
    printArrayInt(nums3, numsSize3); 
    sol3 = permute(nums3, numsSize3, true);
    printf("Solution 3:\n");
    printMatrixInt(sol3, 1, 1);

    return EXIT_SUCCESS; 
}
