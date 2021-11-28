#!/usr/bin/python3

import time

target = 0

class Solution:
	'''
	Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
	and nums[i] + nums[j] + nums[k] == 0. Notice that the solution set must not contain duplicate triplets.
	'''
	def threeSum(self, nums):	
		currRow = 0	
		matrix = []		
		nums.sort()	
		
		for i in range(len(nums)-2):
			if i>0 and nums[i] == nums[i-1]:
				continue
			for j in range(i+1, len(nums)-1):
				for k in range(j+1, len(nums)):
					if nums[i] + nums[j] + nums[k] == target:
						temp_list = [nums[i], nums[j], nums[k]]
						matrix.append(temp_list)
		return matrix

	
	def test_function(self, nums, sol, test_num): 
		start_time = time.time()
		temp = self.threeSum(nums)
		end_time = time.time()
        
		if temp == sol:
			print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
		else:
			print('\nTEST FAILED')        

s = Solution()

# Test 1

nums = [-1,0,1,2,-1,-4]
sol = [[-1,-1,2],[-1,0,1]] 

s.test_function(nums, sol, 1)

# Test 2

nums = []
sol = []

s.test_function(nums, sol, 2)

# Test 3

nums = [0]
sol = []

s.test_function(nums, sol, 3)
