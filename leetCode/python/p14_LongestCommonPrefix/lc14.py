import time 

class Solution: 
    """ 
    Write a function to find the longest common prefix string amongst an array of strings
    If there is no common prefix, return an empty string ""
    """
    def longestCommonPrefix(self, strs) -> str:
        prefix = strs[0]
        for s in strs:
            prefix = self.longest_prefix_between_two_strings(prefix, s)

        return prefix

    def longest_prefix_between_two_strings(self, str1: str, str2: str) -> str:
        i = 0 
        while i < len(str1) and i < len(str2):
            if str1[i] != str2[i]:
                break
            i += 1
        
        return str1[:i]
        
    def test_function(self, strs, sol: str, test_num: int): 
        start_time = time.time()
        temp = self.longestCommonPrefix(strs)
        end_time = time.time()
        
        if temp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')        

s = Solution()

# Test 1

strs = ['flower', 'flow', 'flight']

s.test_function(strs, 'fl', 1)

# Test 2

strs = ['dog', 'racecar', 'car']

s.test_function(strs, '', 2)
