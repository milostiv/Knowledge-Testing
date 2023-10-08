#!/usr/bin/python3

class Solution:
    '''
        The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
        countAndSay(1) = "1"
        countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
        which is then converted into a different digit string.

        To determine how you "say" a digit string, 
        split it into the minimal number of substrings such that each substring 
        contains exactly one unique digit. Then for each substring, 
        say the number of digits, then say the digit. 
        Finally, concatenate every said digit.
    '''
    def countAndSay(self, n: int) -> str:
        res = '1'

        for i in range(1, n):
            count = 0
            prev = '.'
            curr_str = ''

            for char in res:
                if char == prev or prev == '.':
                    count += 1
                else:
                    curr_str += str(count) + prev
                    count = 1
                prev = char 

            curr_str += str(count) + prev
            res = curr_str 

        return res

if __name__ == '__main__':

    s = Solution()

    # Test 1:

    print('Test 1:')
    n1 = 1
    sol1 = s.countAndSay(n1)

    print('Number: ' + str(n1))
    
    print('Solution: ' + str(sol1))

    # Test 2:
       
    print('\nTest 2:')
    n2 = 4
    sol2 = s.countAndSay(n2)

    print('Number: ' + str(n2))
    
    print('Solution: ' + str(sol2))
