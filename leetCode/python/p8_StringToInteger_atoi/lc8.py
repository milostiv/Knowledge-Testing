#!/usr/bin/python3

import time

class Solution:
    """
    Implement atoi which converts a string to an integer.

    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this 
    character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

    The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of 
    this function.

    If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is 
    empty or it contains only whitespace characters, no conversion is performed.

    If no valid conversion could be performed, a zero value is returned.
    """
    def myAtoi(self, s: str) -> int:        
        first_digit = False
        sign = 1
        n = 0
        i = 0
        
        while i < len(s):
            if first_digit == False:
                # discard white characters
                while s[i] == ' ' and i < len(s):
                    i += 1

                #check for sign
                if s[i] == '-' and i < len(s):
                    sign *= -1
                    i += 1
            
            # get next digit
            if s[i].isdigit():
                n = n * 10 + ord(s[i]) - ord('0')
                first_digit = True
                i += 1
            else:
                break
             
        return n * sign

    def test_function(self, s: str, sol: int, test_num: int): 
        start_time = time.time() 
        tmp = self.myAtoi(s)
        end_time = time.time()
        
        if tmp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))            
        else:
            print('\nTEST FAILED') 

# Test

s1 = '42'
s2 =  '   -42'
s3 = '4193 with words'

s = Solution()
n = s.test_function(s1, 42, 1)
n = s.test_function(s2, -42, 2)
n = s.test_function(s3, 4193, 3)
