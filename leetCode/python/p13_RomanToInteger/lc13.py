#!/usr/bin/python3

import time 

roman_to_int_map = {
    'M':  1000,
    'CM': 900,
    'D':  500,
    'CD': 400,
    'C':  100, 
    'XC': 90,
    'L':  50, 
    'XL': 40,
    'X':  10, 
    'IX': 9, 
    'V':  5,
    'IV': 4,
    'I':  1
}

class Solution:
    """ Given a roman numeral, convert it to an integer """    
    def romanToInt(self, s: str) -> int:  
        num = i = 0 
        temp = ''
        
        while i < len(s):  
            if (s[i] == 'C' or s[i] == 'X' or s[i] == 'I') and i+1 < len(s): 
                temp = s[i] + s[i+1]  
                if temp in roman_to_int_map.keys():
                    num += roman_to_int_map[temp]
                    i += 1
                else:
                    num += roman_to_int_map[s[i]] 
            else: 
                num += roman_to_int_map[s[i]]         

            i += 1
        
        return num
                        
    def test_function(self, rom_num: str, sol: int, test_num: int): 
        start_time = time.time()
        temp = self.romanToInt(rom_num)
        end_time = time.time()
        
        if temp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')        

s = Solution()

# Test 1

s.test_function('III', 3, 1)

# Test 2

s.test_function('IV', 4, 2)

# Test 3

s.test_function('IX', 9, 3)

# Test 4 

s.test_function('LVIII', 58, 4)

# Test 5

s.test_function('MCMXCIV', 1994, 5)
