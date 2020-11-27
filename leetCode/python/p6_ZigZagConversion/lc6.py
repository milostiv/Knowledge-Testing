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

    def print_zig_zag_elements(self, s: str, numRows: int):
        curr_pos = 0
        i = 1
        string_list = []
        while len(s) > curr_pos:
            if i % 2 == 0:
                string_list.append(s[curr_pos:(curr_pos + numRows - 2)])
                curr_pos += numRows - 2
            else:  
                string_list.append(s[curr_pos:(curr_pos + numRows)])
                curr_pos += numRows
            i += 1
        print(string_list) 

string = 'PAYPALISHIRING'
s = Solution()
s.print_zig_zag_elements(string, 4)
