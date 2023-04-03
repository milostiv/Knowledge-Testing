#!/usr/bin/python3

import numpy as np

class Solution:
    '''
        Given an array nums of distinct integers, return all the possible permutations. 
        You can return the answer in any order. 
    '''

    ans = []
    ds = []

    def print_mat(self, mat):

        print(np.matrix(mat))
    
    def recur_permute(self, nums: list, freq: list):

        if len(self.ds) == len(nums):
            self.ans.append(self.ds.copy())
            return
       
        for i in range(len(nums)):
            if not freq[i]:
                self.ds.append(nums[i])
                freq[i] = 1
                self.recur_permute(nums, freq)
                freq[i] = 0
                self.ds.pop() 

    def permute(self, nums: list):

        self.ans = []
        self.ds = []
        freq = [0] * len(nums)
    
        self.recur_permute(nums, freq)
        return self.ans

if __name__ == '__main__':

    s = Solution()
       
    # Test 1:

    print('Test 1:\n')
    
    nums = [1,2,3]

    print('List 1: {}\n'.format(nums))

    sol = s.permute(nums)

    print('Solution 1:')

    s.print_mat(sol)

    # Test 2:

    print('\nTest 2:\n')

    nums = [0, 1]

    print('List 2: {}\n'.format(nums))

    sol = s.permute(nums)

    print('Solution 2:')

    s.print_mat(sol)

    # Test 3:

    print('\nTest 3:\n')

    nums = [1]

    print('List 3: {}\n'.format(nums))

    sol = s.permute(nums)

    print('Solution 3:')

    s.print_mat(sol)
