/* You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

bool canJump(int* nums, int numsSize){
   
    int curr = 0; 
    int i = 0;

    for(; i < numsSize && i <= curr; i++)
        curr = maxInt(curr, i + nums[i]); 

    return i == numsSize;
}

int main(void) {

    // Test 1:

    printf("Test 1:\n");
    int nums1[5] = {2, 3, 1, 1, 4};
    int numsSize1 = sizeof(nums1) / sizeof(int); 
    printf("\nList 1: "); 
    printArrayInt(nums1, numsSize1);
    if(canJump(nums1, numsSize1))
        printf("\nSolution 1: True");
    else 
        printf("\nSolution 1: False");

    // Test 2:

    printf("\nTest 2:\n");
    int nums2[5] = {3, 2, 1, 0, 4};
    int numsSize2 = sizeof(nums2) / sizeof(int); 
    printf("\nList 2: "); 
    printArrayInt(nums2, numsSize2);
    if(canJump(nums2, numsSize2))
        printf("\nSolution 2: True");
    else 
        printf("\nSolution 2: False");

    return EXIT_SUCCESS;
}
