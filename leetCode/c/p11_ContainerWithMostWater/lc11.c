/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two end    
points of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains     
the most water. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int maxArea(int* height, int heightSize) {
    
    int max = 0, area = 0, left = 0, right = heightSize - 1;

    while(left < right) {
        area = (right - left) * MIN(height[left], height[right]);

        if(area > max) 
            max = area;

        if(height[left] > height[right])
            right--;
        else 
            left++; 
    }

    return max;
}

/* Test */ 


void testFunction(int* height, int heightSize, int sol, int testNumber) {
    
    int tmp; 
    double timeSpent;  
 
    clock_t tic = clock();
 
    tmp = maxArea(height, heightSize);
    
    clock_t toc = clock();
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;

    printf("\nTEST%d: ", testNumber);

    if(tmp == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else
        printf("FAILED\n");
}
    
int main(void) {
    
    int height1[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height1)/sizeof(height1[0]);
    
    testFunction(height1, heightSize, 49, 1); 
    
    int height2[] = {1,1};
    heightSize = sizeof(height2)/sizeof(height2[0]);
    
    testFunction(height2, heightSize, 1, 2); 

    int height3[] = {4,3,2,1,4};
    heightSize = sizeof(height3)/sizeof(height3[0]);
    
    testFunction(height3, heightSize, 16, 3); 

    int height4[] = {1,2,1};
    heightSize = sizeof(height4)/sizeof(height4[0]);
    
    testFunction(height4, heightSize, 2, 4); 
 
    return EXIT_SUCCESS;
}
