/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int i = 0, j = 0; // Array indices
    int count; // Position counter
    double median1, median2; // Two medians in case of even number of elements
    
    if((nums1Size + nums2Size) % 2 == 1) { // Odd case
            
        for(count = 0; count <= (nums1Size + nums2Size) / 2; count++) {
        
            if(i != nums1Size && j != nums2Size) {
                                                     
                if(nums1[i] < nums2[j]) 
                    median1 = (double) nums1[i++]; 
                else 
                    median1 = (double) nums2[j++]; 
            }
            else if(i < nums1Size) 
                median1 = (double) nums1[i++];
            else
                median2 = (double) nums2[j++];
        }
    
        return median1;    
    } 
    
    else { // Even case
          
        for(count = 0; count <= (nums1Size + nums2Size) / 2; count++) {
            
            median2 = median1;
 
            if(i != nums1Size && j != nums2Size) {
                                                     
                if(nums1[i] < nums2[j]) 
                    median1 = (double) nums1[i++]; 
                else 
                    median1 = (double) nums2[j++]; 
            }
            else if(i < nums1Size) 
                median1 = (double) nums1[i++];
            else 
                median2 = (double) nums2[j++];
        }
    
        return (double) (median1 + median2) / 2;    
    }
}

/* Test */

void testFunction(int *nums1, int nums1Size, int *nums2, int nums2Size, double sol, int testNum) {

    double timeSpent;

    clock_t tic = clock();
 
    double num = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
 
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
     
    if(num == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {  

    // Test 1:
    
    int nums1[2] = {1, 3};
    int nums2[1] = {2};          

    testFunction(nums1, 2, nums2, 1, 2.0, 1);
  
    // Test 2:
    
    int nums3[2] = {1, 2};
    int nums4[2] = {3, 4};          

    testFunction(nums3, 2, nums4, 2, 2.5, 2);

    // Test 3:
    
    int nums5[2] = {0, 0};
    int nums6[2] = {0, 0};          

    testFunction(nums5, 2, nums6, 2, 0.0, 3);

    // Test 4:
    
    int nums7[1] = {1};
    int nums8[0] = {};          

    testFunction(nums7, 1, nums8, 0, 1.0, 4);

    // Test 5:
    
    int nums9[1] = {2};
    int nums10[0] = {};          

    testFunction(nums9, 1, nums10, 0, 2.0, 5);

    return EXIT_SUCCESS;
}
