#!/usr/bin/python3

class Solution:
    '''
        Given an array of strings strs, group the anagrams together. 
        You can return the answer in any order.

        An Anagram is a word or phrase formed by rearranging the letters of a different word 
        or phrase, typically using all the original letters exactly once. 
    '''
    def groupAnagrams(self, strs: list):

        d = dict()
    
        for i in range(len(strs)):
            temp = ''.join(sorted(strs[i]))
 
            if temp not in d:
                d[temp] = [strs[i]]
            else:
                d[temp].append(strs[i])
   
        return d.values()

if __name__ == '__main__':
    
    s = Solution()

    # Test 1:

    print('Test 1:\n')

    strs1 = ['eat','tea','tan','ate','nat','bat'] 
    print('Strings 1: ' + str(strs1))

    sol1 = s.groupAnagrams(strs1)

    print('Grouped anagrams 1:', end = ' ')
    print(*sol1)

    # Test 2:

    print('\nTest 2:\n')
    strs2 = ['']

    print('Strings 2: ' + str(strs2))

    sol2 = s.groupAnagrams(strs2)
 
    print('Grouped anagrams 2:', end = ' ')
    print(*sol2)

    # Test 3:

    print('\nTest 3:\n')
    strs3 = ['a']

    print('Strings 3: ' + str(strs3))

    sol3 = s.groupAnagrams(strs3)
 
    print('Grouped anagrams 3:', end = ' ')
    print(*sol3)
