/*  Given a sorted array of distinct integers and a target value,
return the index if the target is found. 

If not, return the index where it would be if it were inserted in order. */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {

    int start = 0;
    int end = numsSize - 1;
    int mid;

    while(start <= end) {
        
        mid = (start + end) / 2;
       
        if(nums[mid] == target) 
            return mid;
        else if(nums[mid] < target)
            start = mid + 1;
        else 
            end = mid - 1;  
    }

    return end + 1;
}

int main(void) {

    int nums[4] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(int);

    // Test 1:

    int target1 = 5;

    printf("Test 1: \nTarget (%d) insert position is %d.\n", target1, searchInsert(nums, numsSize, target1));

    // Test 2:

    int target2 = 2;

    printf("\nTest 2: \nTarget (%d) insert position is %d.\n", target2, searchInsert(nums, numsSize, target2));

    // Test 3:

    int target3 = 7;

    printf("\nTest 3: \nTarget (%d) insert position is %d.\n", target3, searchInsert(nums, numsSize, target3));

    return EXIT_SUCCESS;
}
