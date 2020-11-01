/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int *nums, int numsSize, int target, int *returnSize) {
    
    int *answer = (int*) malloc(*returnSize * sizeof(int)); 
    answer[0] = -1;
    answer[1] = -1;

    for(int i=0; i<numsSize-1; i++) {
        for(int j=i+1; j<numsSize; j++) {
            if(nums[i] + nums[j] == target) {   
                answer[0] = i;
                answer[1] = j;   
                return answer;
            }
        }
    }

    return answer;
}   

/* Test */

void testFunction(int *testNums, int numsSize, int target, int *returnSize, int *solution, int testNumber) {
   
    *returnSize = 2; 
    int *answer = (int*) malloc(*returnSize * sizeof(int));
    double timeSpent; 

    printf("\nTEST%d: ", testNumber);
    
    clock_t tic = clock();
 
    answer = twoSum(testNums, numsSize, target, returnSize);
    
    clock_t toc = clock();
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;

    if(answer[0] == solution[0] && answer[1] == solution[1]) {
        printf("PASSED IN %.2fus\n", timeSpent);
    }
    else
        printf("FAILED\n");

    free(answer);
}

int main(void) {

    int returnSize;

    int test1[3] = {3, 2, 4};
    int solution1[2] = {1, 2};
    
    testFunction(test1, 3, 6, &returnSize, solution1, 1);
    
    int test2[4] = {2, 7, 11, 15};
    int solution2[2] = {0, 1};
 
    testFunction(test2, 4, 9, &returnSize, solution2, 2);
    
    int test3[2] = {3, 3};
    int solution3[2] = {0, 1};
 
    testFunction(test3, 2, 6, &returnSize, solution3, 3);

    return EXIT_SUCCESS;
}
