import time

class Solution:    
    """
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order. 
    """ 
    def twoSum(self, nums, target): 
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sum = {}
        for i in range(len(nums)):
            difference = target - nums[i]    
            if difference in sum:
                return [sum.get(difference)+1, i+1]
            else: 
                sum[nums[i]] = i


nums = [1, 3, 5, 4, 2, 6, 8, 7, 9, 10]
answer = []

start_time = time.time()

print(Solution.twoSum(answer, nums, 16))

print('{:.3f}us'.format((time.time() - start_time) * 1000000))
