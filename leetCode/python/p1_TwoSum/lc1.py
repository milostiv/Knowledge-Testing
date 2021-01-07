import time

class Solution:    
    """
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order. 
    """ 
    def two_sum(self, nums: list, target: int) -> list: 
        sum = {}
        for i in range(len(nums)):
            difference = target - nums[i]    
            if difference in sum:
                return [sum.get(difference), i]
            else: 
                sum[nums[i]] = i

    def test_function(self, nums: list, target: int, sol: list, test_num: int): 
        answer = []
        start_time = time.time()
        answer = self.two_sum(nums, target) 
        end_time = time.time()
        if answer[0] == sol[0] and answer[1] == sol[1]:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')        

s = Solution()

# Test 1

nums = [2,7,11,15]
target = 9
sol = [0, 1]

s.test_function(nums, target, sol, 1)

# Test 2

nums = [3, 2, 4]
target = 6
solution = [1, 2]

s.test_function(nums, target, solution, 2)

# Test 3

nums = [3, 3]
target = 6
solution = [0, 1]

s.test_function(nums, target, solution, 3)
