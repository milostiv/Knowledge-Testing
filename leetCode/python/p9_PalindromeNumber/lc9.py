import time

class Solution:
    """
    Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
    """
    def isPalindrome(self, x: int) -> bool:
        if (x != 0 and x % 10 == 0) or x < 0:
            return False
        
        if self.flip_number(x) == x:
            return True
        else:
            return False 

    def flip_number(self, x: int) -> int:  
        sol = 0 
    
        while x != 0:
            sol = sol * 10 + (x % 10)
            x = x // 10 

        return sol

    def test_function(self, x: int, sol: bool, test_num: int): 
        start_time = time.time() 
        tmp = self.isPalindrome(x)
        end_time = time.time()
        
        if tmp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))            
        else:
            print('\nTEST FAILED') 

s = Solution()

# Test

s.test_function(121, True, 1)
s.test_function(-121, False, 2)
s.test_function(10, False, 3)
s.test_function(-101, False, 4)
