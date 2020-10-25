/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int* answer = (int*)malloc(*returnSize * sizeof(int));
    answer[0] = -1;
    answer[1] = -1; 
     
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i] + nums[j] == target){
                answer[0] = i;
                answer[1] = j;
                return answer;
            }
        }
    }

    return answer; 
}

/* Test */
int main(void){
    
    int testNums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int testNumsSize = sizeof(testNums) / sizeof(testNums[0]);
    int testTarget = 18;
    int answerSize = 2; 
    int *testReturnSize = &answerSize; 
 
    int *answer = (int*)malloc(*testReturnSize * sizeof(int)); 
    
    clock_t tic = clock();

    answer = twoSum(testNums, testNumsSize, testTarget, testReturnSize);
   
    clock_t toc = clock(); 

    printf("[%d, %d]\n", answer[0], answer[1]);
   
    double time_spent_us = ((double) (toc - tic) / CLOCKS_PER_SEC) * 1000000;

    printf("%.3fus\n", time_spent_us);

    return EXIT_SUCCESS;
}
