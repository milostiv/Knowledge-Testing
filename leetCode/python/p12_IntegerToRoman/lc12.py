import time

int_to_roman_map = {
    1000: 'M',
    900:  'CM',
    500:  'D',
    400:  'CD',
    100:  'C', 
    90:   'XC',
    50:   'L', 
    40:   'XL',
    10:   'X', 
    9:    'IX', 
    5:    'V',
    4:    'IV',
    1:    'I'
}

class Solution:
    """
    Given an integer, convert it to a roman numeral
    Constraint: 1 <= num <= 3999
    """    
    def intToRoman(self, num: int) -> str:
        roman_numeral = ''

        for key, value in int_to_roman_map.items():
            while num >= key:
                roman_numeral += value
                num -= key

        return roman_numeral
    
    def test_function(self, sol: str, num: int, test_num: int): 
        start_time = time.time()
        temp = self.intToRoman(num)
        end_time = time.time()
        
        if temp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')        

s = Solution()

# Test 1

arabic_numeral = 3
s.test_function('III', 3, 1)

# Test 2 

arabic_numeral = 4
s.test_function('IV', 4, 2)

# Test 3

arabic_numeral = 9
s.test_function('IX', 9, 3)

# Test 4

arabic_numeral = 58 
s.test_function('LVIII', 58, 4)

# Test 5 

arabic_numeral = 1994
s.test_function('MCMXCIV', 1994, 5)
