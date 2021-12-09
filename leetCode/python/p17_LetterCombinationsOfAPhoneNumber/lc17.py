#!/usr/bin/python3

import time

buttons = {
	'2' : 'abc',
	'3' : 'def',
	'4' : 'ghi',
	'5' : 'jkl',
	'6' : 'mno',
	'7' : 'pqrs',
	'8' : 'tuv',
	'9' : 'wxyz'
}

class Solution:
	'''
	Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

	A mapping of digit to letters is just like on the telephone buttons. Note that 1 does not map to any letters.
	'''
	test_num = 0
	
	def letterCombinations(self, digits: str) -> list:
		ans = []	
		if digits == '': 
			return []
	
		def recursive_search(pos: int, string: str):
			if pos >= len(digits):
				ans.append(string)
			else:
				letters = buttons[digits[pos]]
				for letter in letters:
					recursive_search(pos+1, string + letter)

		recursive_search(0, '')
		return ans	
	
	def test_function(self, digits: str, sol: list): 
		start_time = time.time()
		temp = self.letterCombinations(digits)
		end_time = time.time()
       
		self.test_num += 1	
 
		if temp == sol:
			print('\nTEST' + str(self.test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
		else:
			print('\nTEST' + str(self.test_num) + ': FAILED')        

s = Solution()

# Test 1

digits = '23'
sol = ['ad','ae','af','bd','be','bf','cd','ce','cf']

s.test_function(digits, sol)

# Test 2 

digits = ''
sol = []

s.test_function(digits, sol)

# Test 3

digits = '2'
sol = ['a','b','c']

s.test_function(digits, sol)
