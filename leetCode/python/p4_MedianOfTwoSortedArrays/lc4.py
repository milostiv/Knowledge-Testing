import time 

class Solution:
    """ Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays """
    def findMedianSortedArrays(self, nums1: list, nums2: list) -> float:       
        nums1_size = len(nums1)
        nums2_size = len(nums2)
        count = i = j = 0
        median1 = median2 = 0.0
 
        while count <= (nums1_size + nums2_size) // 2:

            median2 = median1
                
            if i != nums1_size and j != nums2_size:     
                if nums1[i] < nums2[j]: 
                    median1 = nums1[i]
                    i += 1
                else:
                    median1 = nums2[j]
                    j += 1
            elif i < nums1_size:
                median1 = nums1[i]
                i += 1
            else:
                median1 = nums2[j]
                j += 1 

            count += 1

        if (nums1_size + nums2_size) % 2 == 1: # Odd case 
            return median1
        else: # Even case
            return (median1 + median2) / 2

    def test_function(self, nums1: list, nums2: list, sol: float, test_num: int): 
        start_time = time.time()
        temp = self.findMedianSortedArrays(nums1, nums2)
        end_time = time.time()
        
        if temp == sol:
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')        

s = Solution()

# Test 1
 
nums1 = [1, 3]
nums2 = [2]
s.test_function(nums1, nums2, 2, 1)

# Test 2

nums1 = [1, 2]
nums2 = [3, 4]
s.test_function(nums1, nums2, 2.5, 2)

# Test 3

nums1 = [0, 0]
nums2 = [0, 0]
s.test_function(nums1, nums2, 0, 3)

# Test 4

nums1 = []
nums2 = [1]
s.test_function(nums1, nums2, 1, 4)

# Test 5

nums1 = []
nums2 = [2]
s.test_function(nums1, nums2, 2, 5)
