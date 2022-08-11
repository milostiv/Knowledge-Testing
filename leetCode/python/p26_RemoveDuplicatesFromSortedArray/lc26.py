#!/usr/bin/python

class Solution:
	'''
		Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

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

	def removeDuplicates(self, nums: list) -> int:	

		count = 0

		for i in range(len(nums)):
			
			if i < len(nums) - 2 and nums[i] == nums[i+1]:
				continue

			nums[count] = nums[i]
			count += 1
		
		return count  		

s = Solution()

# Test 1:

print('Test 1: ', end = '\n\n')

nums = [1, 1, 2]
nums_size = len(nums)

print("List 1 before removing duplicates:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 1 size before removing duplicates:", end = ' ')
print(nums_size)

nums_size = s.removeDuplicates(nums)

print("List 1 after removing duplicates:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 1 size after removing duplicates:", end = ' ')
print(nums_size)

# Test 2:

print('\nTest 2: ', end = '\n\n')

nums = [0,0,1,1,1,2,2,3,3,4]
nums_size = len(nums)

print("List 2 before removing duplicates:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 2 size before removing duplicates:", end = ' ')
print(nums_size)

nums_size = s.removeDuplicates(nums)

print("List 2 after removing duplicates:", end = ' ')
s.print_list_limited(nums, nums_size)
print("List 2 size after removing duplicates:", end = ' ')
print(nums_size)
