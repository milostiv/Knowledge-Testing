#!/usr/bin/python3

class Solution:
    '''
        Given two non-negative integers num1 and num2 represented as strings, 
        return the product of num1 and num2, also represented as a string.

        Note: You must not use any built-in BigInteger library or 
        convert the inputs to integer directly.
    '''
    def num_str_to_int(self, num: str) -> int:
        
        ans = 0
        dec = 1

        for i in range(len(num)):
        
            ans += (ord(num[len(num) - 1 - i]) - 48) * dec
            dec *= 10

        return ans

    def num_int_to_str(self, num: int) -> str:
        
        ans = str()
        i = 0
        
        while num > 0:

            temp = num % 10
            ans += chr(temp + 48)  
            num = num // 10

        ans = ans[::-1]
        return ans
    
    def multiply(self, num1: str, num2: str) -> str:

        ans = 0
        
        ans = self.num_str_to_int(num1) * self.num_str_to_int(num2)
        ans_st = self.num_int_to_str(ans)

        return ans_st

if __name__ == '__main__':
   
    s = Solution()
 
    # Test 1:

    print('Test 1:\n')
    num1 = '2'
    num2 = '3'
    print('Number 1: {}\nNumber 2: {}'.format(num1, num2))
    sol = s.multiply(num1, num2)
    print('Solution 1: {}'.format(sol))
    
    # Test 2:

    print('\nTest 2:\n')
    num1 = '123'
    num2 = '456'
    print('Number 1: {}\nNumber 2: {}'.format(num1, num2))
    sol = s.multiply(num1, num2)
    print('Solution 2: {}'.format(sol))
