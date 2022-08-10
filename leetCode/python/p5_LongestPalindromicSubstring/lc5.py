#!/usr/bin/python3

import time 

class Solution:
    """
    Given a string s, return the longest palindromic substring in s.
    """
    def find_palindrome(self, s: str, l: int, r: int) -> str:
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1 # decrement to left
            r += 1 # increment to right        
        return s[l+1:r]
    
    def longestPalindrome(self, s: str) -> str:
        longest = ''
        for i in range(len(s)):
            # odd case
            tmp = self.find_palindrome(s, i, i) 
            if len(tmp) > len(longest):
                longest = tmp
            # even case
            tmp = self.find_palindrome(s, i, i+1) 
            if len(tmp) > len(longest):
                longest = tmp
        return longest

    def test_function(self, s: str, sol: str, test_num: int):        
        start_time = time.time() 
        tmp = self.longestPalindrome(s) 
        end_time = time.time()        
        if(sol == tmp):
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')

# Test 1         

string = 'babad'
s = Solution()
s.test_function(string, 'bab', 1)

# Test 2

string = 'cbbd'
s = Solution()
s.test_function(string, 'bb', 1)

# Test 3

string = 'a'
s = Solution()
s.test_function(string, 'a', 1)

# Test 4

string = 'ac'
s = Solution()
s.test_function(string, 'a', 1)
