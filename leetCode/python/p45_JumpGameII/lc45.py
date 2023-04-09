#!/usr/bin/python3

class Solution:
    '''
        You are given a 0-indexed array of integers nums of length n. 
        You are initially positioned at nums[0].

        Each element nums[i] represents the maximum length of a forward jump from index i. 
        In other words, if you are at nums[i], you can jump to any nums[i + j] where:

            * 0 <= j <= nums[i] and
            * i + j < n

        Return the minimum number of jumps to reach nums[n - 1]. 
        The test cases are generated such that you can reach nums[n - 1].
    '''
    def jump(self, nums: list) -> int:
        
        prev = curr = level = 0

        while curr < len(nums) - 1:
            
            level += 1 
            prev = curr

            for i in range(prev + 1):
            
                curr = max(curr, i + nums[i])

        return level

if __name__ == '__main__':
   
    s = Solution()    
 
    # Test 1:

    print('Test 1:\n') 
    nums1 = [2, 3, 1, 1, 4]
    print('List 1: {}'.format(nums1))
    print('Solution 1: {}\n'.format(s.jump(nums1)))

    # Test 2:

    print('Test 2:\n') 
    nums2 = [2, 3, 1, 1, 4]
    print('List 2: {}'.format(nums2))
    print('Solution 2: {}'.format(s.jump(nums2)))
