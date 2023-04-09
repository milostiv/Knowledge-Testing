/* You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    * 0 <= j <= nums[i] and
    * i + j < n

Return the minimum number of jumps to reach nums[n - 1]. 
The test cases are generated such that you can reach nums[n - 1]. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

int jump(int* nums, int numsSize) {

    int prev = 0;
    int curr = 0;
    int level = 0;

    while(curr < numsSize - 1) {
        
        level++;

        prev = curr;
    
        for(int i=0; i <= prev; i++) { 
            
            curr = maxInt(curr, i + nums[i]);             
        }
    }
        
    return level;
}

int main(void) {

    // Test 1:

    printf("Test 1:\n");
    int nums1[5] = {2, 3, 1, 1, 4};
    int numsSize1 = sizeof(nums1) / sizeof(int); 
    printf("\nList 1: "); 
    printArrayInt(nums1, numsSize1);
    printf("\nSolution 1: %d", jump(nums1, numsSize1));

    // Test 2:

    printf("\nTest 2:\n");
    int nums2[5] = {2, 3, 0, 1, 4};
    int numsSize2 = sizeof(nums2) / sizeof(int); 
    printf("\nList 2: "); 
    printArrayInt(nums2, numsSize2);
    printf("\nSolution 2: %d", jump(nums2, numsSize2));

    return EXIT_SUCCESS;
}
