#!/usr/bin/python3

class Solution():
    '''
        A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

        For example, for arr = [1,2,3], the following are all the permutations of arr: 
            [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
        The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
        More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
        then the next permutation of that array is the permutation that follows it in the sorted container. 
        If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
    
        * For example, the next permutation of arr = [1,2,3] is [1,3,2].
        * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
        * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
        
        Given an array of integers nums, find the next permutation of nums.
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

    def nextPermutation(self, nums: list):
        temp = nums.copy()
        temp.sort()
        
        mat = self.permute(temp)

        for i in range(len(mat)):
            if nums == mat[i] and i != len(mat) - 1: 
                return mat[i+1]
            elif nums == mat[i] and i == len(mat) - 1:
                return mat[0] 

        return None

if __name__ == '__main__':

    s = Solution()

    # Test 1:
    
    print('Test 1:\n') 
    nums = [1, 2, 3]
    print('List 1: {}'.format(nums))
    sol = s.nextPermutation(nums) 
    print('Solution 1: {}\n'.format(sol))
    
    # Test 2:

    print('Test 2:\n') 
    nums = [3, 2, 1]
    print('List 2: {}'.format(nums))
    sol = s.nextPermutation(nums) 
    print('Solution 2: {}\n'.format(sol))
 
    # Test 3:

    print('Test 3:\n') 
    nums = [1, 1, 5]
    print('List 3: {}'.format(nums)) 
    sol = s.nextPermutation(nums) 
    print('Solution 3: {}\n'.format(sol))
