#!/usr/bin/python

class Solution:
	'''
		Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

		Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
		More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

		Return k after placing the final result in the first k slots of nums.
	'''
	def printListLimited(self, nums: list, printSize: int):
			
		i = 0
	
		while(i < printSize):
			print(nums[i], end = ' ')
			i += 1
		
		print()
	
	def removeDuplicates(self, nums: list) -> int:
		pass	

# Test 1:

s = Solution()

print('Test 1: ', end = '\n\n')

nums = [1, 1, 2]
nums_size = 3

print("List 1 before removing duplicates:", end = ' ')
s.printListLimited(nums, nums_size)
