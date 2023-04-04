#!/usr/bin/python3

import numpy as np

class Solution:
    '''
        Given a collection of numbers, nums, that might contain duplicates, 
        return all possible unique permutations in any order.
    '''

    ans = []
    ds = []

    def print_mat(self, mat):

        print(np.matrix(mat))
    
    def recur_permute_unique(self, nums: list, freq: list):

        if len(self.ds) == len(nums) and self.ds not in self.ans:
            self.ans.append(self.ds.copy())
            return
       
        for i in range(len(nums)):
            if not freq[i]:
                self.ds.append(nums[i])
                freq[i] = 1
                self.recur_permute_unique(nums, freq)
                freq[i] = 0
                self.ds.pop() 

    def permuteUnique(self, nums: list):

        self.ans = []
        self.ds = []
        freq = [0] * len(nums)
    
        self.recur_permute_unique(nums, freq)
        return self.ans

if __name__ == '__main__':

    s = Solution()

    # Test 1:
 
    print('Test 1:\n') 
    nums = [1,1,2]
    print('List 1: {}\n'.format(nums))
    sol = s.permuteUnique(nums)
    print('Solution 1:')
    s.print_mat(sol)    

    # Test 2:

    print('Test 2:\n') 
    nums = [1,2,3]
    print('List 2: {}\n'.format(nums))
    sol = s.permuteUnique(nums)
    print('Solution 2:')
    s.print_mat(sol)
