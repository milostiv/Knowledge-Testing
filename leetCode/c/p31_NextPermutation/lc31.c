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

bool arraysEqual(int* nums1, int* nums2, int numsSize) {

    int temp = 0;

    for(int i=0; i<numsSize; i++) {
        
        if(nums1[i] == nums2[i]) 
            temp++;
    }

    if(temp == numsSize)
        return true;

    return false;
}

void nextPermutation(int* nums, int numsSize) {
    
    int temp[3];
    int matSize;

    for(int i=0; i<numsSize; i++) 
        temp[i] = nums[i];

    selectionSort(temp, numsSize);
    
    matSize = factorialInt(numsSize);
    int** matPermute = allocateMatrixInt(matSize, numsSize);
    matPermute = permute(temp, numsSize, true);
    
    for(int i=0; i<matSize; i++) {
    
        if(arraysEqual(nums, matPermute[i], numsSize) && i != matSize - 1) {
            for(int j=0; j<numsSize; j++) 
                nums[j] = matPermute[i+1][j];

            return; 
        }
        else if(arraysEqual(nums, matPermute[i], numsSize) && i == matSize - 1) {
            for(int j=0; j<numsSize; j++) 
                nums[j] = matPermute[0][j];

            return;

        } 
    } 
}

int main(void) {
    
    // Test 1:
    
    printf("Test 1:\n");
    int nums1[3] = {1, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(int);
    printf("\nList 1: ");
    printArrayInt(nums1, numsSize1);    
    nextPermutation(nums1, numsSize1);
    printf("Solution 1: ");
    printArrayInt(nums1, numsSize1);

    printf("\nTest 2:\n");
    int nums2[3] = {3, 2, 1};
    int numsSize2 = sizeof(nums2) / sizeof(int);
    printf("\nList 2: ");
    printArrayInt(nums2, numsSize2);    
    nextPermutation(nums2, numsSize2);
    printf("Solution 2: ");
    printArrayInt(nums2, numsSize2);

    printf("\nTest 3:\n");
    int nums3[3] = {1, 1, 5};
    int numsSize3 = sizeof(nums3) / sizeof(int);
    printf("\nList 3: ");
    printArrayInt(nums3, numsSize3);    
    nextPermutation(nums3, numsSize3);
    printf("Solution 3: ");
    printArrayInt(nums3, numsSize3);
 
    return EXIT_SUCCESS;
}
