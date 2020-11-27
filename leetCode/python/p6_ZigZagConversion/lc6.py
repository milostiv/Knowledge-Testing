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
        pass

    def print_zig_zag(self, s: str, numRows: int):
        start_elem = 0 
        curr_pos = start_elem
        end_string = (numRows - 2) * ' '
 
        if len(s) % (2 * numRows - 2) != 0:
            zig_zags = (len(s) // (2 * numRows - 2)) + 1
            last_elem = (2 * numRows - 2) * (zig_zags - 1) - 2
        else:
            zig_zags = (len(s) // (2 * numRows - 2))
            last_elem = (2 * numRows - 2) * zig_zags - 2

        while True:
            curr_char = s[curr_pos]
            print(curr_char, end = end_string)
            curr_pos += numRows + 1
            
            if curr_pos > len(s):
                start_elem += 1 
                curr_pos = start_elem
                print()
                
            if curr_pos == last_elem:
                print(curr_char, end = end_string)
                break
        
string = 'PAYPALISHIRING'
s = Solution()
s.print_zig_zag(string, 3)
