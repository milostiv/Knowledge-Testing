import time

class Solution:
    """
    Given a string s, find the length of the longest substring without repeating characters. 
    """
    def lengthOfLongestSubstring(self, s: str) -> int:
        substring = {}
        curr_substring_start = 0
        curr_len = 0         
        longest = 0
        
        for i, letter in enumerate(s): 
            if letter in substring and substring[letter] >= curr_substring_start:
                curr_substring_start = substring[letter] + 1
                curr_len = i - substring[letter] 
                substring[letter] = i
            else:
                substring[letter] = i
                curr_len += 1
                if curr_len > longest:
                    longest = curr_len

        return longest
     
    def test_function(self, s: str, sol_num: int, test_num: int):
        start_time = time.time() 
        sol = self.lengthOfLongestSubstring(s) 
        end_time = time.time()
        if(sol == sol_num):
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')
            
# Test 1

string = 'abcabcbb' 
s = Solution()
s.test_function(string, 3, 1)

# Test 2

string = 'bbbbb' 
s = Solution()
s.test_function(string, 1, 2)

# Test 3

string = 'pwwkew' 
s = Solution()
s.test_function(string, 3, 3)

# Test 4

string = ''
s = Solution()
s.test_function(string, 0, 4)
