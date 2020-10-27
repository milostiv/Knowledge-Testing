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
                return [sum.get(difference), i]
            else: 
                sum[nums[i]] = i

    def testFunction(nums, target, solution, testNum): 
        """
        :type nums: List[int]
        :type target: int
        :type solution: List[int]
        :type testNum: int 
        """
        answer = []
        start_time = time.time()
        answer = Solution.twoSum(answer, nums, target)
        end_time = time.time()
        if(answer[0] != -1):
            print('TEST' + str(testNum) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('TEST FAILED')        

# Test 1
print()
nums = [2,7,11,15]
target = 9
solution = [0, 1]

Solution.testFunction(nums, target, solution, 1)

# Test 2
print()
nums = [3, 2, 4]
target = 6
solution = [1, 2]

Solution.testFunction(nums, target, solution, 2)

# Test 3
print()
nums = [3, 3]
target = 6
solution = [0, 1]

Solution.testFunction(nums, target, solution, 3)
