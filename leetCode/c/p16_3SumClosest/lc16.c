/* Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int threeSumClosest(int* nums, int numsSize, int target){
	
	int closestSum = 10000;
	int threeSum = 0;

	for(int i=0; i<numsSize-2; i++) {
		for(int j=i+1; j<numsSize-1; j++) {
			for(int k=j+1; k<numsSize; k++) {
				threeSum = nums[i] + nums[j] + nums[k];
				
				if((target - threeSum) < closestSum)
					closestSum = threeSum;
			}
		}
	}
	
	return closestSum;
}

// Test

void testFunction(int* nums, int numsSize, int target, int sol) {

    double timeSpent;
	int solution;
	static int testNum = 1;

    clock_t tic = clock();
 
	solution = threeSumClosest(nums, numsSize, target);
 
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
     
    if(solution == sol)
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");

	testNum++;
}

int main(void) {
	
	int nums1[4] = {-1, 2, 1, -4};
	int numsSize = sizeof(nums1)/sizeof(int);
	
	int target = 1;
	int sol = 2;

	testFunction(nums1, numsSize, target, sol);

	int nums2[3] = {0, 0, 0};
	numsSize = sizeof(nums2)/sizeof(int);
	sol = 0;	

	testFunction(nums2, numsSize, target, sol);

	return EXIT_SUCCESS;
}
