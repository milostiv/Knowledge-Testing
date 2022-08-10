#!/usr/bin/python3

import time

class Solution:
	'''
	Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
	Return the sum of the three integers.
	You may assume that each input would have exactly one solution.
	'''	
	def threeSumClosest(self, nums: list, target: int) -> int:
		closest_sum = 10000;
	
		for i in range(len(nums)-2):
			for j in range(i+1, len(nums)-1):
				for k in range(j+1, len(nums)):
					three_sum = nums[i] + nums[j] + nums[k]
					if abs(target - three_sum) < closest_sum:
						closest_sum = three_sum

		return closest_sum
	
	def test_function(self, nums: list, target: int, sol: int, test_num: int): 
		start_time = time.time()
		temp = self.threeSumClosest(nums, target)
		end_time = time.time()
        
		if temp == sol:
			print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
		else:
			print('\nTEST FAILED')        
					
s = Solution()

# Test 1
	
nums = [-1,2,1,-4]
target = 1
sol = 2

s.test_function(nums, target, sol, 1)

# Test 2

nums = [0, 0, 0]
target = 1
sol = 0

s.test_function(nums, target, sol, 2)
