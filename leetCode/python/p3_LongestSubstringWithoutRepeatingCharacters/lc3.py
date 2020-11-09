class Solution:
    """
    Given a string s, find the length of the longest substring without repeating characters. 
    """
    def __init__(self, input_string: str):
        self.string = inputString
    
    def lengthOfLongestSubstring(self) -> int:
        substring_letters = {}
        curr_substring_start = 0
        curr_len = 0         
        longest = 0
        
        for i, letter in enumerate(self.string): 
            if letter in sub and sub[letter] >= curr_substring_start:
                curr_substring_start = sub[letter] + 1
                curr_len = i - sub[letter] # Ovo verovatno moze da se izbaci... 
                sub[letter] = i
            else:
                sub[letter] = i
                curr_len += 1
                if curr_len > longest
                    longest = curr_len

        return longest
     
    def testFunction(self, sol_num: int, test_num: int):
        pass

# Test 1


# Test 2


# Test 3


