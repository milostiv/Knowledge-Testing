#!/usr/bin/python3

import time

class Solution:
	def fourSum(self, nums: list, target: int):	
		matrix = []
		previous_temp_list = []
		nums.sort()	
		
		for i in range(len(nums)-3):
			if i>0 and nums[i] == nums[i-1]:
				continue
			for j in range(i+1, len(nums)-2):
				for k in range(j+1, len(nums)-1):
					for l in range(k+1, len(nums)):
						if nums[i] + nums[j] + nums[k] + nums[l] == target:
							temp_list = [nums[i], nums[j], nums[k], nums[l]]
							if temp_list != previous_temp_list:
								matrix.append(temp_list)
							previous_temp_list = temp_list
		return matrix

		
	def test_function(self, nums: list, target: int, sol: list, test_num: int): 
		start_time = time.time()
		temp = self.fourSum(nums, target)
		end_time = time.time()
        
		if temp == sol:
			print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
		else:
			print('\nTEST FAILED')        

s = Solution()

# Test 1

nums = [1,0,-1,0,-2,2]
target = 0
sol = [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

s.test_function(nums, target, sol, 1)

# Test 2

nums = [2,2,2,2,2]
target = 8
sol = [[2,2,2,2]]

s.test_function(nums, target, sol, 2)
