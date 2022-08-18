#!/usr/bin/python

NEEDLE_NOT_IN_HAYSTACK = -1

class Solution:
	''' 
		Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
	'''

	def strStr(self, haystack: str, needle: str) -> int:
	
		haystack_size = len(haystack)
		needle_size = len(needle)
	
		for i in range(0, haystack_size - needle_size + 1):
			
			for j in range(0, needle_size):
				
				if(haystack[i+j] != needle[j]):
					break

			if j == needle_size-1:
				return i

		return NEEDLE_NOT_IN_HAYSTACK

s = Solution()

# Test 1:

print('Test 1: ', end = '\n\n')

haystack1 = "hello"
needle1 = "ll"

print("Haystack: " + str(haystack1))
print("Needle: " + str(needle1))

sol = s.strStr(haystack1, needle1)

print("Test 1 solution: " + str(sol))

# Test 2:

print('\nTest 2: ', end = '\n\n')

haystack2 = "aaaaa"
needle2 = "bba"

print("Haystack: " + str(haystack2))
print("Needle: " + str(needle2))

sol = s.strStr(haystack2, needle2)

print("Test 2 solution: " + str(sol))
