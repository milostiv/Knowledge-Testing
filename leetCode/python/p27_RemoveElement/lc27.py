#!/usr/bin/python

class Solution:
	''' 
		Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

	Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
	More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

	Return k after placing the final result in the first k slots of nums.
	'''
	def print_list_limited(self, nums: list, num_of_el: int):
	
		i = 0	
	
		while i < num_of_el:
			print(nums[i], end = ' ')
			i += 1

		print()
 
	def removeElement(self, nums: list, val: int) -> int:
		
		count = 0

		for i in range(len(nums)):
	
			if nums[i] == val:
				continue
		
			nums[count] = nums[i]
			count += 1

		return count

s = Solution()

# Test 1:

print('Test 1: ', end = '\n\n')

nums = [3,2,2,3]
nums_size = len(nums)
val = 3

print("List 1 before removing elements:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 1 size before removing elements:", end = ' ')
print(nums_size)

nums_size = s.removeElement(nums, val)

print("List 1 after removing elements:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 1 size after removing elements:", end = ' ')
print(nums_size)

# Test 2:

print('Test 2: ', end = '\n\n')

nums = [0,1,2,2,3,0,4,2]
nums_size = len(nums)
val = 2

print("List 2 before removing elements:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 2 size before removing elements:", end = ' ')
print(nums_size)

nums_size = s.removeElement(nums, val)

print("List 2 after removing elements:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 2 size after removing elements:", end = ' ')
print(nums_size)
