#!/usr/bin/python3

class Solution:	
	"""
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
	"""
	def _generateParentheses(self, string: list, pos: int, n: int, opened: int, closed: int):
	
		if closed == n:
			for char in string:	
				print(char, end='')

			print()
			return
		else: 
			if opened > closed:
				string[pos] = ')'
				self._generateParentheses(string, pos + 1, n, opened, closed + 1)

			if opened < n:
				string[pos] = '('
				self._generateParentheses(string, pos + 1, n, opened + 1, closed)	
	
	def generateParentheses(self, string: list, n: int):
	
		if n > 0:
			self._generateParentheses(string, 0, n, 0, 0)

s = Solution()

# Test 1:

n = 3
print('Test 1: N =', n)
string = [""]*2*n
s.generateParentheses(string, n)
print()

# Test 2:

n = 1
print('Test 2: N =', n)
string = [""]*2*n
s.generateParentheses(string, n)
print()
