#!/usr/bin/python3

class Solution:
    '''
        You are given an integer array nums. 
        You are initially positioned at the array's first index, 
        and each element in the array represents your maximum jump length at that position.

        Return true if you can reach the last index, or false otherwise.
    '''
    def canJump(self, nums: list) -> bool:

        curr = i = 0

        while i < len(nums) and i <= curr:

            curr = max(curr, i + nums[i]) 
            i += 1   

        return i == len(nums)

if __name__ == '__main__':

    s = Solution()

    # Test 1:

    print('Test 1:\n') 
    nums1 = [2, 3, 1, 1, 4]
    print('List 1: {}'.format(nums1))
    print('Solution 1: {}\n'.format(s.canJump(nums1)))

    # Test 2:   
 
    print('Test 2:\n') 
    nums2 = [3, 2, 1, 0, 4]
    print('List 2: {}'.format(nums2))
    print('Solution 2: {}'.format(s.canJump(nums2)))
