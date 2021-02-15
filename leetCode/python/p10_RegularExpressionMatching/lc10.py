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
        dp = [[False for i in range(rows + 1)] for j in range(columns + 1)]
    
        # Match if both string and pattern are empty
        dp[0][0] = True

        # Nastavak sutra        
