import time

class Solution:
    """
    Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two 
    endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container 
    contains the most water.
    """
    def maxArea(self, height) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1
        
        while left < right:
            area = (right - left) * min(height[left], height[right])
            
            if area > max_area:
                max_area = area
            
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1

        return max_area 

    def test_function(self, height, sol: int, test_num: int): 
        start_time = time.time()
        temp = self.maxArea(height)
        end_time = time.time()
        
        if temp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')        
    
s = Solution()

# Test 1

height = [1,8,6,2,5,4,8,3,7]
s.test_function(height, 49, 1)

# Test 2

height = [1,1]
s.test_function(height, 1, 2)

# Test 3

height = [4,3,2,1,4]
s.test_function(height, 16, 3)

# Test 4

height = [1,2,1]
s.test_function(height, 2, 4)
