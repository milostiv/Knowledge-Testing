import time 

class Solution:
    """            
    String "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a number of rows:
    """
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        delta = -1
        row = 0
        res = [[] for i in range(numRows)]
        
        for c in s:
            res[row].append(c)
            
            if row == 0 or row == numRows - 1:
                delta *= -1

            row += delta
            
        for i in range(len(res)):
            res[i] = ''.join(res[i])
        
        return ''.join(res)

    def test_function(self, s: str, numRows: int, sol: str, test_num: int):
        start_time = time.time() 
        tmp = self.convert(s, numRows) 
        end_time = time.time()
    
        if tmp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))            
        else:
            print('\nTEST FAILED') 
        
# Test 1
 
string = 'PAYPALISHIRING'
sol = 'PAHNAPLSIIGYIR'
s = Solution()
s.test_function(string, 3, sol, 1)

# Test 2
 
string = 'PAYPALISHIRING'
sol = 'PINALSIGYAHRPI'
s = Solution()
s.test_function(string, 4, sol, 2)

# Test 3
 
string = 'A'
sol = 'A'
s = Solution()
s.test_function(string, 1, sol, 3)
