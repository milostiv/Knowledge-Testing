#!/usr/bin/python3

class Solution:
	'''
	Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
	Return the sum of the three integers.
	You may assume that each input would have exactly one solution.
	'''
	def threeSumClosest(self, nums: list, target: int) -> int:
		pass
	
	def threeSum(self, nums):	
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
