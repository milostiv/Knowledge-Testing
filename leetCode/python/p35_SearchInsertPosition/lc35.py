#!/usr/bin/python3

class Solution:
    '''
        Given a sorted array of distinct integers and a target value,
        return the index if the target is found. 

        If not, return the index where it would be if it were inserted in order. */
    '''
    def searchInsert(self, nums: list, target: int) -> int:
     
        start = 0
        end = len(nums) - 1

        while start <= end:

            mid = (start + end) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1

        return end + 1

if __name__ == '__main__':

    s = Solution()

    nums = [1, 3, 5, 6]

    # Test 1:

    target1 = 5

    print('Test 1: \nTarget ({}) insert position is {}\n'.format(target1, s.searchInsert(nums, target1)))
    
    # Test 2:

    target2 = 2

    print('Test 2: \nTarget ({}) insert position is {}\n'.format(target2, s.searchInsert(nums, target2)))

    # Test 3:

    target3 = 7

    print('Test 3: \nTarget ({}) insert position is {}\n'.format(target3, s.searchInsert(nums, target3)))
