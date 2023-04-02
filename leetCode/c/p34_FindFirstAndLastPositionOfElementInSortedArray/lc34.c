/* Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1]. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

void searchRange(int* nums, int numsSize, int target, int* sol) {
    
    int start = 0;
    int end = numsSize - 1;
    int mid;
    sol[0] = -1;
    sol[1] = -1;

    if(numsSize == 0) {
        return;
    }

    while(start <= end) {
        
        mid = (start + end) / 2;

        if(nums[mid] == target) {
            
            sol[0] = mid - 1;
            int temp = mid;
        
            while(nums[mid] == nums[temp])
                temp++;

            sol[1] = temp - 1;

            break;
        }
        else if(nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1; 
    }        
}

int main(void) {

    int nums[6] = {5, 7, 7, 8, 8, 10}; 
    int numsSize = sizeof(nums) / sizeof(int);
    int sol[2] = {-1, -1};
    
    // Test 1:

    printf("\nTest 1:\n"); 

    int target1 = 8;

    printf("Array 1: "); 
    printArrayInt(nums, 6);
    printf("Target 1: %d\n", target1);
    searchRange(nums, numsSize, target1, sol);
    printf("Solution 1: ");
    printArrayInt(sol, 2); 

    // Test 2:

    printf("\nTest 2:\n"); 

    int target2 = 6;

    printf("Array 2: ");
    printArrayInt(nums, 6);
    printf("Target 2: %d\n", target2);
    searchRange(nums, numsSize, target2, sol);
    printf("Solution 2: ");
    printArrayInt(sol, 2); 

    // Test 3:

    printf("\nTest 3:\n"); 
   
    int target3 = 0;
    int* nums1;
    allocateArrayInt(nums1, 0);
 
    printf("Array 3: Empty\n");
    printf("Target 3: %d\n", target3);
    searchRange(nums1, 0, target3, sol);
    printf("Solution 3: ");
    printArrayInt(sol, 2); 

    return EXIT_SUCCESS;
}
