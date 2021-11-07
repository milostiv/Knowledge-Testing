#!/usr/bin/python3

import time

class Solution:
    """
    Given a 32-bit signed integer, reverse digits of an integer.
    """
    def reverse(self, x: int) -> int:   
        sign = False  
        
        if x < 0:
            sign = True
            x = -x 
        x_str = str(x)[::-1]
        sol = int(x_str) 
        
        if sign:
            sol *= -1  
        index = 0 
         
        # remove zeros from begining
        if x_str != '0': 
            while x_str[index] == '0':
                x_str = x_str[:index] + x_str[index+1:] 
        
        return sol 
    
    def test_function(self, x: int, sol: int, test_num: int):
        start_time = time.time() 
        tmp = self.reverse(x) 
        end_time = time.time()
        if tmp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))            
        else:
            print('\nTEST FAILED') 
         
# Test 1
            
num = 123
sol = Solution()
sol.test_function(num, 321, 1)

# Test 2

num = -123
sol = Solution()
sol.test_function(num, -321, 1)

# Test 3

num = 120
sol = Solution()
sol.test_function(num, 21, 1)

# Test 4

num = 0
sol = Solution()
sol.test_function(num, 0, 1)
