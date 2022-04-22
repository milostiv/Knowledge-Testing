#!/usr/bin/python3

import time

class Solution:
	'''
	Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	'''
	def __init__(self):
		self.test_num = 1

	def isValid(self, s: str) -> bool:
		stack = []	
		opening = '([{'
		closing = ')]}'
		pair = {')' : '(', ']' : '[', '}' : '{'}
		
		for i in s:
			if i in opening:
				stack.append(i)
			if i in closing:
				if not stack or stack.pop() != pair[i]:
					return False

		if not stack:
			return True
		else:
			return False				

	def test_function(self, s: str, sol: bool):
		start_time = time.time()
		temp = self.isValid(s)
		end_time = time.time()
		
		if temp == sol:	
			print('\nTEST' + str(self.test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
		else:
			print('\nTEST FAILED')        
	
		self.test_num += 1

s = Solution()

# Test 1

s1 = '()'
s.test_function(s1, True)

# Test 2

s2 = '()[]{}'
s.test_function(s2, True)

# Test 3

s3 = '(]'
s.test_function(s3, False)
