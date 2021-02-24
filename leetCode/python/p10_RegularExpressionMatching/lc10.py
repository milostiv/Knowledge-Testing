import time

class Solution:
    """
    Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 
    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.
    
    The matching should cover the entire input string (not partial)
    """
    def isMatch(self, s: str, p: str) -> bool:
        rows, columns = len(s), len(p)
         
        # Both strings empty
        if rows == 0 and columns == 0: 
            return True

        # Pattern empty
        if columns == 0:                           
            return False

        # Dynamic programming matrix        
        dp = [[False for j in range(columns + 1)] for i in range(rows + 1)]
    
        # Match if both string and pattern are empty
        dp[0][0] = True

        # For patterns with *
        for i in range(2, columns + 1):
            if p[i - 1] == '*':
                dp[0][i] = dp[0][i - 2]

        # For remaining characters
        for i in range(1, rows + 1):
            for j in range(1, columns + 1):
                if s[i - 1] == p[j - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif j > 1 and p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2]
                    if p[j - 2] == '.' or p[j - 2] == s[i - 1]:
                        dp[i][j] = dp[i][j] or dp[i - 1][j]
        
        return dp[rows][columns]

        
    def test_function(self, s: str, p: str, sol: bool, test_num: int): 
        start_time = time.time() 
        tmp = self.isMatch(s, p)
        end_time = time.time()
        
        if tmp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))            
        else:
            print('\nTEST FAILED') 

sol = Solution()

# Test 1

s = 'aa'
p = 'a'
sol.test_function(s, p, False, 1)

# Test 2

s = 'aa'
p = 'a*'
sol.test_function(s, p, True, 2)

# Test 3

s = 'ab'
p = '.*'
sol.test_function(s, p, True, 3)

# Test 4

s = 'aab'
p = 'c*a*b'
sol.test_function(s, p, True, 4)

# Test 5

s = 'mississippi'
p = 'mis*is*p*.'
sol.test_function(s, p, False, 5)
