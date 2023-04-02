#!/usr/bin/python3

class Solution:
    '''
        Given an array of integers nums sorted in non-decreasing order, 
        find the starting and ending position of a given target value.

        If target is not found in the array, return [-1, -1].

        You must write an algorithm with O(log n) runtime complexity.
    '''
    
    def searchRange(self, nums: list, target: int) -> list:
        
        start = 0
        end = len(nums) - 1
        sol = [-1, -1]

        if len(nums) == 0:
            return sol

        while start <= end:
            
            mid = (start + end) // 2;
        
            if nums[mid] == target:
                
                sol[0] = mid - 1
                temp = mid

                while nums[mid] == nums[temp]:
                    temp += 1

                sol[1] = temp - 1

                break
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1

        return sol

if __name__ == '__main__':

    nums = [5, 7, 7, 8, 8, 10]

    s = Solution()

    # Test 1:

    target = 8

    print('\nTest 1:\n') 
    print('List 1:', end = ' ')
    print(nums)
    print('Target 1: {}'.format(target))
    print('Solution 1:', end = ' ')
    print(s.searchRange(nums, target))

    # Test 2:
     
    target = 6

    print('\nTest 2:\n') 
    print('List 2:', end = ' ')
    print(nums)
    print('Target 2: {}'.format(target))
    print('Solution 2:', end = ' ')
    print(s.searchRange(nums, target))

    # Test 3:

    nums = []
    target = 0

    print('\nTest 3:\n') 
    print('List 3:', end = ' ')
    print(nums)
    print('Target 3: {}'.format(target))
    print('Solution 3:', end = ' ')
    print(s.searchRange(nums, target))
